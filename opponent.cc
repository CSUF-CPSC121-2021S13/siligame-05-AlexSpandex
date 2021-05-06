#include "opponent.h"
#include <memory>

void Opponent::Move(const graphics::Image& move) {
  if (!GameElement::IsOutOfBounds(move)) {
    GameElement::SetX(x_ + 1);
    GameElement::SetY(y_ + 1);
  } else {
    isactive = false;
  }
}

void OpponentProjectile::Move(const graphics::Image& move) {
  if (!GameElement::IsOutOfBounds(move)) {
    GameElement::SetX(x_ + 1);
    GameElement::SetY(y_ + 1);
  } else {
    isactive = false;
  }
}

std::unique_ptr<OpponentProjectile> Opponent::LaunchProjectile() {
  if (count == 50){
     std::unique_ptr<OpponentProjectile> badbeam = std::make_unique<OpponentProjectile>((x_+ width_) * 0.5, y_ + height_);
     count = 0;
     return badbeam;
  }
  else {
    count++;
    return nullptr;
  }
  }

void Opponent::Draw(graphics::Image& opponent) {
  opponent.DrawRectangle(x_ + 19, y_ + 1, 11, 2, 48, 44, 44);   ////////////
  opponent.DrawRectangle(x_ + 16, y_ + 3, 3, 2, 48, 44, 44);    /// Dark
  opponent.DrawRectangle(x_ + 14, y_ + 5, 2, 2, 48, 44, 44);    ///
  opponent.DrawRectangle(x_ + 12, y_ + 7, 2, 4, 48, 44, 44);    /// Gray
  opponent.DrawRectangle(x_ + 10, y_ + 11, 2, 16, 48, 44, 44);  ///
  opponent.DrawRectangle(x_ + 8, y_ + 15, 2, 2, 48, 44, 44);    //
  opponent.DrawRectangle(x_ + 6, y_ + 13, 2, 2, 48, 44, 44);    /// Outline
  opponent.DrawRectangle(x_ + 4, y_ + 11, 2, 2, 48, 44, 44);    ///
  opponent.DrawRectangle(x_ + 2, y_ + 9, 2, 2, 48, 44, 44);     ///
  opponent.DrawRectangle(x_ + 0, y_ + 11, 2, 6, 48, 44, 44);    ///
  opponent.DrawRectangle(x_ + 2, y_ + 17, 2, 4, 48, 44, 44);    ////
  opponent.DrawRectangle(x_ + 4, y_ + 21, 2, 4, 48, 44, 44);    ///
  opponent.DrawRectangle(x_ + 6, y_ + 25, 2, 2, 48, 44, 44);    ////
  opponent.DrawRectangle(x_ + 8, y_ + 27, 2, 10, 48, 44, 44);   /////
  opponent.DrawRectangle(x_ + 6, y_ + 37, 2, 4, 48, 44, 44);    ////
  opponent.DrawRectangle(x_ + 4, y_ + 41, 2, 7, 48, 44, 44);    /////
  opponent.DrawRectangle(x_ + 2, y_ + 44, 2, 2, 48, 44, 44);    ///////
  opponent.DrawRectangle(x_ + 6, y_ + 46, 4, 2, 48, 44, 44);    ////
  opponent.DrawRectangle(x_ + 10, y_ + 44, 4, 2, 48, 44, 44);   ///
  opponent.DrawRectangle(x_ + 14, y_ + 42, 4, 2, 48, 44, 44);   //
  opponent.DrawRectangle(x_ + 18, y_ + 44, 4, 2, 48, 44, 44);   ///
  opponent.DrawRectangle(x_ + 22, y_ + 46, 6, 2, 48, 44, 44);   ///
  opponent.DrawRectangle(x_ + 28, y_ + 44, 3, 2, 48, 44, 44);   ////
  opponent.DrawRectangle(x_ + 31, y_ + 42, 3, 2, 48, 44, 44);   ////
  opponent.DrawRectangle(x_ + 36, y_ + 44, 3, 2, 48, 44, 44);   /////
  opponent.DrawRectangle(x_ + 39, y_ + 46, 4, 2, 48, 44, 44);   /////
  opponent.DrawRectangle(x_ + 43, y_ + 41, 2, 7, 48, 44, 44);   ////
  opponent.DrawRectangle(x_ + 45, y_ + 44, 2, 2, 48, 44, 44);   ////
  opponent.DrawRectangle(x_ + 41, y_ + 37, 2, 4, 48, 44, 44);   ////
  opponent.DrawRectangle(x_ + 39, y_ + 27, 2, 10, 48, 44, 44);  ////
  opponent.DrawRectangle(x_ + 41, y_ + 25, 2, 2, 48, 44, 44);   ////
  opponent.DrawRectangle(x_ + 43, y_ + 21, 2, 4, 48, 44, 44);   ////
  opponent.DrawRectangle(x_ + 45, y_ + 17, 2, 4, 48, 44, 44);   ////
  opponent.DrawRectangle(x_ + 47, y_ + 11, 2, 6, 48, 44, 44);   ////
  opponent.DrawRectangle(x_ + 45, y_ + 9, 2, 2, 48, 44, 44);    ////
  opponent.DrawRectangle(x_ + 43, y_ + 11, 2, 2, 48, 44, 44);   ////
  opponent.DrawRectangle(x_ + 41, y_ + 13, 2, 2, 48, 44, 44);   ////
  opponent.DrawRectangle(x_ + 39, y_ + 15, 2, 2, 48, 44, 44);   ////
  opponent.DrawRectangle(x_ + 37, y_ + 11, 2, 16, 48, 44, 44);  ////
  opponent.DrawRectangle(x_ + 35, y_ + 7, 2, 4, 48, 44, 44);    ////
  opponent.DrawRectangle(x_ + 33, y_ + 5, 2, 2, 48, 44, 44);    ////
  opponent.DrawRectangle(x_ + 30, y_ + 3, 3, 2, 48, 44,
                         44);  //////////////////////
  opponent.DrawRectangle(x_ + 2, y_ + 11, 2, 6, 88, 82, 82);       ////light
  opponent.DrawRectangle(x_ + 4, y_ + 19, 2, 2, 88, 82, 82);       ////
  opponent.DrawRectangle(x_ + 6, y_ + 23, 2, 2, 88, 82, 82);       ////
  opponent.DrawRectangle(x_ + 8, y_ + 25, 2, 2, 88, 82, 82);       ////
  opponent.DrawRectangle(x_ + 6, y_ + 44, 4, 2, 88, 82, 82);       ////////
  opponent.DrawRectangle(x_ + 10, y_ + 42, 2, 2, 88, 82, 82);      ////
  opponent.DrawRectangle(x_ + 12, y_ + 40, 2, 4, 88, 82, 82);      ////
  opponent.DrawRectangle(x_ + 14, y_ + 38, 4, 4, 88, 82, 82);      ////
  opponent.DrawRectangle(x_ + 18, y_ + 40, 2, 4, 88, 82, 82);      ////
  opponent.DrawRectangle(x_ + 20, y_ + 42, 2, 2, 88, 82, 82);      ////
  opponent.DrawRectangle(x_ + 22, y_ + 44, 2, 2, 88, 82, 82);      ////
  opponent.DrawRectangle(x_ + 26, y_ + 44, 2, 2, 88, 82, 82);      ////Gray
  opponent.DrawRectangle(x_ + 28, y_ + 42, 1, 2, 88, 82, 82);      ////
  opponent.DrawRectangle(x_ + 29, y_ + 40, 2, 4, 88, 82, 82);      ////
  opponent.DrawRectangle(x_ + 31, y_ + 38, 5, 4, 88, 82, 82);      ////
  opponent.DrawRectangle(x_ + 36, y_ + 40, 2, 4, 88, 82, 82);      ////
  opponent.DrawRectangle(x_ + 38, y_ + 42, 2, 1, 88, 82, 82);      ////
  opponent.DrawRectangle(x_ + 39, y_ + 44, 4, 2, 88, 82, 82);      ////
  opponent.DrawRectangle(x_ + 39, y_ + 25, 2, 2, 88, 82, 82);      ////
  opponent.DrawRectangle(x_ + 43, y_ + 19, 2, 2, 88, 82, 82);      ////
  opponent.DrawRectangle(x_ + 41, y_ + 23, 2, 2, 88, 82, 82);      ////
  opponent.DrawRectangle(x_ + 45, y_ + 11, 2, 6, 88, 82, 82);      /////////////
  opponent.DrawRectangle(x_ + 4, y_ + 13, 2, 6, 255, 255, 255);    ////Going
  opponent.DrawRectangle(x_ + 6, y_ + 15, 2, 8, 255, 255, 255);    ////ghost
  opponent.DrawRectangle(x_ + 8, y_ + 17, 2, 8, 255, 255, 255);    ////
  opponent.DrawRectangle(x_ + 6, y_ + 41, 4, 3, 255, 255, 255);    ////
  opponent.DrawRectangle(x_ + 8, y_ + 37, 4, 5, 255, 255, 255);    ////
  opponent.DrawRectangle(x_ + 10, y_ + 27, 4, 13, 255, 255, 255);  ////
  opponent.DrawRectangle(x_ + 12, y_ + 11, 25, 27, 255, 255, 255);  ////
  opponent.DrawRectangle(x_ + 18, y_ + 38, 13, 2, 255, 255, 255);   ////
  opponent.DrawRectangle(x_ + 20, y_ + 40, 9, 2, 255, 255, 255);    ////
  opponent.DrawRectangle(x_ + 22, y_ + 42, 6, 2, 255, 255, 255);    ////
  opponent.DrawRectangle(x_ + 24, y_ + 44, 2, 2, 255, 255, 255);    ////
  opponent.DrawRectangle(x_ + 36, y_ + 37, 5, 3, 255, 255, 255);    ////
  opponent.DrawRectangle(x_ + 38, y_ + 37, 3, 5, 255, 255, 255);    ////
  opponent.DrawRectangle(x_ + 39, y_ + 41, 4, 3, 255, 255, 255);    ////
  opponent.DrawRectangle(x_ + 37, y_ + 27, 2, 10, 255, 255, 255);   ////
  opponent.DrawRectangle(x_ + 39, y_ + 17, 2, 8, 255, 255, 255);    ////
  opponent.DrawRectangle(x_ + 1, y_ + 15, 2, 8, 255, 255, 255);     ////
  opponent.DrawRectangle(x_ + 43, y_ + 13, 2, 6, 255, 255, 255);    ////
  opponent.DrawRectangle(x_ + 14, y_ + 7, 21, 4, 255, 255, 255);    ////
  opponent.DrawRectangle(x_ + 16, y_ + 5, 17, 2, 255, 255, 255);    ////
  opponent.DrawRectangle(x_ + 19, y_ + 3, 11, 2, 255, 255, 255);    ////////////
  opponent.DrawRectangle(x_ + 16, y_ + 14, 3, 3, 0, 0, 0);          ////left eye
  opponent.DrawRectangle(x_ + 27, y_ + 12, 3, 1, 0, 0, 0);     ////right eye
  opponent.DrawRectangle(x_ + 26, y_ + 13, 5, 1, 0, 0, 0);     ////
  opponent.DrawRectangle(x_ + 25, y_ + 14, 7, 1, 0, 0, 0);     ///
  opponent.DrawRectangle(x_ + 25, y_ + 15, 7, 1, 0, 0, 0);     ///
  opponent.DrawRectangle(x_ + 25, y_ + 16, 7, 1, 0, 0, 0);     ////
  opponent.DrawRectangle(x_ + 26, y_ + 17, 5, 1, 0, 0, 0);     ///////////
  opponent.DrawRectangle(x_ + 14, y_ + 20, 2, 2, 0, 0, 0);     // mouth
  opponent.DrawRectangle(x_ + 16, y_ + 22, 2, 2, 0, 0, 0);     ////
  opponent.DrawRectangle(x_ + 28, y_ + 22, 2, 2, 0, 0, 0);     /////
  opponent.DrawRectangle(x_ + 30, y_ + 20, 2, 2, 0, 0, 0);     //////
  opponent.DrawRectangle(x_ + 18, y_ + 22, 2, 10, 255, 0, 0);  /////////
  opponent.DrawRectangle(x_ + 25, y_ + 14, 7, 1, 255, 0, 0);   ////
  opponent.DrawRectangle(x_ + 20, y_ + 22, 2, 4, 255, 0, 0);   /////red
  opponent.DrawRectangle(x_ + 25, y_ + 14, 7, 1, 255, 0, 0);   ///////mouth
  opponent.DrawRectangle(x_ + 22, y_ + 22, 2, 2, 255, 0,
                         0);  /////////////////////
  opponent.DrawRectangle(x_ + 24, y_ + 22, 2, 4, 255, 0, 0);       ///////
  opponent.DrawRectangle(x_ + 26, y_ + 22, 2, 10, 255, 0, 0);      /////saliva
  opponent.DrawRectangle(x_ + 18, y_ + 32, 2, 2, 185, 136, 136);   ///
  opponent.DrawRectangle(x_ + 20, y_ + 26, 6, 10, 185, 136, 136);  //
  opponent.DrawRectangle(x_ + 22, y_ + 24, 2, 2, 185, 136, 136);   //
  opponent.DrawRectangle(x_ + 26, y_ + 32, 2, 2, 185, 136, 136);   ////////////
}

