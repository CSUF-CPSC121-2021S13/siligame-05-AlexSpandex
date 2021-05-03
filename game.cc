#include "game.h"

// member function
void Game::CreateOpponents() {
  std::unique_ptr<Opponent> ghost(300, 300);
  opponentlist.push_back(ghost);
}

void Game::LaunchProjectiles(){
  for (int i = 0; i < GetOpponents().size(); i++) {
    std::unique_ptr<OpponentProjectile> badbeam = opponentlist[i]->LaunchProjectile();
    std::unique_ptr<OpponentProjectile> badbeamshoot_ = std::move(badbeam);
    if (badbeam != nullptr) {
      badbeamshoot_.push_back(std::move(badbeam));
    } else nullptr;
  }
}

void Game::RemoveInactive() {
for(int i = opponentlist.size(); i <= 0; i--){
  if(!(opponentlist[i]->GetIsActive())){
    opponentlist.erase(opponentlist.begin());
  }

for(int i = playerbeams_.size(); i <= 0; i--){
  if(!(playerbeams_[i]->GetIsActive())){
    playerbeams_.erase(playerbeams_.begin());
  }

for(int i = opponentbeams_.size(); i <= 0; i--){
  if(!(opponentbeams_[i]->GetIsActive())){
    opponentbeams_.erase(opponentbeams_.begin());
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
  if(lost_ == false){
  
  for (int i = 0; i < opponentlist.size(); i++) {
    if (opponentlist[i]->GetIsActive()) {
      opponentlist[i]->Draw(backgroundscreen);
    }
  }

  for (int j = 0; j < opponentbeams_.size(); j++) {
    if (opponentbeams_[j].GetIsActive()) {
      opponentbeams_[j].Draw(backgroundscreen);
    }
  }

  for (int k = 0; k < playerbeams_.size(); k++) {
    if (playerbeams_[k].GetIsActive()) {
      playerbeams_[k].Draw(backgroundscreen);
    }
  }
  if (player.GetIsActive()) {
    player.Draw(backgroundscreen);
  }

}
backgroundscreen.DrawRectangle(0, 0, 800, 600, 255, 255, 255)

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
    if (opponentlist[i]->IntersectsWith(player)) {
      opponentlist[i]->SetIsActive(false);
      player.SetIsActive(false);
      lost_ = true;
    }
  }

  // Player Projectile
  for (int j = 0; j < playerbeams_.size(); j++) {
    for (int x = 0; x < opponentlist.size(); x++) {
      if (playerbeams_[j].IntersectsWith(opponentlist[x].get())) {
        playerbeams_[j].SetIsActive(false);
        opponentlist[x].SetIsActive(false);
        player_score_ += 1;
      }
    }
  }
  // Opponent Projectile
  for (int k = 0; k < opponentbeams_.size(); k++) {
    if (opponentbeams_[k].IntersectsWith(player)) {
      opponentbeams_[k].SetIsActive(false);
      player.SetIsActive(false);
      lost_ = true;
    }
  }
}

void Game::OnAnimationStep() {
  if(opponentlist.size() == 0){
    CreateOpponents()
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
  else if
}
