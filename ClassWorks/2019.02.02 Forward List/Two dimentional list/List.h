#pragma once
#include<iostream>


class List {
protected:
	struct Node {
	public:
		Node(int data) : data(data) {}
		int data = 0;
		Node* next = nullptr;
		Node* prev = nullptr;
	};
	Node* Head = nullptr;
	Node* Tail = nullptr;
public:
	void addHead(int data) {
		Node* tmp = new Node(data);
		if (this->empty()){
			Tail = tmp;
			Head = tmp;
		}
		else{
		tmp->next = Head;
		Head->prev = tmp;
		Head = tmp;
		}
	}
	void addTail(int data) {
		Node* tmp = new Node(data);
		if (this->empty()){
			Head = tmp;
			Tail = tmp;
		}
		else {
			Tail->next = tmp;
			tmp->prev = Tail;
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
	void ReShow() { // show all list
		Node* tmp = Tail;
		while (nullptr != tmp) {
			std::cout << tmp->data << "\n";
			tmp = tmp->prev;
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
	Node* Finder(int search) {
		if (this->empty())
			return nullptr;
		else{
		Node* tmp = Head;
		do{
			if (tmp->data == search)
				return tmp;
			else
				tmp = tmp->next;
		} while (tmp);
		return nullptr;
		}
	}
	void delNode(int search) {
		Node* tmp = this->Finder(search);
		if (tmp == Head) {
			tmp->next->prev = nullptr;
			Head = tmp->next;
			delete tmp;
		}
		else if (tmp != Tail) {
			tmp->prev->next = tmp->next;
			tmp->next->prev = tmp->prev;
			delete tmp;
		}
		else {
			tmp->prev->next = nullptr;
			Tail = tmp->prev;
			delete tmp;
		}
	}
	List();
	~List();
};

