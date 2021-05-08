#include "game_element.h"

// getters
int GameElement::GetX() const { return x_; }
int GameElement::GetY() const { return y_; }
int GameElement::GetHeight() const { return height_; }
int GameElement::GetWidth() const { return width_; }
bool GameElement::GetIsActive() const { return isactive; }

// setters
void GameElement::SetX(int x) { x_ = x; }
void GameElement::SetY(int y) { y_ = y; }
void GameElement::SetIsActive(bool notActive) { isactive = notActive; }

bool GameElement::IntersectsWith(const GameElement* intersects) {
  return !(x_ > intersects->GetX() + intersects->GetWidth() ||
           intersects->GetX() > GetX() + GetWidth() ||
           y_ > intersects->GetY() + intersects->GetHeight() ||
           intersects->GetY() > GetY() + GetHeight());
}

bool GameElement::IsOutOfBounds(const graphics::Image& bounds) {
  if (!(x_ + width_ > bounds.GetWidth() || x_ < 0 ||
      y_ + height_ > bounds.GetHeight() || y_ < 0)) {
    return false;
  } else {
    return true;
  }
}
