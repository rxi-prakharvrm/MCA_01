#include <iostream>
#include <unordered_map>
using namespace std;

class Item {
public:
    int code;
    int price;
    unordered_map<int, int> u;

public:
    Item() {}

    Item(int code, int price) {
        this->code = code;
        this->price = price;
    }

    void insertItem();

    void deleteItem();

    int totalPrice();
};

void Item::insertItem() {
    bool isContinue = true;
    string ans;
    int code, price;

    while (isContinue) {
        cout << "1. Do you want to add item to the list? (yes / no): ";
        cin >> ans;
        if (ans == "yes") {
            cout << "Enter the code of the purchased item: ";
            cin >> code;
            cout << "Enter the price of the purchased item: ";
            cin >> price;
            u[code] = price;  // Correct way to insert into unordered_map
        } else {
            isContinue = false;
        }
    }
}

void Item::deleteItem() {
    bool isContinue = true;
    int code;
    string ans;

    while (isContinue) {
        cout << "1. Do you want to delete item from the list? (yes / no): ";
        cin >> ans;
        if (ans == "yes") {
            cout << "Enter the code of the purchased item: ";
            cin >> code;
            u.erase(code);
        } else {
            isContinue = false;
        }
    }
}

int Item::totalPrice() {
    int sum = 0;
    for (auto it = u.begin(); it != u.end(); it++) {
        sum += it->second;
    }

    return sum;
}

int main() {
    Item itm;
    itm.insertItem();
    itm.deleteItem();
    cout << "Total Price: " << itm.totalPrice() << endl;
    return 0;
}
