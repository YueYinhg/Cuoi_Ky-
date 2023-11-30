#include <iostream>
using namespace std;

// Lớp trừu tượng
class Shape {
public:
    // Phương thức thuần ảo
    virtual void draw() const = 0;

    // Phương thức không thuần ảo
    void displayInfo() const {
        cout << "Thông tin hình" << endl;
    }
};

// Lớp dẫn xuất từ lớp trừu tượng
class Circle : public Shape {
public:
    void draw() const override {
        cout << "Vẽ hình tròn" << endl;
    }
};

int main() {
    // Không thể tạo đối tượng từ lớp trừu tượng
    // Shape shape; // Lỗi!

    // Tạo đối tượng từ lớp dẫn xuất
    Circle circle;
    circle.draw();         // Vẽ hình tròn
    circle.displayInfo();  // Thông tin hình

    return 0;
}
