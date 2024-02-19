#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/VideoMode.hpp>

int main(){

  const float width = 780.0f;
  const float height = 720.0f;

  sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Graph");
  window.setPosition(sf::Vector2(0, 0));

  sf::RectangleShape background(sf::Vector2f(width, height));
  background.setFillColor(sf::Color::White);

  while(window.isOpen()){
    sf::Event event;
    while(window.pollEvent(event)){
      if(event.type == sf::Event::Closed){
        window.close();
      }
    }

    window.clear();
    window.draw(background);
    window.display();
  }

  return 0;
}
