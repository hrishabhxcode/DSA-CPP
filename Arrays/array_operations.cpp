#include <iostream>
#include <vector>
using namespace std;

class ArrayOperations {
public:
    void displayArray(const vector<int>& arr) {
        int n=arr.size();
        cout << "Array elements: ";
        for (int i=0;i<n;i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    int sumArray(const vector<int>& arr) {
        int n=arr.size();
        int sum = 0;
        for (int i=0;i<n;i++) {
            sum += arr[i];
        }
        return sum;
    }

    int findMax(const vector<int>& arr) {
        int n=arr.size();
        if (n==0) {
            throw runtime_error("Array is empty!");
        }
        int maxVal = arr[0];
        for (int i=0;i<n;i++) {
            if (arr[i] > maxVal) {
                maxVal = arr[i];
            }
        }
        return maxVal;
    }

    bool searchArray(const vector<int>& arr, int target) {
        int n=arr.size();
        for (int i=0;i<n;i++) {
            if (arr[i] == target) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    ArrayOperations arrayOps;
    int a[] = {1, 2, 3, 4, 5, 6, 7};
    int n=sizeof(a)/sizeof(a[0]);
    //vector can't be initialised as initialiser list 
    //vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    vector<int> arr(a,a+n);

    arrayOps.displayArray(arr);

    cout << "Sum of elements: " << arrayOps.sumArray(arr) << endl;
    
    try {
        cout << "Maximum element: " << arrayOps.findMax(arr) << endl;
    } catch (const exception& e) {
        cerr << e.what() << endl;
    }

    int target = 4;
    cout << "Is " << target << " in the array? " 
         << (arrayOps.searchArray(arr, target) ? "Yes" : "No") << endl;

    return 0;
}
