#include "MyClass.h"

void
MyClass::Task1() const {

    // Task 1
    cout << "\nTask 1\n";
    cout << "\nEnter the number of elements in the first and second array: \n";
    int M, N;
    cin >> M >> N;
    int *pA = new int[M], *pB = new int[N];
    cout << "\nA[" << M << "]: ";
    for (int i = 0; i < M; ++i) { // filling the values of the elements of the first array
        pA[i] = i + 1;
        cout << pA[i] << ' ';
    }
    cout << "\nB[" << N << "]: ";
    for (int i = 0; i < N; ++i) { // filling the values of the elements of the second array
        pB[i] = (i + 1) * 2;
        cout << pB[i] << ' ';
    }
    int size = M; // number of elements of the third array
    for (int i = 0; i < M; ++i)
        for (int j = 0; j < N; ++j)
            if (pA[i] == pB[j]) {
                --size; // if there is an element with the same value, - reduce the size of the array by one
                pA[i] = pB[0];
            }
    if (0 == size)
        cout << "\nAll elements of array A are included in the array B\n";
    else {
        cout << "\nC[" << size << "]: ";
        int *pC = new int[size];
        for (int i = 0, j = 0; i < M; ++i)
            if (pA[i] != pB[0]) {
                pC[j] = pA[i];
                cout << pC[j] << ' ';
                ++j;
            }
        cout << '\n';
        delete[]pC;
        pC = NULL;
    }
    delete[]pA, delete[]pB;
    pA = NULL, pB = NULL;
}

void
MyClass::Task2() const {

    // Task 2
    cout << "\nTask 2\n";
    cout << "\nEnter the number of elements in the first and second array: \n";
    int M, N;
    cin >> M >> N;
    int *pA = new int[M], *pB = new int[N];
    cout << "\nA[" << M << "]: ";
    for (int i = 0; i < M; ++i) { // filling the values of the elements of the first array
        pA[i] = i + 1;
        cout << pA[i] << ' ';
    }
    cout << "\nB[" << N << "]: ";
    for (int i = 0; i < N; ++i) { // filling the values of the elements of the second array
        pB[i] = (i + 1) * 2;
        cout << pB[i] << ' ';
    }
    int size = M + N; // number of elements of the third array
    int buf = -1; // buffer
    for (int i = 0; i < M; ++i)
        for (int j = 0; j < N; ++j)
            if (pA[i] == pB[j]) {
                size -= 2; // if there is an element with the same value, - reduce the size of the array by one
                pA[i] = pB[j] = buf;
            }
    if (0 == size)
        cout << "\nIn arrays A[] and B[] there are no elements that are not common to them\n";
    else {
        cout << "\nC[" << size << "]: ";
        int *pC = new int[size];
        int j = 0;
        for (int i = 0; i < M; ++i)
            if (pA[i] != buf) {
                pC[j] = pA[i];
                cout << pC[j] << ' ';
                ++j;
            }
        for (int i = 0; i < N; ++i)
            if (pB[i] != buf) {
                pC[j] = pB[i];
                cout << pC[j] << ' ';
                ++j;
            }
        cout << '\n';
        delete[]pC;
        pC = NULL;
    }
    delete[]pA, delete[]pB;
    pA = NULL, pB = NULL;
}

void
MyClass::Task3() const {

    // Task 3
    cout << "\nTask 3\n";
    cout << "\nEnter the number of elements in the first and second array: \n";
    int M, N;
    cin >> M >> N;
    int *pA = new int[M], *pB = new int[N];
    cout << "\nA[" << M << "]: ";
    for (int i = 0; i < M; ++i) { // filling the values of the elements of the first array
        pA[i] = i + 1;
        cout << pA[i] << ' ';
    }
    cout << "\nB[" << N << "]: ";
    for (int i = 0; i < N; ++i) { // filling the values of the elements of the second array
        pB[i] = (i + 1) * 2;
        cout << pB[i] << ' ';
    }
    int size = M + N; // number of elements of the third array
    cout << "\nC[" << size << "]: ";
    int *pC = new int[size];
    int j = 0;
    for (int i = 0; i < M; ++i) {
        pC[j] = pA[i];
        cout << pC[j] << ' ';
        ++j;
    }
    for (int i = 0; i < N; ++i) {
        pC[j] = pB[i];
        cout << pC[j] << ' ';
        ++j;
    }
    cout << '\n';
    delete[]pC;
    pC = NULL;
    delete[]pA, delete[]pB;
    pA = NULL, pB = NULL;
}

