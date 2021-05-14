#pragma once
#include <immintrin.h>


long float DotProduct(const float* a, const float* b,const int size) {
	long float result = 0;
	const float* const end = a + size;
	for (; a < end; a++, b++)
		result += a[0] * b[0];
	return result;
}

float DotProductSSE(const float* a, const float* b, const int size) {
	long float result = 0;
	const float* const end = a + size;
	float resultarr[8];
	__m256 inter_a;
	__m256 inter_b;
	__m256 inter_res;
	for (; a < end; a += 8, b += 8) {
		inter_a = _mm256_loadu_ps(a);
		inter_b = _mm256_loadu_ps(b);
		inter_res = _mm256_mul_ps(inter_a, inter_b);
		_mm256_storeu_ps(resultarr, inter_res);
		for (auto fl : resultarr) {
			result += fl;
		}
	}
	return result;
}

float DotProductSSEDP(const float* a, const float* b, const int size) {
	const float* const end = a + size;
	float resultarr[8];
	__m256 inter_a;
	__m256 inter_b;
	__m256 inter_res;
	__m256 acc = _mm256_setzero_ps();
	for (; a < end; a += 8, b += 8) {
		inter_a = _mm256_loadu_ps(a);
		inter_b = _mm256_loadu_ps(b);
		inter_res = _mm256_dp_ps(inter_a, inter_b, 0xFF);
		acc = _mm256_add_ps(acc, inter_res);
	}
	const __m128 low = _mm256_castps256_ps128(acc);	//< Compiles into no instructions. The low half of a YMM register is directly accessible as an XMM register with the same number.
	const __m128 high = _mm256_extractf128_ps(acc, 1);	//< This one however does need to move data, from high half of a register into low half. vextractf128 instruction does that.
	const __m128 result = _mm_add_ss(low, high);
	return _mm_cvtss_f32(result);
}
