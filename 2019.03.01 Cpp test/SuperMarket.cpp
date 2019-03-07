#include<algorithm>
#include<fstream>
#include<iostream>
#include "SuperMarket.h"

typedef std::vector<Goods*>::iterator             ListIterator;

GoodsList::~GoodsList()
{
	WriteDataToFile();
	for (auto x : List)
		delete x;
}

void
GoodsList::AddNewGoods()
{
	std::string    Name     = "NoName";
	std::string    Category = "Nocategory";
	std::string    Date     =  "01.04.2019";
	float          Price    = 0;
	unsigned short Count    = 0;
	
	std::cout << "\nDo you want to add goods<1> or product<2>?";
		int choise = 1;
	std::cin >> choise;
		std::cout << "\nPlease enter the name of the goods: ";
		std::cin >> Name;
		std::cout << "\nPlease enter the category of goods: ";
		std::cin >> Category;
		std::cout << "\nPlease enter the price: ";
		std::cin >> Price;
		std::cout << "\nPlease enter the count:";
		std::cin >> Count;
		if(2 == choise)
		{
		std::cout << "\nPlease enter the date: ";
		std::cin >> Date;
		}
		// Increase the Count of Goods
		for(auto &x : List)
			if (x->GetName() == Name)
			{
				x->SetCount(x->GetCount() + 1);
				return;
			}
		// Add new Goods to List
		Goods *Pointer = 
			2 == choise ? 
			new Product(Name, Date, Category, Price, Count) 
			: new Goods(Name, Category, Price, Count);
		List.push_back(Pointer);
		std::cout << "\nChanges successfully applied.\n";
}
//----------------------------------------------------------------------------------------------------------------------------------
void
GoodsList::WriteDataToFile()
{
	std::ofstream outFile;
	outFile.open("FilePath.txt");

	// failed to open file
	if (!outFile.is_open())
	{
		std::cout << "Could not open the file " << "FilePath.txt" << std::endl;
		std::cout << "Program terminating.\n";
		system("pause");
		// keep window open
		std::cin.get();
		//exit(EXIT_FAILURE);
	}

	for (Goods *x : List)
	{
		dynamic_cast<Product*>(x) ?
		// for Product*
		 outFile << "Product " 
		// for Goods*
		:outFile << "Goods ";
		
		outFile << x->Print() << '\n';
	}
	outFile.close();
	std::cout << "\nData of countries and cities successfully written to a file.\n";
}
//----------------------------------------------------------------------------------------------------------------------------------
void
GoodsList::ReadDataFromFile()
{
	std::ifstream inFile;
	inFile.open("FilePath.txt");

	// failed to open file
	if (!inFile.is_open())
	{
		std::cout << "Could not open the file " << "FilePath.txt" << std::endl;
		std::cout << "Program terminating.\n";
		system("pause");
		// keep window open
		std::cin.get();
		//exit(EXIT_FAILURE);
	}
	std::string    Type;
	std::string    Name = "NoName";
	std::string    Category = "Nocategory";
	std::string    Date = "01.04.2019";
	float          Price = 0;
	unsigned short Count = 0;
	char buf;
	// while !+ EOF
	while (inFile >> Type)
	{
		inFile >> Name >> Category >> Price >> Count;
		
		if ("Product" == Type)
			inFile >> Date;

		// get '\n'
			inFile.get(buf);

			"Product" == Type ?
			 List.push_back(new Product(Name, Date, Category, Price, Count))
			:List.push_back(new Goods(Name, Category, Price, Count));
	}
	inFile.close();
	std::cout << "\nData of countries and cities successfully read from the file.\n";
}
//----------------------------------------------------------------------------------------------------------------------------------
void GoodsList::SortByCategories()
{
	for (int i = 0; i < List.size() - 1; ++i)
		if (List.at(i)->GetCategory() > List.at(i + 1)->GetCategory())
			std::swap(List.at(i), List.at(i + 1));
}
//----------------------------------------------------------------------------------------------------------------------------------
void GoodsList::ShowGoods()const
{
	for (auto x : List) {
		std::cout << "\nCategory: " << x->GetCategory() << ", Name: " << x->GetName() << ", Price" << x->GetPrice() << ", Count: " << x->GetCount(); 
		
		if (dynamic_cast<Product*>(x))
			std::cout << ", Date: " << dynamic_cast<Product*>(x)->GetTermOfConsumption();
	}
}
//----------------------------------------------------------------------------------------------------------------------------------
void
GoodsList::FindGoods() const
{
	std::cout << "\nEnter the name of the Goods/Product: ";
	std::string name;
	std::cin >> name;
	for(auto x : List)
		if (x->GetName() == name)
		{
			std::cout << "\nCategory: " << x->GetCategory() << ", Name: " << x->GetName() << ", Price" << x->GetPrice() << ", Count: " << x->GetCount();

			if (dynamic_cast<Product*>(x))
				std::cout << ", Date: " << dynamic_cast<Product*>(x)->GetTermOfConsumption();
			return;
		}
	std::cout << "\nSorry, Mickle,- there is no such goods with own name in our base...";
}
//----------------------------------------------------------------------------------------------------------------------------------
void
GoodsList::DeleteGoods()
{
	std::cout << "\nEnter the name of the Goods/Product: ";
	std::string name;
	std::cin >> name;
	int i = 0;
	for (ListIterator Iterator = List.begin(); Iterator != List.end(); ++Iterator, ++i)
		if (List.at(i)->GetName() == name)
		{
			List.erase(Iterator);
			break;
		}

	std::cout << "\nChanges successfully applied.\n";
}
//----------------------------------------------------------------------------------------------------------------------------------