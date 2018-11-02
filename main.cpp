#include <iostream>
#include <ctime>
#include <LIMITS.H>
#include	<math.h>
using namespace std;

const int range = 10;
const int arrSize = 100;
int avrg = 0;

int get_dev1(int* arr)		//in forehead solution
{
	int dev = 0;
	for (int i = 0; i < arrSize; ++i)
	{
		dev += pow(arr[i]-avrg, 2);
	}
	dev /= arrSize-1;
	dev = sqrt(dev);
	return dev;
}

int sqrSumm = 0;
int summ = 0;
int get_dev2(int* arr)
{
	int dev = 0;
	for (int i = 0; i < arrSize; ++i)
	{
		sqrSumm += pow(arr[i], 2);
		summ += arr[i];
	}
	summ = pow(summ, 2)/arrSize;
	
	dev = (sqrSumm - summ)/arrSize-1;
	dev = sqrt(dev);
	return dev;
}

int histogramm[2*range+1] = {0};
int get_dev3(int* arr)
{
	int dev = 0;
	for (int i = 0; i < arrSize; ++i)		// fill histogramm
	{
		histogramm[arr[i]+range] += 1;
	}
	/*
	for (int i = 0; i < 2*range+1; ++i)
	{
		avrg += histogramm[i]*i;
	}
	//count avrg
	 */
	for (int i = -range; i < range+1; ++i)
	{
		dev += pow(i-avrg, 2)*histogramm[i+range];
	}
	dev /= arrSize-1;
	dev = sqrt(dev);
	return dev;
}

void printHistogramm(int* h)
{
	for (int j = 0; j < 2*range; ++j)
	{
		
	}
		for (int i = 0; i < 2*range; ++i)
		{
			cout << histogramm[2*range+1];
		}
	
}

int main()
{
	srand(time(NULL));
	int* Arr = new int(arrSize);
	
	for (int i = 0; i < arrSize; ++i)
	{
		Arr[i] = rand() % range;
		avrg += Arr[i];
	}	
	avrg /= arrSize;	//prepairing complete
	
	cout << "first deviation = "<<get_dev1(Arr)<<endl;
	cout << "second deviation = "<<get_dev2(Arr)<<endl;
	cout << "third deviation = "<<get_dev3(Arr)<<endl;
	
	return 0;
}