void OpponentProjectile::Draw(graphics::Image& opponentprojectile) {
  opponentprojectile.DrawRectangle(x_ + 0, y_ + 0, 50, 50, 255, 255, 255);
  opponentprojectile.DrawRectangle(x_ + 0, y_ + 0, 4, 4, 29, 27, 27);
  opponentprojectile.DrawRectangle(x_ + 0, y_ + 0, 1, 1, 255, 255, 255);
  opponentprojectile.DrawRectangle(x_ + 2, y_ + 0, 1, 1, 255, 255, 255);
  opponentprojectile.DrawRectangle(x_ + 4, y_ + 0, 1, 1, 255, 255, 255);
  opponentprojectile.DrawRectangle(x_ + 1, y_ + 1, 1, 1, 255, 255, 255);
  opponentprojectile.DrawRectangle(x_ + 3, y_ + 1, 1, 1, 255, 255, 255);
  opponentprojectile.DrawRectangle(x_ + 0, y_ + 2, 1, 1, 255, 255, 255);
  opponentprojectile.DrawRectangle(x_ + 2, y_ + 2, 1, 1, 255, 255, 255);
  opponentprojectile.DrawRectangle(x_ + 4, y_ + 2, 1, 1, 255, 255, 255);
  opponentprojectile.DrawRectangle(x_ + 1, y_ + 3, 1, 1, 255, 255, 255);
  opponentprojectile.DrawRectangle(x_ + 0, y_ + 0, 1, 1, 255, 255, 255);
  opponentprojectile.DrawRectangle(x_ + 0, y_ + 0, 1, 1, 255, 255, 255);
  opponentprojectile.DrawRectangle(x_ + 0, y_ + 4, 1, 1, 255, 255, 255);
  opponentprojectile.DrawRectangle(x_ + 2, y_ + 4, 1, 1, 255, 255, 255);
  opponentprojectile.DrawRectangle(x_ + 4, y_ + 4, 1, 1, 255, 255, 255);
}
