#pragma once

#include<iostream>

template<typename T>
class List {
protected:
    struct Node {
    public:
        Node(T data) : data(data) {}

        int data = 0;
        Node *next = nullptr;
        Node *prev = nullptr;
    };

    Node *Head = nullptr;
    Node *Tail = nullptr;
public:
    List() {}

    ~List() { Delete(); }

    void addHead(T data) {
        Node *tmp = new Node(data);
        if (this->empty()) {
            Tail = tmp;
            Head = tmp;
        } else {
            tmp->next = Head;
            Head->prev = tmp;
            Head = tmp;
        }
    }

    void addTail(T data) {
        Node *tmp = new Node(data);
        if (this->empty()) {
            Head = tmp;
            Tail = tmp;
        } else {
            Tail->next = tmp;
            tmp->prev = Tail;
            Tail = tmp;
        }
    }

    void DeleteHead() {
        if (empty())
            return;
        else if (Head == Tail) {
            Node *tmp = Head;
            Head = Tail = nullptr;
            delete tmp;
            return;
        } else {
            Node *tmp = Head;
            Head = tmp->next;
            Head->prev = nullptr;
            delete tmp;
        }
    }

    void DeleteTail() {
        if (empty())
            return;
        else if (Head == Tail) {
            Node *tmp = Head;
            Head = Tail = nullptr;
            delete tmp;
            return;
        } else {
            Node *tmp = Tail;
            Tail = tmp->prev;
            Tail->next = nullptr;
            delete tmp;
        }
    }

    inline bool empty() const { return !Head; }

    void Show() { // show all list
        Node *tmp = Head;
        while (nullptr != tmp) {
            std::cout << tmp->data << "\n";
            if (this->empty())
                Tail = tmp;
            tmp = tmp->next;
        }
    }

    void ReShow() { // show all list
        Node *tmp = Tail;
        while (nullptr != tmp) {
            std::cout << tmp->data << "\n";
            tmp = tmp->prev;
        }
    }

    void Clear() {
        if (!this->empty()) {
            Node *tmp = Head;
            do {
                tmp->data = 0;
                tmp = tmp->next;
            } while (tmp);
        }
    }

    void Delete() {
        if (!this->empty()) {
            Node *tmp = Head;
            do {
                Head = tmp->next;
                delete tmp;
                tmp = Head;
            } while (tmp);
        }
        Tail = nullptr;
    }

    Node *Finder(T search) {
        if (this->empty())
            return nullptr;
        else {
            Node *tmp = Head;
            do {
                if (tmp->data == search)
                    return tmp;
                else
                    tmp = tmp->next;
            } while (tmp);
            return nullptr;
        }
    }

    void delNode(T search) {
        Node *tmp = this->Finder(search);
        if (tmp == Head) {
            tmp->next->prev = nullptr;
            Head = tmp->next;
            delete tmp;
        } else if (tmp != Tail) {
            tmp->prev->next = tmp->next;
            tmp->next->prev = tmp->prev;
            delete tmp;
        } else {
            tmp->prev->next = nullptr;
            Tail = tmp->prev;
            delete tmp;
        }
    }

    Node *PushBefore(Node *node) {
        if (this->empty()) {
            Head = Tail = new Node;
            return Head;
        } else {
            Node *tmp = Head;
            do {
                if (tmp == node) {
                    Node *newNode = new Node;
                    newNode->next = node;
                    newNode->prev = node->prev;
                    if (node->prev) // if node != Head
                        node->prev->next = newNode;
                    node->prev = newNode;
                    if (node == Head)
                        Head = newNode;
                    break;
                } else
                    tmp = tmp->next;
            } while (tmp->next);
            return newNode;
        }
    }

    Node *PushAfter(Node *node) {
        if (this->empty()) {
            Head = Tail = new Node;
            return Head;
        } else {
            Node *tmp = Head;
            do {
                if (tmp == node) {
                    Node *newNode = new Node;
                    newNode->next = node->next;
                    newNode->prev = node;
                    if (node->next) // if node != Tail
                        node->next->prev = newNode;
                    node->next = newNode;
                    if (node == Tail)
                        Tail = newNode;
                    break;
                } else
                    tmp = tmp->next;
            } while (tmp->next);
            return newNode;
        }
    }

    int Rewrite(T valueOld, T valueNew) {
        Node *tmp = Head;
        int changes = 0;
        do {
            if (Finder(valueOld)) {
                tmp->data = valueNew;
                ++changes;
            } else
                tmp = tmp->next;
        } while (tmp->next);
        return changes;
    }

    void ListWrapping() {
        Node *tmp = Tail;
        Node *copy = new Node;
        do {
            copy = tmp->next;
            tmp->next = tmp->prev;
            tmp->prev = copy;
            tmp = tmp->next;
        } while (tmp->next);
        Tail = Head;
        Head = tmp;
    }

    List operator+(const List &two) const {
        List third;

        Node *tmp = Head;
        Node *tmpTwo = two->Head;
        while (tmp) {
            third.PushAfter(Node(tmp->data + tmpTwo->data));
            tmp = tmp->next;
            tmpTwo - tmpTwo->next;
        }
        return third;
    }

    List operator*(const List &two) const {
        List third;

        tmp = two->Head;
        while (tmp) {
            for (Node *x: this)
                if (x->data == tmp->data)
                    third.PushAfter(tmp->data);
            tmp = tmp->next;
        }

        return third;
    }
};
