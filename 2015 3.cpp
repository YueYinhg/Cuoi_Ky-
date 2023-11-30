#include <iostream>
#include <vector>

// Lớp cơ sở
class Stall {
protected:
    int stallNumber;
    double area;

public:
    Stall(int number, double area) : stallNumber(number), area(area) {}

    virtual double calculateRent() const = 0;
};

// Lớp con cho sạp thực phẩm
class FoodStall : public Stall {
private:
    double coldStorageFee;

public:
    FoodStall(int number, double area, double coldStorageFee)
        : Stall(number, area), coldStorageFee(coldStorageFee) {}

    double calculateRent() const override {
        double baseRent = 40000000 * area;
        double totalRent = baseRent + baseRent * 0.05 + coldStorageFee;
        return totalRent;
    }
};

// Lớp con cho sạp quần áo
class ClothingStall : public Stall {
public:
    ClothingStall(int number, double area) : Stall(number, area) {}

    double calculateRent() const override {
        double baseRent = 40000000 * area;
        double totalRent = baseRent + baseRent * 0.10;
        return totalRent;
    }
};

// Lớp con cho sạp trang sức
class JewelryStall : public Stall {
private:
    double totalRevenue;

public:
    JewelryStall(int number, double area, double totalRevenue)
        : Stall(number, area), totalRevenue(totalRevenue) {}

    double calculateRent() const override {
        double baseRent = 40000000 * area;
        double additionalTax = (totalRevenue < 100000000) ? 0.20 : 0.30;
        double totalRent = baseRent + baseRent * additionalTax;
        return totalRent;
    }
};

int main() {
    std::vector<Stall*> stalls;

    // Nhập thông tin các sạp
    stalls.push_back(new FoodStall(1, 30.5, 5000000));
    stalls.push_back(new ClothingStall(2, 25.0));
    stalls.push_back(new JewelryStall(3, 15.5, 120000000));

    // Tính tổng số tiền các sạp phải đóng hàng năm
    double totalPayment = 0.0;
    for (const auto& stall : stalls) {
        totalPayment += stall->calculateRent();
    }

    // Xuất tổng số tiền
    std::cout << "Total Payment: " << totalPayment << " VND" << std::endl;

    // Giải phóng bộ nhớ
    for (const auto& stall : stalls) {
        delete stall;
    }

    return 0;
}
