#include<iostream>
#include<string>
#include<ctime>

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!PROGRAM DESCRIPTION DISPLAYED IN LINES 415-481 OR IN A SEPARATE FILE Zeland.txt!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
class Abstract { // class contains virtual functions that will be overloaded in derived classes
public:
    Abstract() {} // constructor
    virtual ~Abstract() {} // virtual destructor, since the class has virtual functions
    void CreateArr(int); // array filling method
    inline bool Get_sort_result() { return sort_result; } // output of array result
    virtual void SortArr() {};

    void FindArr(int, int);

    void DisplayTheValues();

protected: // class data members that are visible to derived classes, but not available to other program objects
    bool sort_result = true; // flag for the result of selecting the sorting method
    const int size = 10;
    static int arr[10];
};

class Bubble
        : public Abstract { // declaring a derived class to create an overloaded array sorting function (bubble method)
public:
    Bubble() {} //constructor
    ~Bubble() {} // destructor
    virtual void SortArr(); // overloading the base class sort method
};

class Insert
        : public Abstract { // Declaring a derived class to create an overloaded array sorting function (insert method)
public:
    Insert() {} //constructor
    ~Insert() {} // destructor
    virtual void SortArr(); // overloading the base class sort method
};

class Selection
        : public Abstract { // declaring a derived class to create an overloaded array sorting function (selection method)
public:
    Selection() {} //constructor
    ~Selection() {} // destructor
    virtual void SortArr(); // overloading the base class sort method
};

class Shaker
        : public Abstract { // declaring a derived class to create an overloaded array sorting function (shaker method)
public:
    Shaker() {} //constructor
    ~Shaker() {} // destructor
    virtual void SortArr(); // overloading the base class sort method
};

void Abstract::CreateArr(int a) { // method definition of array filling
    switch (a) {
        case 1: {
            for (int i = 0; i < size; ++i) { // random values from 0 to 10
                arr[i] = rand() % 11;
            }
            sort_result = true;
            break;
        }
        case 2: { // manually
            std::cout
                    << "\nTo manually fill the values of the elements of the array, enter ten integer values with a space and press <Enter>:\n";
            for (int i = 0, k = 0; i < size; ++i) {
                std::cin >> k;
                arr[i] = k;
            }
            sort_result = true;
            break;
        }
        default: {
            std::cout << "\nThe method of filling the values of array elements is entered incorrectly.\n";
            sort_result = false;
            break;
        }
    }
}

void Abstract::FindArr(int value, int type_of_parsing) { // Determine the search function of the selected item
    int ater_line_search = 0;
    switch (type_of_parsing) {
        case 1: { // linear search
            for (; ater_line_search < size && value !=
                                              arr[ater_line_search]; ++ater_line_search); // just loop through the iterations of the loop before exiting the loop (without any conditions being met)

            value == arr[ater_line_search] ? std::cout << "\nResult of the method of linear search: "
                                                       << ater_line_search << '\t' << arr[ater_line_search] << std::endl
                                           :
            std::cout << "\nUsing the linear search method, no element with a specified value was found in the array\n";
            break;
        }
        case 2: { // binary search
            for (int start = 0, end = size, diapazon = size;;) {
                if (arr[end - 1] == value) {
                    std::cout << "\nResult of the binary search method: " << end - 1 << '\t' << arr[end - 1]
                              << std::endl;
                    break;
                }
                if (arr[start] == arr[end - 1]) {
                    std::cout
                            << "\nUsing the binary search method, no element with a specified value was found in the array\n";
                    break;
                }
                diapazon /= 2;
                if (end >= value)
                    end /= 2;
                else {
                    start = end;
                    end = end + diapazon;
                }
            }
            break;
        }
        default: { // passing an optional argument of sort type
            std::cout << "\nThe method for finding the selected array element was entered incorrectly.\n";
            break;
        }
    }
}

void Abstract::DisplayTheValues() { // output of array elements
    system("cls");
    for (int i = 0; i < size; ++i)
        std::cout << i << "\t" << arr[i] << std::endl;
}

