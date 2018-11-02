#include <iostream>
#include <ctime>
#include <LIMITS.H>
#include	<math.h>
#include <sys/time.h>
#include <queue>
using namespace std;

const int range = 10;
const int arrSize = 100;
int avrg = 0;

class profilingClass
{
	queue<double> periods;
	double timeBegin;
	struct timeval tv;
public:
	void startCount()
	{
		gettimeofday(&tv, NULL);
		timeBegin = ((double)tv.tv_sec) *1000 +((double)tv.tv_usec)/1000;
	}
	void stopCount()
	{
		gettimeofday(&tv, NULL);
		periods.push( ((double)tv.tv_sec) *1000 + ((double)tv.tv_usec)/1000 - timeBegin );
	}
	double getElem()
	{
		double r = periods.front();
		periods.pop();
		return r;
	}
}pc;

int get_dev1(int* arr)		//in forehead solution
{	
	//pc.startCount();
	int dev = 0;
	for (int i = 0; i < arrSize; ++i)
	{
		dev += pow(arr[i]-avrg, 2);
	}
	dev /= arrSize-1;
	dev = sqrt(dev);
	//pc.stopCount();
	return dev;
}

int sqrSumm = 0;
int summ = 0;
int get_dev2(int* arr)
{
	pc.startCount();
	int dev = 0;
	for (int i = 0; i < arrSize; ++i)
	{
		sqrSumm += pow(arr[i], 2);
		summ += arr[i];
	}
	summ = pow(summ, 2)/arrSize;
	
	dev = (sqrSumm - summ)/arrSize-1;
	dev = sqrt(dev);
	pc.stopCount();
	return dev;
}

int histogramm[range] = {0};
int get_dev3(int* arr)
{
	pc.startCount();
	int dev = 0;
	cout<< "gg"<<endl;
	for (int i = 0; i < arrSize; ++i)		// fill histogramm
	{
		cout << arr[i]-1<<' ';
		histogramm[arr[i]-1] += 1;
	}
	cout << endl<< "gg2";
	for (int i = 0; i < range; ++i)
	{
		dev += pow(i-avrg, 2)*histogramm[i];
	}
	dev /= arrSize-1;
	dev = sqrt(dev);
	pc.stopCount();
	return dev;
}

void countAverage()
{
	avrg = 0;
	for (int i = 0; i < range; ++i)
	{
		avrg += histogramm[i]*(i+1);
	}
	avrg /= arrSize;
}

void printHistogramm()
{
	for (int i = 0; i < range; ++i)
	{
		cout << histogramm[i]<<' ';
	}	
	cout<<endl;
}

int main()
{
	srand(time(NULL));
	int* Arr = new int(arrSize);
	avrg = 0;
	
	for (int i = 0; i < arrSize; ++i)
	{
		Arr[i] = 1+(rand() % range);	//begin from 1, to prevent mistake in histogramm count
		avrg += Arr[i];
		cout << Arr[i] << ' ';
	}	
	avrg /= arrSize;	//prepairing complete
	
	cout <<endl<<"average = " << avrg << endl;
	/*cout << "first deviation = "<<get_dev1(Arr) << " time = "<<endl;
	cout << "second deviation = "<<get_dev2(Arr) << " time = "<< pc.getElem() <<endl;*/
	cout << "third deviation = "<<get_dev3(Arr) << " time = "<< pc.getElem() <<endl;
	cout << "histogramm:" << endl;
	printHistogramm();
	countAverage();
	cout <<"average = " << avrg << endl;
	return 0;
}

