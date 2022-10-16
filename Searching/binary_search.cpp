//BINARY SEARCH

#include <iostream>
#include <algorithm>
using namespace std;

int binary_Search(int arr[], int low, int high, int key) {

	while (low <= high)
	{
		int mid = low + (high - low) / 2;

		if (arr[mid] == key)
		{
			return mid;
		}

		else if (key < arr[mid])
		{
			high = mid - 1;
		}

		else {
			low = mid + 1;
		}
	}

	return -1;

}

void input(int arr[], int n) {

	printf("enter elements: ");

	for (int i = 0; i < n; ++i) {

		cin >> arr[i];

	}
}


int main() {
	int n;
	cout << "Enter size of array: ";
	cin >> n;

	int arr[n];

	input(arr, n);

	sort(arr, arr + n); //STL sort function

	cout << "enter key to search: ";
	int key;
	cin >> key;

	int x = binary_Search(arr, 0, n - 1, key);

	cout << "key is at the index " << x << endl;

}
