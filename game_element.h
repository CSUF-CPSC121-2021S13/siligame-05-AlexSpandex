#ifndef GAME_ELEMENT_H
#define GAME_ELEMENT_H
#include "cpputils/graphics/image.h"
class GameElement {
 protected:
  int x_;
  int y_;
  int width_;
  int height_;
  bool isactive = true;

 public:
  // constructors
  GameElement() : x_(0), y_(0), width_(50), height_(50) {}
  GameElement(int x, int y, int width, int height) {
    x_ = x;
    y_ = y;
    width_ = width;
    height_ = height;
  }

  // getters
  int GetX() const;
  int GetY() const;
  int GetHeight() const;
  int GetWidth() const;
  bool GetIsActive() const;

  // setters
  void SetX(int x);
  void SetY(int y);
  void SetIsActive(bool notActive);

  // pure virtual function
  virtual void Draw(graphics::Image& draw) = 0;
  virtual void Move(const graphics::Image& move) = 0;

  // InterectsWith function
  bool IntersectsWith(const GameElement* intersects);
  bool IsOutOfBounds(const graphics::Image& bounds);
};
#endif
