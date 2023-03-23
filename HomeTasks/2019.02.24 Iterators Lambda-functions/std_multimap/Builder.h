#pragma once

#include<algorithm>
#include<fstream>
#include<iostream>
#include<map>
#include<string>
#include<vector>

typedef std::string Country;
typedef std::pair<const Country, std::string> Pair;
typedef std::multimap <Country, std::string> CountriesCities;
typedef CountriesCities::iterator ListIterator;

class Geography {
private:
    std::string FilePath;
    CountriesCities List;
public:
    Geography(std::string filePath = "Countries.txt")
            : FilePath(filePath) {
        ReadDataFromFile();
    }

    //----------------------------------------------------------------------------------------------------------------------------------
    ~Geography() {
        WriteDataToFile();
    }

    //----------------------------------------------------------------------------------------------------------------------------------
    inline void ReadDataFromFile() {
        std::ifstream inFile;
        inFile.open(FilePath);

        // failed to open file
        if (!inFile.is_open()) {
            std::cout << "Could not open the file " << FilePath << std::endl;
            std::cout << "Program terminating.\n";
            system("pause");
            // keep window open
            std::cin.get();
            //exit(EXIT_FAILURE);
        }

        std::string currentCountry = "";
        std::string currentCity = "";

        // while !+ EOF
        while (inFile >> currentCountry) {
            inFile >> currentCity;
            List.insert(Pair(currentCountry, currentCity));

        }
        inFile.close();
        std::cout << "\nData of countries and cities successfully read from the file.\n";
    }

    //----------------------------------------------------------------------------------------------------------------------------------
    inline void WriteDataToFile() {
        std::ofstream outFile;
        outFile.open(FilePath);

        // failed to open file
        if (!outFile.is_open()) {
            std::cout << "Could not open the file " << FilePath << std::endl;
            std::cout << "Program terminating.\n";
            system("pause");
            // keep window open
            std::cin.get();
            //exit(EXIT_FAILURE);
        }

        ListIterator Iterator;
        for (Iterator = List.begin(); Iterator != List.end(); ++Iterator)
            outFile << (*Iterator).first << ' ' << (*Iterator).second << '\n';
        outFile.close();
        std::cout << "\nData of countries and cities successfully written to a file.\n";
    }

    //----------------------------------------------------------------------------------------------------------------------------------
    inline void ShowCountries() {
        std::cout << "\nList of the countries:\n";

        ListIterator IteratorCurrent;
        ListIterator IteratorPrevious;
        for (IteratorCurrent = List.begin();
             IteratorCurrent != List.end(); IteratorPrevious = IteratorCurrent, ++IteratorCurrent) {
            if (IteratorCurrent == List.begin()) {
                std::cout << (*IteratorCurrent).first << '\n';
                continue;
            }
                // if current country is new
            else if ((*IteratorCurrent).first != (*IteratorPrevious).first) {
                std::cout << (*IteratorCurrent).first << '\n';
            }
        }
    }

    //----------------------------------------------------------------------------------------------------------------------------------
    inline void ShowCitiesOfSelectedCountry() {
        std::string selectedCountry = "";
        ShowCountries();
        std::cout << "\nEnter the name of the country which cities you want to see: ";
        std::cin >> selectedCountry;

        auto range = List.equal_range(selectedCountry);
        std::cout << "\nCities of the " << selectedCountry << '\n';
        for (auto iterator = range.first; iterator != range.second; ++iterator)
            std::cout << (*iterator).second << '\n';
    }

    //----------------------------------------------------------------------------------------------------------------------------------
    inline void RenameCity() {
        std::string oldCityName = "";
        std::string newCityName = "";
        std::cout << "\nEnter the name of the city which you want to rename: ";
        std::cin >> oldCityName;
        std::cout << "\nEnter new name of that city: ";
        std::cin >> newCityName;

        ListIterator Iterator;
        for (Iterator = List.begin(); Iterator != List.end(); ++Iterator)
            if ((*Iterator).second == oldCityName) {
                (*Iterator).second = newCityName;
                break;
            }

        std::cout << "\nChanges successfully applied.\n";
    }

    //----------------------------------------------------------------------------------------------------------------------------------
    void AddNewCity() {
        std::string country = "";
        std::string city = "";
        std::cout << "\nEnter the name of the country: ";
        std::cin >> country;
        std::cout << "\nEnter the name of the city: ";
        std::cin >> city;

        List.insert(Pair(country, city));

        std::cout << "\nChanges successfully applied.\n";
    }

    //----------------------------------------------------------------------------------------------------------------------------------
    void DeleteCity() {
        std::string city = "";
        std::cout << "\nEnter the name of the city: ";
        std::cin >> city;

        for (ListIterator Iterator = List.begin(); Iterator != List.end(); ++Iterator) {
            ListIterator eraseIterator = Iterator;
            if (eraseIterator->second == city) {
                List.erase(eraseIterator);
                break;
            }
        }

        std::cout << "\nChanges successfully applied.\n";
    }

    //----------------------------------------------------------------------------------------------------------------------------------
    void DeleteCountry() {
        std::string country = "";
        std::cout << "\nEnter the name of the country: ";
        std::cin >> country;
        if (List.erase(country))
            std::cout << "\nChanges successfully applied.\n";
    }

    //----------------------------------------------------------------------------------------------------------------------------------
    inline int CityCount() const {
        return List.size();
    }

    //----------------------------------------------------------------------------------------------------------------------------------
    inline int CountryCount() {
        ListIterator IteratorCurrent;
        ListIterator IteratorPrevious;
        int countryCount = 0;
        for (IteratorCurrent = List.begin();
             IteratorCurrent != List.end(); IteratorPrevious = IteratorCurrent, ++IteratorCurrent) {
            if (IteratorCurrent == List.begin()) {
                ++countryCount;
            }
                // if current country is new
            else if ((*IteratorCurrent).first != (*IteratorPrevious).first) {
                ++countryCount;
            }
        }
        return countryCount;
    }

}; // class Geography 

class Menu {
protected:
    Geography Object;
public:
    inline void SelectFunction() {
        int choise;
        bool DoMenuCycle = true;
        do {
            std::cout << "\tMenu:\n"
                      << " 1 - Load data from file\n"
                      << " 2 - Save data to file\n"
                      << " 3 - Search for city of a particular country\n"
                      << " 4 - Replace the name of the city\n"
                      << " 5 - Add city and country\n"
                      << " 6 - Delete the city\n"
                      << " 7 - Delete the country\n"
                      << " 8 - Count the number of cities\n"
                      << " 9 - Display a list of countries\n"
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
                    Object.ReadDataFromFile();
                    break;
                case 2:
                    Object.WriteDataToFile();
                    break;
                case 3:
                    Object.ShowCitiesOfSelectedCountry();
                    break;
                case 4:
                    Object.RenameCity();
                    break;
                case 5:
                    Object.AddNewCity();
                    break;
                case 6:
                    Object.DeleteCity();
                    break;
                case 7:
                    Object.DeleteCountry();
                    break;
                case 8:
                    std::cout << "\nTotal numbers of cities: " << Object.CityCount();
                case 9:
                    Object.ShowCountries();
                    break;
                default:
                    break;
            }
        } while (DoMenuCycle);
    }
};