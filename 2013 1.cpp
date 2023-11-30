#include <iostream>

class ComplexNumber {
private:
    int realPart;    // Phần thực (a)
    int imaginaryPart;  // Phần ảo (b)

public:
    // Hàm khởi tạo
    ComplexNumber(int real = 0, int imaginary = 0) : realPart(real), imaginaryPart(imaginary) {}

    // Hàm nhập số phức
    void input() {
        std::cout << "Nhap phan thuc (a): ";
        std::cin >> realPart;
        std::cout << "Nhap phan ao (b): ";
        std::cin >> imaginaryPart;
    }

    // Hàm xuất số phức
    void output() const {
        std::cout << realPart;
        if (imaginaryPart >= 0) {
            std::cout << " + " << imaginaryPart << "√7";
        } else {
            std::cout << " - " << -imaginaryPart << "√7";
        }
        std::cout << std::endl;
    }

    // Các thao tác cộng, trừ, đổi dấu, nhân
    ComplexNumber operator+(const ComplexNumber& other) const;
    ComplexNumber operator-(const ComplexNumber& other) const;
    ComplexNumber operator-() const;
    ComplexNumber operator*(const ComplexNumber& other) const;
};
// Cài đặt toán tử cộng
ComplexNumber ComplexNumber::operator+(const ComplexNumber& other) const {
    return ComplexNumber(realPart + other.realPart, imaginaryPart + other.imaginaryPart);
}

// Cài đặt toán tử trừ
ComplexNumber ComplexNumber::operator-(const ComplexNumber& other) const {
    return ComplexNumber(realPart - other.realPart, imaginaryPart - other.imaginaryPart);
}

// Cài đặt toán tử đổi dấu
ComplexNumber ComplexNumber::operator-() const {
    return ComplexNumber(-realPart, -imaginaryPart);
}

// Cài đặt toán tử nhân
ComplexNumber ComplexNumber::operator*(const ComplexNumber& other) const {
    int newReal = realPart * other.realPart + 7 * imaginaryPart * other.imaginaryPart;
    int newImaginary = realPart * other.imaginaryPart + imaginaryPart * other.realPart;
    return ComplexNumber(newReal, newImaginary);
}
int main() {
    ComplexNumber num1, num2, result;

    // Nhập hai số phức
    std::cout << "Nhap so phuc thu nhat:\n";
    num1.input();

    std::cout << "Nhap so phuc thu hai:\n";
    num2.input();

    // Thực hiện các phép toán
    result = num1 + num2;
    std::cout << "Tong: ";
    result.output();

    result = num1 - num2;
    std::cout << "Hieu: ";
    result.output();

    result = -num1;
    std::cout << "Doi cua so thu nhat: ";
    result.output();

    result = num1 * num2;
    std::cout << "Tich: ";
    result.output();

    return 0;
}
