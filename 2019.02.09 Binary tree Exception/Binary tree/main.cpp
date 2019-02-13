#include<iostream>
#include"Builder.h"

int main() {
	
	Node* rootBinaryTree = new Node(1,Violation("Unright parking", "2019.01.27", 100));
	BinaryTree FinesBase(rootBinaryTree);

	FinesBase.AddNode(1, Violation("Riding without rights", "2019.01.15", 50), rootBinaryTree);
	FinesBase.AddNode(2, Violation("over speed", "2019.01.13", 70), rootBinaryTree);
	FinesBase.AddNode(2, Violation("driving while intoxicated", "2019.01.20", 150), rootBinaryTree);
	FinesBase.AddNode(3, Violation("riding without wearing a seat belt", "2019.01.31", 450), rootBinaryTree);
	FinesBase.AddNode(4, Violation("red light", "2019.01.28", 550), rootBinaryTree);
	FinesBase.AddNode(5, Violation("untimely inspection", "2019.01.14", 580), rootBinaryTree);
	FinesBase.AddNode(5, Violation("lack of medical first-aid kits", "2019.01.30", 570), rootBinaryTree);
	FinesBase.AddNode(6, Violation("over speed", "2019.01.03", 750), rootBinaryTree);
	FinesBase.AddNode(7, Violation("driving while intoxicated", "2019.01.16", 530), rootBinaryTree);

	std::cout << "\nShow all base info:\n";
	FinesBase.ShowAllBaseInfo(rootBinaryTree);
	int FirstNumber = 2, LastNumber = 6;
	std::cout << "\nShow base info about car with number 2:\n";
	FinesBase.ShowCustomNodeInfo(FirstNumber, rootBinaryTree);
	std::cout << "\nShow base info about car with diapazone 2-6:\n";
	FinesBase.ShowCustomNodeDiapazoneInfo(FirstNumber, LastNumber, rootBinaryTree);

	system("pause");
	return 0;
}