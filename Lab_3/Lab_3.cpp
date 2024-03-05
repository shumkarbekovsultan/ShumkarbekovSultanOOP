/*#1*/

/* #include <iostream>
#include <string>
#include <thread>
#include <chrono>

class Timer {
private:
    int seconds;

public:
    Timer() : seconds(0) {}

    void setTime(int minutes, int secs) {
        this->seconds = minutes * 60 + secs;
    }

    void run() {
        std::cout << "Timer started for " << seconds << " seconds.\n";
        while (seconds > 0) {
            std::cout << "Time left: " << seconds << " seconds.\n";
            std::this_thread::sleep_for(std::chrono::seconds(1));
            seconds--;
        }
        std::cout << "Time's up! Ring ring!\n";
    }
};

int main() {
    Timer countdown;

    int minutes, seconds;
    std::cout << "Enter minutes: ";
    std::cin >> minutes;
    std::cout << "Enter seconds: ";
    std::cin >> seconds;

    countdown.setTime(minutes, seconds);

    countdown.run();

    return 0;
}

*/

/*#2*/
/*
#include <iostream>
#include <string>

class Nomenclature {
private:
    std::string itemName;
    double wholesalePrice;
    double retailMarkup;
    int quantityInStock;

public:

    Nomenclature() {}

    ~Nomenclature() {}


    void setItemDetails() {
        std::cout << "Enter item name: ";
        std::cin >> itemName;
        std::cout << "Enter wholesale price: ";
        std::cin >> wholesalePrice;
        std::cout << "Enter retail markup (%): ";
        std::cin >> retailMarkup;
        std::cout << "Enter quantity in stock: ";
        std::cin >> quantityInStock;
    }


    double calculateNetProfit() const {
        double retailPrice = wholesalePrice * (1 + retailMarkup / 100.0);
        return retailPrice * quantityInStock - wholesalePrice * quantityInStock;
    }


    void printItemDetails() const {
        std::cout << "Item name: " << itemName << std::endl;

    }
};

int main() {

    Nomenclature item;


    item.setItemDetails();


    item.printItemDetails();

    double netProfit = item.calculateNetProfit();
    std::cout << "Net profit: $" << netProfit << std::endl;

    return 0;
}
*/

/*#3*/


#include <iostream>
#include <string>
#include <chrono>
#include <iomanip>

using namespace std;

class Soft {
private:
    string program;
    string developer;
    double size;
    string date;
    chrono::system_clock::time_point licenseDate;

public:

    Soft(string prog, string dev, double size, string date, chrono::system_clock::time_point license)
        : program(prog), developer(dev), size(size), date(date), licenseDate(license) {}

    ~Soft() {

    }

    int dayscount() const {
        auto now = chrono::system_clock::now();
        auto duration = chrono::duration_cast<chrono::hours>(licenseDate - now);
        return duration.count() / 24;
    }

    void display() {
        struct tm tm = {};
        sscanf(date.c_str(), "%2d-%2d-%4d", &tm.tm_mday, &tm.tm_mon, &tm.tm_year);
        tm.tm_mon--;
        tm.tm_year -= 1900;
        licenseDate = chrono::system_clock::from_time_t(mktime(&tm));
        cout << "Название программы: " << program << endl;
        cout << "Разработчик: " << developer << endl;
        cout << "Занимаемый размер: " << size << " MB" << endl;
        cout << "Дата срока истечения лицензии: " << date << endl;
        cout << "Осталось дней: " << dayscount() << endl;
    }

    bool isDateValid() const {
        auto now = chrono::system_clock::now();
        return licenseDate >= now;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");

    string prog;
    string dev;
    double size;
    string date;

    bool validDate = false;

        cout << "Введите название программы: ";
        cin >> prog;

        cout << "Введите разработчика: ";
        cin >> dev;

        cout << "Введите занимаемый размер (в MB): ";
        cin >> size;
while (!validDate) {
        cout << "Введите дату срока истечения лицензии (дд-мм-гггг): ";
        cin >> date;

        struct tm tm = {};
        sscanf(date.c_str(), "%2d-%2d-%4d", &tm.tm_mday, &tm.tm_mon, &tm.tm_year);
        tm.tm_mon--;
        tm.tm_year -= 1900;
        chrono::system_clock::time_point licenseDate = chrono::system_clock::from_time_t(mktime(&tm));

        // Проверка на прошедшую дату
        if (licenseDate < chrono::system_clock::now()) {
            cout << "Ошибка: Вы ввели прошедшую дату. Пожалуйста, введите корректные данные." << endl;

        } else {
            validDate = true;
            Soft soft1(prog, dev, size, date, licenseDate);
            soft1.display();
        }
    }

    return 0;
}

