#include <iostream>
#include <cmath>
#include <tuple>
#include "MCE.h"

#define PI 3.14159265358979323

// void Animacao(char Hz) {}

std::tuple<float*, float*> PlotSin(float Hz) {
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
	};
	return std::make_tuple(x_list, list_sin);
}

// void PlotCic(char complex) {}