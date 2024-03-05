/*TASK 1*/

#include <iostream>
#include <stdexcept>
#include <climits> // For INT_MIN and INT_MAX

using namespace std;

class Int {
private:
    int value;
public:
    Int(int value) : value(value) {}

    Int operator+(const Int& other) const {
        long long result = static_cast<long long>(value) + static_cast<long long>(other.value);
        if (result > INT_MAX || result < INT_MIN) {
            throw overflow_error("Overflow occurred");
        }
        return Int(static_cast<int>(result));
    }

    Int operator-(const Int& other) const {
        long long result = static_cast<long long>(value) - static_cast<long long>(other.value);
        if (result > INT_MAX || result < INT_MIN) {
            throw overflow_error("Overflow occurred");
        }
        return Int(static_cast<int>(result));
    }

    Int operator*(const Int& other) const {
        long long result = static_cast<long long>(value) * static_cast<long long>(other.value);
        if (result > INT_MAX || result < INT_MIN) {
            throw overflow_error("Overflow occurred");
        }
        return Int(static_cast<int>(result));
    }

    Int operator/(const Int& other) const {
        if (other.value == 0) {
            throw invalid_argument("Division by zero");
        }
        return Int(value / other.value);
    }

    Int& operator++() {
        if (value == INT_MAX) {
            throw overflow_error("Overflow occurred");
        }
        ++value;
        return *this;
    }

    Int operator++(int) {
        if (value == INT_MAX) {
            throw overflow_error("Overflow occurred");
        }
        Int temp(value);
        ++value;
        return temp;
    }

    Int& operator--() {
        if (value == INT_MIN) {
            throw overflow_error("Underflow occurred");
        }
        --value;
        return *this;
    }

    Int operator--(int) {
        if (value == INT_MIN) {
            throw overflow_error("Underflow occurred");
        }
        Int temp(value);
        --value;
        return temp;
    }

    friend ostream& operator<<(ostream& os, const Int& obj) {
        return os << obj.value;
    }
};

int main() {
    while (true) {
        try {
            int choice;
            int x, y;

            cout << "Choose an operation:" << endl;
            cout << "0. +" << endl;
            cout << "1. -" << endl;
            cout << "2. *" << endl;
            cout << "3. /" << endl;
            cout << "4. ++a" << endl;
            cout << "5. --a" << endl;
            cout << "6. a++ " << endl;
            cout << "7. a--" << endl;
            cout << "9 Exit" << endl;
            cout << "Your choice: ";
            cin >> choice;

            if (choice == 9) {
                cout << "Exiting program" << endl;
                return 0;
            }

            cout << "Enter another integer: ";
            cin >> y;
            Int b(y); // Declare and initialize b


            Int a(y), result(0);

            switch (choice) {
            case 0:
                result = a + b;
                cout << "Sum: " << result << endl;
                break;
            case 1:
                result = a - b;
                cout << "Difference: " << result << endl;
                break;
            case 2:
                result = a * b;
                cout << "Product: " << result << endl;
                break;
            case 3:
                result = a / b;
                cout << "Quotient: " << result << endl;
                break;

            case 4:
                ++a;
                cout << "Result: " << a << endl;
                break;
            case 5:
                --a;
                cout << "Result: " << a << endl;
                break;
            case 6:
                a++;
                cout << "Result: " << a << endl;
                break;
            case 7:
                a--;
                cout << "Result: " << a << endl;
                break;
            default:
                cout << "Invalid operation choice" << endl;
            }
        }
        catch (const overflow_error& e) {
            cout << "Overflow error: " << e.what() << endl;
        }
        catch (const invalid_argument& e) {
            cout << "Error: " << e.what() << endl;
        }
    }

    return 0;
}


/*TASK 2*/
#include <iostream>

using namespace std;

class Fraction {
private:
    double chislo;
    double chislo2;
public:
    Fraction() : chislo(0), chislo2(0) {}

    Fraction(double value) : chislo(value), chislo2(0) {}

    Fraction(double value1, double value2) : chislo(value1), chislo2(value2) {}

    Fraction operator+(const Fraction& other) const {
        return Fraction(chislo + other.chislo, chislo2 + other.chislo2);
    }

    Fraction operator+(double value) const {
        return Fraction(chislo + value, chislo2);
    }

    Fraction operator-(const Fraction& other) const {
        return Fraction(chislo - other.chislo, chislo2 - other.chislo2);
    }

    Fraction operator-(double value) const {
        return Fraction(chislo - value, chislo2);
    }

    Fraction operator*(const Fraction& other) const {
        return Fraction(chislo * other.chislo, chislo2 * other.chislo2);
    }

    Fraction operator*(double value) const {
        return Fraction(chislo * value, chislo2 * value);
    }

    Fraction operator/(const Fraction& other) const {
        if (other.chislo == 0) {
            cerr << "Division by zero!" << endl;
            return *this;
        }
        return Fraction(chislo / other.chislo, chislo2 / other.chislo2);
    }

    Fraction operator/(double value) const {
        if (value == 0) {
            cerr << "Division by zero!" << endl;
            return *this;
        }
        return Fraction(chislo / value, chislo2 / value);
    }

    Fraction operator++(int) {
        Fraction temp(*this);
        chislo++;
        chislo2++;
        return temp;
    }

    Fraction& operator++() {
        chislo++;
        chislo2++;
        return *this;
    }

    friend ostream& operator<<(ostream& os, const Fraction& frac) {
        os << "(" << frac.chislo << ", " << frac.chislo2 << ")";
        return os;
    }

    friend Fraction operator*(int value, const Fraction& frac) {
        return Fraction(value * frac.chislo, value * frac.chislo2);
    }
};

int main() {
    double num1, num2, num3, num4;
    char operation;

    cout << "Enter the first number (chislo1): ";
    cin >> num1;
    cout << "Enter the second number (chislo2): ";
    cin >> num2;
    cout << "Enter the operation (+, -, *, /): ";
    cin >> operation;
    cout << "Enter the third number (chislo1): ";
    cin >> num3;
    cout << "Enter the fourth number (chislo2): ";
    cin >> num4;

    Fraction f1(num1, num2);
    Fraction f2(num3, num4);
    Fraction result;

    switch (operation) {
    case '+':
        result = f1 + f2;
        break;
    case '-':
        result = f1 - f2;
        break;
    case '*':
        result = f1 * f2;
        break;
    case '/':
        result = f1 / f2;
        break;
    default:
        cerr << "Invalid operation!" << endl;
        return 1;
    }

    cout << "Result: " << result << endl;

    return 0;
}

/*TASK 3*/
#include <iostream>
#include <limits> 

using namespace std;

class Rectangle {
private:
    double a;
    double b;

public:
    Rectangle(double side1, double side2) : a(side1), b(side2) {}

    double rect_area(double side1, double side2) {
        return side1 * side2;
    }

    double rect_area(double side) {
        return side * side;
    }
};

int main() {
    double side1, side2;

    cout << "Enter the sides: ";
    cin >> side1;
    cin >> side2;

    if (cin.peek() == '\n') {
        Rectangle square(side1, side1);
        double area = square.rect_area(side1);
        cout << "Area of the square: " << area << endl;
    }
    else {
        cin >> side2;
        Rectangle rectangle(side1, side2);
        double area = rectangle.rect_area(side1, side2);
        cout << "Area of the rectangle: " << area << endl;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    return 0;
}
s
