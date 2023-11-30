#include <iostream> 
using namespace std; 

class MayXucTac {
private:
    static const int DON_GIA_THUE = 80000;  // Đơn giá thuê theo đề bài
    static const int DON_GIA_HOA_CHAT = 10000;  // Đơn giá hóa chất theo đề bài
    double congSuatLoc;  // Công suất lọc của máy (m3/h)
    double thoiGianSuDung;  // Thời gian sử dụng máy (h)
    double luongHoaChat;  // Lượng hóa chất sử dụng (g)

public:
    // Phương thức nhập thông tin máy
    void nhap() {
        cout << "Nhap cong suat loc (m3/h): ";
        cin >> congSuatLoc;
        cout << "Nhap thoi gian su dung (h): ";
        cin >> thoiGianSuDung;
        cout << "Nhap luong hoa chat su dung (g): ";
        cin >> luongHoaChat;
    }

    // Phương thức tính chi phí thuê máy
    double tinhChiPhiThue() const {
        return DON_GIA_THUE * thoiGianSuDung;
    }

    // Phương thức tính lượng nước lọc được
    double tinhLuongNuocLoc() const {
        double congSuatLocThucTe;
        if (thoiGianSuDung < 10) {
            congSuatLocThucTe = congSuatLoc * (luongHoaChat / 100);
        } else {
            congSuatLocThucTe = congSuatLoc * (luongHoaChat / 100) / (thoiGianSuDung / 10);
        }
        return congSuatLocThucTe * thoiGianSuDung;
    }

    // Phương thức tính chi phí sử dụng máy
    double tinhChiPhiSuDung() const {
        return tinhChiPhiThue() + (DON_GIA_HOA_CHAT * luongHoaChat);
    }
};

int main() {
    cout << "Don gia hoa chat: " << MayXucTac::DON_GIA_HOA_CHAT << endl;
    MayXucTac m;
    m.nhap();  // Nhập thông tin sử dụng của máy xúc tác này
    cout << "Chi phi su dung may: " << m.tinhChiPhiSuDung() << endl;
    cout << "Luong nuoc loc duoc: " << m.tinhLuongNuocLoc() << endl;

    return 0;
}