void
Bubble::SortArr() { // overloading the virtual method of sorting an array of Abstract class by the method of sorting by a bubble
    int choise = 0;
    bool swap_is = false, choise_type_sort = true;
    do {
        std::cout << "\nChoose the type of data sorting: 1 - ascending, 2 - descending: ";
        std::cin >> choise;
        switch (choise) {
            case 1: {
                for (int i = 0; i < size; ++i) { // sorting by arr [] by bubble method in ascending order
                    for (int m = 0; m < size - i - 1; ++m) {
                        if (arr[m] > arr[m + 1]) {
                            std::swap(arr[m], arr[m + 1]);
                            swap_is = true;
                        }
                    }
                    if (!swap_is)
                        break;
                }
                choise_type_sort = true;
                break;
            }
            case 2: {
                for (int i = 0; i < size; ++i) { // sorting [arr] by bubble method in descending order
                    for (int m = 0; m < size - i - 1; ++m) {
                        if (arr[m] < arr[m + 1]) {
                            std::swap(arr[m], arr[m + 1]);
                            swap_is = true;
                        }
                    }
                    if (!swap_is)
                        break;
                }
                choise_type_sort = true;
                break;
            }
            default: {
                std::cout << "\nSort type of array element values is entered incorrectly.\n";
                choise_type_sort = false;
                break;
            }
        }
    } while (!choise_type_sort); // repeat the sort type selection until the correct type is entered
    Abstract::DisplayTheValues();
}

void Insert::SortArr() { // overloading the virtual method of sorting an array of Abstract class by insertion sorting
    int choise = 0;
    bool swap_is = false, choise_type_sort = true;
    do {
        std::cout << "\nChoose the type of data sorting: 1 - ascending, 2 - descending: ";
        std::cin >> choise;
        switch (choise) {
            case 1: {
                for (int k = 0; k < size - 1; ++k) { // sort arr [] by insertion method in ascending order
                    for (int j = k; arr[j] > arr[j + 1] && j >= 0; --j)
                        std::swap(arr[j], arr[j + 1]);
                }
                choise_type_sort = true;
                break;
            }
            case 2: {
                for (int k = 0; k < size - 1; ++k) { // sort arr [] by insertion method in descending order
                    for (int j = k; arr[j] < arr[j + 1] && j >= 0; --j)
                        std::swap(arr[j], arr[j + 1]);
                }
                choise_type_sort = true;
                break;
            }
            default: {
                std::cout << "\nSort type of array element values is entered incorrectly.\n";
                choise_type_sort = false;
                break;
            }
        }
    } while (!choise_type_sort); // repeat the sort type selection until the correct type is entered
    Abstract::DisplayTheValues();
}

void Selection::SortArr() { // overloading the virtual method of sorting an array of Abstract class by sorting by choice
    int choise = 0;
    bool swap_is = false, choise_type_sort = true;
    do {
        std::cout << "\nChoose the type of data sorting: 1 - ascending, 2 - descending: ";
        std::cin >> choise;
        switch (choise) {
            case 1: {
                for (int k = 0; k < size - 1; ++k) { // сортировка arr[] методом выбора по возрастанию
                    for (int j = k + 1; j < size; ++j)
                        if (arr[k] > arr[j])
                            std::swap(arr[k], arr[j]);
                }
                choise_type_sort = true;
                break;
            }
            case 2: {
                for (int k = 0; k < size - 1; ++k) { // sort arr[] ascending selection method
                    for (int j = k + 1; j < size; ++j)
                        if (arr[k] < arr[j])
                            std::swap(arr[k], arr[j]);
                }
                choise_type_sort = true;
                break;
            }
            default: {
                std::cout << "\nSort type of array element values is entered incorrectly.\n";
                choise_type_sort = false;
                break;
            }
        }
    } while (!choise_type_sort); // repeat the sort type selection until the correct type is entered
    Abstract::DisplayTheValues();
}

void Shaker::SortArr() { // overloading the virtual method for sorting an Abstract class array by shaker sorting
    int choise = 0;
    bool swap_is = false, choise_type_sort = true;
    do {
        std::cout << "\nChoose the type of data sorting: 1 - ascending, 2 - descending: ";
        std::cin >> choise;
        switch (choise) {
            case 1: {
                for (int i = 0; i < size; ++i) { // sort arr[] shaker method ascending
                    for (int m = 0; m < size - i - 1; ++m) {
                        if (arr[m] > arr[m + 1]) {
                            std::swap(arr[m], arr[m + 1]);
                            swap_is = true;
                        }
                    }
                    for (int m = size - i; m > 0 - 1; --m) {
                        if (arr[m] < arr[m - 1]) {
                            std::swap(arr[m], arr[m - 1]);
                            swap_is = true;
                        }
                    }
                    if (!swap_is)
                        break;
                }
                choise_type_sort = true;
                break;
            }
            case 2: {
                for (int i = 0; i < size; ++i) { // sort arr[] by shaker method in descending order
                    for (int m = 0; m < size - i - 1; ++m) {
                        if (arr[m] < arr[m + 1]) {
                            std::swap(arr[m], arr[m + 1]);
                            swap_is = true;
                        }
                    }
                    for (int m = size - i; m > 0 - 1; --m) {
                        if (arr[m] > arr[m - 1]) {
                            std::swap(arr[m], arr[m - 1]);
                            swap_is = true;
                        }
                    }
                    if (!swap_is)
                        break;
                }
                choise_type_sort = true;
                break;
            }
            default: {
                std::cout << "\nSort type of array element values is entered incorrectly.\n";
                choise_type_sort = false;
                break;
            }
        }
    } while (!choise_type_sort); // repeat the sort type selection until the correct type is entered
    Abstract::DisplayTheValues();
}

