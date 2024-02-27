#include <SFML/Graphics/PrimitiveType.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics.hpp>
#include <cmath>

#include "../include/graph.hpp"

sf::VertexArray L_FUNC;

mc::principal::principal(): window(sf::VideoMode::getDesktopMode(), "MCEcpp"){
  exec();
}

auto mc::principal::funcSin(){//Gerador dos dados para a criação do gráfico senoidal.
  float Hz, cic, val_x;
  Hz = 60.0f;
  cic = Hz*360.0f;
  float data[(int)cic];

  for(int i = 0; i < (int)cic; i++){
    float rad;
    float y;
    const float PI = 3.14f;
    rad = ((float)i*PI)/180.0f;
    y = std::sin(2.0f * PI * (rad/(1.0f/Hz)));
    data[i] = y;
  };


  sf::VertexArray l_func(sf::LineStrip, (int)cic);
/*  l_func[0].position = sf::Vector2f(15.0f, 15.0f);
  l_func[0].color = sf::Color::Blue;
  l_func[1].position = sf::Vector2f(20.0f, 100.0f);
  l_func[1].color = sf::Color::Blue;
  l_func[2].position = sf::Vector2f(30.0f, 100.0f);
  */l_func[2].color = sf::Color::Blue;
  val_x = 0.0f;

  
  for(int i = 0; i < (int)cic; i++){
    l_func[i].position = sf::Vector2f(val_x, ((data[i] * 10.0f) + 100.0f));
    l_func[i].color = sf::Color::Blue;
    val_x += 1.0f;
  };

  L_FUNC = l_func;
  return l_func;
}

auto mc::principal::position(){ //Função para gerar os dados da posição do gráfico.
  sf::Vector2u window_size = mc::principal::principal::window.getSize();
  float w_size_x = window_size.x;
  float w_size_y = window_size.y;
  float pos_x = (w_size_x/5);
  float pos_y = (9.0f/10.0f) * (w_size_y);

  std::vector<float> position = {pos_x, pos_y};
  return position;
}

mc::principal::~principal(){}

auto mc::principal::GraphFunc(){ //Cria  gráfico (layout)

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

auto mc::principal::Vector(){ //Cria o eixo "x" dentro do gráfico.
  sf::Vector2u window_size = mc::principal::principal::window.getSize();
  float w_size_x = window_size.x;
  float w_size_y = window_size.y;
  float pos_x = (w_size_x / 5);
  float pos_y = (9.0f/10.0f) * (w_size_y);

  sf::VertexArray vector(sf::LineStrip, 2);
  vector[0].position = sf::Vector2f(pos_x, (pos_y - (250.0f / 2.0f)));
  vector[1].position = sf::Vector2f((4*pos_x), (pos_y - (250.0f/2.0f)));
  
  vector[0].color = sf::Color::Black;
  vector[1].color = sf::Color::Black;
  
  return vector;
}

auto mc::principal::Arrow(){ //Cira a ponta do eixo

  sf::Vector2u window_size = mc::principal::principal::window.getSize();
  float w_size_x = window_size.x;
  float w_size_y = window_size.y;
  float pos_x = (w_size_x / 5);
  float pos_y = (9.0f/10.0f) * (w_size_y);

  sf::VertexArray arrow(sf::Triangles, 3);
  arrow[0].position = sf::Vector2f(((4*pos_x)-10), ((pos_y - (250.0f/2.0f)) - 5));
  arrow[1].position = sf::Vector2f(((4*pos_x)-10), (pos_y - ((250.0f/2.0f)) + 5));
  arrow[2].position = sf::Vector2f((4*pos_x), (pos_y - (250.0f/2.0f)));

  arrow[0].color = sf::Color::Black;
  arrow[1].color = sf::Color::Black;
  arrow[2].color = sf::Color::Black;

  return arrow;
}

void mc::principal::exec(){ //Executa toda a sequência que postra as janelas.

  sf::Vector2u window_size = mc::principal::principal::window.getSize();

  window.setPosition(sf::Vector2(0, 0));
  sf::RectangleShape bg;
  bg.setOutlineColor(sf::Color::White);
  bg.setSize(sf::Vector2f(window_size));
  bg.setPosition(0, 0);

  while(window.isOpen()){
    sf::Event event;
    sf::Vector2u window_size = mc::principal::principal::window.getSize();
    if((window_size.x < 800) && (window_size.y < 600)){
      mc::principal::principal::window.setSize(sf::Vector2u(800, 600));
    };
    while(window.pollEvent(event)){
      if(event.type == sf::Event::Closed){
        window.close();
      }
    };
    window.clear();
    window.draw(bg);
    window.draw(mc::principal::GraphFunc());
    window.draw(mc::principal::Vector());
    window.draw(mc::principal::Arrow());
    window.draw(mc::principal::funcSin());
    window.display();
  }
}
