#pragma once

#ifdef _WIN32
    #ifdef BUILD_DLL
        #define DLL_EXPORT __declspec(dllexport)
    #else
        #define DLL_EXPORT __declspec(dllimport)
    #endif
#else
    #define DLL_EXPORT __attribute__((visibility("default")))
#endif

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/VertexArray.hpp>

namespace mc{
  class DLL_EXPORT principal{
    private:
      sf::RenderWindow window;
    public:
      principal(float hz, float a, float b);
      ~principal();
      void exec(const float hz);
      auto GraphFunc();
      auto Vector();
      auto Arrow();
      auto cicTrig();
      auto GraphCic();
      auto Xeixo();
      auto Yeixo();
      auto CicArrowY();
      auto CicArrowX();
      auto funcSin(const float hz, const int n);
      void position(float x_size, float y_size);
  };
}
