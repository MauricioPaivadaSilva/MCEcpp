#include <iostream>
#include <cmath>
#include <tuple>
#include "MCE.hpp"
#include <SFML/Graphics.hpp>

const float PI = 3.14159265358979323f;

// void Animacao(char Hz) {}

/*/
void PlotSin(float Hz) {
	if (Hz == 0.0f) {
		Hz = 1.0f;
	};
	float rad = 0.0f, x_total = 0.0f;
	x_total = Hz * 360;
	float* x_list = new float[x_total];
	float* list_sin = new float[x_total];
	for (int x = 0; x < x_total; x++) {
		x_list[x] = x;
		rad = (x * PI) / 180;
		list_sin[x] = std::sin(rad);
	}
}
*/
// void PlotCic(char complex) {}

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}