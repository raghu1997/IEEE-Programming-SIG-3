#include <iostream>

using namespace std;

const int MAX_SIZE = 10;

void swap(float* elt1, float* elt2) {
	float temp = *elt1;
	*elt1 = *elt2;
	*elt2 = temp;
}

void bubSort(float arr[]) {

	//boolean to check if any 2 elements were swapped in 1 pass
	bool swapped = true;

	//outer loop keeps track of number of passes
	//after each pass last i+1 elements are sorted
	int i = 0;
	while(i < MAX_SIZE and swapped) {
		swapped = false;

		//inner function compares adjacent elements
		for(int j = 0; j < MAX_SIZE-i-1; j++) {
			if(arr[j] > arr[j+1]) {
				swap(&arr[j], &arr[j+1]);

				//make swapped = true if even 1 swapping was done
				swapped = true;
			}
		}
		i++;
	}
}

int main() {
	float arr[MAX_SIZE] = {-3, -8, 0, 23, 100, 34, -34, -77, 45, 87};
	bubSort(arr);
	for(int i = 0; i < MAX_SIZE; i++)
		cout << arr[i] << " ";
	cout << endl;
	return 0;
}