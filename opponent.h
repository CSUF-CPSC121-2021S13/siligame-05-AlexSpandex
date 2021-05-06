#ifndef OPPONENT_H
#define OPPONENT_H
#include <memory>
#include <vector>
#include "cpputils/graphics/image.h"
#include "game_element.h"

class OpponentProjectile : public GameElement {
 public:
  OpponentProjectile(int x, int y) : GameElement(x, y, 5, 5) {}
  OpponentProjectile() : GameElement() {}
  void Draw(graphics::Image &draw) override;
  void Move(const graphics::Image &move) override;

 private:
  std::vector<std::unique_ptr<OpponentProjectile>> op_vector;
};

class Opponent : public GameElement {
 public:
  Opponent(int x, int y) : GameElement(x, y, 50, 50) {}
  Opponent() : GameElement() {}
  void Draw(graphics::Image &draw) override;
  void Move(const graphics::Image &move) override;

  std::unique_ptr<OpponentProjectile> LaunchProjectile();

 private:
  int count = 0;
};
#endif
