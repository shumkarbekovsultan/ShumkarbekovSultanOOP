#include <iostream>
using namespace std;

// Task 1: Function 
double power(double n, int p) {
    for (int i = 1; i < p; ++i) {
        n *= n;
    }
    return n;
}

// Task 2: Function
double power(char n, int p = 2) {
    return power(static_cast<double>(n), p);
}

double power(short n, int p = 2) {
    return power(static_cast<double>(n), p);
}

double power(int n, int p = 2) {
    return power(static_cast<double>(n), p);
}

double power(long int n, int p = 2) {
    return power(static_cast<double>(n), p);
}

double power(float n, int p = 2) {
    return power(static_cast<double>(n), p);
}

// Task 3: Structure 
struct Employee {
    string lastName;
    int age;
    string specialty;
    double avgSalary;
};

int main(int argc, char* argv[]) {
    int choice;

    do {

        cout << "1. Exponentiation" << endl;
        cout << "2. Overloaded functions" << endl;
        cout << "3. Info about employees" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice:" << endl;
        cin >> choice;

        switch (choice) {
        case 1: {
            double number;
            int exponent;

            cout << "Enter a number: ";
            cin >> number;

            cout << "Do you want to enter the exponent? (0 for default, 1 for custom): ";
            cin >> exponent;

            if (exponent == 1) {
                cout << "Enter the exponent: ";
                cin >> exponent;
            }
            else {
                exponent = 2;
            }

            cout << "Result: " << power(number, exponent) << endl;
            break;
        }
        case 2: {

            char char_val;
            short short_val;
            int int_val;
            long int long_int_val;
            float float_val;

            cout << "Enter char value: ";
            cin >> char_val;
            cout << "Enter int short value: ";
            cin >> short_val;
            cout << "Enter int  value: ";
            cin >> int_val;
            cout << "Enter int long  value: ";
            cin >> long_int_val;
            cout << "Enter float value: ";
            cin >> float_val;


            cout << "Overloaded power function results:" << endl;
            cout << "char: " << power(char_val) << endl;
            cout << "short: " << power(short_val) << endl;
            cout << "int: " << power(int_val) << endl;
            cout << "long int: " << power(long_int_val) << endl;
            cout << "float: " << power(float_val) << endl;
            break;
        }
        case 3: {

            int n;
            cout << "Enter the number of employees: ";
            cin >> n;

            int mechanics_count = 0;
            int turners_count = 0;

            auto* employees = new Employee[n];

            for (int i = 0; i < n; ++i) {
                cout << "Enter information for employee " << i + 1 << ":" << endl;
                cout << "Last name: ";
                cin >> employees[i].lastName;
                cout << "Age: ";
                cin >> employees[i].age;
                cout << "Specialty: ";
                cin >> employees[i].specialty;
                cout << "Average salary: ";
                cin >> employees[i].avgSalary;


                if (employees[i].specialty == "mechanic") {
                    mechanics_count++;
                }
                else if (employees[i].specialty == "turner") {
                    turners_count++;
                }
            }

            cout << "Number of mechanics: " << mechanics_count << endl;
            cout << "Number of turners: " << turners_count << endl;

            delete[] employees;
            break;
        }
        }
    } while (choice != 4);

    return 0;
}
