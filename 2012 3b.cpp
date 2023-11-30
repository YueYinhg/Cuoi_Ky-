#include <cmath>
#include <iostream>

// Khai báo lớp cơ sở Function
class Function {
public:
    // Phương thức thuần ảo để tính giá trị của hàm số
    virtual double Value(double x) = 0;

    // Phương thức thuần ảo để tính đạo hàm của hàm số
    virtual double Derive(double x) = 0;
};

// Lớp dẫn xuất từ lớp cơ sở Function, biểu diễn hàm f(x) = cos(x)
class Cos : public Function {
public:
    // Triển khai phương thức Value để tính giá trị của cos(x)
    double Value(double x) override {
        return cos(x);
    }

    // Triển khai phương thức Derive để tính đạo hàm của cos(x)
    double Derive(double x) override {
        return -sin(x);  // Đạo hàm của cos(x) là -sin(x)
    }
};

int main() {
    // Giả sử x là PI/6
    double x = 3.14 / 6;

    // Tạo đối tượng của lớp Cos
    Cos* cosFunction = new Cos();

    // Tính và in giá trị của cos(x) và đạo hàm của nó tại x
    std::cout << "cos(x) = " << cosFunction->Value(x) << "; cos'(x) = " << cosFunction->Derive(x) << std::endl;

    // Giải phóng bộ nhớ
    delete cosFunction;

    return 0;
}
