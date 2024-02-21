#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <iostream>

namespace mc{
  class principal{
    private:
      sf::RenderWindow window;
    public:
      principal();
      ~principal();
      void exec();
  };
}
