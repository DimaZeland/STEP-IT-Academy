#pragma once

#include<iostream>
#include<string>
#include<vector>



class Goods
{
protected:
	std::string    name = "NoName";
	std::string    category = "Nocategory";
	float          price = 0;
	unsigned short count = 0;
public:
	Goods(std::string Name, std::string Category, float Price, unsigned short Count)
		: name(Name)
		, category(Category)
		, price(Price)
		, count(Count)
	{}
	inline std::string    GetName()              const { return name; }
	inline std::string    GetCategory()          const { return category; }
	inline float          GetPrice()             const { return price; }
	inline unsigned short GetCount()             const { return count; }
	inline void SetName(std::string Name) 
	{ 
		name = Name; 
	}
	inline void SetCategory(std::string Category) 
	{ 
		category = Category; 
	}
	inline void SetPrice(float Price) 
	{ 
		price = Price;
	}
	inline void SetCount(unsigned short Count)
	{ 
		count = Count;
	}
	inline std::string virtual Print()const
	{
		return name + " " + category + " " + std::to_string(price) + " " + std::to_string(count);
	}
};

class Product : public Goods
{
protected:
	std::string    termOfConsumption = "01.04.2019";
public:
	Product(std::string Name, std::string Date, std::string Category, float Price, unsigned short Count)
		: Goods(Name, Category, Price, Count)
		, termOfConsumption(Date)
	{}
	inline std::string    GetTermOfConsumption() const { return termOfConsumption; }
	inline void SetTermOfConsumption(std::string Date) { termOfConsumption = Date; }
	inline std::string Print()const override final
	{
		return Goods::Print() + " " + termOfConsumption;
	}
};

class GoodsList
{
protected:
	std::vector<Goods*> List;
public:
	GoodsList() 
	{
		ReadDataFromFile();
	}
	GoodsList(std::vector<Goods*> list) : List(list)
	{
		ReadDataFromFile();
	}
	~GoodsList();
	inline void ShowCategories(std::initializer_list<std::string> CategoriesType)const
	{
		for (std::string category : CategoriesType)
			std::cout << category << '\n';
	}
	void AddNewGoods();
	void WriteDataToFile();
	void ReadDataFromFile();
	void SortByCategories();
	void ShowGoods()const;
	void FindGoods()const;
	void DeleteGoods();
};


class Menu
{
protected:
	GoodsList Object;
public:
	inline void SelectFunction()
	{
		int  choise;
		bool DoMenuCycle = true;
		do
		{
			std::cout << "\tMenu:\n"
				<< " 1 - Load data from file\n"
				<< " 2 - Save data to file\n"
				<< " 3 - Search goods by name\n"
				<< " 4 - Show goods with sorting by categories\n"
				<< " 5 - Add goods\n"
				<< " 6 - Delete goods\n"
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
				Object.FindGoods();
				break;
			case 4:
				Object.SortByCategories();
				Object.ShowGoods();
				break;
			case 5:
				Object.AddNewGoods();
				break;
			case 6:
				Object.DeleteGoods();
				break;
			default:
				break;
			}
		} while (DoMenuCycle);
	}
};