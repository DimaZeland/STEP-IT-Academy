#include<iostream>
#include<fstream>
#include<string>
//#include"Builder.h"

void EncryptFile(std::string fileName);
void DecryptFile(std::string fileName);

int main() {
	EncryptFile("C:\\Users\\User\\source\\repos\\HomeTask\\HomeTask\\Text.txt");
	DecryptFile("C:\\Users\\User\\source\\repos\\HomeTask\\HomeTask\\TextEncrypt.txt");

	system("pause");
	return 0;
}

void EncryptFile(std::string fileName) {
	std::ifstream inFile;
	inFile.open(fileName);

	if (!inFile.is_open()) { // failed to open file
		std::cout << "Could not open the file " << fileName << std::endl;
		std::cout << "Program terminating.\n";
		system("pause");
		std::cin.get();    // keep window open
		exit(EXIT_FAILURE);
	}

	char ch;
	std::string encryptString;

	while (inFile.get(ch)) {
		encryptString.push_back(++ch); //create an encrypted string;
	}
	inFile.close();

	std::ofstream outFile;
	outFile.open("C:\\Users\\User\\source\\repos\\HomeTask\\HomeTask\\TextEncrypt.txt");
	outFile << encryptString; // saving an encrypted file
	outFile.close();
}

void DecryptFile(std::string fileName) {
	std::ifstream inFile;
	inFile.open(fileName);

	if (!inFile.is_open()) { // failed to open file
		std::cout << "Could not open the file " << fileName << std::endl;
		std::cout << "Program terminating.\n";
		system("pause");
		std::cin.get();    // keep window open
		exit(EXIT_FAILURE);
	}

	char ch;
	std::string DecryptString;

	while (inFile.get(ch)) {
		DecryptString.push_back(--ch); //create an decrypted string;
	}
	inFile.close();

	std::ofstream outFile;
	outFile.open("C:\\Users\\User\\source\\repos\\HomeTask\\HomeTask\\TextDecrypt.txt");
	outFile << DecryptString; // saving an decrypted file
	outFile.close();
}