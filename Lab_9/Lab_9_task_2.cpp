#include <iostream>
#include <string>
#include <stdexcept> 
using namespace std;

class Kamaz;

class Tatra {
private:
    string name;
public:
    int speed;
    Tatra(string n, int s) : name(n), speed(s) {
        if (s > 100) {
            throw invalid_argument("Speed cannot be greater than 100 km/h");
        }
    }

    void display() {
        cout << "Truck " << name << ", speed: " << speed << " km/h" << endl;
    }
};

class Kamaz {
private:
    string name;
public:
    int speed;
    Kamaz(string n, int s) : name(n), speed(s) {
        if (s > 100) {
            throw invalid_argument("Speed cannot be greater than 100 km/h");
        }
    }

    void display() {
        cout << "Truck " << name << ", speed: " << speed << " km/h" << endl;
    }
};

int CompareSpeed(const Kamaz& k, const Tatra& t) {
    if (k.speed > t.speed)
        return 1;
    else if (k.speed < t.speed)
        return -1;
    else
        return 0;
}

int main() {
    try {
        Kamaz kamaz("Kamaz", 80);
        Tatra tatra("Tatra", 110);

        cout << "Comparing speeds:" << endl;
        int result = CompareSpeed(kamaz, tatra);
        if (result == 1)
            cout << "Kamaz is faster than Tatra." << endl;
        else if (result == -1)
            cout << "Tatra is faster than Kamaz." << endl;
        else
            cout << "Trucks' speeds are equal." << endl;

        cout << "\nTruck information:" << endl;
        kamaz.display();
        tatra.display();
    }
    catch (const exception& e) {
        throw runtime_error(string("Execution error: ") + e.what());
    }

    return 0;
}

