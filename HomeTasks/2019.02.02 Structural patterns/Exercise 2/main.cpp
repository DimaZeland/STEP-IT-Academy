#include<iostream>
#include"Builder.h"

using namespace std;

int main() {
	//
	//����: ��������� �������.Composite.
	//
	//	�������� ��������, �� ���� ��������� ������ ������� �������(����� � �����).
	//	��� ������� ����� �������� ��� �� �����.
	//	����������� ���������
	//	��������� ���������� ��� ����
	//	��������� �����  �����
	//	���������� ������ �����
	ItemFS *  fileZ = new File("z.doc", 12000);
	ItemFS *  fileW = new File("w.doc", 23000);
	ItemFS *  folderA = new Folder("A");
	ItemFS *  folderB = new Folder("B");
	folderB->AddItem(fileW);
	folderA->AddItem(fileZ);
	folderA->AddItem(folderB);
	cout << fileZ->getSize() << endl;
	cout << folderA->getSize() << endl; // 12000 + 23000 = 35000

	system("pause");
	return 0;
}