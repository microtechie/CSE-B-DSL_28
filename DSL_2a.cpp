#include <iostream>
using namespace std;

int main() {
    int n, key;

    cout << "enter number of elements:";
    cin >> n;

    int arr[n];
    cout << "enter sorted elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "enter element to search:";
    cin >> key;

    int low = 0, high = n - 1, mid;
    bool found = false;

    while (low <= high) {
        mid = (low + high) / 2;

        if (arr[mid] == key) {
            cout << "element found at position: " << mid + 1;
            found = true;
            break;
        }
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    if (!found)
        cout << "element not found";

    return 0;
}

