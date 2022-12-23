#include<iostream>
#include"List.h"

int main() {
	List list;
	list.addTail(100);
	list.addHead(20);
	list.addHead(30);
	list.addHead(40);
	list.addHead(50);
	list.Show();
	std::cout << "\n";
	list.delNode(100);
	list.Show();
	std::cout << "\n";
	list.delNode(50);
	list.Show();
	std::cout << "\n";
	list.delNode(30);
	list.Show();


	//list.ReShow();
	//list.Clear();
	//list.Show();
	//list.Delete();
	//std::cout << "\nList is empty: " << std::boolalpha << list.empty() << std::endl;
	//list.addTail(100);
	//list.addHead(20);
	//list.addHead(50);
	//list.Show();
	system("pause");
	return 0;
}