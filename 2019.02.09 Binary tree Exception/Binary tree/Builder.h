#include <iostream>
#include<string>
#include<vector>
using namespace std;

struct Violation {
public:
	std::string name = "";
	std::string date = "";
	float sum = 0;
	Violation(std::string n = "", std::string d = "", float s = 0) : name(n), date(d), sum(s) {}
	friend std::ostream& operator<<(std::ostream& os, Violation& V);
};

class Node {
public:
	int number = 0;
	std::vector<Violation> offenses{};
	Node *l = nullptr;
	Node* r = nullptr;
	Node() = default;
	Node(int num, Violation offense) : number(num) {
		offenses.push_back(offense);
	}
	friend std::ostream& operator<<(std::ostream& os, Node& n);
};

class BinaryTree {
public:
	Node * Tree = nullptr;
public:
	BinaryTree(Node* tree = nullptr) : Tree(tree) {}
	void AddNode(int num, Violation offense, Node* &MyTree);
	inline Node* GetRootTree() const { return Tree; }
	void DeleteNode(Node* &MyTree);
	void ShowAllBaseInfo(Node* &MyTree);
	void ShowCustomNodeInfo(int& num, Node* &MyTree);
	void ShowCustomNodeDiapazoneInfo(int& numFirst, int& numLast, Node* &MyTree);

	
	~BinaryTree() { DeleteNode(Tree); }
};





