#include <iostream>
#include <string>

using namespace std;

class Display {
protected:
    string type;
    long colors;
    int x_resolution;
    int y_resolution;

public:
    Display(const string& displayType, long displayColors, int resolutionX, int resolutionY)
        : type(displayType), colors(displayColors), x_resolution(resolutionX), y_resolution(resolutionY) {}

    void displayInfo() const {
        cout << "Display Type: " << type << endl;
        cout << "Colors: " << colors << endl;
        cout << "Resolution (X): " << x_resolution << endl;
        cout << "Resolution (Y): " << y_resolution << endl;
    }
};

class MotherBoard {
protected:
    int processor;
    int speed;
    int RAM;

public:
    MotherBoard(int procType, int procSpeed, int memoryRAM)
        : processor(procType), speed(procSpeed), RAM(memoryRAM) {}

    void displayInfo() const {
        cout << "Processor Type: " << processor << endl;
        cout << "Processor Speed: " << speed << " GHz" << endl;
        cout << "RAM: " << RAM << " GB" << endl;
    }
};

class Computer : public Display, public MotherBoard {
private:
    string name;
    int hard_disk;

public:
    Computer(const string& computerName, const string& displayType, long displayColors,
        int resolutionX, int resolutionY, int procType, int procSpeed, int memoryRAM,
        int hdSize)
        : Display(displayType, displayColors, resolutionX, resolutionY),
        MotherBoard(procType, procSpeed, memoryRAM), name(computerName), hard_disk(hdSize) {}

    void show() const {
        cout << "Computer Name: " << name << endl;
        Display::displayInfo();
        MotherBoard::displayInfo();
        cout << "Hard Disk Size: " << hard_disk << " GB" << endl;
    }
};

int main() {

    Computer pc("My PC", "LED", 111111111, 1000, 1000, 1, 2, 3, 1000);


    pc.show();

    return 0;
}

