//MERGE SORT algorithm

#include <iostream>

using namespace std;

void merge(int arr[], int low, int mid, int high) {

    int n1 = mid - low + 1; //to find array size of first sub-array
    int n2 = high - mid; //to find array size of second sub array

    int * left_array = new int[n1];
    int * right_array = new int[n2]; //creating temp arrays for storing the original values of array

    //storing the values of original array in temp array
    for (int i = 0; i < n1; ++i) {
        left_array[i] = arr[low + i];
    }

    for (int i = 0; i < n2; ++i) {
        right_array[i] = arr[mid + i + 1];
    }

    int i = 0, j = 0, k = low; //for tracking the array indices 

    //comparing elements of 1st sub-array with 2nd sub-array and then updating the original array.
    while (i < n1 && j < n2) {
        if (left_array[i] < right_array[j]) {
            arr[k] = left_array[i];
            i++;
            k++;
        } else {
            arr[k] = right_array[j];
            j++;
            k++;
        }
    }

    //to update the remaining values to main array after one of the sub-array in exhausted.
    while (i < n1) {
        arr[k] = left_array[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = right_array[j];
        j++;
        k++;
    }

    delete[] left_array;
    delete[] right_array;
}

void merge_sort(int arr[], int low, int high) {

    if (low < high) {

        int mid = low + (high - low) / 2;

        merge_sort(arr, low, mid);
        merge_sort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }

}

void input(int arr[], int n) {

    cout << "enter elements: \n";

    for (int i = 0; i < n; ++i) {

        cin >> arr[i];

    }
}

void display(int arr[], int n) {
    cout<<"new array is \n";

    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }

    cout << endl;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];

    input(arr, n);

    merge_sort(arr, 0, n - 1);

    cout << "after merge sort: \n";

    display(arr, n);

    return 0;

}
