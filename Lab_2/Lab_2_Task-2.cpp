#include <iostream>
#include <algorithm>

class Student {
public:
    std::string firstName;
    std::string lastName;
    std::string birthDate;
    std::string phoneNumber;

    Student() {}

    void inputStudentData() {
        std::cout << "Введите имя студента: ";
        std::cin >> firstName;

        std::cout << "Введите фамилию студента: ";
        std::cin >> lastName;

        std::cout << "Введите дату рождения студента (формат dd.mm.yyyy): ";
        std::cin >> birthDate;

        std::cout << "Введите номер телефона студента: ";
        std::cin >> phoneNumber;
    }

    void displayStudentData() const {
        std::cout << "Имя: " << firstName << ", Фамилия: " << lastName << ", Дата рождения: "
            << birthDate << ", Номер телефона: " << phoneNumber << "\n";
    }

    bool operator==(const Student& other) const {
        return firstName == other.firstName && lastName == other.lastName &&
            birthDate == other.birthDate && phoneNumber == other.phoneNumber;
    }
};

class StudentGroup {
private:
    static const int MAX_STUDENTS = 100;
    Student students[MAX_STUDENTS];
    int numStudents;

public:
    StudentGroup() : numStudents(0) {}

    void addStudent() {
        if (numStudents < MAX_STUDENTS) {
            Student newStudent;
            newStudent.inputStudentData();

            // Проверка наличия студента в группе
            auto it = std::find(std::begin(students), std::begin(students) + numStudents, newStudent);
            if (it == std::begin(students) + numStudents) {
                students[numStudents++] = newStudent;
                std::cout << "Студент добавлен успешно.\n";
            }
            else {
                std::cout << "Такой студент уже существует в группе.\n";
            }
        }
        else {
            std::cout << "Группа заполнена, невозможно добавить студента.\n";
        }
    }

    void removeStudent() {
        std::string lastName;
        std::cout << "Введите фамилию студента для удаления: ";
        std::cin >> lastName;

        auto it = std::find_if(std::begin(students), std::begin(students) + numStudents,
            [&](const Student& s) { return s.lastName == lastName; });

        if (it != std::begin(students) + numStudents) {
            std::rotate(it, std::begin(students) + numStudents - 1, std::begin(students) + numStudents);
            --numStudents;
            std::cout << "Студент удален успешно.\n";
        }
        else {
            std::cout << "Студент с фамилией " << lastName << " не найден.\n";
        }
    }

    void searchStudent() {
        std::string key, value;
        std::cout << "Выберите критерий поиска (фамилия-1, дата_рождения-2, номер_телефона-3): ";
        std::cin >> key;

        std::cout << "Введите значение для поиска: ";
        std::cin >> value;

        auto it = std::find_if(std::begin(students), std::begin(students) + numStudents, [&](const Student& s) {
            if (key == "1") {
                return s.lastName == value;
            }
            else if (key == "2") {
                return s.birthDate == value;
            }
            else if (key == "3") {
                return s.phoneNumber == value;
            }
            return false;
            });

        if (it != std::begin(students) + numStudents) {
            std::cout << "Студент найден:\n";
            it->displayStudentData();
        }
        else {
            std::cout << "Студент с указанным " << key << " " << value << " не найден.\n";
        }
    }

    void displayStudents() {
        std::cout << "Список студентов:\n";
        for (int i = 0; i < numStudents; ++i) {
            students[i].displayStudentData();
        }
    }
};

int main() {
    StudentGroup group;

    int choice;
    do {
        std::cout << "\nМеню:\n";
        std::cout << "1. Добавить студента\n";
        std::cout << "2. Поиск студента\n";
        std::cout << "3. Удалить студента\n";
        std::cout << "4. Вывести список студентов\n";
        std::cout << "5. Выйти\n";
        std::cout << "Выберите действие (1-5): ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            group.addStudent();
            break;
        case 2:
            group.searchStudent();
            break;
        case 3:
            group.removeStudent();
            break;
        case 4:
            group.displayStudents();
            break;
        case 5:
            std::cout << "Программа завершена.\n";
            break;
        default:
            std::cout << "Некорректный выбор. Попробуйте снова.\n";
        }
    } while (choice != 5);

    return 0;
}
