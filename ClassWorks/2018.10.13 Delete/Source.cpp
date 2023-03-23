#include<iostream>
#include<string>

using namespace std;

class Person1 {
    int e: 1;
    int d;
    double c;
};


struct Person {
    int age;
    char *Ename;
    char *Lname;
    char c;

    Person() : age(0), Lname(new char[20]) {
        cout << "\nConstructor!\n";
        Ename = new char[20];
        strcpy_s(Lname, 20, "FirstName");
        strcpy_s(Ename, 20, "LastName");
    }

    Person(int Age, const char *name, const char *lastname) : age(Age) { // overload constructor
        strcpy_s(Ename, 20, name);
        strcpy_s(Lname, 20, lastname);
    }

    ~Person() {
        cout << "\nDestructor!\n";
        delete[]Ename;
        delete[]Lname;
        Ename = NULL, Lname = NULL;
    }

    void Fill() {
        cout << "\nEnter age";
        cin >> age;
        cin.ignore();
        cout << "\nEnter Ename";

        cin.getline(Ename, 20);
        //cin.get();
        cout << "\nEnter Lname";
        cin.getline(Lname, 20);
    }

    void OutPut() {
        cout << "\nAge " << this->age << "\nEname " << this->Ename << "\nLname " << this->Lname << endl;
    }

    void Name(int a) { // function
        cout << a << endl;
        cout << Ename << endl;
        cout << Lname << endl;
        cout << c << endl;
    }
};

enum Color {
    Red = 1, Blue, White, Black
};
enum Brand {
    BMW = 1, Mercedes, Audi, Opel
};

struct Cars {
public:
    int Year;
    Color MyColor;
    Brand MyBrand;
    char *MyModel;

    Cars(int year = 2000, Color myColor = Black, Brand Mybrand = Audi, const char *mymodel = "1") :
            Year(year), MyColor(myColor), MyBrand(Mybrand) {
        strcpy_s(MyModel, 20, mymodel);
    }

    void Set() {
        int i = 0;
        cout << "\nEnter the year: ";
        cin >> this->Year;
        cout << "\nEnter the Brand\n1 - BMW, 2 - Mercedes, 3 - Audi, 4 - Opel\n";
        cin >> i;
        this->MyBrand = Brand(i);
        cout << "\nEnter the Model: ";
        cin >> this->MyModel;
        cout << "\nEnter the color\n1 - Red, 2 - Blue, 3 - White, 4 - Black\n";
        cin >> i;
        this->MyColor = Color(i);
    }

    void Show() const {
        cout << "Year " << this->Year << ", Brand " << this->MyBrand << ", Model " << this->MyModel << ", Color "
             << this->MyColor << endl;
    }
};

class CarsArray {
public:
    int index;
    Cars ArrCars[10];

    bool Push(Cars &obj) {
        if (index < 10) {
            ArrCars[index] = obj;
            ++index;
            return true;
        } else
            return false;
    }

    bool Pop() {
        if (index > 0) {
            --index;
            return true;
        } else
            return false;

    };
};

int main() {

    Cars **A = new Cars *[10];
    for (int i = 0; i < 10; ++i)
        A[i] = new Cars;

    for (int i = 0; i < 10; ++i)
        A[i]->Show();


    system("pause");
    return 0;
}
