#pragma once
#include <iostream>
#include <Vector>

using namespace std;

template<class T>
static vector<T>* FT(vector<T> signal) {
	auto result = new vector<T>;
	for (int i = 0; i < 1000000; i++) {
		int j = 0;
		float real = 0;
		float imag = 0;
		for (auto iter : signal) {
			real += iter * cos(2 * 3.14 / signal.size() * i * j);
			imag += iter * sin(2 * 3.14 / signal.size() * i * j);
			j++;
		}
		result->push_back(sqrt(real*real + imag*imag));
	}
	return result;
}
