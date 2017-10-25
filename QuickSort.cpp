#include <iostream>

using namespace std;

const int MAX_SIZE = 10;

void swap(float *elt1, float *elt2) {
	float temp = *elt1;
	*elt1 = *elt2;
	*elt2 = temp;
}

//creates partition for each subarray passed
//by bringing all elements less than the 'pivot' to the left
//and all elements greater than the 'pivot' to the right
int partition(float arr[], int low, int high) {
	float pivot = arr[high];
	int i = low-1;
	for(int j = low; j < high; j++) {
		if(arr[j] <= pivot) {
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i+1], &arr[high]);
	return i+1;
}

void quickSort(float arr[], int low, int high) {

	//recursively call quickSort() until there is just one element left in each subproblem
	//and hence a further pivot can't be made
	if(low < high) {
		int pi = partition(arr, low, high);

		quickSort(arr, low, pi-1);
		quickSort(arr, pi+1, high);
	}
}

int main() {
	float arr[MAX_SIZE] = {-3, -8, 0, 23, 100, 34, -34, -77, 45, 87};
	quickSort(arr, 0, MAX_SIZE-1);
	for(int i = 0; i < MAX_SIZE; i++)
		cout << arr[i] << " ";
	cout << endl;
	return 0;
}