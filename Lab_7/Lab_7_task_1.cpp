?#include <iostream>
#include <algorithm> // ??? std::min

using namespace std;

class Array {
protected:
    unsigned* array;
    size_t size;
    static const size_t MAX_SIZE = 100; 

public:
    Array(size_t n, unsigned initialValue = 0) : size(n) {
        size = (n > MAX_SIZE) ? MAX_SIZE : n;
        array = new unsigned[size];
        fill(array, array + size, initialValue);
    }

    // ??????????
    virtual ~Array() {
        delete[] array;
    }

    virtual void add(const Array& other) {
        size_t minSize = min(this->size, other.size);
        for (size_t i = 0; i < minSize; i++) {
            this->array[i] += other.array[i];
        }
    }

    void print() const {
        for (size_t i = 0; i < size; i++) {
            cout << array[i] << " ";
        }
        cout << endl;
    }

    size_t getSize() const {
        return size;
    }

    unsigned* getArray() const {
        return array;
    }
};

class DoubleArray : public Array {
public:
    using Array::Array; 

    virtual void add(const Array& other) override {
        size_t minSize = min(getSize(), other.getSize());
        for (size_t i = 0; i < minSize; i++) {
            getArray()[i] += 2 * other.getArray()[i];
        }
    }
};

class SquareArray : public Array {
public:
    using Array::Array; 

    virtual void add(const Array& other) override {
        size_t minSize = min(getSize(), other.getSize());
        for (size_t i = 0; i < minSize; i++) {
            getArray()[i] += other.getArray()[i] * other.getArray()[i];
        }
    }
};

int main() {
    Array a1(5, 1); 
    DoubleArray a2(5, 2);
    SquareArray a3(5, 3);

    cout << "Initial Arrays:" << endl;
    cout << "a1: "; a1.print(); 
    cout << "a2: "; a2.print(); 

    a1.add(a2); 
    cout << "After Adding DoubleArray to Array:" << endl;
    cout << "a1: "; a1.print(); 

    a2.add(a3); 
    cout << "After Adding SquareArray to DoubleArray:" << endl;
    cout << "a2: "; a2.print(); 

    a3.add(a1); // Square + Base
    cout << "After Adding Array to SquareArray:" << endl;
    cout << "a3: "; a3.print(); 

    return 0;
}
