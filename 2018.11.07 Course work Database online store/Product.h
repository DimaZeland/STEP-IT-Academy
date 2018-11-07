#pragma once

#include<iostream>
#include<string>
#include<vector>
#include<fstream>

class Product {
private: // class data
	int itsMyArticle;
	double itsMyPrice;
	int itsMyAmoung;
	std::string itsMyManufactured;
	std::string itsMyModel;
public:
	friend class Menu; // Menu has access to the private part Product
	//constructors & destructor
	Product(int article = 0, double price = 0.0, int amoung = 0, std::string manufactured = " ", std::string model = " "); // overload base explicit constructor
	Product(int article = 0, double price = 0.0, int amoung = 0, const char* manufactured = " 1\0", const char* model = " 1\0"); // overload base explicit constructor
	~Product() {}
	Product(const Product&); // explicit copy-constrictor
	Product& operator=(const Product&); // explicit assignment operator
	// friend functions
	friend std::ostream& operator<<(std::ostream& os, const Product&); // overload operator<<
};

class Menu
{
private:
	bool itsMyRewriteFile;
	std::string itsMyDataBaseFilePath;
	std::vector<std::string>  itsMyModels;
	std::vector<Product> itsMyBase;
public:
	Menu(std::string);// read file data into vector
	~Menu(); // rewrite the file Mobile.csv (if necessary)
	// class methods
	void ReadFile(); // read file data into item queue
	void ShowMobiles(); // outup the selected mobile phones
	void SetitsMyModels(); // Find all names of mobile phone models
	void GetModels()const; // output the names of models
	void FindMobileByParameters(int Brand = 0, double minPrice = 0, double maxPrice = 1000000, int number = -1, bool growth = true); // cout the selected mobiles
	void FindMobileByID(int ID = 1, int lastID = -1) const; // cout the selected mobile by ID
	void SortMobile(std::vector<Product>& queue, bool growth = true)const; // sort the selected phones
	void BuyMobilePhone(); // for user to buy mobile phone
	void DeleteProduct(); // delete one product
	void InviteProduct(); // invine new product
	void EditProduct(); // edit product
	void RewriteFile()const; // rewrite the file Mobile.csv
	void AdminFunctions(); // work with the database in the admin panel
	void UserFunctions(); // work with the database in the user panel
};

