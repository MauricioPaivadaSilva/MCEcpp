#include <iostream>
#include <cmath>
#include "MCE.h"

#define PI 3.14159265358979323

// void Animacao(char Hz) {}

void PlotSin(float Hz) {
	if (Hz == NULL) {
		Hz = 1.0f;
		float rad = 0.0f, x_total = 0.0f;
		x_total = Hz * 360;
		float * x_list = new float[x_total];
		float* list_sin = new float[x_total];
		for (int x = 0; x < x_total; x++) {
			x_list[x] = x;
			rad = (x * PI) / 180;
			list_sin[x] = std::sin(rad);
		}
	}
	else {
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
}

// void PlotCic(char complex) {}