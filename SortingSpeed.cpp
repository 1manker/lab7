//Driver file for Sorting Speeds Lab
//Created by: Lucas Manker
//4/1/2018

#include "SortingSpeed.h"
#include "winTimer.h"//change this based on your system


void print(vector<double> list);
void check(vector<double> list);

int main() {
	Timer time1, time2, time3, time4, time5, time6, time7, time8;
	vector<double> test1 = getNums(64500, 1, 500);
	time1.start();
	QuickSort(test1);
	time1.stop();
	cout<<"time to quicksort: "<<(time1)()<<endl;

	vector<double> test2 = getNums(129000, 1, 500);
	time2.start();
	QuickSort(test2);
	time2.stop();
	cout << "time to quicksort doubled: " << (time2)() << endl;

	vector<double> test3 = getNums(2500, 1, 500);
	time3.start();
	BubbleSort(test3);
	time3.stop();
	cout << "time to bubble: " << (time3)() << endl;

	vector<double> test4 = getNums(5000, 1, 500);
	time4.start();
	BubbleSort(test4);
	time4.stop();
	cout << "time to bubble sort double: " << (time4)() << endl;

	vector<double> test5 = getNums(5000, 1, 500);
	time5.start();
	InsertionSort(test5);
	time5.stop();
	cout << "time to insertion sort: " << (time5)() << endl;

	vector<double> test6 = getNums(10000, 1, 500);
	time6.start();
	InsertionSort(test6);
	time6.stop();
	cout << "time to insertion sort doubled: " << (time6)() << endl;

	vector<double> test7 = getNums(5000, 1, 500);
	time7.start();
	SelectionSort(test7);
	time7.stop();
	cout << "time to selection sort: " << (time7)() << endl;

	vector<double> test8 = getNums(10000, 1, 500);
	time8.start();
	SelectionSort(test8);
	time8.stop();
	cout << "time to selection sort doubled: " << (time8)() << endl;

	return 0;
}

void print(vector<double> list) {
	for (int i = 0; i < list.size(); i++) {
		cout << list[i] << endl;
	}
	cout << endl << endl;
	return;
}

void check(vector<double> list) {
	for (int i = 0; i < list.size()-1; i++) {
		if (list[i] > list[i + 1]) {
			cout << "error detected " << list[i] << " is greater than " << list[i + 1] << endl;
		}
	}
}
