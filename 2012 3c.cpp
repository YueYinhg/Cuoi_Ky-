#include <iostream>

class Function {
public:
    virtual double Value(double x) = 0;
    virtual double Derive(double x) = 0;
};

class DeriveCalculator {
public:
    // Tính đạo hàm của hàm tổng (f + g) theo công thức
    static double DeriveSum(Function* f, Function* g, double x) {
        if (f != nullptr && g != nullptr) {
            return f->Derive(x) + g->Derive(x);
        }
        return 0;
    }

    // Tính đạo hàm của hàm tích (f * g) theo công thức
    static double DeriveProduct(Function* f, Function* g, double x) {
        if (f != nullptr && g != nullptr) {
            return f->Derive(x) * g->Value(x) + f->Value(x) * g->Derive(x);
        }
        return 0;
    }

    // Tính đạo hàm của hàm thương (f / g) theo công thức
    static double DeriveQuotient(Function* f, Function* g, double x) {
        if (f != nullptr && g != nullptr) {
            double numerator = f->Derive(x) * g->Value(x) - f->Value(x) * g->Derive(x);
            double denominator = g->Value(x) * g->Value(x);
            if (denominator != 0) {
                return numerator / denominator;
            }
        }
        return 0;
    }

    // Tính đạo hàm của hàm hợp (f ∘ g) theo công thức
    static double DeriveComposition(Function* f, Function* g, double x) {
        if (f != nullptr && g != nullptr) {
            return f->Derive(g->Value(x)) * g->Derive(x);
        }
        return 0;
    }
};

// Lớp mẫu để triển khai
class ExampleFunction : public Function {
public:
    double Value(double x) override {
        return x * x;  // Ví dụ: hàm x^2
    }

    double Derive(double x) override {
        return 2 * x;  // Đạo hàm của x^2 là 2x
    }
};

int main() {
    double x = 2.0;

    // Tạo đối tượng của lớp mẫu
    ExampleFunction* exampleFunction = new ExampleFunction();

    // Tính đạo hàm của hàm tổng (f + g)
    double sumDerivative = DeriveCalculator::DeriveSum(exampleFunction, exampleFunction, x);
    std::cout << "Derivative of sum: " << sumDerivative << std::endl;

    // Tính đạo hàm của hàm tích (f * g)
    double productDerivative = DeriveCalculator::DeriveProduct(exampleFunction, exampleFunction, x);
    std::cout << "Derivative of product: " << productDerivative << std::endl;

    // Tính đạo hàm của hàm thương (f / g)
    double quotientDerivative = DeriveCalculator::DeriveQuotient(exampleFunction, exampleFunction, x);
    std::cout << "Derivative of quotient: " << quotientDerivative << std::endl;

    // Tính đạo hàm của hàm hợp (f ∘ g)
    double compositionDerivative = DeriveCalculator::DeriveComposition(exampleFunction, exampleFunction, x);
    std::cout << "Derivative of composition: " << compositionDerivative << std::endl;

    // Giải phóng bộ nhớ
    delete exampleFunction;

    return 0;
}
