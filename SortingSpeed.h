//SortingSpeed.h
//Lucas Manker

#include "RandomUtilities.h"
#include<vector>
#include<algorithm>
#include<iostream>
#include <iomanip>
// From Dr. Tom Bailey's Lab6 SortedDriver.cpp
// *modified*
// post: a vector of listSize random doubles from
//         the range minNum to maxNum has been returned.

using std::vector;
using std::cout;
using std::endl;
using namespace std;

vector<double> getNums(size_t listSize, double minNum, double maxNum)
{
	vector<double> theList;
	for (size_t i = 0; i < listSize; ++i)
	{
		theList.push_back(randReal(minNum, maxNum));
	}
	return theList;
}

//TODO: implement quicksort here
//return a sorted vector of doubles
vector<double> QS(vector<double>& vec1, int lIndex, int rIndex) {
	double temp;
	int i = lIndex;
	int j = rIndex;
	double pivot = vec1[(lIndex + rIndex) / 2];

	while (i <= j) {
		while (vec1[i] < pivot) {
			i++;
		}
		while (vec1[j] > pivot) {
			j--;
		}
		if (i <= j) {
			temp = vec1[i];
			vec1[i] = vec1[j];
			vec1[j] = temp;
			i++;
			j--;
		}
	}

	if (lIndex < j) {
		QS(vec1, lIndex, j);
	}
	if (i < rIndex) {

		QS(vec1, i, rIndex);
	}
	return vec1;
}
//A large portion of this code was adapted from algolist.net

vector<double> QuickSort(vector<double>& vec1){
	QS(vec1, 0, vec1.size() - 1);
	return vec1;
}



//TODO: implement quicksort here
//return a sorted vector of doubles
vector<double> BubbleSort(vector<double>& vec1){
	int error = 0;
	do  {
		error = 0;
		for (int i = 0; i < vec1.size()-1; i++) {
			if (vec1[i] > vec1[i + 1]) {
				double temp = vec1[i];
				vec1[i] = vec1[i + 1];
				vec1[i + 1] = temp;
				error++;
			}
		}
	} while (error);
	return vec1;
}
//TODO: implement quicksort here
//return a sorted vector of doubles
vector<double> InsertionSort(vector<double>& vec1){
	for (int j = 1; j < vec1.size(); j++) {
		bool swap = false;
		bool found = false;
		int index;
		int i = 0;
		while(i < j && !found){
			if (vec1[j] < vec1[i]) {
				index = i;
				found = true;
				swap = true;
			}
			i++;
		}
		if (swap) {
			double temp = vec1[j];
			for (int i = j; i > index; i--) {
				vec1[i] = vec1[i - 1];
			}
			vec1[index] = temp;
		}
	}

	return vec1;
}
//TODO: implement SelectionSort here
//return a sorted vector of doubles
vector<double> SelectionSort(vector<double>& vec1) {
	int tempElement(0);
	int count = 0;
	for (int j = 0; j < vec1.size(); j++) {
		double lowest = vec1[j];
		bool swap = false;
		for (int i = j; i < vec1.size(); i++) {
			if (vec1[i] < lowest) {
				lowest = vec1[i];
				tempElement = i;
				swap = true;
			}
		}
		if (swap) {
		double temp = vec1[j];
		vec1[j] = vec1[tempElement];
		vec1[tempElement] = temp;
	}
	}
	return vec1;
}
