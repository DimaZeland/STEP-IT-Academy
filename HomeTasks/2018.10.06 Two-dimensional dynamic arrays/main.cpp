#include<ctime>
#include<iostream>

using std::cout;
using std::cin;
using std::endl;

enum ArrayEnum {
    COLUMNS = 5, LINES = 5
};

template<typename T>
void FillArray(T[], const int, const int); // fill two-dimensional array
template<typename T>
void OutPutArray(T[], const int, const int); // output two-dimensional array
template<typename T>
void SortArray(T[], const int, const int); // Growth sorting by a bubble method of two-dimensional array
template<typename T>
void LinesOffset(T[], int, int); // lines offset
template<typename T>
void ColumnsOffset(T[], int, int); // columns offset

int main() {
    srand(time(0));
    int ArrInt[COLUMNS][LINES] = {}; // static two-dimensional array
    int **ArrInt1 = new int *[COLUMNS]; // denamic two-dimensional array
    for (int i = 0; i < LINES; ++i)
        ArrInt1[i] = new int[5];

    cout << "\nTask1\n";
    cout << "\nFillArray\n";
    FillArray(ArrInt1, COLUMNS, LINES);
    cout << "\nOutPutArray\n";
    OutPutArray(ArrInt1, COLUMNS, LINES);
    cout << "\nSortArray\n";
    SortArray(ArrInt1, COLUMNS, LINES);
    cout << "\nOutPutArray\n";
    OutPutArray(ArrInt1, COLUMNS, LINES);
    cout << "\nTask2\n";
    cout << "\nLinesOffset\n";
    cout << "\nenter line numbers to replace their item values: ";
    int a = 0, b = 0;
    cin >> a >> b;
    LinesOffset(ArrInt1, a, b);
    cout << "\nOutPutArray\n";
    OutPutArray(ArrInt1, COLUMNS, LINES);
    cout << "\nColumnsOffset\n";
    cout << "\nenter column numbers to replace their item values: ";
    cin >> a >> b;
    ColumnsOffset(ArrInt1, a, b);
    cout << "\nOutPutArray\n";
    OutPutArray(ArrInt1, COLUMNS, LINES);

    for (int i = 0; i < LINES; ++i) { // release of memory allocated for storing a two-dimensional dynamic array
        delete[] ArrInt1[i];
        ArrInt1[i] = NULL;
    }
    delete[]ArrInt1;
    system("pause");
    return 0;
}

template<typename T>
void
FillArray(T itsArr[], const int column, const int line) { // fill two-dimensional array
    for (int i = 0; i < column; ++i)
        for (int j = 0; j < line; ++j)
            itsArr[i][j] = rand() % 10;
}

template<typename T>
void
OutPutArray(T itsArr[], const int column, const int line) { // output two-dimensional array
    for (int i = 0; i < column; ++i) {
        for (int j = 0; j < line; ++j)
            cout << ' ' << itsArr[i][j] << ' ';
        cout << '\n';
    }
}

template<typename T>
void
SortArray(T itsArr[], const int column, const int line) { // Growth sorting by a bubble method of two-dimensional array
    for (int i = 0; i < column; ++i)
        for (int j = 0; j < line; ++j) // index formation of the current item
            for (int k = i; k < column; ++k) { // row walk
                int m = (i == k) ? j : -1; // accounting of the passage of the current and next lines
                for (; m < line - 1; ++m) // column walk
                    if (itsArr[i][j] > itsArr[k][m + 1])
                        std::swap(itsArr[i][j], itsArr[k][m + 1]);
            }
}

template<typename T>
void
LinesOffset(T itsArr[], int line1, int line2) { // lines offset
    for (int i = 0; i < COLUMNS; ++i)
        std::swap(itsArr[line1][i], itsArr[line2][i]);
}

template<typename T>
void
ColumnsOffset(T itsArr[], int column1, int column2) { // columns offset
    for (int i = 0; i < LINES; ++i)
        std::swap(itsArr[i][column1], itsArr[i][column2]);
}