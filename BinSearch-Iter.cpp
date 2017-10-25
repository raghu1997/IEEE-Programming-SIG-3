#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_SIZE = 10;

int binSearch(float arr[], float elt) {
	int l = 0;				//declare left bound
	int r = MAX_SIZE-1;				//declare right bound
	int mid = (l+r)/2;		//declare middle index

	//loop executes until left bound equals right bound
	while(l <= r) {
		mid = (l+r)/2;
		if(elt > arr[mid])
			l = mid+1;
		else if(elt < arr[mid])
			r = mid-1;
		else if(elt == arr[mid])
			return mid;
	}

	//return -1 if element isn't found
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
	int index = binSearch(arr, elt);
	if(index == -1)
		cout << "Not Found";
	else
		cout << "Index Found: " << index+1;

	cout << endl;

	return 0;
}