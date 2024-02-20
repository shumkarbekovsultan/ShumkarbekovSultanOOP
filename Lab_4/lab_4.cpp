#include <iostream>
#include <string>

using namespace std;

class Tatra;

class Kamaz {
private:
    string name;
    int speed;
public:
    Kamaz() : name("Kamaz") { 
        cout << "Enter Kamaz speed: ";
        cin >> speed;
    }
    void display() {
        cout << "Name: " << name << ", Speed: " << speed << endl;
    }
    friend int FrCreater(Kamaz k, Tatra t);
    friend class Tatra;
};

class Tatra {
private:
    string name;
    int speed;
public:
    Tatra() : name("Tatra") { 
        cout << "Enter Tatra speed: ";
        cin >> speed;
    }
    void display() {
        cout << "Name: " << name << ", Speed: " << speed << endl;
    }
    friend int FrCreater(Kamaz k, Tatra t);
    friend class Kamaz;
};

int FrCreater(Kamaz k, Tatra t) {
    if (k.speed > t.speed) {
        return 1;
    } else if (k.speed < t.speed) {
        return -1;
    } else {
        return 0;
    }
}

int main() {
    char choice;
    do {
        Kamaz kamaz;
        Tatra tatra;
		cout << "----------------------" << endl;
        kamaz.display();
        tatra.display();
		
        int result = FrCreater(kamaz, tatra);
        if (result == 1) {
        	cout << "--------------------------" << endl;
            cout << "Kamaz is faster than Tatra" << endl;
           	cout << "--------------------------" << endl;
        } else if (result == -1) {
        	cout << "--------------------------" << endl;
            cout << "Tatra is faster than Kamaz " << endl;
            cout << "--------------------------" << endl;
        } else {
        	cout << "------------------------------------" << endl;
            cout << "Kamaz and Tatra have the same speed" << endl;
            cout << "------------------------------------" << endl;
        }

     	cout << "Do you want to continue? (1-yes/ 0-no): ";
        cin >> choice;
       
        
    } while (choice == '1');

    return 0;
}

