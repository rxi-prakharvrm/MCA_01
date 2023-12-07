#include <iostream>
using namespace std;

class ITCompany {
    public:
    static int showCount;

    ITCompany() {
        showCount++;
    }
};

int ITCompany::showCount = 0;

int main() {
    ITCompany company1;
    ITCompany company2;
    ITCompany company3;
    ITCompany company4;
    ITCompany company5;

    cout << ITCompany::showCount << endl;
    return 0;
}