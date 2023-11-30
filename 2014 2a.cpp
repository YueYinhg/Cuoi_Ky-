#include <iostream>
#include <string> 

using namespace std;

class IFace {
public:
    virtual void show() = 0;
    virtual IFace* clone() = 0;
    virtual ~IFace() {}
};

class Face : public IFace {
private:
    string shape;

protected:
    string getShape();

public:
    Face(string sh) : shape(sh) {}

    virtual void show() override {
        cout << "Shape: " << shape << endl;
    }
};

class EyeFace : public Face {
private:
    int eyes;

public:
    EyeFace(string sh, int e) : Face(sh), eyes(e) {}

    virtual void show() override {
        Face::show();
        cout << "Eyes: " << eyes << endl;
    }

    virtual IFace* clone() override {
        return new EyeFace(*this);
    }
};

int main() {
    EyeFace eyeFace("Circle", 2);
    eyeFace.show();

    IFace* clonedFace = eyeFace.clone();
    clonedFace->show();

    delete clonedFace;

    return 0;
}
