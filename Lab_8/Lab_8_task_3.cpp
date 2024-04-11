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
            cerr << "���� ����������!" << endl;
            exit(1);
        }
        elements[++top] = element;
    }

    T pop() {
        if (isEmpty()) {
            cerr << "���� ����!" << endl;
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
    cout << "������� ���������� �������: ";
    cin >> numFactories;

    Stack<Employee, double> employeesStack; // Stack with zp as a double
    int totalLocksmiths = 0;
    int totalTurners = 0;

    for (int i = 0; i < numFactories; ++i) {
        int numEmployees;
        cout << "������� ���������� ���������� �� " << i + 1 << "-� ������: ";
        cin >> numEmployees;

        for (int j = 0; j < numEmployees; ++j) {
            Employee employee;
            cout << "������� ���������� � ��������� #" << j + 1 << " �� ������ " << i + 1 << ":" << endl;
            cout << "�������: ";
            cin >> employee.surname;
            cout << "�������: ";
            cin >> employee.age;
            cout << "�������������: ";
            cin >> employee.specialization;
            cout << "���������� �����: ";
            cin >> employee.salary;
            cout << "����������� zp: ";
            cin >> employee.zp;

            employeesStack.push(employee);
            if (employee.specialization == "�������") {
                ++totalLocksmiths;
            }
            else if (employee.specialization == "������") {
                ++totalTurners;
            }
        }
    }

    double totalSalary = 0;
    while (!employeesStack.isEmpty()) {
        Employee employee = employeesStack.pop();
        totalSalary += employee.salary * employee.zp + employee.salary;
    }

    cout << "����� �������� ���� ����������: " << totalSalary << endl;
    cout << "���������� ��������: " << totalLocksmiths << endl;
    cout << "���������� �������: " << totalTurners << endl;

    return 0;
}

