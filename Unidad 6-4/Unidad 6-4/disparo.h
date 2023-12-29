#pragma once
#include <cstdlib>
#include <iostream>
using namespace std;

bool disparo(float xm, float ym, float xn, float yn) {
	bool imp = false;
	if (xm > (xn - 50) && xm<(xn + 50) && ym>(yn - 50) && ym < (yn + 50)) {
		imp = true;
	}
	return imp;
};
