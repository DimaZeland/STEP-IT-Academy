#include "MyClass.h"

void
MyClass::BubbleSortFall(int size) { // sorting the array by degeneration
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size - 1; ++j)
            if (Arr[j] < Arr[j + 1]) {
                std::swap(Arr[j], Arr[j + 1]);
                ++itsAteration;
            }
}

void
MyClass::BubbleSortGrowth(int size) { // sort an array in ascending order
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size - 1; ++j)
            if (Arr[j] > Arr[j + 1]) {
                std::swap(Arr[j], Arr[j + 1]);
                ++itsAteration;
            }
}


void
MyClass::FillArray(int size) { // fill an array
    for (int i = 0; i < size; ++i)
        Arr[i] = Arr2[i] = Arr[3] = rand() % 10;
}

int
MyClass::FindIndex(const int *arr_test, int &value, int size) const { // array element index search
    for (int i = 0; i < size; ++i)
        if (arr_test[i] == value)
            return i;
    return -1;
}

void
MyClass::OutPutArray(int size) const { // output the array
    for (int i = 0; i < size; ++i)
        cout << i << ' ' << Arr[i] << '\n';
}

void
MyClass::SortInsertFall(int size) { // sorting the array by inserting it fall
    for (int i = 0; i < size; ++i)
        for (int j = i; j > 0 && Arr2[j - 1] > Arr2[j]; --j) {
            std::swap(Arr2[j - 1], Arr2[j]);
            ++itsAteration;
        }
}

void
MyClass::SortInsertGrowth(int size) { // sorting the array by inserting it growth
    for (int i = 0; i < size; ++i)
        for (int j = i; j > 0 && Arr2[j - 1] < Arr2[j]; --j) {
            std::swap(Arr2[j - 1], Arr2[j]);
            ++itsAteration;
        }
}

void
MyClass::SortSelectionFall(int size) { // sorting the array by selection it (Fall)
    for (int i = 0; i < size; ++i)
        for (int j = i + 1; j < size; ++j)
            if (Arr3[i] < Arr3[j]) {
                std::swap(Arr3[i], Arr3[j]);
                ++itsAteration;
            }
}

void
MyClass::SortSelectionGrowth(int size) { // sorting the array by selection it (Growth)
    for (int i = 0; i < size; ++i)
        for (int j = i + 1; j < size; ++j)
            if (Arr3[i] > Arr3[j]) {
                std::swap(Arr3[i], Arr3[j]);
                ++itsAteration;
            }
}

