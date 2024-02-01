#include <iostream>
#include <stack>

class Train {
public:
    int type;

    Train(int t) : type(t) {}
};

class SortingNode {
private:
    std::stack<Train> mainTrack;
    std::stack<Train> sideTrack1;
    std::stack<Train> sideTrack2;

public:
    void addToMainTrack(const Train& train) {
        mainTrack.push(train);
    }

    void sortTrains() {
        while (!mainTrack.empty()) {
            Train currentTrain = mainTrack.top();
            mainTrack.pop();

            std::cout << "Train " << currentTrain.type << ": Send to Track 1 or Track 2 ? ";
            int trackChoice;
            std::cin >> trackChoice;

            if (trackChoice == 1) {
                sideTrack1.push(currentTrain);
            }
            else if (trackChoice == 2) {
                sideTrack2.push(currentTrain);
            }
            else {
                std::cout << "Invalid choice. Defaulting to Track 1." << std::endl;
                sideTrack1.push(currentTrain);
            }
        }
    }

    void printSortedTrains() {
        std::cout << "Trains on Side Track (Type 1): ";
        printStack(sideTrack1);

        std::cout << "Trains on Side Track (Type 2): ";
        printStack(sideTrack2);
    }

private:
    void printStack(std::stack<Train>& track) {
        while (!track.empty()) {
            std::cout << track.top().type << " ";
            track.pop();
        }
        std::cout << std::endl;
    }
};

int main() {
    SortingNode sortingNode;

    std::cout << "Enter the number of trains: ";
    int numTrains;
    std::cin >> numTrains;

    std::cout << "Enter train numbers (from " << numTrains << " to 1), separated by space:" << std::endl;
    for (int i = 1; i <= numTrains; ++i) {
        Train train(i);
        sortingNode.addToMainTrack(train);
    }

    sortingNode.sortTrains();
    sortingNode.printSortedTrains();

    return 0;
}
