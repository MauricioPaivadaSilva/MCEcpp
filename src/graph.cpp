#include <SFML/Graphics/PrimitiveType.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics.hpp>
#include <cmath>

#include "../include/graph.hpp"

float POS_X, POS_Y;

mc::principal::principal(float hz): window(sf::VideoMode::getDesktopMode(), "MCEcpp"){
  if(hz < 0.0f){
    hz = 0.0f;
  };
  position(window.getSize().x, window.getSize().y);
  exec(hz);
}

auto mc::principal::funcSin(float hz){ //Gerador dos dados para a criação do gráfico senoidal.
  float Hz, cic, val_x, pos_x, pos_y, point, size_vec_x;
  Hz = hz;
  cic = Hz*360.0f;
  float data[(int)cic];
  point = 0.0f;

  pos_x = POS_X;
  size_vec_x = (9.0f*pos_x) - pos_x;
  pos_y = POS_Y;

  for(int i = 0; i < (int)cic; i++){
    float rad, y;
    const float PI = 3.14159265358979323f;
    rad = (-point*PI)/180.0f;
    y = std::sin(10.0f * rad);
    data[i] = y;
    point += 1.0f/10.0f;
  };

  sf::VertexArray l_func(sf::LineStrip, (int)cic);
  val_x = 0.0f;

  
  for(int i = 0; i < (int)cic; i++){
    l_func[i].position = sf::Vector2f((pos_x + val_x), ((pos_y-125.0f) + (data[i] * 100.0f)));
    l_func[i].color = sf::Color::Blue;
    val_x += (size_vec_x / cic); // Dimenciona a função para que ela ocupe apenas o domínio do gráfico apresentado.
  };

  return l_func;
}

void mc::principal::position(float x_size, float y_size){ //Função para gerar os dados da posição do gráfico.
//  sf::Vector2u window_size = mc::principal::principal::window.getSize();
  float w_size_x = x_size;
  float w_size_y = y_size;
  float pos_x, pos_y;
  pos_x = (1.0f/10.0f)*(w_size_x);
  pos_y = (9.0f/10.0f) * (w_size_y);

  POS_X = pos_x;
  POS_Y = pos_y;
}

mc::principal::~principal(){}

auto mc::principal::GraphFunc(){ //Cria  gráfico (layout)

  sf::Vector2u window_size = mc::principal::principal::window.getSize();
  float w_size_x = window_size.x;
  float w_size_y = window_size.y;
  float pos_x = (1.0f/10.0f)*(w_size_x);
  float pos_y = (9.0f/10.0f) * (w_size_y);

  sf::VertexArray graph_func(sf::LineStrip, 5);
  graph_func[0].position = sf::Vector2f(pos_x, pos_y);
  graph_func[1].position = sf::Vector2f((9.0f * pos_x), pos_y);
  graph_func[2].position = sf::Vector2f((9.0f * pos_x), (pos_y - 250.0f));
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
  float pos_x = (1.0f/10.0f)*(w_size_x);
  float pos_y = (9.0f/10.0f) * (w_size_y);

  sf::VertexArray vector(sf::LineStrip, 2);
  vector[0].position = sf::Vector2f(pos_x, (pos_y - (250.0f / 2.0f)));
  vector[1].position = sf::Vector2f((9.0f*pos_x), (pos_y - (250.0f/2.0f)));
  
  vector[0].color = sf::Color::Black;
  vector[1].color = sf::Color::Black;
  
  return vector;
}

auto mc::principal::Arrow(){ //Cira a ponta do eixo

  sf::Vector2u window_size = mc::principal::principal::window.getSize();
  float w_size_x = window_size.x;
  float w_size_y = window_size.y;
  float pos_x = (1.0f/10.0f)*(w_size_x);
  float pos_y = (9.0f/10.0f) * (w_size_y);

  sf::VertexArray arrow(sf::Triangles, 3);
  arrow[0].position = sf::Vector2f(((9.0f*pos_x)-10), ((pos_y - (250.0f/2.0f)) - 5.0f));
  arrow[1].position = sf::Vector2f(((9.0f*pos_x)-10), (pos_y - ((250.0f/2.0f)) + 5.0f));
  arrow[2].position = sf::Vector2f((9.0f*pos_x), (pos_y - (250.0f/2.0f)));

  arrow[0].color = sf::Color::Black;
  arrow[1].color = sf::Color::Black;
  arrow[2].color = sf::Color::Black;

  return arrow;
}

void mc::principal::exec(float hz){ //Executa toda a sequência que postra as janelas.

  while(window.isOpen()){
    sf::Event event;
    sf::Vector2u window_size = mc::principal::principal::window.getSize();
    position(window_size.x, window_size.y);
    while(window.pollEvent(event)){
      if(event.type == sf::Event::Closed){
        window.close();
      };
    };
    window.clear(sf::Color::White);
    window.draw(mc::principal::GraphFunc());
    window.draw(mc::principal::Vector());
    window.draw(mc::principal::Arrow());
    window.draw(mc::principal::funcSin(hz));
    window.display();
  }
}
