#include "MyClass.h"

void
MyClass::CharacterCount() const { // character count by type

    cout << "\nEnter first string: ";
    std::string str, str1;
    cin >> str;
    cin.get();
    cout << "\nEnter second string: ";
    cin.get();
    cin >> str1;
    cin.get();
    cin.get();
    char *first = &str[0], *second = &str1[0];
    int digits = 0, alpha = 0, punkt = 0;
    for (int i = 0; i < str.size(); ++i) {
        //isupper(str[i]) ? str[i] = tolower(str[i]) : str[i] = toupper(str[i]); //change the case of words
        if (isalpha(str[i]))
            ++alpha;
        else if (isdigit(str[i]))
            ++digits;
        else if (ispunct(str[i]))
            ++punkt;
    }
    //str1 = cin.getline(strstr(first, second),str1.size());
    //_strupr_s(first, 10); // all characters in string to upper
    //_strlwr_s(first, 10); all characters in string to lower
    //strset( first, 'a'); // sets all characters of the specified string
    //strcmp(first, first); // return -1 if strlen(first) < strlen(second), return 0 if first == second, return 1 if first > second;
    cout << "\nThere are " << alpha << " characters, " << digits << " digits, " << punkt << " puncts in string " << str
         << '\n';
    cout << strstr(first, second)
         << '\n'; // return the adress the first symbol in second string which is identical with symbol of first string
    //strcat(char* one, char* two); // concatenation of two lines
}

void
MyClass::EditingWord() const { // editing a sentence

    cout << "\nEnter the sentence:";
    char str[50] = {" \0"};
    cin.getline(str, 50);
    cout << "\nEnter the word: ";
    char word[50];
    cin >> word;
    int i = 0;
    char second[50];
    for (; &str[i] != strstr(str, word); ++i)
        second[i] = str[i];
    int j = i;
    i += strlen(word);
    for (; i < strlen(str); ++i, ++j)
        second[j] = str[i];
    cout << second << endl;
}

void
MyClass::SortArray() const { // division of the array into two (with the pair elements and unpaired ones)

    cout << "\nEnter the numbers of elements of array A[]: ";
    int size;
    int pair = 0, notpair = 0;
    cin >> size;
    int *pA = new int[size];


    cout << "\nArray[" << size << "]:\n";
    for (int i = 0; i < size; ++i) { // search for the size of a pair and unpaired array
        pA[i] = rand() % 10;
        cout << pA[i] << ' ';
        0 == pA[i] % 2 ? ++pair : ++notpair;
    }
    cout << endl;

    int *pPair = new int[pair];
    int *pNotPair = new int[notpair];

    for (int i = 0, j = 0, k = 0; i < size; ++i) // filling in arrays
        if (0 == pA[i] % 2) {
            pPair[j] = pA[i];
            ++j;
        } else {
            pNotPair[k] = pA[i];
            ++k;
        }

    cout << "\nPair[" << pair << "]:\n";
    for (int i = 0; i < pair; ++i) //
        cout << pPair[i] << ' ';
    cout << endl;

    cout << "\nNotPair[" << notpair << "]:\n";
    for (int i = 0; i < notpair; ++i) //
        cout << pNotPair[i] << ' ';
    cout << endl;

    delete pA, pPair, pNotPair;
    pA = NULL, pPair = NULL, pNotPair = NULL;
}