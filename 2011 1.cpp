#include <iostream>

using namespace std;

class MayLoc {
public:
  MayLoc() {}
  virtual ~MayLoc() {}
  virtual float congSuat() { return 0.0; }
  virtual void tinhLuongNuoc() {
    cout << "Luong nuoc = " << congSuat() * m_tgian << endl;
  }
protected:
  float m_cs;
  float m_tgian;
};

class MayLyTam : public MayLoc {
public:
  MayLyTam(float cs, float t) : MayLoc() {
    this->m_cs = cs;
    this->m_tgian = t;
  }
  virtual float congSuat() override { return m_cs * 2; }
};

int main() {
  MayLoc *pm = new MayLyTam(81.9, 10);
  pm->congSuat();
  pm->tinhLuongNuoc();
  delete pm;
  return 0;
}
