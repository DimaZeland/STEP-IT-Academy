#pragma once
#include<iostream>


class List {
protected:
	struct Node {
	public:
		Node(int data) : data(data) {}
		int data = 0;
		Node* next = nullptr;
	};
	Node* Head = nullptr;
	Node* Tail = nullptr;
public:
	void addHead(int data) {
		Node* tmp = new Node(data);
		tmp->next = Head;
		Head = tmp;
	}
	void addTail(int data) {
		Node* tmp = new Node(data);
		if (this->empty())
			Head = tmp;
		else {
			Tail->next = tmp;
			Tail = tmp;
		}
	}
	inline bool empty()const { return !Head; }
	void Show() { // show all list
		Node* tmp = Head;
		while (nullptr != tmp) {
			std::cout << tmp->data << "\n";
			if (this->empty())
				Tail = tmp;
			tmp = tmp->next;
		}
	}
	void Clear() {
		if (!this->empty()) {
			Node* tmp = Head;
			do{
				tmp->data = int();
				tmp = tmp->next;
			} while (tmp);
		}
	}
	void Delete() {
		if (!this->empty()) {
			Node* tmp = Head;
			do {
				Head = tmp->next;
				delete tmp;
				tmp = Head;
			} while (tmp);
		}
		Tail = nullptr;
	}
	List();
	~List();
};

