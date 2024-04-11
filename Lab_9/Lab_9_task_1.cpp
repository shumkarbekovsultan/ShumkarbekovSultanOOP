#include <iostream>
#include <stdexcept> 
using namespace std;

const int LIMIT = 100;

class ArrayIndexOutOfBoundsException : public exception {
public:
    const char* what() const noexcept override {
        return "Error!";
    }
};

class safearray {
private:
    int arr[LIMIT];
public:
    void putel(int n, int elvalue) {
        if (n < 0  n >= LIMIT) {
            throw ArrayIndexOutOfBoundsException();
        }
        arr[n] = elvalue;
    }

    int getel(int n) const {
        if (n < 0  n >= LIMIT) {
            throw ArrayIndexOutOfBoundsException();
        }
        return arr[n];
    }
};

int main() {
    safearray sal;

    try {
        for (int j = 0; j < LIMIT; j++) {
            sal.putel(j, j * 10);
        }

        for (int j = 0; j < LIMIT; j++) {
            int temp = sal.getel(j);
            cout << "Insert " << j << " element " << temp << endl;

        }

        
        sal.getel(200); 
    }
    catch (const ArrayIndexOutOfBoundsException& e) {
        cout << e.what() << endl;
    }

    return 0;
}

