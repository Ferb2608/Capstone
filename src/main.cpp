#include <iostream>
#include "controller.h"
#include "game.h"
#include "renderer.h"
#include "gamer.h"
#include "menu.h"
#include "history.h"

int main()
{
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kGridWidth{32};
  constexpr std::size_t kGridHeight{32};

  Menu menu;
  History history;
  Gamer gamer;
  menu.MainMenu();
  int mode = menu.InputNumber();
  if (mode == 1)
  {
    string gamerName = menu.InputGamerName();
    gamer.SetName(gamerName);

    Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
    Controller controller;
    Game game(kGridWidth, kGridHeight);

    game.Run(controller, renderer, kMsPerFrame);
    std::cout << "Game has terminated successfully!\n";
    std::cout << "Score: " << game.GetScore() << "\n";
    std::cout << "Size: " << game.GetSize() << "\n";
    gamer.SetScore(game.GetScore());
    history.SaveHistory(gamer);
  }
  else if (mode == 2)
  {
    history.DisplayHistory();
  }

  return 0;
}