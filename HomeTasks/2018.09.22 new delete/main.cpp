#include <iostream>
#include "MyClass.h"

int main() {
    MyClass *pObj = new MyClass;
    pObj->Task1();
    pObj->Task2();
    pObj->Task3();
    pObj->Task4();
    pObj->Task5();
    delete pObj;
    pObj = NULL;
    system("pause");
    return 0;
}