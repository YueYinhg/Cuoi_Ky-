#include <iostream>
using namespace std;
class absList { // Bắt đầu của lớp absList
protected:
int dataId;
public:
absList(int pId = 0) {
dataId = pId;
}
virtual ~absList() {}
int getData() {
return dataId;
}
virtual absList* addFirst(int pId) = 0;
virtual absList* getSubItem() = 0;
virtual void showAll(ostream&) = 0;
virtual int countAll() {
return 0; // tạm thời 0 phần tử
}
}; // Kết thức lớp absList

class simpleList : public absList {
public:
simpleList(int pId) : absList(pId) {
}
virtual absList* addFirst(int pId) {
dataId = pId;
return this;
}
virtual absList* getSubItem() {
return NULL; // Không có thành phần con
}
virtual void showAll(ostream& outDev) {
outDev << dataId << " ";
}
virtual int countAll() {
return 1; // Chỉ có đúng một phần tử
}
};

// Lớp linearList
class linearList : public absList {
absList* subLst;
public:
linearList(int pId) : absList(pId) {
subLst = NULL;
}
virtual ~linearList() {
if (subLst != NULL)
delete subLst;
}

virtual absList* addFirst(int pId) {
linearList *Lst = new linearList(pId);
Lst->subLst = this;
return Lst;
}
virtual absList* getSubItem() {
return subLst;
}
virtual void showAll(ostream& outDev) {
{
    virtual int countAll() override {
    if (subLst == NULL) {
        return 0;
    } else {
        return 1 + subLst->countAll();
    }
}
virtual void showAll(ostream& outDev) override {
    absList* current = this;
    while (current != NULL) {
        current->showAll(outDev);
        current = current->getSubItem();
    }
}

}
}
