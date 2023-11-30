#include <iostream>
#include <string>
using namespace std;
class Bike {
private:
char* brand; // hiệu xe
public:
virtual void move(int t1) {
cout << brand << ":" << t1*12 << " ";
}
};
class EBike : public Bike {
public: void move(int t2) {
Bike::move(t2*2);
}
};
void display(Bike& a, EBike& b) {
a.move(2);
b.move(2);
}
int main() {
EBike b1, b2;
display(b1, b2);
return 0;
}