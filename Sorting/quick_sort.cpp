// QUICK SORT
#include <iostream>

using namespace std;

int partation(int arr[], int low, int high)
{

    int random = rand() % (high - low + 1) + low;
    swap(arr[random], arr[high]); // swaping random to minimise the probablity of worst case of O(n^2)

    int pivot = arr[high];
    int i = low - 1; // i pointer to track the maximum element in array

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);

    return i + 1;
}

void quick_sort(int arr[], int low, int high)
{
    if (low < high) {

        int mid = partation(arr, low, high);
        quick_sort(arr, low, mid - 1);
        quick_sort(arr, mid + 1, high);
    }
}

void input(int arr[], int n)
{

    cout << "Enter Elements: " << endl;

    for (int i = 0; i < n; ++i) {

        cin >> arr[i];
    }
}

void display(int arr[], int n)
{
    cout << "Array is: " << endl;

    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }

    cout << endl;
}

int main()
{
    int n;
    cout << "enter size of array: ";
    cin >> n;

    int arr[n];

    input(arr, n);

    quick_sort(arr, 0, n - 1);

    printf("after sort: ");

    display(arr, n);
}
