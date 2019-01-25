#include<iostream>
#include<string>

class MyClass{
public:
const char * t = "my text\0";
const std::string* ps = new std::string("my test");
public:
	MyClass(const char* T = "my text\0", const char* PS = "my test"): t(T), ps(new std::string(PS)){}
};

void change(const int * pt, int n);

int main() {
	MyClass Obj;

	char* t1 = const_cast<char*>(Obj.t);
	std::string* ps1 = const_cast<std::string*>(Obj.ps);

	int pop1 = 38383;
	const int pop2 = 2000;

	std::cout << "pop1, pop2: " << pop1 << ", " << pop2 << std::endl;
	change(&pop1, -103);
	change(&pop2, -103);
	std::cout << "pop1, pop2: " << pop1 << ", " << pop2 << std::endl;


	system("pause");
	return 0;
}

void change(const int * pt, int n)
{
	int * pc;

	pc = const_cast<int *>(pt);
	*pc += n;

}