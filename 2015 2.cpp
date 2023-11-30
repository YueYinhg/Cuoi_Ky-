#include <iostream>
#include <cstring>
#include <sstream>

class BigInteger {
private:
    char* value;

public:
    // Constructor từ chuỗi
    BigInteger(const char* str) {
        value = new char[strlen(str) + 1];
        strcpy(value, str);
    }

    // Constructor mặc định
    BigInteger() {
        value = new char[2];
        value[0] = '0';
        value[1] = '\0';
    }

    // Destructor
    ~BigInteger() {
        delete[] value;
    }

    // Hàm nhập
    friend std::istream& operator>>(std::istream& is, BigInteger& num) {
        char buffer[1000];
        is >> buffer;
        num.value = new char[strlen(buffer) + 1];
        strcpy(num.value, buffer);
        return is;
    }

    // Hàm so sánh bằng
    bool operator==(const BigInteger& other) const {
        return strcmp(value, other.value) == 0;
    }

    // In giá trị
    friend std::ostream& operator<<(std::ostream& os, const BigInteger& num) {
        os << num.value;
        return os;
    }
};

int main() {
    BigInteger n1("1234567891011");
    BigInteger n2;

    std::cout << "Input an integer = ";
    std::cin >> n2;

    if (n1 == n2)
        std::cout << "Equal.\n";
    else
        std::cout << "Not equal.\n";

    return 0;
}
