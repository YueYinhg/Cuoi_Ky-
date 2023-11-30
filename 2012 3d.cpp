#include <iostream>
#include <cmath>

class Sin {
private:
    // Đối tượng Singleton của lớp Sin
    static Sin* instance;

    // Hàm khởi tạo ẩn để ngăn chặn tạo đối tượng từ bên ngoài
    Sin() {}

public:
    // Hàm lấy đối tượng Singleton
    static Sin* getInstance() {
        if (instance == nullptr) {
            instance = new Sin();
        }
        return instance;
    }

    // Hủy bỏ hàm copy constructor và operator= để ngăn chặn sao chép đối tượng
    Sin(const Sin&) = delete;
    Sin& operator=(const Sin&) = delete;

    // Hàm tính giá trị của sin(x)
    double Value(double x) {
        return sin(x);
    }

    // Hàm tính đạo hàm của sin(x)
    double Derive(double x) {
        return cos(x);
    }

    // Hàm hủy bỏ đối tượng Singleton khi chương trình kết thúc
    static void destroyInstance() {
        if (instance != nullptr) {
            delete instance;
            instance = nullptr;
        }
    }
};

// Khởi tạo đối tượng Singleton là nullptr
Sin* Sin::instance = nullptr;

int main() {
    // Sử dụng đối tượng Singleton của lớp Sin
    Sin* sinFunction = Sin::getInstance();

    // Sử dụng hàm Value và Derive
    double x = 0.5;
    double sinValue = sinFunction->Value(x);
    double sinDerivative = sinFunction->Derive(x);

    // In kết quả
    printf("sin(%f) = %f\n", x, sinValue);
    printf("sin'(%f) = %f\n", x, sinDerivative);

    // Hủy bỏ đối tượng Singleton khi không cần thiết
    Sin::destroyInstance();

    return 0;
}
