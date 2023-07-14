#include <iostream>
using namespace std;

class Rectangle {
    int height, width;
public:
    void setdata(int h, int w) {
        height = h;
        width = w;
    }
    friend void printdata(Rectangle s);
};

void printdata(Rectangle s) {
    cout << "Height is: " << s.height << endl;
    cout << "Width is: " << s.width << endl;
    cout << "Area of Rectangle is: " << s.height*s.width;
}

int main() {
    Rectangle s;
    s.setdata(10, 12);
    printdata(s);
    return 0;
}
