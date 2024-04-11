#include <iostream>
#include <string>

using namespace std;

class Employee {
protected:
    string name;
    string position;
    double salary;

public:

    Employee() : name(""), position(""), salary(0.0) {}

    Employee(const string& name, const string& position, double salary)
        : name(name), position(position), salary(salary) {}


    ~Employee() {}

    double calculateAnnualSalary() const {
        return salary * 12;
    }

    void inputInfo() {
        cout << "Enter name: ";
        getline(cin, name);
        cout << "Enter position: ";
        getline(cin, position);
        cout << "Enter salary: ";
        cin >> salary;
        cin.ignore();  }

    void displayInfo() const {
        cout << "Name: " << name << endl;
        cout << "Position: " << position << endl;
        cout << "Salary: " << salary << endl;
    }
};

class Manager : public Employee {
private:
    double annual_bonus;
    string company_car;
    int stock_options;

public:
 
    Manager() : Employee(), annual_bonus(0.0), company_car(""), stock_options(0) {}


    Manager(const string& name, const string& position, double salary,
        double annual_bonus, const string& company_car, int stock_options)
        : Employee(name, position, salary), annual_bonus(annual_bonus),
        company_car(company_car), stock_options(stock_options) {}

    // Destructor
    ~Manager() {}

    // Input manager information from console
    void inputInfo() {
        Employee::inputInfo(); // Call base class method
        cout << "Enter annual bonus: ";
        cin >> annual_bonus;
        cin.ignore(); // Ignore newline character after cin
        cout << "Enter company car: ";
        getline(cin, company_car);
        cout << "Enter stock options: ";
        cin >> stock_options;
        cin.ignore(); // Ignore newline character after cin
    }

    // Display manager information on console
    void displayInfo() const {
        Employee::displayInfo(); // Call base class method
        cout << "Annual Bonus: " << annual_bonus << endl;
        cout << "Company Car: " << company_car << endl;
        cout << "Stock Options: " << stock_options << endl;
    }
};

int main() {
    // Example usage of classes
    Employee emp;
    Manager manager;

    cout << "Enter employee information:" << endl;
    emp.inputInfo();

    cout << "\nEnter manager information:" << endl;
    manager.inputInfo();

    cout << "\nEmployee Information:" << endl;
    emp.displayInfo();
    cout << "Annual Salary: " << emp.calculateAnnualSalary() << endl;

    cout << "\nManager Information:" << endl;
    manager.displayInfo();
    cout << "Annual Salary: " << manager.calculateAnnualSalary() << endl;

    return 0;
}

