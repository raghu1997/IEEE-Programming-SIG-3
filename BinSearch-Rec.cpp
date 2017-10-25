#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_SIZE = 10;

int binSearch(float arr[], int l, int r, int elt) {

	//searching continues unless left-bound is less than or equal to right bound
	if(l <= r) {
		int mid = (l+r)/2;

		//return index if element is found
		if(arr[mid] == elt)
			return mid;

		//this section is executed if element lies in the second half of subarray
		else if(arr[mid] < elt)
			return binSearch(arr, mid+1, r, elt);

		//this section is executed if element lies in the first half of subarray
		else
			return binSearch(arr, l, mid-1, elt);
	}

	//function call reaches here if element isn't found
	return -1;
}

int main() {
	float elt;
	float arr[MAX_SIZE] = {-3, -8, 0, 23, 100, 34, -34, -77, 45, 87};
	sort(arr, arr+9);
	cout << "Array: ";
	for(int i = 0; i < MAX_SIZE; i++)
		cout << arr[i] << " ";
	cout << endl;
	cout << "Enter Element to Search: ";
	cin >> elt;
	int index = binSearch(arr, 0, 9, elt);
	if(index == -1)
		cout << "Not Found";
	else
		cout << "Index Found: " << index+1;

	cout << endl;

	return 0;
}