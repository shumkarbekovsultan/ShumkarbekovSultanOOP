#include <iostream>
#include <string>

using namespace std;

class Employee {
private:
    string name;
    string position;
    double salary;

public:
    Employee(const string& name, const string& position, double salary)
        : name(name), position(position), salary(salary) {}

    void displayInfo() const {
        cout << "Name: " << name << endl;
        cout << "Position: " << position << endl;
        cout << "Salary: " << salary << endl;
    }
};

class Manager : private Employee {
private:
    double annual_bonus;
    string company_car;
    int stock_options;

public:
    Manager(const string& name, const string& position, double salary,
        double annual_bonus, const string& company_car, int stock_options)
        : Employee(name, position, salary), annual_bonus(annual_bonus),
        company_car(company_car), stock_options(stock_options) {}

    using Employee::displayInfo;
};

int main() {
 
    Manager manager("John Doe", "Manager", 5000, 1000, "Company Car", 100);

    manager.displayInfo();

    return 0;
}
s
