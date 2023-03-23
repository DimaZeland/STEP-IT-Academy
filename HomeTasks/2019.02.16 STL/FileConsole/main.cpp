#include<iostream>
#include<fstream>
#include<string>
//#include"Builder.h"

void CreateFile(std::string fileName, std::string fileContent);

void PrintFile(std::string fileName);

void AppendFile(std::string fileName, std::string fileContent);

void CopyFile(std::string fileName1, std::string fileName2);

int main() {
    std::string command, fileName1, fileName2, text;
    char ch;
    std::cout << "Microsoft Corporation [Version 6.1.7601]\n";
    std::cout << std::endl << "C:\\Admin:";
    while (true) {
        std::cin.get(ch);
        if (' ' != ch) {
            command += ch;
            if ("create" != command && "print" != command && "append" != command && "copy" != command &&
                "quit" != command)
                continue;
            else
                std::cin.get(ch); // get the space
        }
        if ("create" == command) {
            while (true) {
                std::cin.get(ch);
                if (' ' != ch) {
                    fileName1 += ch;
                } else
                    break;
            }
            while (true) {
                std::cin.get(ch);
                if (26 != ch) {
                    text += ch;
                } else
                    break;
            }
            CreateFile(fileName1, text);
        } else if ("print" == command) {
            while (10 != std::cin.peek()) {
                std::cin.get(ch);
                if (' ' != ch) {
                    fileName1 += ch;
                } else
                    break;
            }
            PrintFile(fileName1);
            std::cin.get(ch); // get the \n
        } else if ("append" == command) {
            while (true) {
                std::cin.get(ch);
                if (' ' != ch) {
                    fileName1 += ch;
                } else
                    break;
            }
            while (true) {
                std::cin.get(ch);
                if (26 != ch) {
                    text += ch;
                } else
                    break;
            }
            AppendFile(fileName1, text);
        } else if ("copy" == command) {
            while (true) {
                std::cin.get(ch);
                if (' ' != ch) {
                    fileName1 += ch;
                } else
                    break;
            }
            while (10 != std::cin.peek()) {
                std::cin.get(ch);
                if (' ' != ch) {
                    fileName2 += ch;
                } else
                    break;
            }
            CopyFile(fileName1, fileName2);
            std::cin.get(ch); // get the \n
        } else if ("quit" == command)
            break;
        else
            std::cout << "\nWrond command";
        std::cin.clear();
        command = fileName1 = fileName2 = text = "";
        std::cout << std::endl << "C:\\Admin:";
    }

    system("pause");
    return 0;
}

void CreateFile(std::string fileName, std::string fileContent) {
    std::ofstream outFile;
    outFile.open(fileName);
    if (!outFile.is_open()) { // failed to open file
        std::cout << "Invalid path to file " << fileName << std::endl;
        return;
    }

    outFile << fileContent;
    outFile.close();
    std::cout << " file " << fileName << " successfully created.";
}

void PrintFile(std::string fileName) {
    std::ifstream inFile;
    inFile.open(fileName);
    if (!inFile.is_open()) { // failed to open file
        std::cout << "Invalid path to file " << fileName << std::endl;
        return;
    }

    std::cout << "Print the content of the file " << fileName << std::endl;
    char ch;
    while (inFile.get(ch))
        std::cout << ch;

    inFile.close();
}

void AppendFile(std::string fileName, std::string fileContent) {
    std::ofstream outFile;
    outFile.open(fileName, std::ios_base::out | std::ios_base::app);
    if (!outFile.is_open()) { // failed to open file
        std::cout << "Invalid path to file " << fileName << std::endl;
        return;
    }

    outFile << fileContent;
    outFile.close();
    std::cout << " file " << fileName << " successfully edited.";
}

void CopyFile(std::string fileName1, std::string fileName2) {
    std::ifstream inFile;
    inFile.open(fileName1);
    if (!inFile.is_open()) { // failed to open file
        std::cout << "Invalid path to file " << fileName1 << std::endl;
        return;
    }

    char ch;
    std::string fileName1Content;

    while (inFile.get(ch)) {
        fileName1Content.push_back(ch);
    }
    inFile.close();

    std::ofstream outFile;
    outFile.open(fileName2);
    if (!outFile.is_open()) { // failed to open file
        std::cout << "Invalid path to file " << fileName2 << std::endl;
        return;
    }
    outFile << fileName1Content;
    outFile.close();
    std::cout << " The content of the file " << fileName1 << " successfully copying to the " << fileName2 << std::endl;
}