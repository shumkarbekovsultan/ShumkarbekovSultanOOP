#include <iostream>
#include <algorithm> 
using namespace std;

template<typename T>
class ArrayUtility {
public:
    static T findMax(const T arr[], int size) {
        T maxElement = arr[0];
        for (int i = 1; i < size; ++i) {
            if (arr[i] > maxElement) {
                maxElement = arr[i];
            }
        }
        return maxElement;
    }

    static void sortArray(T arr[], int size) {
        sort(arr, arr + size);
    }
};

template<typename T>
void inputArray(T arr[], int size) {
    cout << "Enter " << size << " elements: ";
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }
}

template<typename T>
void printArray(const T arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {

    int size;
    cout << "Enter array size: ";
    cin >> size;


    int* intArray = new int[size];
    double* doubleArray = new double[size];
    char* charArray = new char[size];


    cout << "Enter integer elements:" << endl;
    inputArray(intArray, size);

    cout << "Enter double elements:" << endl;
    inputArray(doubleArray, size);

    cout << "Enter char elements:" << endl;
    inputArray(charArray, size);


    cout << "Max integer in the array: " << ArrayUtility<int>::findMax(intArray, size) << endl;
    cout << "Sorted integer array: ";
    ArrayUtility<int>::sortArray(intArray, size);
    printArray(intArray, size);

    cout << "Max double in the array: " << ArrayUtility<double>::findMax(doubleArray, size) << endl;
    cout << "Sorted double array: ";
    ArrayUtility<double>::sortArray(doubleArray, size);
    printArray(doubleArray, size);

    cout << "Max char in the array: " << ArrayUtility<char>::findMax(charArray, size) << endl;
    cout << "Sorted char array: ";
    ArrayUtility<char>::sortArray(charArray, size);
    printArray(charArray, size);

    delete[] intArray;
    delete[] doubleArray;
    delete[] charArray;

    return 0;
}

