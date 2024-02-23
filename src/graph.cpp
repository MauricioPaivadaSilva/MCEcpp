#include <SFML/Graphics/RectangleShape.hpp>
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

  sf::RectangleShape graph_func;
  graph_func.setPosition(pos_x, pos_y);
  graph_func.setSize(sf::Vector2f((3*pos_x), -(250.0f)));
  graph_func.setFillColor(sf::Color::Black);

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
