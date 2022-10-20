#include <iostream>
using namespace std;

void display(int arr[], int n) {
	cout << "array is: ";

	for (int i = 0; i < n; ++i) {
		cout << arr[i] << " ";
	}

	cout << endl;
}

void input(int arr[], int n) {

	cout << "enter elements: ";

	for (int i = 0; i < n; ++i) {

		cin >> arr[i];

	}
}

void selection_sort(int arr[], int n) {
	for (int i = 0; i < n - 1; ++i)
	{
		int min = i;

		for (int j = i + 1; j < n; ++j) {
			if (arr[j] < arr[min]) {
				min = j;
			}
		}

		if (min != i) {
			swap(arr[i], arr[min]);
		}
	}
}

int main() {
	int n;
	cout << "array size: ";
	cin >> n;

	int arr[n];

	input(arr, n);

	selection_sort(arr, n);

	display(arr, n);

	return 0;
}
