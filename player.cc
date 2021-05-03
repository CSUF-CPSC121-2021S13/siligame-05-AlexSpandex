#include "player.h"
#include "game_element.h"
#include "opponent.h"

void Player::Move(const graphics::Image &move) {}

void PlayerProjectile::Move(const graphics::Image &move) {
  if (!GameElement::IsOutOfBounds(move)) {
    GameElement::SetX(x_ + 1);
    GameElement::SetY(y_ + 1);
  } else {
    isactive = false;
  }
}

void Player::Draw(graphics::Image &player) {
  player.DrawRectangle(x_ + 3, y_ + 4, 1, 7, 255, 0, 0);  ////////////////////
  player.DrawRectangle(x_ + 4, y_ + 3, 1, 9, 255, 0, 0);
  player.DrawRectangle(x_ + 5, y_ + 2, 1, 11, 255, 0, 0);
  player.DrawRectangle(x_ + 6, y_ + 1, 7, 13, 255, 0, 0);  ////left ear////////
  player.DrawRectangle(x_ + 13, y_ + 2, 1, 12, 255, 0, 0);
  player.DrawRectangle(x_ + 14, y_ + 3, 1, 20, 255, 0, 0);
  player.DrawRectangle(x_ + 15, y_ + 4, 1, 20, 255, 0, 0);
  player.DrawRectangle(x_ + 16, y_ + 6, 1, 19, 255, 0, 0);   ///////////////////
  player.DrawRectangle(x_ + 17, y_ + 8, 12, 17, 255, 0, 0);  // face background
  player.DrawRectangle(x_ + 29, y_ + 6, 1, 19, 255, 0, 0);   //////////////////
  player.DrawRectangle(x_ + 30, y_ + 4, 1, 19, 255, 0, 0);
  player.DrawRectangle(x_ + 31, y_ + 3, 1, 19, 255, 0, 0);
  player.DrawRectangle(x_ + 32, y_ + 2, 1, 12, 255, 0, 0);  //////right ear//
  player.DrawRectangle(x_ + 33, y_ + 1, 7, 13, 255, 0, 0);
  player.DrawRectangle(x_ + 40, y_ + 2, 1, 11, 255, 0, 0);
  player.DrawRectangle(x_ + 41, y_ + 3, 1, 9, 255, 0, 0);
  player.DrawRectangle(x_ + 42, y_ + 4, 1, 7, 255, 0, 0);  ////////////////////
  player.DrawRectangle(x_ + 16, y_ + 10, 4, 3, 255, 255, 255);  /// left
  player.DrawRectangle(x_ + 17, y_ + 9, 4, 3, 255, 255, 255);   /////eye
  player.DrawRectangle(x_ + 25, y_ + 9, 4, 3, 255, 255, 255);   ////right
  player.DrawRectangle(x_ + 26, y_ + 10, 4, 3, 255, 255, 255);  ////eye
  player.DrawRectangle(x_ + 16, y_ + 15, 14, 5, 0, 0, 0);       ////////////
  player.DrawRectangle(x_ + 17, y_ + 20, 12, 1, 0, 0, 0);       /// mouth
  player.DrawRectangle(x_ + 18, y_ + 21, 10, 1, 0, 0, 0);       ///////////
  player.DrawRectangle(x_ + 20, y_ + 24, 6, 2, 207, 141, 101);  // neck
  player.DrawRectangle(x_ + 15, y_ + 26, 16, 15, 40, 34, 34);   // shirt
  player.DrawRectangle(x_ + 13, y_ + 26, 2, 5, 40, 34, 34);     ////////////
  player.DrawRectangle(x_ + 9, y_ + 26, 2, 5, 207, 141, 101);   ////left
  player.DrawRectangle(x_ + 9, y_ + 26, 4, 5, 63, 48, 48);      //////arm
  player.DrawRectangle(x_ + 7, y_ + 26, 2, 5, 207, 141, 101);   /////////
  player.DrawRectangle(x_ + 31, y_ + 26, 2, 5, 40, 34, 34);     // right
  player.DrawRectangle(x_ + 31, y_ + 26, 4, 5, 40, 34, 34);     // arm
  player.DrawRectangle(x_ + 33, y_ + 26, 4, 5, 63, 48, 48);     ///////
  player.DrawRectangle(x_ + 37, y_ + 26, 2, 5, 207, 141, 101);  //////////
  player.DrawRectangle(x_ + 19, y_ + 32, 8, 1, 176, 175, 133);  // shirt
  player.DrawRectangle(x_ + 20, y_ + 31, 6, 1, 176, 175, 133);  // design
  player.DrawRectangle(x_ + 21, y_ + 30, 4, 1, 176, 175, 133);  //
  player.DrawRectangle(x_ + 22, y_ + 29, 2, 1, 176, 175, 133);  /////////
  player.DrawRectangle(x_ + 15, y_ + 41, 7, 6, 26, 52, 140);    ///////
  player.DrawRectangle(x_ + 22, y_ + 41, 2, 2, 26, 52, 140);    // jeans
  player.DrawRectangle(x_ + 24, y_ + 41, 7, 6, 26, 52, 140);    //////
  player.DrawRectangle(x_ + 13, y_ + 48, 2, 2, 40, 34, 34);     // left
  player.DrawRectangle(x_ + 15, y_ + 47, 7, 3, 40, 34, 34);     // shoes
  player.DrawRectangle(x_ + 24, y_ + 47, 7, 3, 40, 34, 34);     /////////////
  player.DrawRectangle(x_ + 31, y_ + 48, 2, 2, 40, 34, 34);     // right shoes
}

void PlayerProjectile::Draw(graphics::Image &playerprojectile) {
  playerprojectile.DrawRectangle(x_ + 0, y_ + 0, 5, 5, 255, 255, 255);
  playerprojectile.DrawRectangle(x_ + 0, y_ + 0, 4, 4, 236, 252, 126);
  playerprojectile.DrawRectangle(x_ + 0, y_ + 0, 2, 1, 189, 184, 56);
  playerprojectile.DrawRectangle(x_ + 0, y_ + 3, 1, 1, 189, 184, 56);
  playerprojectile.DrawRectangle(x_ + 1, y_ + 4, 1, 1, 189, 184, 56);
  playerprojectile.DrawRectangle(x_ + 3, y_ + 4, 1, 1, 189, 184, 56);
  playerprojectile.DrawRectangle(x_ + 4, y_ + 2, 1, 1, 189, 184, 56);
  playerprojectile.DrawRectangle(x_ + 4, y_ + 0, 1, 1, 189, 184, 56);
}
