#pragma once
#include<algorithm>
#include<fstream>
#include<iostream>
#include<string>
#include<vector>

//enum Week { Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday };

class TrainInfo {
protected:
	unsigned short number = 0;
	std::string    departureTime = "09:00";
	std::string    stationDestination = "Rivne";
public:
	TrainInfo(unsigned short Number = 0, std::string Time = "09:00", std::string Destination = "Rivne")
		: number(Number)
		, departureTime(Time)
		, stationDestination(Destination)
	{}
	inline unsigned short GetNumber()             const { return number; }
	inline std::string    GetDepartureTime()      const { return departureTime; }
	inline std::string    GetStationDestination() const { return stationDestination; }
	inline void           ShowTrainInfo()         const {
		std::cout
			<< "Number: " << GetNumber()
			<< ", Departure Time: " << GetDepartureTime()
			<< ", Station Destination: " << GetStationDestination() << '\n';
	}
	inline void SetNumber(unsigned short Number) { number = Number; }
	inline void SetDepartureTime(std::string Time) { departureTime = Time; }
	inline void SetStationDestination(std::string Destination) { stationDestination = Destination; }
};

class TrainsList {
protected:
	std::vector<TrainInfo> List;
public:
	TrainsList() = default;
	TrainsList(std::vector<TrainInfo> list) : List(list) {}
	inline void AddNewTrainInfo() {
		unsigned short number;
		std::string    time;
		std::string    destination;
		std::cout << "\nPlease enter the number of train: ";
		std::cin >> number;
		std::cout << "\nPlease enter the departure time of the train: ";
		std::cin >> time;
		std::cout << "\nPlease enter the station of destination: ";
		std::cin >> destination;
		List.push_back(TrainInfo(number, time, destination));
		std::cout << "\nChanges successfully applied.\n";
	}
	inline void DeleteTrainInfo() {
		unsigned int i = 0;
		ShowTrainsInfoList();
		std::cout << "\nEnter the number of train which do you want to delete:";
		std::cin >> i;
		// set the value of i to index of elements std::vector<Case> List
		--i;
		List.erase(List.begin() + i);
		std::cout << "\nChanges successfully applied.\n";
	}
	inline void ShowTrainsInfoList()const {
		std::cout << "\nCurrent List of Trains Info:\n";
		int i = 0;
		for (auto& x : List)
			x.ShowTrainInfo();
	}
	inline void SortTrainsInfoList() {
		unsigned int i = 0;
		std::cout << "\nPlease enter the type of sort:\n1 - by number\n2 - by departure time\n3 - by station of destination: ";
		std::cin >> i;
		switch (i) {
		case 1:
			std::sort(
				List.begin()
				, List.end()
				, [&](TrainInfo first, TrainInfo second) {
				return first.GetNumber() < second.GetNumber() ? true : false;
			}
			);
			break;
		case 2:
			std::sort(
				List.begin()
				, List.end()
				, [&](TrainInfo first, TrainInfo second) {
				return first.GetDepartureTime() < second.GetDepartureTime() ? true : false;
			}
			);
			break;
		case 3:
			std::sort(
				List.begin()
				, List.end()
				, [&](TrainInfo first, TrainInfo second) {
				return first.GetStationDestination() < second.GetStationDestination() ? true : false;
			}
			);
			break;
		default:
			break;
		}
		ShowTrainsInfoList();
	}
	inline void ShowSelectedTrainInfo()const {
		unsigned int trainNumber = 0;
		std::cout << "\nPlease enter the number of train: ";
		std::cin >> trainNumber;
		auto IteratorTrainInfo = std::find_if(
			List.begin()
			, List.end()
			, [&](TrainInfo element) {return trainNumber == element.GetNumber() ?  true : false; }
		);
		IteratorTrainInfo->ShowTrainInfo();
	}
	inline void WriteTrainsInfoListToFile() {
		std::ofstream outFile;
		outFile.open("TrainsInfoList.txt");

		// failed to open file
		if (!outFile.is_open()) {
			std::cout << "Could not open the file " << "TrainsInfoList.txt" << std::endl;
			std::cout << "Program terminating.\n";
			system("pause");
			// keep window open
			std::cin.get();
			//exit(EXIT_FAILURE);
		}

		for (auto& x : List)
			outFile << x.GetNumber() << ';' << x.GetDepartureTime() << ' ' << x.GetStationDestination() << '\n';
		outFile.close();
		std::cout << "\nChanges successfully applied.\n";
	}
	inline void ReadTrainsInfoListFromFile() {
		std::ifstream inFile;
		inFile.open("TrainsInfoList.txt");

		// failed to open file
		if (!inFile.is_open()) {
			std::cout << "Could not open the file " << "TrainsInfoList.txt" << std::endl;
			std::cout << "Program terminating.\n";
			system("pause");
			// keep window open
			std::cin.get();
			//exit(EXIT_FAILURE);
		}

		unsigned short number;
		std::string    time;
		std::string    destination;

		// while !+ EOF
		char buf;
		while (inFile >> number) {
			//pass ';'
			inFile.get(buf);
			inFile >> time;
			inFile.get(buf);
			inFile >> destination;
			inFile.get(buf);
			List.push_back(TrainInfo(number, time, destination));
		}
		inFile.close();
		std::cout << "\nChanges successfully applied.\n";
	}
};

class Menu {
protected:
	TrainsList Object;
public:
	inline void SelectFunction() {
		int  choise;
		bool DoMenuCycle = true;
		do {
			std::cout << "\tMenu:\n"
				<< " 1 - Add New Train Info\n"
				<< " 2 - Delete Train Info\n"
				<< " 3 - Show Trains Info List\n"
				<< " 4 - Sort Trains Info List\n"
				<< " 5 - Show Selected Train Info\n"
				<< " 6 - Write Trains Info List To File\n"
				<< " 7 - Read Trains Info List From File\n"
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
				Object.AddNewTrainInfo();
				break;
			case 2:
				Object.DeleteTrainInfo();
				break;
			case 3:
				Object.ShowTrainsInfoList();
				break;
			case 4:
				Object.SortTrainsInfoList();
				break;
			case 5:
				Object.ShowSelectedTrainInfo();
				break;
			case 6:
				Object.WriteTrainsInfoListToFile();
				break;
			case 7:
				Object.ReadTrainsInfoListFromFile();
			default:
				break;
			}
		} while (DoMenuCycle);
	}
};