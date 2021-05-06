#include "game.h"

// member function
void Game::CreateOpponents() {
  std::unique_ptr<Opponent> ghost = std::make_unique<Opponent>(400, 50);
  opponentlist.push_back(std::move(ghost));
}

void Game::LaunchProjectiles() {
  for (int i = 0; i < opponentlist.size(); i++) {
    // std::unique_ptr<OpponentProjectile> badbeam
    // =std::make_unique<OpponentProjectile>(opponentlist[i]->GetX(),
    // opponentlist[i]->GetY())
    std::unique_ptr<OpponentProjectile> badbeam =
        opponentlist[i]->LaunchProjectile();
    if (badbeam != nullptr) {
      opponentbeams_.push_back(std::move(badbeam));
    } else
      continue;
  }
}

void Game::RemoveInactive() {
  for (int i = opponentlist.size() - 1; i >= 0; i--) {
    if (!(opponentlist[i]->GetIsActive())) {
      opponentlist.erase(opponentlist.begin() + i);
    }
  }
  for (int i = playerbeams_.size() - 1; i >= 0; i--) {
    if (!(playerbeams_[i]->GetIsActive())) {
      playerbeams_.erase(playerbeams_.begin() + i);
    }
  }
  for (int i = opponentbeams_.size() - 1; i >= 0; i--) {
    if (!(opponentbeams_[i]->GetIsActive())) {
      opponentbeams_.erase(opponentbeams_.begin() + i);
    }
  }
}

void Game::Init() {
  backgroundscreen.AddMouseEventListener(*this);
  backgroundscreen.AddAnimationEventListener(*this);
  player.GameElement::SetX(player.GameElement::GetX() + 3);
  player.GameElement::SetY(player.GameElement::GetY() + 3);
}

void Game::UpdateScreen() {
  backgroundscreen.DrawRectangle(0, 0, 800, 600, 255, 255, 255);

  std::string show_score = "Score: " + std::to_string(player_score_);
  backgroundscreen.DrawText(10, 10, show_score, 16, 0, 0, 0);

  if (player.GetIsActive()) {
    player.Draw(backgroundscreen);
  }
  for (int i = 0; i < opponentlist.size(); i++) {
    if (opponentlist[i]->GetIsActive()) {
      opponentlist[i]->Draw(backgroundscreen);
    }
  }

  for (int j = 0; j < opponentbeams_.size(); j++) {
    if (opponentbeams_[j]->GetIsActive()) {
      opponentbeams_[j]->Draw(backgroundscreen);
    }
  }

  for (int k = 0; k < playerbeams_.size(); k++) {
    if (playerbeams_[k]->GetIsActive()) {
      playerbeams_[k]->Draw(backgroundscreen);
    }
  }

  if (lost_) {
    std::string gameOver = "Game Over";
    backgroundscreen.DrawText(400, 300, gameOver, 30, graphics::Color(0, 0, 0));
  }
}

void Game::Start() { backgroundscreen.ShowUntilClosed(); }

void Game::MoveGameElements() {
  for (int i = 0; i < opponentlist.size(); i++) {
    if (opponentlist[i]->GetIsActive()) opponentlist[i]->Move(backgroundscreen);
  }

  for (int j = 0; j < opponentbeams_.size(); j++) {
    if (opponentbeams_[j]->GetIsActive()) {
      opponentbeams_[j]->Move(backgroundscreen);
    }
  }

  for (int k = 0; k < playerbeams_.size(); k++) {
    if (playerbeams_[k]->GetIsActive()) {
      playerbeams_[k]->Move(backgroundscreen);
    }
  }
}

void Game::FilterIntersections() {
  // Opponent
  for (int i = 0; i < opponentlist.size(); i++) {
    if (opponentlist[i]->IntersectsWith(&player)) {
      opponentlist[i]->SetIsActive(false);
      player.SetIsActive(false);
      lost_ = true;
    }
  }

  // Player Projectile
  for (int j = 0; j < playerbeams_.size(); j++) {
    for (int x = 0; x < opponentlist.size(); x++) {
      if (playerbeams_[j]->IntersectsWith(opponentlist[x].get())) {
        playerbeams_[j]->SetIsActive(false);
        opponentlist[x]->SetIsActive(false);
        if (player.GetIsActive()) {
          playerbeams_[j]->SetIsActive(false);
          opponentlist[x]->SetIsActive(false);
          player_score_++;
        }
      }
    }
  }
  // Opponent Projectile
  for (int k = 0; k < opponentbeams_.size(); k++) {
    if (opponentbeams_[k]->IntersectsWith(&player)) {
      opponentbeams_[k]->SetIsActive(false);
      player.SetIsActive(false);
      lost_ = true;
    }
  }
}

void Game::OnAnimationStep() {
  if (opponentlist.size() == 0) {
    CreateOpponents();
  }

  MoveGameElements();
  LaunchProjectiles();
  FilterIntersections();
  RemoveInactive();
  UpdateScreen();

  backgroundscreen.Flush();
}

void Game::OnMouseEvent(const graphics::MouseEvent& event) {
  if (event.GetX() <= backgroundscreen.GetWidth() && event.GetX() >= 0 &&
      event.GetY() <= backgroundscreen.GetHeight() && event.GetY() >= 0) {
    player.SetX(event.GetX() - (player.GetWidth() / 2));
    player.SetY(event.GetY() - (player.GetHeight() / 2));
  }
  if (event.GetMouseAction() == graphics::MouseAction::kPressed ||
      event.GetMouseAction() == graphics::MouseAction::kDragged) {
    std::unique_ptr<PlayerProjectile> pp =
        std::make_unique<PlayerProjectile>(player.GetX(), player.GetY());
    playerbeams_.push_back(std::move(pp));
  }
}
