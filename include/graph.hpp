#pragma once

#include <SFML/Graphics/RenderWindow.hpp>

namespace mc{
  class principal{
    private:
      sf::RenderWindow window;
    public:
      principal();
      ~principal();
      void exec();
      auto GraphFunc();
      auto Vector();
      auto Arrow();
  };
  class sin{
    public:
      std::vector<double> Sin(double hz);
  };
}
