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

void insertion_sort(int arr[], int n) {
	for (int i = 1; i < n ; ++i)
	{
		int temp = arr[i];
		int j = i - 1;

		while (j >= 0 && arr[j] > temp) {
			arr[j + 1] = arr[j];
			j--;
		}

		arr[j + 1] = temp;

	}
}

int main() {
	int n;
	cout << "array size: ";
	cin >> n;

	int arr[n];

	input(arr, n);

	insertion_sort(arr, n);

	display(arr, n);

	return 0;
}
