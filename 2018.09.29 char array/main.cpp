/*
Mark all the desired projects in solution explorer.

Press Alt-F7 or right click in solution explorer and select "Properties"

Configurations:All Configurations

Click on the Preprocessor Definitions line to invoke its editor

Choose Edit...

Copy "_CRT_SECURE_NO_WARNINGS" into the Preprocessor Definitions white box on the top.
*/
#include <iostream>

using namespace std;

char** CreateArr(int); // creating a two-dimensional dynamic array
void InputWords(char**, int); // input words
void OutputWords(char**, int); // output words
void OutputWords2(char**, int); // output words, which have the same first and last letters
void OutputWords3(char** pArr, int numbers); // output words, which have more than two vowels
void OutputWords4(char**, int); // output all words, rejecting the first and last letter of words
int main()
{
	// Task 1
	cout << "Task 1\nPlease enter the number of words: ";
	int numbers;
	cin >> numbers;
	char** pArr = CreateArr(numbers);  // creating a two-dimensional dynamic array
	InputWords(pArr, numbers);  // input words
	OutputWords(pArr, numbers); // output words
	cout << "\nTask 2\nWords, which having the same first and last letters: ";
	OutputWords2(pArr, numbers); // output words, which have the same first and last letters
	cout << "\nTask 3\nWords, which have more than two vowels: ";
	OutputWords3(pArr, numbers); // output words, which have more than two vowels
	cout << "\nTask 4\nAll words, rejecting the first and last letter of words: ";
	OutputWords4(pArr, numbers); // All words, rejecting the first and last letter of words

	system("pause");
	return 0;
}

char** CreateArr(int numbers) { // creating a two-dimensional dynamic array
	char** pArr = new char*[numbers];
	for (int i = 0; i < numbers; ++i)
		pArr[i] = new char[20];
	return pArr;
}

void InputWords(char** pArr, int numbers) { // input words
	cout << "\nPlease enter " << numbers << " words and <Enter>: ";
	char ch[20];
	for (int i = 0; i < numbers; ++i) {
		cin >> ch;
		int j = -1;
		while (ch[++j] != '\0') // copying an array of characters to the terminating zero character
			(pArr[i])[j] = ch[j];
		(pArr[i])[j] = '\0';
	}
}

void OutputWords(char** pArr, int numbers) { // output words
	for (int i = 0; i < numbers; ++i)
		cout << pArr[i] << ' ';
	cout << "\n";
}

void OutputWords2(char** pArr, int numbers) { // output words, which have the same first and last letters
	for (int i = 0, j = 0; i < numbers; ++i) {
		while ((pArr[i])[++j] != '\0'); // search index of trailing zero character
		if ((pArr[i])[j - 1] == (pArr[i])[0])
			cout << pArr[i] << ' ';
		j = 0;
	}
	cout << "\n";
}

void OutputWords3(char** pArr, int numbers) { // output words, which have more than two vowels
	for (int i = 0, j = -1, vowels = 0; i < numbers; ++i) {
		while ((pArr[i])[++j] != '\0') // search index of trailing zero character
			if ((pArr[i])[j - 1] == 'A' || (pArr[i])[j - 1] == 'a' ||
				(pArr[i])[j - 1] == 'E' || (pArr[i])[j - 1] == 'e' ||
				(pArr[i])[j - 1] == 'I' || (pArr[i])[j - 1] == 'i' ||
				(pArr[i])[j - 1] == 'O' || (pArr[i])[j - 1] == 'o' ||
				(pArr[i])[j - 1] == 'U' || (pArr[i])[j - 1] == 'u' ||
				(pArr[i])[j - 1] == 'Y' || (pArr[i])[j - 1] == 'y')
				++vowels;
		if (vowels > 2)
			cout << pArr[i] << ' ';
		j = -1, vowels = 0;
	}
	cout << "\n";
}

void OutputWords4(char** pArr, int numbers) { // output all words, rejecting the first and last letter of words
	char str[20] = { ' ' };
	char strlong[100] = {0};
	for (int i = 0, j = 0; i < numbers; ++i) {
		while ((pArr[i])[++j] != '\0') // search index of trailing zero character
			str[j - 1] = (pArr[i])[j];
		str[j - 2] = '\0';
		strcat(strlong, " ");
		strcat(strlong, str);
		j = 0;
	}
	cout << strlong << '\n';
	//delete[] strlong;
	//strlong = NULL;
}
