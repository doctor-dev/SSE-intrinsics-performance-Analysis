// Analysis of SSE Intrinsiscs.cpp : Defines the entry point for the application.
//

#include "Analysis of SSE Intrinsiscs.h"
#include "Fourier Transform/FourierTransform.h"
#include <vector>
using namespace std;

int main()
{	
	auto test = new vector<float>;
	test->push_back(1.0f);
	test->push_back(1.0f);
	test->push_back(1.0f);
	test->push_back(1.0f);
	auto res = FT<float>(*test);
	cout << (*res)[0]<< "  " << (*res)[1] << "  " << (*res)[2] << "  " << (*res)[3] << "  " << res->size() << endl;
	delete res;
	delete test;
	return 0;
}
