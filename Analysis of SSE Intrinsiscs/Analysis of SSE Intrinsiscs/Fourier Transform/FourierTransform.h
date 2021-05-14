#pragma once
#include <iostream>
#include <Vector>

using namespace std;

template<class T>
static vector<T>* FT(vector<T> signal) {
	auto result = new vector<T>;
	for (int i = 0; i < signal.size(); i++) {
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


template<class T>
static vector<T>* FTSSE(vector<T> signal) {
	auto result = new vector<T>;
	for (int i = 0; i < signal.size(); i++) {
		int j = 0;
		float resr = 0, resi = 0;
		float ansr[8],ansi[8];
		__m256 accr = _mm256_setzero_ps();
		__m256 acci = _mm256_setzero_ps();
		for (auto iter = signal.begin()._Ptr; iter < signal.end()._Ptr; iter += 8) {// I am aware that last <4 odd numbers will get discarded
			__m256 xn = _mm256_loadu_ps(iter);
			float cosarg[8] = { 2 * 3.14 / signal.size() * i * j++, 2 * 3.14 / signal.size() * i * j++, 2 * 3.14 / signal.size() * i * j++, 2 * 3.14 / signal.size() * i * j++, 2 * 3.14 / signal.size() * i * j++, 2 * 3.14 / signal.size() * i * j++, 2 * 3.14 / signal.size() * i * j++, 2 * 3.14 / signal.size() * i * j++};
			__m256 cosargsse = _mm256_loadu_ps(cosarg);
			__m256 cos = _mm256_cos_ps(cosargsse);
			__m256 real = _mm256_mul_ps(xn, cos);
			accr = _mm256_add_ps(accr, real);
			__m256 sin = _mm256_sin_ps(cosargsse);
			__m256 imag = _mm256_mul_ps(xn, sin);
			acci = _mm256_add_ps(acci, imag);
		}
		_mm256_storeu_ps(ansr, accr);
		_mm256_storeu_ps(ansi, acci);
		for (auto i : ansr) {
			resr += i;
		};
		for (auto i : ansi) {
			resi += i;
		};
		result->push_back(sqrt(resr *resr + resi * resi));
	}
	return result;
}
