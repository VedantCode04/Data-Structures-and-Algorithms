//QUICK SORT    

#include <iostream>

using namespace std;

int partation(int arr[], int low, int high) {

    int beg = low;
    int end = high;
    int p = arr[low];

    //traversing through the array and swapping the array at indices END and BEG 
    while (beg < end) {
        while (arr[beg] < p) {
            beg++; //beg increases if the element is smaller than the Pivoit element
        }

        while (arr[end] > p) {
            end--; //end decreases if the element is larger than the Pivoit element
        }

        swap(arr[beg], arr[end]);
    }

    /*swapping the LOW and END array indexes in order to put the ARR[LOW] at its correct position 
    so all the small numbers than it is on left hand side and all the large numbers than it is on its 
    right side, thus making the left and right side of array partially sorted*/

    swap(arr[end], p);

    //returning the index value of the pivoit element
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
