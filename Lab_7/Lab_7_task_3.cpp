#include <iostream>

using namespace std;

class Currency {
public:
    
    virtual double toRubles(double amount) const = 0;

    virtual void display(double amount) const = 0;
};

class Dollar : public Currency {
public:

    virtual double toRubles(double amount) const override {
        return amount * 88; 
    }

  
    virtual void display(double amount) const override { 
        cout << "$" << amount;
    }
};
4

class Euro : public Currency {
public:
    virtual double toRubles(double amount) const override {
        return amount * 100; 
    }

   
    virtual void display(double amount) const override {
        cout << "?" << amount;
    }
};

int main() {
    double amount;
    cout << "Enter the amount in dollars: ";
    cin >> amount;

    Dollar dollar;
    cout << "Amount in dollars: ";
    dollar.display(amount);
    cout << endl;

    cout << "Amount in rubles: " << dollar.toRubles(amount) << " RUB" << endl;

    cout << "\nEnter the amount in euros: ";
    cin >> amount;

    Euro euro;
    cout << "Amount in euros: ";
    euro.display(amount);
    cout << endl;

    cout << "Amount in rubles: " << euro.toRubles(amount) << " RUB" << endl;

    return 0;
}
