#include <iostream>

class Base {
public:
    ~Base() {
        std::cout << "Base Destructor\n";
    }
};

class Derived : public Base {
public:
    ~Derived() {
        std::cout << "Derived Destructor\n";
    }
};

int main() {
    Base* ptr = new Derived();
    delete ptr;  // Gọi hàm hủy của lớp cơ sở, không giải phóng đầy đủ tài nguyên

    return 0;
}
