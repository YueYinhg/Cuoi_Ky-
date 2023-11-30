#include <iostream>
#include <string>
using namespace std;
class EyeFace : public Face {
private:
    int eyes;
    static int instanceCount;  

public:
    EyeFace(string sh, int e) : Face(sh), eyes(e) {
        instanceCount++;  
    }

    ~EyeFace() {
        instanceCount--;  
    }

    virtual void show() override {
        Face::show();
        cout << "Eyes: " << eyes << endl;
    }

    virtual IFace* clone() override {
        return new EyeFace(*this);
    }

    static int getInstanceCount() {
        return instanceCount;
    }
};

int EyeFace::instanceCount = 0;  

void testFace(IFace* fc) {
    IFace* a[3] = {fc, fc->clone(), fc->clone()};
    for (int i = 0; i < 3; i++) {
        a[i]->show();
    }
    cout << "The same 3 lines?" << endl;
}

int main() {
    EyeFace eyeFace("Circle", 2);
    testFace(&eyeFace);

    
    cout << "Total EyeFace instances: " << EyeFace::getInstanceCount() << endl;

    return 0;
}
