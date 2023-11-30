#include <iostream>
using namespace std;

// Lớp cơ sở
class Shape {
public:
    virtual void draw() const {
        cout << "Vẽ hình" << endl;
    }
};

// Lớp dẫn xuất 1
class Circle : public Shape {
public:
    void draw() const override {
        cout << "Vẽ hình tròn" << endl;
    }
};

// Lớp dẫn xuất 2
class Square : public Shape {
public:
    void draw() const override {
        cout << "Vẽ hình vuông" << endl;
    }
};

int main() {
    Circle circle;
    Square square;

    // Đa hình
    Shape* shape1 = &circle;
    Shape* shape2 = &square;

    shape1->draw();  // Vẽ hình tròn
    shape2->draw();  // Vẽ hình vuông

    return 0;
}
