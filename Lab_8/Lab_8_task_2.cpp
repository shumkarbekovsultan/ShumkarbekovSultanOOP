#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

template<typename T, typename U, int Size, typename L>
class ArrayPair {
private:
    T array1[Size];
    U array2[Size];
    L multiplier;
    
public:
    ArrayPair(L multiplier) : multiplier(multiplier) {
        srand(time(nullptr));
        for (int i = 0; i < Size; ++i) {
            array1[i] = static_cast<T>(rand() % 100);
            array2[i] = static_cast<U>(rand() % 100);
        }
    }

    double sum() const {
        double total = 0;
        for (int i = 0; i < Size; ++i) {
            total += array1[i] + array2[i];
        }
        cout<<total<<endl;
        cout<<total<<" * "<< multiplier <<" = ";
        return total * multiplier;
    }
};

int main() {
    double L;

    cout << "Enter value for L: ";
    cin >> L;

    ArrayPair<int, double, 5 , double> intDoublePair(L);
    ArrayPair<double, float, 7 , double> doubleFloatPair(L);

    cout << "Sum of elements in int and double arrays: " << intDoublePair.sum() << endl;
    cout << "Sum of elements in double and float arrays: " << doubleFloatPair.sum() << endl;

    return 0;
}
