#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <memory>
#include <vector>
#include "cpputils/graphics/image.h"
#include "cpputils/graphics/image_event.h"
#include "game_element.h"
#include "opponent.h"
#include "player.h"

class Game : public graphics::AnimationEventListener,
             graphics::MouseEventListener {
 private:
  graphics::Image backgroundscreen;
 std::vector<std::unique_ptr<Opponent>> opponentlist;
  std::vector<std::unique_ptr<OpponentProjectile>> opponentbeams_;
  std::vector<std::unique_ptr<PlayerProjectile>> playerbeams_;
  Player player;
 int player_score_ = 0;
 bool lost_;

 public:
  // getters
  graphics::Image &GetGameScreen() { return backgroundscreen; }
  Player &GetPlayer() { return player; }

  std::vector<std::unique_ptr<Opponent>> &GetOpponents() { return opponentlist; }
  std::vector<std::unique_ptr<OpponentProjectile>> &GetOpponentProjectiles() {return opponentbeams_;}
   std::vector<std::unique_ptr<PlayerProjectile>> &GetPlayerProjectiles() { return playerbeams_; }

  int GetScore() const { return  player_score_; }
  bool HasLost() const { return lost_; }
  // constructor
  Game() : backgroundscreen(800, 600) {}
  Game(const int &width, const int &height) : backgroundscreen(width, height) {}

  // member function
  void LaunchProjectiles();
  void RemoveInactive();
  void CreateOpponents();
  void CreateOpponentProjectiles();
  void CreatePlayerProjectiles();
  void Init();
  void Start();
  void UpdateScreen();
  void MoveGameElements();
  void OnAnimationStep() override;
  void OnMouseEvent(const graphics::MouseEvent &event) override;
  void FilterIntersections();
};
#endif