int Abstract::arr[10] = {}; // definition of a static array member of the Abstract class (which is not a member of an array of an individual class object, but a static array,
// accessible for use by the methods of the base and derived classes without specifying a specific object of the base or derived class for accessing the array

int main() {
    setlocale(LC_ALL, "RUS");
    srand(time(0));
    int choise = 0, global_choise = 0, number = 0;
    bool *type_of_sort = new bool(true), *vosvrat = new bool(false), *sort_is = new bool(
            false); // Create a pointer to a variable in the heap to track the selection of the sorting method
    mitka:
    Abstract *rpointer = new Abstract; // create a pointer to an object of class Abstract and assign it a cell address in the dynamic memory area (heap)
    do {
        std::cout << "\nChoose how to fill the array: 1 - random values, 2 - manually: ";
        std::cin >> choise;
        rpointer->CreateArr(
                choise); // call function to select the method of filling the array through a pointer to the object Abstract
        *sort_is = false;
    } while (!rpointer->Get_sort_result()); // Run the loop until you enter the correct way to fill the array

    rpointer->DisplayTheValues(); // output of array elements

    delete rpointer; // Remove an Abstract object from the heap (to avoid memory leaks from the heap)
    rpointer = 0; // zeroing the address of a pointer to an object of class Abstract

    do {
        sort_next:
        std::cout << "\nSelect the type of task to be performed: 1 - Sort, 2 - Search, 3 - Back: ";
        std::cin >> global_choise;

        switch (global_choise) {
            case 1: {
                do // -------------------------SORT----------------------------------
                {
                    std::cout
                            << "\nSelect the sorting type for the elements of the array: 1 - bubble, 2 - insert, 3 - select, 4 - shaker, 5 - return to the previous menu: ";
                    std::cin >> choise;
                    *type_of_sort = true;
                    switch (choise) {
                        case 1: {
                            rpointer = new Bubble;
                            rpointer->SortArr();
                            break;
                        }
                        case 2: {
                            rpointer = new Insert;
                            rpointer->SortArr();
                            break;
                        }
                        case 3: {
                            rpointer = new Selection;
                            rpointer->SortArr();
                            break;
                        }
                        case 4: {
                            rpointer = new Shaker;
                            rpointer->SortArr();
                            break;
                        }
                        case 5: {
                            *vosvrat = true;
                            break;
                        }
                        default: {
                            std::cout << "\nSort type of array element values is entered incorrectly.\n";
                            *type_of_sort = false;
                            break;
                        }
                    }
                } while (!*type_of_sort && *vosvrat ==
                                           false); // Perform a loop until the correct method for sorting the array is entered
                *sort_is = true;
                break;
            }
            case 2: {
                if (*sort_is == false) {
                    std::cout
                            << "\nThe value of the elements of the array is not sorted. Please pre-sort the array before searching for the selected item.\n";
                    goto sort_next;
                }
                // --------------------------------------SEARCH
                std::cout << "\nEnter an integer value to search for an array element: ";
                std::cin >> number;

                do {
                    std::cout
                            << "\nSelect the method of searching for the element of the array: 1 - linear, 2 - binary: ";
                    std::cin >> choise;
                    switch (choise) {
                        case 1:
                        case 2: {
                            rpointer->FindArr(number, choise);
                            *type_of_sort = true;
                            break;
                        }
                        default: {
                            std::cout
                                    << "\nThe method for finding the selected array element was entered incorrectly.\n";
                            *type_of_sort = false;
                            break;
                        }
                    }
                } while (!*type_of_sort);
                break;
            }
            case 3: {
                goto mitka;
                break;
            }
            default: {
                std::cout << "\nThe entered selection does not match the menu options\n";
                break;
            }
        }
    } while (global_choise != 1 || global_choise != 2 || global_choise != 3);

    // delete objects and variables allocated in dynamic memory (heap) and nullify the addresses of pointers to objects and variables in the dynamic memory
    delete rpointer;
    rpointer = 0;
    delete type_of_sort;
    type_of_sort = 0;
    delete vosvrat;
    vosvrat = 0;
    delete sort_is;
    sort_is = 0;

    system("pause");
    return 0;
}

