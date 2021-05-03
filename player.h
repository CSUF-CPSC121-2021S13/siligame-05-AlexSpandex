#ifndef PLAYER_H
#define PLAYER_H
#include "game_element.h"
#include "opponent.h"

class Player : public GameElement {
 public:
  Player(int x, int y) : GameElement(x, y, 50, 50) {}
  Player() : GameElement() {}
  void Draw(graphics::Image &draw) override;
  void Move(const graphics::Image &move) override;
};

class PlayerProjectile : public GameElement {
 public:
  PlayerProjectile(int x, int y) : GameElement(x, y, 5, 5) {}
  PlayerProjectile() : GameElement() {}
  void Draw(graphics::Image &draw) override;
  void Move(const graphics::Image &move) override;
};
#endif
