// Analysis of SSE Intrinsiscs.cpp : Defines the entry point for the application.
//

#include "Analysis of SSE Intrinsiscs.h"
#include "Fourier Transform/FourierTransform.h"
#include "Dot Product/DotProduct.h"

using namespace std;

typedef std::chrono::high_resolution_clock Time;
typedef std::chrono::milliseconds ms;

int main()
{
	/*###########################################################################
		Code Comparing different implementaions of Dot Product
	##############################################################################*/
	//int size = 64 * 1024 * 1024;
	////allocating two arrays that act as a vector of size->size
	//auto a = (float*)malloc(size * sizeof(float));
	//auto b = (float*)malloc(size * sizeof(float));
	//
	//
	////initializing the array to random values
	//for (int i = 0; i < size; i++) {
	//	a[i] = rand();
	//	b[i] = rand();
	//}
	//
	//
	////Dot Product using scalar operation
	//auto start = Time::now();
	//auto result = DotProduct(a, b, size);
	//auto end = Time::now();
	//auto interval = end - start;
	//cout << "Time taken by function using scalar instructions" << endl;
	//cout << chrono::duration_cast<chrono::milliseconds>(interval).count() << "ms" << endl;
	//cout << result << endl;
	//
	//
	////Dot product using SIMD for add for more accuracy
	//start = Time::now();
	//result = DotProductSSE(a, b, size);
	//end = Time::now();
	//interval = end - start;
	//cout << "Time taken by function using vector instructions" << endl;
	//cout << chrono::duration_cast<chrono::milliseconds>(interval).count() << "ms" << endl;
	//cout << result << endl;
	//
	//
	////Dot product using SIMD for dot product for less accuracy but faster performance
	//start = Time::now();
	//result = DotProductSSEDP(a, b, size);
	//end = Time::now();
	//interval = end - start;
	//cout << "Time taken by function using vector instructions, less accuracy for more speed" << endl;
	//cout << chrono::duration_cast<chrono::milliseconds>(interval).count() << "ms" << endl;
	//cout << result << endl;
	//
	//
	//free(a);
	//free(b);
	//return 0;

	/*###########################################################################
		Code Comparing different implementaions of fourier transform
	##############################################################################*/

	//const auto size = 1024 ;
	////allocating array with random values of size ->size
	//auto arr = (float*)malloc(size * sizeof(float));
	//vector<float> testobj(arr, arr + size);
	//auto test = &testobj;
	//
	////Function using Scalar instructions
	//auto start = Time::now();
	//auto res = FT<float>(*test);
	//auto end = Time::now();
	//auto interval = end - start;
	//cout << "Time taken by function using scalar instructions" << endl;
	//cout << chrono::duration_cast<chrono::milliseconds>(interval).count() << "ms"  << endl;
	//cout << (*res)[0] << "  " << (*res)[1] << "  " << (*res)[2] << "  "<< (*res)[3] << endl;
	//
	////Function using Vector instructions
	//start = Time::now();
	//res = FTSSE<float>(*test);
	//end = Time::now();
	//interval = end - start;
	//cout << "Time taken by function using vector instructions" << endl;
	//cout << chrono::duration_cast<chrono::milliseconds>(interval).count() << "ms"  << endl;
	//cout << (*res)[0] << "  " << (*res)[1] << "  " << (*res)[2] << "  " << (*res)[3] << endl;
	//
	//
	//delete res;
	//delete arr;
	//return 0;
}
