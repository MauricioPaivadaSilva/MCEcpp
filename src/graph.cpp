#include <SFML/Graphics/PrimitiveType.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics.hpp>
#include <future>
#include <iostream>

#include "../include/graph.hpp"

mc::principal::principal(): window(sf::VideoMode::getDesktopMode(), "MCEcpp"){
  exec();
}

mc::principal::~principal(){}

auto mc::principal::GraphFunc(){

  sf::Vector2u window_size = mc::principal::principal::window.getSize();
  float w_size_x = window_size.x;
  float w_size_y = window_size.y;
  float pos_x = (w_size_x / 5);
  float pos_y = (9.0f/10.0f) * (w_size_y);

  sf::VertexArray graph_func(sf::LineStrip, 5);
  graph_func[0].position = sf::Vector2f(pos_x, pos_y);
  graph_func[1].position = sf::Vector2f((4 * pos_x), pos_y);
  graph_func[2].position = sf::Vector2f((4 * pos_x), (pos_y - 250.0f));
  graph_func[3].position = sf::Vector2f(pos_x, (pos_y - 250.0f));
  graph_func[4].position = sf::Vector2f(pos_x, pos_y);

  // Define a color for lines

  graph_func[0].color = sf::Color::Black;
  graph_func[1].color = sf::Color::Black;
  graph_func[2].color = sf::Color::Black;
  graph_func[3].color = sf::Color::Black;
  graph_func[4].color = sf::Color::Black;

  return graph_func;
}

void mc::principal::exec(){

  sf::Vector2u window_size = mc::principal::principal::window.getSize();

  window.setPosition(sf::Vector2(0, 0));
  sf::RectangleShape bg;
  bg.setOutlineColor(sf::Color::White);
  bg.setSize(sf::Vector2f(window_size));
  bg.setPosition(0, 0);

  while(window.isOpen()){
    sf::Event event;
    while(window.pollEvent(event)){
      if(event.type == sf::Event::Closed){
        window.close();
      }
    };
    window.clear();
    window.draw(bg);
    window.draw(mc::principal::GraphFunc());
    window.display();
  }
}
