#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

#include "../include/graph.hpp"

mc::principal::principal(): window(sf::VideoMode::getDesktopMode(), "MCEcpp"){
  exec();
}

mc::principal::~principal(){}

void mc::principal::exec(){
  window.setPosition(sf::Vector2(0, 0));
  sf::RectangleShape bg;
  bg.setOutlineColor(sf::Color::White);
  bg.setSize(sf::Vector2f(1080.0f, 720.0f));
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
    window.display();
  }
}
