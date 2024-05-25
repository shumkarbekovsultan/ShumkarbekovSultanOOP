#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QListWidget>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

class Bank {
public:
    std::string name;
    std::string address;
    std::string ownership;
    std::vector<std::pair<std::string, double>> deposits; // pair<deposit_name, annual_interest_rate>

    Bank(const std::string& n, const std::string& addr, const std::string& own)
        : name(n), address(addr), ownership(own) {}

    void addDeposit(const std::string& depositName, double annualInterestRate) {
        deposits.push_back({ depositName, annualInterestRate });
    }

    std::string toString() const {
        std::stringstream ss;
        ss << "Bank Name: " << name << "\n";
        ss << "Address: " << address << "\n";
        ss << "Ownership: " << ownership << "\n";
        ss << "Deposits:\n";
        for (const auto& deposit : deposits) {
            ss << " - " << deposit.first << " (Annual Interest Rate: " << deposit.second << "%)\n";
        }
        return ss.str();
    }
};

class BankDirectory {
private:
    std::vector<Bank> banks;

public:
    void addBank(const Bank& bank) {
        banks.push_back(bank);
    }

    void saveToFile(const std::string& filename) const {
        std::ofstream outFile(filename);
        if (!outFile.is_open()) {
            return;
        }

        for (const auto& bank : banks) {
            outFile << bank.name << "," << bank.address << "," << bank.ownership;
            for (const auto& deposit : bank.deposits) {
                outFile << "," << deposit.first << ":" << deposit.second;
            }
            outFile << std::endl;
        }

        outFile.close();
    }

    void loadFromFile(const std::string& filename) {
        std::ifstream inFile(filename);
        if (!inFile.is_open()) {
            return;
        }

        banks.clear(); // Clear existing data before loading new data

        std::string line;
        while (std::getline(inFile, line)) {
            std::istringstream iss(line);
            std::string name, address, ownership, depositInfo;
            getline(iss, name, ',');
            getline(iss, address, ',');
            getline(iss, ownership, ',');
            Bank bank(name, address, ownership);
            while (getline(iss, depositInfo, ',')) {
                size_t pos = depositInfo.find(':');
                if (pos != std::string::npos) {
                    std::string depositName = depositInfo.substr(0, pos);
                    double annualInterestRate = std::stod(depositInfo.substr(pos + 1));
                    bank.addDeposit(depositName, annualInterestRate);
                }
            }
            addBank(bank);
        }

        inFile.close();
    }

    std::vector<Bank> getBanks() const {
        return banks;
    }
};

class BankApp : public QWidget {
    Q_OBJECT

public:
    BankApp(QWidget* parent = nullptr)
        : QWidget(parent) {
        QVBoxLayout* layout = new QVBoxLayout(this);

        listWidget = new QListWidget(this);
        layout->addWidget(listWidget);

        addButton = new QPushButton("Add Bank", this);
        connect(addButton, &QPushButton::clicked, this, &BankApp::addBankClicked);
        layout->addWidget(addButton);

        saveButton = new QPushButton("Save Banks", this);
        connect(saveButton, &QPushButton::clicked, this, &BankApp::saveBanksClicked);
        layout->addWidget(saveButton);

        loadButton = new QPushButton("Load Banks", this);
        connect(loadButton, &QPushButton::clicked, this, &BankApp::loadBanksClicked);
        layout->addWidget(loadButton);

        setLayout(layout);
    }

private slots:
    void addBankClicked() {
        // Implement adding a bank
    }

    void saveBanksClicked() {
        // Implement saving banks to a file
    }

    void loadBanksClicked() {
        // Implement loading banks from a file
    }

private:
    QListWidget* listWidget;
    QPushButton* addButton;
    QPushButton* saveButton;
    QPushButton* loadButton;
    BankDirectory directory;
};

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    BankApp bankApp;
    bankApp.show();
    return app.exec();
}

#include "main.moc"

