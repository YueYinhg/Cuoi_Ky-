using namespace std;

class A {
public:

  A() {
    a = new int[3];
    for (int i = 0; i < 3; i++) {
      a[i] = i + 1;
    }
  }

  A(const A& num) {
    a = new int[3];
    for (int i = 0; i < 3; i++) {
      a[i] = num.a[i];
    }
  }

  A& operator=(const A& num) {
    if (this != &num) {
      delete[] a;
      a = new int[3];
      for (int i = 0; i < 3; i++) {
        a[i] = num.a[i];
      }
    }
    return *this;
  }

  ~A() {
    delete[] a;
  }

private:
  int* a;
};

void init(A& a) {
    
}
  
