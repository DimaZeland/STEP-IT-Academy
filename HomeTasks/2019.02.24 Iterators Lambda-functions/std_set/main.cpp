#include<iostream>
#include<set>
#include<string>
#include<fstream>
//#include"Builder.h"

std::string ServiceWordsCpp[] = {"auto", "break", "case", "catch", "char", "class", "const", "continue", "default",
                                 "delete", "do",
                                 "double", "else", "enum", "extern", "float", "for", "friend", "goto", "if", "inline",
                                 "int", "long", "new", "operator",
                                 "private", "protected", "public", "register", "return", "short", "signed", "sizeof",
                                 "static", "struct", "switch",
                                 "template", "this", "throw", "try", "typedef", "union", "unsigned", "virtual", "void",
                                 "volatile", "while"};

int main() {
    std::ifstream inFile;
    inFile.open("Builder.h");
    std::set <std::string> ServiceWordsCppInFile;
    // failed to open file
    if (!inFile.is_open()) {
        std::cout << "Could not open the file " << "Builder.h" << std::endl;
        std::cout << "Program terminating.\n";
        system("pause");
        // keep window open
        std::cin.get();
        //exit(EXIT_FAILURE);
    }

    std::string buf;
    while (inFile >> buf) {
        for (auto &x: ServiceWordsCpp)
            if (x == buf) {
                ServiceWordsCppInFile.insert(buf);
                break;
            }
    }

    std::set<std::string>::iterator it = ServiceWordsCppInFile.begin();

    std::cout << "Sort variant of Service Words C++ language which are include into file:\n";
    for (int i = 1; it != ServiceWordsCppInFile.end(); i++, it++)
        std::cout << *it << " ";
    std::cout << std::endl;

    system("pause");
    return 0;
}