/*
DESCRIPTION:
When writing the executable, the following features of the C ++ language were used:

Lines 5-18 declare the Abstract class, which contains virtual functions, the definition of which will be overloaded in derived classes.
In addition, the class Abstract declaratively declares a constructor. The class destructor is declared virtual, since the class contains virtual functions, which defines
The need to use only a virtual destructor (in contrast to the simple destructor provided by the compiler by default).
In the class description, the CreateArr (int) method is declared, the definition of which is in lines 48-72. This method takes integer values ​​and fills an array
at the user's choice (randomly or manually).

In addition, the inline method Get_sort_result () (inline method) of the Abstract class is located in line 10 (definition of the inline method, in contrast to the usual function without
the keyword inline is inserted directly into the place of its call. In this case, the inline keyword should be used because of the content
definition of the method of just one expression, which does not greatly affect the decrease in the productivity of the entire program.) This function returns the value
a member of the sort_result member that has a protected access specifier that provides access to a variable to only the methods of the base and derived classes.

In line 11, the empty virtual function void SortArr () is declared and defined. This function is not declared purely virtual (virtual void SortArr () = 0 in connection with
in that when the program is executed, an object of the Abstract class is created, which is not permissible for purely virtual classes that contain one or more purely virtual
functions. This virtual function is overloaded in the derived classes Bubble (117-161), Insert (163-195), Selection (197-231), Shaker (233-289).
The essence of overloading this function is the call of different methods for sorting the elements of the array through pointers to the object of the corresponding derived class (polymorphism).

In line 12 of the definition of public methods of the Abstract class, there is a definition of the void FindArr (int, int) method, whose definition is located on lines 74-109.
This method takes the value of the search method and the integer value as arguments to search for matches on the elements of the arr [] array.

Line 13 shows the declaration of the void DisplayTheValues ​​() function, which displays the value of the array elements on the screen. The definition of this method is in lines
111-115.

Lines 15-17 specify the data members of the Abstract class that are available for use by the base and derived class methods (heritage principle), but are not available
for other program methods (encapsulation). It is worth paying attention to the array-member int arr [10], in the declaration of which the keyword static was used, that
It allows to use it not separately for each object of the base or derived class, but in general all objects of the base and derived classes
one specific static array member of the class. The definition of a static array member of the Abstract class is specified in line 291.

Lines 20-46 contain declarations of derived classes Bubble {}; Insert {}; selection {}; Shaker {}, which contain the declaration of the overloaded SortArr () method,
as well as the constructor and destructor.

In line 294, the main function of the program is executed.
In line 298 there is a definition of pointers to values ​​of type bool from the dynamic memory area of ​​the computer. Using pointers to values ​​of type bool in the heap
is dictated by purely practical goals of gaining the skills of using computer's dynamic memory when writing programs in C ++. Subsequent release
dynamic memory and zeroing addresses of pointers pointing to the memory participant's data before the end of the program in lines 402-409.
Although at the end of the program execution, the dynamic memory areas will be automatically released, but self-release of memory in the heap is
a good programming tone and beyond that, it anticipates the occurrence of possible errors in the subsequent development of the program.

In line 300 of main, a pointer is created to an object of class Abstract, which is assigned a memory address in the heap allocated to store the value of the specified
type of data.

In lines 301-307, a choice is made of how to fill the array. So, in line 240, the Abstract :: CreateArr (int) method is called, the argument of which determines
subsequent execution of the method body. Access to the specified method of an object of the Abstract class is done through a pointer to the object created and defined
in line 300.

In line 309, the value of the elements of the static array of the Abstract class is output after the latter is filled in by the Abstract :: CreateArr (int) method in line 305.

Lines 311-312 release memory on the heap and reset the address of the pointer in connection with the absence of the subsequent need to use
given heap resources.

In lines 314-399, you select the type of action to be performed. Just note that in view of the poor architecture of the program in line 391 was used
the goto keyword to return to the previous menu (line 299).

In addition, lines 322-358 create a pointer to an object of the appropriate data type (Bubble, Insert, Selection, Shaker) and
the subsequent call through the pointer of the corresponding type of the overloaded function SortArt () (329, 334, 339, 344). So, when you call an overloaded method through a pointer
of the corresponding derived type, the virtual function table of the v-table compiler determines the type of value stored at the specified pointer to rpointer address
(264? 269? 274) and causes the corresponding overloaded member function.

In lines 372-387, a number is selected for searching (374), sorting type (383), and then passing arguments to the FindArr method (line 377).
In the definition of the function Abstract :: FindArr (int, int), the subsequent algorithm of the function for searching and displaying the desired value (74-109) is indicated.


In line 391, the goto statement was used to return to line 299. (because of poorly designed program architecture).
*/



