// LINEAR SEARCH

#include <algorithm>

#include <iostream>

using namespace std;

int linear_search(int arr[], int n, int key) {

    int i;

    for (i = 0; i < n; ++i) {
        if (arr[i] == key)
            return i;
    }

    return -1;
}

void input(int arr[], int n) {

    cout << "Enter elements: ";

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

    cout << "Enter key to find: ";
    int key;
    cin >> key;

    int a = linear_search(arr, n, key);

    cout << "key is at " << a << endl;
}
