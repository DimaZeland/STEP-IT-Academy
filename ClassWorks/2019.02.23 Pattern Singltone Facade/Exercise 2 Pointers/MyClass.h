#pragma once

#include<fstream>
#include<iostream>
#include<string>
#include<vector>

enum Week {
    Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday
};

class Case {
protected:
    std::string tag = "no tag";
    unsigned short priority = 0;
    unsigned short date = Week::Monday;
    std::string content = "No content";
public:
    Case(std::string Tag = " no tag", unsigned short Priority = 0, unsigned short Date = Week::Monday,
         std::string Content = "No content")
            : tag(Tag), priority(Priority), date(Date), content(Content) {}

    inline std::string GetTag() const { return tag; }

    inline std::string GetContent() const { return content; }

    inline std::string GetDate() const {
        std::string Date;
        switch (date) {
            case 0:
                Date = "Sunday";
                break;
            case 1:
                Date = "Monday";
                break;
            case 2:
                Date = "Tuesday";
                break;
            case 3:
                Date = "Wednesday";
                break;
            case 4:
                Date = "Thursday";
                break;
            case 5:
                Date = "Friday";
                break;
            case 6:
                Date = "Saturday";
                break;
            default:
                Date = "Monday";
                break;
        }
        return Date;
    }

    inline unsigned short GetDateIndex() const { return date; }

    inline unsigned short GetPriority() const { return priority; }

    inline void ShowCase() const {
        std::cout
                << "Tag: " << GetTag()
                << ", Date: " << GetDate()
                << ", Priority: " << GetPriority()
                << ", Case: " << GetContent() << '\n';
    }

    inline void SetTag(std::string Tag) { tag = Tag; }

    inline void SetPriority(unsigned short Priority) { priority = Priority; }

    inline void SetDate(unsigned short Date) { date = Date; }

    inline void SetContent(std::string Content) { content = Content; }
};

class CasesList {
protected:
    std::vector <Case> List;
public:
    CasesList() = default;

    CasesList(std::vector <Case> list) : List(list) {}

//	static void CreateCasesList() { CasesList:CasesList(); }
    inline void SetCasesPriorities() {
        std::cout << "\nCurrent List of Cases with its priorities:\n";
        unsigned int i = 0, newPriority = 0;
        for (auto &x: List) {
            std::cout << ++i << "old  priority: " << x.GetPriority() << ", case: " << x.GetContent() << '\n';
            std::cout << "\nPlease set new priority for its case: ";
            std::cin >> newPriority;
            x.SetPriority(newPriority);
        }
        std::cout << "\nChanges successfully applied.\n";
    }

    inline void SetCasesDates() {
        std::cout << "\nCurrent List of Cases with its dates:\n";
        unsigned int i = 0, newDate = 0;
        for (auto &x: List) {
            std::cout << ++i << "old  Date: " << x.GetDate() << ", case: " << x.GetContent() << '\n';
            std::cout << "\nPlease set new date for its case <0-6: Sunday - Saturday>: ";
            std::cin >> newDate;
            x.SetDate(newDate);
        }
        std::cout << "\nChanges successfully applied.\n";
    }

    inline void ShowCases() const {
        std::cout << "\nCurrent List of Cases:\n";
        unsigned int i = 0;
        for (auto &x: List)
            std::cout << ++i << ' '
                      << "Tag: " << x.GetTag()
                      << ", Date: " << x.GetDate()
                      << ", Priority: " << x.GetPriority()
                      << ", Case: " << x.GetContent() << '\n';
    }

    inline void ShowSelectedCase(unsigned int index) const {
        std::cout << index + 1
                  << "Tag: " << List.at(index).GetTag()
                  << ", Date: " << List.at(index).GetDate()
                  << ", Priority: " << List.at(index).GetPriority()
                  << ", Case: " << List.at(index).GetContent() << '\n';
    }

    inline void SetCaseContent() {
        unsigned int i = 0;
        std::string newCaseContent = "";
        ShowCases();
        std::cout << "\nEnter the number of case which do you want to change:";
        std::cin >> i;
        // set the value of i to index of elements std::vector<Case> List
        --i;
        std::cout << "\nCurrent Info of selected Case:\n";
        ShowSelectedCase(i);
        std::cout << "\nEnter new content of selected case:";
        std::cin >> newCaseContent;
        List.at(i).SetContent(newCaseContent);
        std::cout << "\nChanges successfully applied.\n";
    }

    inline void DeleteCase() {
        unsigned int i = 0;
        ShowCases();
        std::cout << "\nEnter the number of case which do you want to delete:";
        std::cin >> i;
        // set the value of i to index of elements std::vector<Case> List
        --i;
        List.at(i).SetTag("deleting case");
        List.erase(List.begin() + i);
        std::cout << "\nChanges successfully applied.\n";
    }

