#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Product {
public:
    string name;
    int quantity;
    int price;
    int soldQuantity;
    int soldPrice;

    Product(string n, int q, int p) : name(n), quantity(q), price(p), soldQuantity(0), soldPrice(0) {}
};

class ShoppingCart {
private:
    vector<Product> products;

public:
    void addItem(Product& product, int quantity) {
        product.quantity -= quantity;
        product.soldQuantity += quantity;
        product.soldPrice += quantity * product.price;
        products.push_back(product);
    }

    void generateBill() {
        int total = 0;
        cout << "\nYour Cart:\n";
        cout << "Item\t\tQuantity\tTotal\n";
        for (Product& product : products) {
            cout << product.name << "\t\t" << product.soldQuantity << "\t\t" << product.soldPrice << endl;
            total += product.soldPrice;
        }

        // Discount calculation
        if (total >= 100 && total < 200) {
            cout << "\nTotal Amount: " << total << endl;
            cout << "Discount 5%" << endl;
            total *= 0.95;
        }
        else if (total >= 200 && total < 300) {
            cout << "\nTotal Amount: " << total << endl;
            cout << "Discount 10%" << endl;
            total *= 0.9;
        }
        else if (total >= 300 && total < 400) {
            cout << "\nTotal Amount: " << total << endl;
            cout << "Discount 15%" << endl;
            total *= 0.85;
        }
        else if (total >= 400 && total < 500) {
            cout << "\nTotal Amount: " << total << endl;
            cout << "Discount 20%" << endl;
            total *= 0.8;
        }
        else if (total >= 500) {
            cout << "\nTotal Amount: " << total << endl;
            cout << "Discount 25%" << endl;
            total *= 0.75;
        }

        cout << "\nTotal Amount after discount: " << total << endl;
        int collected;
        cout << "Amount given by the customer: ";
        cin >> collected;
        cout << "Change due: " << collected - total << endl;
        cout << "----------------------------------------------\nThanks for shopping with us! Hope to see you again!";
    }
};

class Inventory {
private:
    vector<Product> products;

public:
    void addProduct(const Product& product) {
        products.push_back(product);
    }

    void viewProducts() {
        cout << "\nProduct List:\n";
        cout << "ID\tName\t\tQuantity\tPrice\n";
        for (size_t i = 0; i < products.size(); ++i) {
            cout << i + 1 << "\t" << products[i].name << "\t\t" << products[i].quantity << "\t\t" << products[i].price << endl;
        }
    }

    void addQuantity(int productId, int quantity) {
        if (productId >= 1 && productId <= products.size()) {
            products[productId - 1].quantity += quantity;
        }
    }

    void changePrice(int productId, int newPrice) {
        if (productId >= 1 && productId <= products.size()) {
            products[productId - 1].price = newPrice;
        }
    }

    void viewSalesReport() {
        int totalSales = 0;
        cout << "\nSales Report:\n";
        cout << "Product\t\tQuantity\tPrice\n";
        for (Product& product : products) {
            product.soldPrice = product.soldQuantity * product.price;
            totalSales += product.soldPrice;
            cout << product.name << "\t\t" << product.soldQuantity << "\t\t" << product.soldPrice << endl;
        }
        cout << "------------------------------------\nTotal\t\t\t\t" << totalSales << endl;
    }
    void removeProduct(int productId) {
        if (productId >= 1 && productId <= products.size()) {
            products.erase(products.begin() + productId - 1);
        }
    }
    vector<Product>& getProducts() { return products; }
};

class User {
private:
    string username;
    string password;

public:
    User(string u, string p) : username(u), password(p) {}

    string getUsername() const { return username; }
    string getPassword() const { return password; }

    void setUsername(const string& u) { username = u; }
    void setPassword(const string& p) { password = p; }
};

class Admin : public User {
public:
    Admin(string u, string p) : User(u, p) {}
};

class SalesReport {
private:
    vector<Product> soldProducts;

public:
    void addSoldProduct(const Product& product) {
        soldProducts.push_back(product);
    }

    void viewSalesReport() {
        int totalSales = 0;
        cout << "\nSales Report:\n";
        cout << "Product\t\tQuantity\tPrice\n";
        for (const Product& product : soldProducts) {
            int productPrice = product.price * product.soldQuantity;
            totalSales += productPrice;
            cout << product.name << "\t\t" << product.soldQuantity << "\t\t" << productPrice << endl;
        }
        cout << "------------------------------------\nTotal\t\t\t\t" << totalSales << endl;
    }
};

