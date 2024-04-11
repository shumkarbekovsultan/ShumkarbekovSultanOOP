#include <iostream>
#include <string>

using namespace std;

const int MAX_SIZE = 100;

template<typename T, class Z>
class Stack {
private:
    T elements[MAX_SIZE];
    int top;
    Z zp;

public:
    Stack() : top(-1) {}

    void push(const T& element) {
        if (top == MAX_SIZE - 1) {
            cerr << "Стек переполнен!" << endl;
            exit(1);
        }
        elements[++top] = element;
    }

    T pop() {
        if (isEmpty()) {
            cerr << "Стек пуст!" << endl;
            exit(1);
        }
        return elements[top--];
    }

    bool isEmpty() const {
        return top == -1;
    }

    int size() const {
        return top + 1;
    }
};

struct Employee {
    string surname;
    int age;
    string specialization;
    double salary;
    double zp; // Coefficient for salary calculation
};

int main() {
    int numFactories;
    cout << "Введите количество заводов: ";
    cin >> numFactories;

    Stack<Employee, double> employeesStack; // Stack with zp as a double
    int totalLocksmiths = 0;
    int totalTurners = 0;

    for (int i = 0; i < numFactories; ++i) {
        int numEmployees;
        cout << "Введите количество работников на " << i + 1 << "-м заводе: ";
        cin >> numEmployees;

        for (int j = 0; j < numEmployees; ++j) {
            Employee employee;
            cout << "Введите информацию о работнике #" << j + 1 << " на заводе " << i + 1 << ":" << endl;
            cout << "Фамилия: ";
            cin >> employee.surname;
            cout << "Возраст: ";
            cin >> employee.age;
            cout << "Специализация: ";
            cin >> employee.specialization;
            cout << "Заработная плата: ";
            cin >> employee.salary;
            cout << "Коэффициент zp: ";
            cin >> employee.zp;

            employeesStack.push(employee);
            if (employee.specialization == "слесарь") {
                ++totalLocksmiths;
            }
            else if (employee.specialization == "токарь") {
                ++totalTurners;
            }
        }
    }

    double totalSalary = 0;
    while (!employeesStack.isEmpty()) {
        Employee employee = employeesStack.pop();
        totalSalary += employee.salary * employee.zp + employee.salary;
    }

    cout << "Общая зарплата всех работников: " << totalSalary << endl;
    cout << "Количество слесарей: " << totalLocksmiths << endl;
    cout << "Количество токарей: " << totalTurners << endl;

    return 0;
}

