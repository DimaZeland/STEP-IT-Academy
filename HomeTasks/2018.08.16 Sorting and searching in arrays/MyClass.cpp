#include "MyClass.h"

void
MyClass::ArgDiagonal(const ushort &itsFirst, const ushort &itsSecond) const { // Average of Diagonal of Arr[][]
    volatile float sum = 0;
    volatile float flag = 0;
    for (ushort i = 0; i < itsFirst; ++i) {
        flag = Arr[i][i];
        sum += Arr[i][i];
        flag = Arr[i][itsFirst - 1 - i];
        sum += Arr[i][itsFirst - 1 - i];
    }
    sum /= 2;
    cout << "Average diagonale of Arr[][[]/2: " << sum;
}

void
MyClass::FindLastMax(const ushort &itsFirst, const ushort &itsSecond) const { // Find Last Local Max Value
    ushort *pNumber = new ushort(0); // local maximum value

    ushort a1 = 0, a2 = 0; // indices of the last local extremum

    ushort im1jm1 = 0, // the value of the element up and to the left of the local maximum
    im1j = 0, // the value of the element up from the local maximum
    im1jp1 = 0, // the value of the element up and to the right of the local maximum
    ijm1 = 0, // the value of the element to the left of the local maximum
    ijp1 = 0, // the value of the element to the right of the local maximum
    ip1jm1 = 0, // the value of the element down and to the left of the local maximum
    ip1j = 0, // the value of the element down from the local maximum
    ip1jp1 = 0; // the value of the element down and to the right of the local maximum

    for (ushort i = 0; i < itsFirst; ++i)
        for (ushort j = 0; j < itsSecond; ++j) {
            // determine the values of neighboring elements from the extremum
            im1jm1 = (i - 1 >= 0 && j - 1 >= 0) ? Arr[i - 1][j - 1] : 0;
            im1j = (i - 1 >= 0) ? Arr[i - 1][j] : 0;
            im1jp1 = (i - 1 >= 0 && j + 1 < itsSecond) ? Arr[i - 1][j + 1] : 0;
            ijm1 = (j - 1 >= 0) ? Arr[i][j - 1] : 0;
            ijp1 = (j + 1 < itsSecond) ? Arr[i][j + 1] : 0;
            ip1jm1 = (i + 1 < itsFirst && j - 1 >= 0) ? Arr[i + 1][j - 1] : 0;
            ip1j = (i + 1 < itsFirst) ? Arr[i + 1][j] : 0;
            ip1jp1 = (i + 1 < itsFirst && j + 1 < itsSecond) ? Arr[i + 1][j + 1] : 0;

            // Verify the validity of the conditions for determining the local extremum
            if (Arr[i][j] > im1jm1 && Arr[i][j] > im1j && Arr[i][j] > im1jp1 && Arr[i][j] > ijm1 &&
                Arr[i][j] > ijp1 && Arr[i][j] > ip1jm1 && Arr[i][j] > ip1j && Arr[i][j] > ip1jp1) {
                *pNumber = Arr[i][j];
                a1 = i, a2 = j;
            }
        }

    cout << "\nThe last local extremum in the array Arr[" << MyClass::itsFirst << "][" << MyClass::itsSecond
         << "] has the meaning " <<
         *pNumber << ".\n and is placed by indices Arr[" << a1 << "][" << a2 << "].\n";

    delete pNumber;
    pNumber = NULL;
}

ushort
MyClass::FindNumber(const ushort &itsFirst, const ushort &itsSecond) const { // Find Most Popular Number
    ushort Arr1[10]{};
    ushort *pNumber = new ushort(0);

    for (ushort i = 0; i < itsFirst; ++i)
        for (ushort j = 0; j < itsSecond; ++j)
            Arr1[Arr[i][j]]++;

    for (ushort i = 0; i < 10; ++i)
        if (*pNumber < Arr1[i])
            *pNumber = i;

    return *pNumber;
}

void
MyClass::FindSumTwoMax(const ushort &itsFirst, const ushort &itsSecond) const { // Find Sum 2 Max Number
    ushort *pNumber = new ushort(0);
    ushort a1 = 0, a2 = 0, a3 = 0, a4 = 0;

    for (ushort i = 0; i < itsFirst - 1; ++i)
        for (ushort j = 0; j < itsSecond - 1; ++j) {
            if (*pNumber < Arr[i][j] + Arr[i][j + 1]) {
                *pNumber = Arr[i][j] + Arr[i][j + 1];
                a1 = i, a2 = j, a3 = i, a4 = j + 1;
            }
            if (*pNumber < Arr[i][j] + Arr[i + 1][j]) {
                *pNumber = Arr[i][j] + Arr[i + 1][j];
                a1 = i, a2 = j, a3 = i + 1, a4 = j;
            }
        }

    cout << "\nSum of Two Max Number in Arr[" << MyClass::itsFirst << "][" << MyClass::itsSecond << "] is " <<
         *pNumber << ".\nFirst element is Arr[" << a1 << "][" << a2 << "].\nSecond Element is Arr[" << a3 << "][" << a4
         << "].\n";
}

void
MyClass::SetArr(const ushort &itsFirst, const ushort &itsSecond) { // set the value of Arr[][]
    for (ushort i = 0; i < itsFirst; ++i)
        for (ushort j = 0; j < itsSecond; ++j)
            Arr[i][j] = rand() % 10;
}

void
MyClass::SortGrowArr(const ushort &itsFirst, const ushort &itsSecond) { // grow sort element of stroka Arr[][]
    for (ushort i = 0; i < itsFirst; ++i)
        for (ushort j = 0; j < itsSecond - 1; ++j)
            for (ushort k = j; k < itsSecond - 1; ++k)
                if (Arr[i][k + 1] < Arr[i][j])
                    std::swap(Arr[i][k + 1], Arr[i][j]);
}

void
MyClass::ShowArr(const ushort &itsFirst, const ushort &itsSecond) const { // show the value of Arr[][]
    for (ushort i = 0; i < itsFirst; ++i) {
        for (ushort j = 0; j < itsSecond; ++j)
            cout << Arr[i][j] << " ";
        cout << '\n';
    }
}