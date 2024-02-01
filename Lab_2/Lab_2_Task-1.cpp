#include <iostream>
#include <algorithm>

class Aeroflot {
public:
    std::string flight_number;
    std::string departure_point;
    std::string destination_point;
    std::string arrival_time;
    std::string departure_time;
    std::string registration_section;

    Aeroflot() {}

    Aeroflot(std::string flight_number, std::string departure_point, std::string destination_point,
             std::string arrival_time, std::string departure_time, std::string registration_section)
        : flight_number(flight_number),
          departure_point(departure_point),
          destination_point(destination_point),
          arrival_time(arrival_time),
          departure_time(departure_time),
          registration_section(registration_section) {}
};

void sortAeroflotArray(Aeroflot arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j].destination_point > arr[j + 1].destination_point) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void displayAeroflot(Aeroflot aeroflot) {
    std::cout << aeroflot.flight_number << "\t"
              << aeroflot.departure_point << "\t\t"
              << aeroflot.destination_point << "\t\t"
              << aeroflot.arrival_time << "\t"
              << aeroflot.departure_time << "\t"
              << aeroflot.registration_section << "\n";
}

int main() {
    int size;
    std::cout << "Enter the number of flights: ";
    std::cin >> size;

    Aeroflot *aeroflots = new Aeroflot[size];
    bool found = false;
    std::string searchFlightNumber;

    int choice;
    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Enter flight data\n";
        std::cout << "2. Display all flights\n";
        std::cout << "3. Display flight by number\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                for (int i = 0; i < size; ++i) {
                    std::cout << "Enter details for flight " << i + 1 << ":\n";
                    std::cout << "Flight Number: ";
                    std::cin >> aeroflots[i].flight_number;
                    std::cout << "Departure Point: ";
                    std::cin >> aeroflots[i].departure_point;
                    std::cout << "Destination Point: ";
                    std::cin >> aeroflots[i].destination_point;
                    std::cout << "Arrival Time: ";
                    std::cin >> aeroflots[i].arrival_time;
                    std::cout << "Departure Time: ";
                    std::cin >> aeroflots[i].departure_time;
                    // Переносим ввод Registration Section после ввода Departure Time
                    std::cout << "Registration Section: ";
                    std::cin >> aeroflots[i].registration_section;
                }
                // Сортировка рейсов по пункту назначения
                sortAeroflotArray(aeroflots, size);
                break;
            case 2:
                // Вывод на консоль
                std::cout << "\nFlight Details:\n";
                std::cout << "Flight#\tDeparture\t\tDestination\t\tArrival\t\tDeparture\tRegistration\n";
                for (int i = 0; i < size; ++i) {
                    displayAeroflot(aeroflots[i]);
                }
                break;
            case 3:
                std::cout << "Enter flight number to display: ";
                std::cin >> searchFlightNumber;
                found = false;
                for (int i = 0; i < size; ++i) {
                    if (aeroflots[i].flight_number == searchFlightNumber) {
                        displayAeroflot(aeroflots[i]);
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    std::cout << "Flight with number " << searchFlightNumber << " not found.\n";
                }
                break;
            case 0:
                std::cout << "Exiting the program.\n";
                break;
            default:
                std::cout << "Invalid choice. Please enter a valid option.\n";
        }
    } while (choice != 0);

    delete[] aeroflots;

    return 0;
}

