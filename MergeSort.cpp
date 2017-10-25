#include <iostream>

using namespace std;

const int MAX_SIZE = 10;

void merge(float arr[], int l, int m, int r) {
	int eltLeft = m-l+1;
	int eltRight = r-m;

	//create temporary arrays for implementing merging
	float tempL[eltLeft], tempR[eltRight];
	for(int i = 0; i < eltLeft; i++) {
		tempL[i] = arr[l+i];
	}
	for(int j = 0; j < eltRight; j++) {
		tempR[j] = arr[m+1+j];
	}

	int i = 0;
	int j = 0;
	int k = l;		//since merging is done in the original array
					//index of the first element won't always be 0

	//merging
	while(i < eltLeft and j < eltRight) {
		if(tempL[i] < tempR[j]) {
			arr[k] = tempL[i];
			i++;
		}
		else {
			arr[k] = tempR[j];
			j++;
		}
		k++;
	}

	while(i < eltLeft) {
		arr[k] = tempL[i];
		i++;
		k++;
	}
	while(j < eltRight) {
		arr[k] = tempR[j];
		j++;
		k++;
	}
}

void mergeSort(float arr[], int l, int r) {

	//recursively call mergeSort() until one element is left in each subproblem
	if(l < r) {
		int m = (l+r)/2;		//middle index
		mergeSort(arr, l, m);
		mergeSort(arr, m+1, r);

		merge(arr, l, m, r);	//call merge() for every instance of the recursive calls
								//to mergeSort() once the execution for each of them is
								//over
	}
}

int main() {
	float arr[MAX_SIZE] = {-3, -8, 0, 23, 100, 34, -34, -77, 45, 87};
	mergeSort(arr, 0, MAX_SIZE-1);
	for(int i = 0; i < MAX_SIZE; i++)
		cout << arr[i] << " ";
	cout << endl;
	return 0;
}