void
MyClass::Task4() const {

    // Task 4
    cout << "\nTask 4\n";
    cout << "\nEnter the number of elements in the first and second array: \n";
    int M, N;
    cin >> M >> N;
    int *pA = new int[M], *pB = new int[N];
    cout << "\nA[" << M << "]: ";
    for (int i = 0; i < M; ++i) { // filling the values of the elements of the first array
        pA[i] = i + 1;
        cout << pA[i] << ' ';
    }
    cout << "\nB[" << N << "]: ";
    for (int i = 0; i < N; ++i) { // filling the values of the elements of the second array
        pB[i] = (i + 1) * 2;
        cout << pB[i] << ' ';
    }
    int size = 0; // number of elements of the third array
    int buf = -1; // buffer
    bool flag = true;
    if (M < N)
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j)
                if (pA[i] == pB[j]) {
                    ++size; // if there is an element with the same value, - increase the size of the array by one
                    flag = false;
                    break;
                }
            flag ? pA[i] = buf : flag = true; // reset the value of the element, if there are no matches
        }
    else
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j)
                if (pB[i] == pA[j]) {
                    ++size; // if there is an element with the same value, - increase the size of the array by one
                    flag = false;
                    break;
                }
            flag ? pB[i] = buf : flag = true; // reset the value of the element, if there are no matches
        }

    if (0 == size)
        cout << "\nIn arrays A[] and B[] there are no common elements\n";
    else {
        cout << "\nC[" << size << "]: ";
        int *pC = new int[size];

        if (M < N) {
            for (int i = 0, j = 0; i < M; ++i)
                if (pA[i] != buf) {
                    pC[j] = pA[i];
                    cout << pC[j] << ' ';
                    ++j;
                }
        } else
            for (int i = 0, j = 0; i < N; ++i)
                if (pB[i] != buf) {
                    pC[j] = pB[i];
                    cout << pC[j] << ' ';
                    ++j;
                }
        cout << '\n';
        delete[]pC;
        pC = NULL;
    }
    delete[]pA, delete[]pB;
    pA = NULL, pB = NULL;
}

void
MyClass::Task5() const {

    // Task 5
    cout << "\nTask 5\n";
    cout << "\nEnter the number of elements in the array: \n";
    int M, value;
    cin >> M;
    int *pA = new int[M];
    cout << "\nEnter the values of the elements in the array A[" << M << "]: ";
    for (int i = 0; i < M; ++i) { // filling the values of the elements of the first array
        cin >> value;
        pA[i] = value;
    }
    cout << "\nEnter 1 to delete odd values and 2 to delete even values: ";
    cin >> value;
    int size = M, buf = -1; // number of elements of the second array
    switch (value) {
        case 1: {
            for (int i = 0; i < M; ++i)
                if (pA[i] % 2) {
                    pA[i] = buf;
                    --size;
                }
            break;
        }
        case 2: {
            for (int i = 0; i < M; ++i)
                if (!(pA[i] % 2)) {
                    pA[i] = buf;
                    --size;
                }
            break;
        }
        default:
            cout << "\nInvalid choise\n";
            break;
    }

    if (0 == size)
        cout << "\nIn arrays A[] there are no elements, which are satisfying the selection condition\n";
    else {
        cout << "\nC[" << size << "]: ";
        int *pC = new int[size];
        for (int i = 0, j = 0; i < M; ++i)
            if (pA[i] != buf) {
                pC[j] = pA[i];
                cout << pC[j] << ' ';
                ++j;
            }
        cout << endl;
    }
    delete[]pA;
    pA = NULL;
}