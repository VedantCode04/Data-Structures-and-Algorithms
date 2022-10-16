#include <iostream>

using namespace std;

int partation(int arr[], int low, int high) {

    int beg = low;
    int end = high;

    while (beg < end) {
        while (arr[beg] < arr[low]) {
            beg++;
        }

        while (arr[end] > arr[low]) {
            end--;
        }

        swap(arr[beg], arr[end]);
    }

    swap(arr[end], arr[low]);

    return end;

}

void quick_sort(int arr[], int low, int high) {
    if (low < high) {

        int mid = partation(arr, low, high);
        quick_sort(arr, low, mid - 1);
        quick_sort(arr, mid + 1, high);

    }
}

void input(int arr[], int n) {

    printf("enter elements: ");

    for (int i = 0; i < n; ++i) {

        cin >> arr[i];

    }
}

void display(int arr[], int n) {
    printf("array is \n");

    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }

    cout << endl;
}

int main() {
    int n;
    cout << "enter size of array: ";
    cin >> n;

    int arr[n];

    input(arr, n);

    quick_sort(arr, 0, n - 1);

    printf("after sort: ");

    display(arr, n);

}
