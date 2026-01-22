#include <iostream>
using namespace std;

int main() {
    int n, key;

    cout << "enter number of elements:";
    cin >> n;

    int arr[n];
    cout << "enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "enter element for search:";
    cin >> key;

    int found = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            found = i;
            break;
        }
    }

    if (found != -1)
        cout << "element found at position: " << found + 1;
    else
        cout << "element not found";

    return 0;
}

