#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/VertexArray.hpp>

namespace mc{
  class principal{
    private:
      sf::RenderWindow window;
      auto position();
    public:
      principal();
      ~principal();
      void exec();
      auto GraphFunc();
      auto Vector();
      auto Arrow();
      auto funcSin();
  };
}