    inline void AddingNewCase() {
        std::string tag;
        unsigned short priority;
        unsigned short date;
        std::string content;
        std::cout << "\nPlease enter the tag of case: ";
        std::cin >> tag;
        std::cout << "\nPlease enter the priority of case: ";
        std::cin >> priority;
        std::cout << "\nPlease enter the date of case <0-6 from Sunday to Saturday>: ";
        std::cin >> date;
        std::cout << "\nPlease enter the content of case:";
        std::cin >> content;
        List.push_back(Case(tag, priority, date, content));
        std::cout << "\nChanges successfully applied.\n";
    }

    inline void FindSelectedCase() {
        int methodFind = 0;
        std::cout << "Please the parameter to find the case: 1 = for date, 2 - for tag, 3 - for priority:";
        std::cin >> methodFind;
        switch (methodFind) {
            case 1: {
                int date = 0;
                std::cout << "\nPlease enter the date of case <0 - 6 from Sunday to Saturday>: ";
                std::cin >> date;
                for (auto &x: List)
                    if (x.GetDateIndex() == date)
                        x.ShowCase();
                break;
            }
            case 2: {
                std::string Tag = "";
                std::cout << "\nPlease enter the tag>: ";
                std::cin >> Tag;
                for (auto &x: List)
                    if (x.GetTag() == Tag)
                        x.ShowCase();
                break;
            }
            case 3: {
                unsigned int priority = 0;
                std::cout << "\nPlease enter the priority>: ";
                std::cin >> priority;
                for (auto &x: List)
                    if (x.GetPriority() == priority)
                        x.ShowCase();
                break;
            }
            default:
                break;
        }
    }

    inline void WriteCasesListToFile() {
        std::ofstream outFile;
        outFile.open("CasesList.txt");

        // failed to open file
        if (!outFile.is_open()) {
            std::cout << "Could not open the file " << "CasesList.txt" << std::endl;
            std::cout << "Program terminating.\n";
            system("pause");
            // keep window open
            std::cin.get();
            //exit(EXIT_FAILURE);
        }

        for (auto &x: List)
            if (x.GetTag() != "deleting case")
                outFile << x.GetTag() << ' ' << x.GetDateIndex() << ';' << x.GetPriority() << ';' << x.GetContent()
                        << '\n';
        outFile.close();
        std::cout << "\nChanges successfully applied.\n";
    }

    inline void ReadCasesListFromFile() {
        std::ifstream inFile;
        inFile.open("CasesList.txt");

        // failed to open file
        if (!inFile.is_open()) {
            std::cout << "Could not open the file " << "CasesList.txt" << std::endl;
            std::cout << "Program terminating.\n";
            system("pause");
            // keep window open
            std::cin.get();
            //exit(EXIT_FAILURE);
        }

        std::string tag;
        unsigned short priority;
        unsigned short date;
        std::string content;

        // while !+ EOF
        char buf;
        while (inFile >> tag) {
            //pass ';'
            inFile.get(buf);
            inFile >> date;
            inFile.get(buf);
            inFile >> priority;
            inFile.get(buf);
            inFile >> content;
            inFile.get(buf);
        }
        List.push_back(Case(tag, priority, date, content));

        inFile.close();
        std::cout << "\nChanges successfully applied.\n";
    }
};

class Menu {
protected:
    CasesList Object;
    static unsigned int count;

    Menu() { ++count; };
public:
    static inline Menu *CreateMenu() {
        if (0 == count) {
            return new Menu;
        } else
            std::cout << "\nYou can not create two menus in one program";
        return nullptr;
    }

    inline void SelectFunction() {
        int choise;
        bool DoMenuCycle = true;
        do {
            std::cout << "\tMenu:\n"
                      << " 1 - Set Cases Priorities\n"
                      << " 2 - Set Cases Dates\n"
                      << " 3 - Show Cases\n"
                      << " 4 - Set Case Content\n"
                      << " 5 - Delete Case\n"
                      << " 6 - Adding New Case\n"
                      << " 7 - Find Selected Case\n"
                      << " 8 - Write Cases List To File\n"
                      << " 9 - Read Cases List From File\n"
                      << " 0 - Exit from menu\n"
                      << "Please select the function: ";
            std::cin >> choise;
            std::system("cls");
            switch (choise) {
                case 0:
                    DoMenuCycle = false;
                    std::cout << "\nGood bye!";
                    break;
                case 1:
                    Object.SetCasesPriorities();
                    break;
                case 2:
                    Object.SetCasesDates();
                    break;
                case 3:
                    Object.ShowCases();
                    break;
                case 4:
                    Object.SetCaseContent();
                    break;
                case 5:
                    Object.DeleteCase();
                    break;
                case 6:
                    Object.AddingNewCase();
                    break;
                case 7:
                    Object.FindSelectedCase();
                case 8:
                    Object.WriteCasesListToFile();
                case 9:
                    Object.ReadCasesListFromFile();
                    break;
                default:
                    break;
            }
        } while (DoMenuCycle);
    }
};