#include "Builder.h"

void
BinaryTree::AddNode(int num, Violation offense, Node *&MyTree) {
    if (nullptr == MyTree) { // create binary tree root
        MyTree = new Node(num, offense);
        MyTree->l = MyTree->r = nullptr;
    } else if (num == MyTree->number)
        MyTree->offenses.push_back(offense);

    else if (num < MyTree->number) {
        if (MyTree->l != nullptr)
            AddNode(num, offense, MyTree->l);
        else {
            MyTree->l = new Node(num, offense);
            MyTree->l->l = MyTree->l->r = nullptr;
        }
    } else if (num > MyTree->number) {
        if (MyTree->r != nullptr)
            AddNode(num, offense, MyTree->r);
        else {
            MyTree->r = new Node(num, offense);
            MyTree->r->r = MyTree->r->l = nullptr;
        }
    }
}

void
BinaryTree::DeleteNode(Node *&MyTree) {
    if (MyTree) {
        DeleteNode(MyTree->l);
        DeleteNode(MyTree->r);
        delete MyTree;
        MyTree = nullptr;
    }
}

std::ostream &
operator<<(std::ostream &os, Violation &V) {
    os << "\nname: " << V.name << ", date: " << V.date << ", sum: " << V.sum << "UAH\n";
    return os;
}

std::ostream &
operator<<(std::ostream &os, Node &n) {
    os << "\nnumber: " << n.number << "\n";
    for (auto &x: n.offenses)
        os << x;
    return os;
}

void
BinaryTree::ShowAllBaseInfo(Node *&MyTree) {
    if (MyTree) {
        ShowAllBaseInfo(MyTree->l);  // ����������� ������� ��� ������ ������ ���������
        std::cout << *MyTree;        //���������� ������ ������
        ShowAllBaseInfo(MyTree->r);  //����������� ������ ��� ������ ������� ���������
    }
}

void
BinaryTree::ShowCustomNodeInfo(int &num, Node *&MyTree) {
    if (MyTree) {
        if (num == MyTree->number)
            std::cout << *MyTree;
        else if (num < MyTree->number)
            ShowCustomNodeInfo(num, MyTree->l);
        else if (num > MyTree->number)
            ShowCustomNodeInfo(num, MyTree->r);
    }
}

void
BinaryTree::ShowCustomNodeDiapazoneInfo(int &numFirst, int &numLast, Node *&MyTree) {
    if (MyTree) {
        ShowCustomNodeDiapazoneInfo(numFirst, numLast, MyTree->l);  // ����������� ������� ��� ������ ������ ���������
        if (MyTree->number >= numFirst && MyTree->number <= numLast)
            std::cout << *MyTree;        //���������� ������ ������
        ShowCustomNodeDiapazoneInfo(numFirst, numLast, MyTree->r);  //����������� ������ ��� ������ ������� ���������
    }
}
