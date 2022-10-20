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

void bubble_sort(int arr[], int n) {
  for (int i = 0; i < n - 1; ++i) {
    for (int j = 0; j < n - i - 1; ++j) {
      if (arr[j] > arr[j + 1]) {
        swap(arr[j], arr[j + 1]);
      }
    }
  }
}

int main() {
  int n;
  cout << "array size: ";
  cin >> n;

  int arr[n];

  input(arr, n);

  bubble_sort(arr, n);

  display(arr, n);

  return 0;
}