class Salesperson : public User {
private:
    SalesReport salesReport;

public:
    Salesperson(string u, string p) : User(u, p) {}

    SalesReport& getSalesReport() { return salesReport; }
};

class ReportGenerator {
public:
    static void generateReport(Salesperson& salesperson) {
        salesperson.getSalesReport().viewSalesReport();
    }
};

class StockAlert {
public:
    static void checkStock(Inventory& inventory) {
        bool isLowStock = false;
        cout << "\n\nStock Alert!\n";
        for (Product& product : inventory.getProducts()) {
            if (product.quantity < 5) {
                isLowStock = true;
                cout << "Quantity of " << product.name << " is less than 5" << endl;
            }
        }
        if (!isLowStock) {
            cout << "No low stock items." << endl;
        }
    }
};

class Menu {
public:
    static void showMainMenu() {
        cout << "Main Menu\nFor admin             Enter 1\nFor user              Enter 2\nFor exiting software  Enter 3\n: ";
    }

    static void showAdminMenu() {
        cout << "\nAdmin Menu\n";
        cout << "1. View Products\n";
        cout << "2. Add Quantity to a Product\n";
        cout << "3. Change Price of a Product\n";
        cout << "4. View Sales Report\n";
        cout << "5. Add a Product\n";

        cout << "6. Main Menu\n";
        cout << "Enter your choice: ";
    }
};

class OptionProcessor {
public:
    static void processAdminOption(int option, Inventory& inventory, string& username, string& password) {
        switch (option) {
        case 0:
        case 6:
            int productIdToDelete;
            cout << "Enter product ID to delete: ";
            cin >> productIdToDelete;
            inventory.removeProduct(productIdToDelete);
            break;
        case 1:
            inventory.viewProducts();
            break;
        case 2:
            int productId, quantity;
            cout << "Enter product ID: ";
            cin >> productId;
            cout << "Enter quantity to add: ";
            cin >> quantity;
            inventory.addQuantity(productId, quantity);
            break;
        case 3:
            int newPrice;
            cout << "Enter product ID: ";
            cin >> productId;
            cout << "Enter new price: ";
            cin >> newPrice;
            inventory.changePrice(productId, newPrice);
            break;
        case 4:
            inventory.viewSalesReport();
            break;
        case 5:
            string productName;
            int productPrice, productQuantity;
            cout << "Enter product name: ";
            cin >> productName;
            cout << "Enter product price: ";
            cin >> productPrice;
            cout << "Enter product quantity: ";
            cin >> productQuantity;
            inventory.addProduct(Product(productName, productQuantity, productPrice));
            break;
        



        }
    }
};

int main() {
    Inventory inventory;
    inventory.addProduct(Product("Bread", 10, 10));
    inventory.addProduct(Product("Chips", 10, 15));
    inventory.addProduct(Product("Biscuit", 10, 5));
    inventory.addProduct(Product("Juice", 10, 30));
    inventory.addProduct(Product("Drinks", 10, 50));
    inventory.addProduct(Product("Rice", 10, 200));
    inventory.addProduct(Product("Grain", 10, 100));
    inventory.addProduct(Product("Noodles", 10, 20));
    inventory.addProduct(Product("Nuggets", 10, 125));
    inventory.addProduct(Product("Bubble", 10, 2));

    string username, password;

    int option;
    do {
        Menu::showMainMenu();
        cin >> option;

        if (option == 2) {
            ShoppingCart cart;
            int productId, quantity;
            inventory.viewProducts();
            cout << "Enter product ID: ";
            cin >> productId;
            cout << "Enter quantity: ";
            cin >> quantity;

            if (productId > 0 && productId <= inventory.getProducts().size() && quantity > 0 &&
                quantity <= inventory.getProducts()[productId - 1].quantity) {
                Product& selectedProduct = inventory.getProducts()[productId - 1];
                cart.addItem(selectedProduct, quantity);
            }
            else {
                cout << "Invalid product ID or quantity. Please try again." << endl;
            }

            cart.generateBill();
        }
        else if (option == 1) {
            cout << "Enter username: ";
            cin >> username;
            cout << "Enter password: ";
            cin >> password;

            if (username == "admin" && password == "123") {
                int adminOption;
                do {
                    Menu::showAdminMenu();
                    cin >> adminOption;
                    OptionProcessor::processAdminOption(adminOption, inventory, username, password);
                } while (adminOption != 6);
            }
            else {
                cout << "Invalid username or password. Please try again." << endl;
            }
        }

        StockAlert::checkStock(inventory);

    } while (option != 3);

    return 0;
}