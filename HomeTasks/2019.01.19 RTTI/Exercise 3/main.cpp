#include<iostream>
#include"Vector.h"

using std::cout;
using std::endl;

int main() {
    Vector<int> v;
    Vector<int> v1(2); // ��������� ����� = 2, �������� ���, buffer -> [0][0],
    //buffer - ���� ��������� �� ����� ������, ���� capacity �����(capcity = 4, �� buffer -> [0][0][.][.])
    v1.pushBack(10);
    v1.pushBack(20);
    cout << "The size of v is " << v.getSize() << endl; // 4
    cout << "The capacity of v is " << v.getCapacity()
         << endl; // >=4, ����� ���� �������, �-�, ���� ������ �� ������� ����� ���������� ������ ������ � ������ ������������(1.5 �� 2)
    v1.print(); // 0 0 10 20
    cout << v1[2] << " " << v[3] << endl;// ������ 10  20


    for (size_t i = 0; i < v1.getSize(); ++i)// ������ �� �������� �������
        cout << v1[i] << "\t";
    if (!v1.empty())// ���� �� �����
        v1.popback(); // �������� �������
    v1.print(); // 0 0 10
    cout << "The size of v is " << v.Size() << endl; // 3
    v1.reserve(20); // capacity = 20, size = ��� ����(3)
    v1.front() = 1234; // ������ ������� ������� �� 1234
    v1.clear();
    cout << "The size of v after clearing is " << v.Size() << endl; // 0


    system("pause");
    return 0;
}