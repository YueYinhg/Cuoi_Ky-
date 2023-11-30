#include <iostream>
#include <vector>

class MayLoc {
protected:
    double donGiaThue;
    double congSuatLoc;

public:
    MayLoc(double giaThue, double congSuat) : donGiaThue(giaThue), congSuatLoc(congSuat) {}

    virtual double tinhChiPhiThue(double thoiGianSuDung) const {
        return donGiaThue * thoiGianSuDung;
    }

    virtual double tinhLuongNuocLoc(double thoiGianSuDung) const {
        return congSuatLoc * thoiGianSuDung;
    }

    virtual double tinhChiPhiSuDung(double thoiGianSuDung) const = 0;

    virtual ~MayLoc() {}
};

class MayLyTam : public MayLoc {
private:
    double luongXang;

public:
    MayLyTam(double giaThue, double congSuat, double xang) : MayLoc(giaThue, congSuat), luongXang(xang) {}

    double tinhChiPhiSuDung(double thoiGianSuDung) const override {
        return tinhChiPhiThue(thoiGianSuDung) + (luongXang * 20000 * thoiGianSuDung);
    }
};

class MayXucTac : public MayLoc {
private:
    double luongHoaChat;

public:
    MayXucTac(double giaThue, double congSuat, double hoaChat) : MayLoc(giaThue, congSuat), luongHoaChat(hoaChat) {}

    double tinhChiPhiSuDung(double thoiGianSuDung) const override {
        return tinhChiPhiThue(thoiGianSuDung) + (luongHoaChat * 10000);
    }
};

class AoChuaNuoc {
private:
    double luongNuoc;
    std::vector<MayLoc*> danhSachMayLoc;

public:
    AoChuaNuoc(double nuoc) : luongNuoc(nuoc) {}

    void themMayLoc(MayLoc* mayLoc) {
        danhSachMayLoc.push_back(mayLoc);
    }

    bool locHetNuoc() const {
        double tongLuongLoc = 0;
        for (const auto& mayLoc : danhSachMayLoc) {
            tongLuongLoc += mayLoc->tinhLuongNuocLoc(1); // Thời gian sử dụng là 1 giờ
        }
        return tongLuongLoc >= luongNuoc;
    }

    double tinhTongChiPhiSuDung() const {
        double tongChiPhi = 0;
        for (const auto& mayLoc : danhSachMayLoc) {
            tongChiPhi += mayLoc->tinhChiPhiSuDung(1); // Thời gian sử dụng là 1 giờ
        }
        return tongChiPhi;
    }
};

int main() {
    // Nhập thông tin máy lọc và lượng nước trong ao
    int n;
    std::cout << "Nhap so luong may loc: ";
    std::cin >> n;

    std::vector<MayLoc*> danhSachMayLoc;

    for (int i = 0; i < n; ++i) {
        std::cout << "Chon loai may loc (1. May Ly Tam / 2. May Xuc Tac): ";
        int loaiMay;
        std::cin >> loaiMay;

        double giaThue, congSuat;
        std::cout << "Nhap don gia thue: ";
        std::cin >> giaThue;
        std::cout << "Nhap cong suat loc: ";
        std::cin >> congSuat;

        if (loaiMay == 1) {
            double luongXang;
            std::cout << "Nhap luong xang: ";
            std::cin >> luongXang;
            danhSachMayLoc.push_back(new MayLyTam(giaThue, congSuat, luongXang));
        } else if (loaiMay == 2) {
            double luongHoaChat;
            std::cout << "Nhap luong hoa chat: ";
            std::cin >> luongHoaChat;
            danhSachMayLoc.push_back(new MayXucTac(giaThue, congSuat, luongHoaChat));
        } else {
            std::cout << "Loai may khong hop le." << std::endl;
            --i;
        }
    }

    double luongNuoc;
    std::cout << "Nhap luong nuoc trong ao (m3): ";
    std::cin >> luongNuoc;

    // Tính toán và hiển thị kết quả
    AoChuaNuoc ao(luongNuoc);

    for (const auto& mayLoc : danhSachMayLoc) {
        ao.themMayLoc(mayLoc);
    }

    if (ao.locHetNuoc()) {
        std::cout << "Ao duoc loc het nuoc." << std::endl;
    } else {
        std::cout << "Ao chua loc het nuoc." << std::endl;
    }

    std::cout << "Tong chi phi su dung cac may loc: " << ao.tinhTongChiPhiSuDung() << " dong." << std::endl;

    // Giải phóng bộ nhớ
    for (const auto& mayLoc : danhSachMayLoc) {
        delete mayLoc;
    }

    return 0;
}
