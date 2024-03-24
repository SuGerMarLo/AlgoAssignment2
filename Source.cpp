#include <iostream>
#include <vector>

using namespace std;

class Array {
private:
    vector<int> arr;

public:
    Array(int size) {
        arr.resize(size);
    }

    void setValue(int index, int value) {
        if (index >= 0 && index < arr.size()) {
            arr[index] = value;
        } else {
            cout << "Index out of range" << endl;
        }
    }

    int getValue(int index) {
        if (index >= 0 && index < arr.size()) {
            return arr[index];
        } else {
            cout << "Index out of range" << endl;
            return -1; // Return -1 as an error indicator
        }
    }

    void display() {
        cout << "Array: ";
        for (int i = 0; i < arr.size(); ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void merge(int low, int mid, int high) {
        vector<int> temp(high - low + 1);
        int i = low, j = mid + 1, k = 0;
        while (i <= mid && j <= high) {
            if (arr[i] <= arr[j]) {
                temp[k++] = arr[i++];
            } else {
                temp[k++] = arr[j++];
                cout << "\a";
                display();
            }
        }
        while (i <= mid) {
            temp[k++] = arr[i++];
        }
        while (j <= high) {
            temp[k++] = arr[j++];
        }
        for (int i = low; i <= high; ++i) {
            arr[i] = temp[i - low];
        }
    }

    void mergeSort(int low, int high) {
        if (low < high) {
            int mid = (low + high) / 2;
            mergeSort(low, mid);
            mergeSort(mid + 1, high);
            merge(low, mid, high);
        }
    }
};

int main() {
    int n;

    cout << "Enter the size of the array: ";
    cin >> n;

    Array myArray(n);

    cout << "Enter " << n << " numbers:\n";
    for (int i = 0; i < n; ++i) {
        int value;
        cout << "Element " << i+1 << ": ";
        cin >> value;
        myArray.setValue(i, value);
    }

    myArray.mergeSort(0, n - 1);

    cout << "Sorted ";
    myArray.display();

    return 0;
}