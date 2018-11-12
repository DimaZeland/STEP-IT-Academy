#include"Product.h"

Menu::Menu(std::string FilePath)
	:itsMyRewriteFile(false), itsMyDataBaseFilePath(FilePath) {
	ReadFile(); // read file data into vector
	SetitsMyModels(); // Find all names of mobile phone models
}

Menu::~Menu() { // rewrite the file Mobile.csv (if necessary)
	if (itsMyRewriteFile) // if there was a database change
		RewriteFile();
}

void
Menu::ReadFile() { // read file data into vector
	int index = 0;
	std::ifstream inFile;
	inFile.open(itsMyDataBaseFilePath);

	if (!inFile.is_open()) { // failed to open file
		std::cout << "Could not open the file " << itsMyDataBaseFilePath << std::endl;
		std::cout << "Program terminating.\n";
		system("pause");
		std::cin.get();    // keep window open
		exit(EXIT_FAILURE);
	}

	char Manufactured[20]; // manufactured name
	char buf = ' ';
	for (int i = 0; i < 5; ++i) {
		inFile.get(buf);
		int j = 0;
		for (; j < 20 and ';' != buf and '\n' != buf; ++j) { // pass the section titles
			Manufactured[j] = buf;
			inFile.get(buf);
		}
		Manufactured[j] = '\0';
	}

	int article = 0;
	while (inFile >> article) { // while !+ EOF
		inFile.get(buf); // pass ';'
		double price = 0;
		inFile >> price;
		inFile.get(buf); // pass ';'
		int amount = 0;
		inFile >> amount;
		inFile.get(); // pass ';'

		inFile.get(buf); // start reading the manufactured by
		int j = 0;
		for (; j < 20 and ';' != buf and '\n' != buf; ++j) {
			Manufactured[j] = buf;
			inFile.get(buf);
		}
		Manufactured[j] = '\0';

		char Model[50]; // Model name
		inFile.get(buf); // start reading the model name
		j = 0;
		for (; j < 50 and '\n' != buf; ++j) {
			Model[j] = buf;
			inFile.get(buf);
		}
		Model[j] = '\0';

		Product pw(article, price, amount, Manufactured, Model); // create a separate item
		itsMyBase.push_back(pw); // add a separate item to the queue
	}
	inFile.close();
}

void
Menu::SetitsMyModels() { // Find all names of mobile phone models
	bool alreadyIs = false;
	for (Product x : itsMyBase) {
		for (std::string y : itsMyModels)
			if (y == x.itsMyManufactured) // if that model name already is in the vector
				alreadyIs = true;

		if (alreadyIs) // analyze the matches
			alreadyIs = false;
		else
			itsMyModels.push_back(x.itsMyManufactured); // if the model of its atteration is a new 
	}
}

void
Menu::GetModels()const { // output the names of models
	int i = 0;
	for (std::string x : itsMyModels) {
		std::cout.width(2);
		std::cout << ++i << ' ' << x << '\n';
	}
}

void
Menu::ShowMobiles() { // outup the selected mobile phones
	std::cout << "\nWould you like to display phones by specified parameters <1> or an a specific phone by ID <0>?: ";
	int choise = 0;
	std::cin >> choise;
	system("cls");
	if (choise) { // show phones  by selected search options
		int company = 0, minPrice = 0, maxPrice = 0, resultsDisplay = 0;
		bool priceRating = true;
		std::cout << "\nList of available manufacturers of mobile phones:\n";
		GetModels(); // output the names of models
		std::cout << "\nPlease enter the manufacturing company or <0> to display all companies: ";
		std::cin >> company;
		std::cout << "\nPlease enter minimum and maximum price for the goods: ";
		std::cin >> minPrice >> maxPrice;
		std::cout << "\nPlease enter number of results to display: ";
		std::cin >> resultsDisplay;
		std::cout << "\nDisplay results ascending price <1> or descending price <0>? ";
		std::cin >> priceRating;
		std::cout << "\nList of mobile phones by specified parameters:\n";
		FindMobileByParameters(company, minPrice, maxPrice, resultsDisplay, priceRating); // cout the selected mobiles
	}
	else {
		std::cout << "\nPlease enter the ID of mobile phone to display information about one selected phone" <<
			" or an ID range <1-" << itsMyBase.size() << "> to display phone list information by ID: ";
		std::cin >> choise;
		system("cls");
		if (' ' == std::cin.peek()) { // checking the presence of characters in the buffer
			int lastID = 0;
			std::cin >> lastID;
			if (choise > lastID) // setting the range in the correct order
				std::swap(choise, lastID);
			if (choise < 0)
				choise = 0;
			if (lastID > itsMyBase.size() or lastID < 0)
				lastID = itsMyBase.size() - 1;
			std::cout << "\nMobile phone search results for a given ID range:\n";
			FindMobileByID(choise, lastID);
		}
		else {
			std::cout << "\nMobile phone information by a given ID:\n";
			FindMobileByID(choise);
		}
	}
}

void
Menu::FindMobileByParameters(int Brand, double minPrice, double maxPrice, int number, bool growth) {
	std::vector<Product> buf;
	number = 0 > number or number > itsMyBase.size() ? itsMyBase.size() : number; // set number to queue if number is negative number or more than vector size
	for (Product x : itsMyBase)
		if ((0 == Brand ? true : x.itsMyManufactured == itsMyModels[Brand - 1]) and // show only selected brand
			x.itsMyPrice >= minPrice and x.itsMyPrice <= maxPrice)
			buf.push_back(x); // selection of phones for further sorting
	if (buf.empty()){
		std::cout << "\nThere are no results for the specified parameters to display.\n";
	return;
}
	SortMobile(buf, growth); // sort the selected phones
	int i = 0;
	for (Product x : buf) // loop through array
		if (++i <= number) // show only selected number of mobile phones
			std::cout << i << ' ' << x; // use the operator<< (ostream&, const Product&)
}

void
Menu::SortMobile(std::vector<Product>& queue, bool growth) const { // sort the selected phones
	if (growth)
		for (int k = 0; k < queue.size() - 1; ++k) // sort arr [] by insertion method in ascending order
			for (int j = k; j >= 0 and queue[j].itsMyPrice > queue[j + 1].itsMyPrice; --j)
				std::swap(queue[j], queue[j + 1]);
	else
		for (int k = 0; k < queue.size() - 1; ++k) // sort arr [] by insertion method in descending order
			for (int j = k; j >= 0 and queue[j].itsMyPrice < queue[j + 1].itsMyPrice; --j)
				std::swap(queue[j], queue[j + 1]);
}

void
Menu::FindMobileByID(int ID, int lastID) const { // cout the selected mobile by ID
	std::vector<Product> buf;
	if (0 > lastID) { // 0 > last ID
		for (Product x : itsMyBase)
			if (x.itsMyArticle == ID) { // show only selected mobile phone
				std::cout << x; // use the operator<< (ostream&, const Product&)
				break;
			}
	}
	else {
		for (Product x : itsMyBase)
			if (x.itsMyArticle >= ID and x.itsMyArticle <= lastID) // show only selected mobile phones
				std::cout << x; // use the operator<< (ostream&, const Product&)
	}
}

void
Menu::BuyMobilePhone() { // for user to buy mobile phone
	std::cout << "\nPlease enter the ID of mobile phone, which you want to buy: ";
	int ID = 0;
	std::cin >> ID;
	system("cls");
	std::cout << "\nInformation on the phone you wish to purchase:\n";
	FindMobileByID(ID);
	if (itsMyBase[ID - 1].itsMyAmoung <= 0) {
		std::cout << "\nWe apologize, currently all mobile phones of this model are sold out.\n";
		return;
	}
	std::cout << "\nDo you really want to buy a mobile phone " << itsMyBase[ID - 1].itsMyModel << " for the " << itsMyBase[ID - 1].itsMyPrice << " $?\n" <<
		"Please enter Yes or No <Y/N>: ";
	char decision = ' ';
	std::cin >> decision;
	system("cls");
	switch (decision) {
	case 'Y': case 'y':
		--itsMyBase[ID - 1].itsMyAmoung; // reducing the amount of goods for one piece
		std::cout << "\nThank you for your purchase in our online store!\nIn the near future, our manager will contact you to clarify the details of sending the order.\n";
		break;
	default:
		std::cout << "\nPurchase of goods is not carried out. If necessary, you can always purchase the desired mobile phone in our online store.\n";
		break;
	}
	std::cin.clear();
	itsMyRewriteFile = true; // need to rewrite Mobile.csv
}

void
Menu::DeleteProduct() { // delete one product
	std::cout << "\nPlease enter the ID of the product you wish to remove from the database: ";
	int removeID = 0;
	std::cin >> removeID;
	system("cls");
	std::cout << "\nDo you really want to delete the next entry from the base?\n";
	FindMobileByID(removeID);
	--removeID; // change the value to the index of the vector
	std::cout << "\nEnter <Y> to confirm or <N> to cancel the action: ";
	char ch = ' ';
	std::cin >> ch;
	system("cls");
	switch (ch)
	{
	case 'Y': case 'y':
		itsMyBase.erase(itsMyBase.begin() + removeID);
		std::cout << "\nRecord successfully removed from the database.\n";
		for (int i = itsMyBase.size() - 1; i >= removeID; --i) // rewriting product indexes after deleting one item
			itsMyBase[i].itsMyArticle = i + 1;
		itsMyRewriteFile = true; // need to rewrite Mobile.csv
		break;
	default:
		std::cout << "\nthe record has not been deleted from the database.\n";
		break;
	}
}

void
Menu::InviteProduct() { // invine new product
	std::cout << "\nPlease enter the mobile phone manufacturer: ";
	std::string manufacturer = " ";
	std::cin >> manufacturer;
	std::cout << "\nPlease enter the mobile phone model: ";
	std::string model = manufacturer + ' ';
	std::string modelBuf = " ";
	std::cin >> modelBuf;
	model += modelBuf;
	std::cout << "\nPlease enter the number of pieces of this mobile phone: ";
	int amount = 0;
	std::cin >> amount;
	std::cout << "\nPlease enter the price of one mobile phone of this model ($): ";
	double price = 0;
	std::cin >> price;
	Product pw(itsMyBase.size() + 1, price, amount, manufacturer, model); // create a separate item
	itsMyBase.push_back(pw); // add a separate item to the queue
	std::cout << "\nProduct successfully added to the database.\n";
	itsMyRewriteFile = true; // need to rewrite Mobile.csv
	bool alreadyIs = false;
	for (std::string x : itsMyModels) // add a new manufacturer to the database if necessary
		if (x == manufacturer) {
			alreadyIs = true;
			break;
		}
	if (alreadyIs)
		itsMyModels.push_back(manufacturer);
}

void
Menu::EditProduct() { // edit product
	std::cout << "\nPlease enter the ID of mobile phone to edit the information about it: ";
	int choise = 0;
	std::cin >> choise;
	system("cls");
	std::cout << "\nCurrent information about the selected product:\n";
	FindMobileByID(choise);
	std::cout << "\nPlease enter the new mobile phone manufacturer: ";
	std::cin >> itsMyBase[choise - 1].itsMyManufactured;
	std::cout << "\nPlease enter the new mobile phone model: ";
	std::string modelBuf;
	std::cin >> modelBuf;
	itsMyBase[choise - 1].itsMyModel = itsMyBase[choise - 1].itsMyManufactured + ' ' + modelBuf;
	std::cout << "\nPlease enter the new number of pieces of this mobile phone: ";
	std::cin >> itsMyBase[choise - 1].itsMyAmoung;
	std::cout << "\nPlease enter the new price of one mobile phone of this model ($): ";
	std::cin >> itsMyBase[choise - 1].itsMyPrice;
	std::cout << "\nInformation about the selected product successfully edited:\n";
	FindMobileByID(choise);
	itsMyRewriteFile = true; // need to rewrite Mobile.csv
	bool alreadyIs = false;
	for (std::string x : itsMyModels) // add a new manufacturer to the database if necessary
		if (x == itsMyBase[choise - 1].itsMyManufactured) {
			alreadyIs = true;
			break;
		}
	if (alreadyIs)
		itsMyModels.push_back(itsMyBase[choise - 1].itsMyManufactured);
}

void
Menu::RewriteFile()const { // rewrite the file Mobile.csv
	std::ofstream outFile;
	outFile.open(itsMyDataBaseFilePath);
	outFile << "Article;Price;Amount;Manufacturer;Model\n";
	for (Product x : itsMyBase) // write product data to file
		outFile << x.itsMyArticle << ';' << x.itsMyPrice << ';' << x.itsMyAmoung << ';' << x.itsMyManufactured <<
		';' << x.itsMyModel << '\n';
	outFile.close();
}

void
Menu::AdminFunctions() { // work with the database in the admin panel
	std::string pass = "q";
	do {
		std::cout << "\nEnter admin password or <q> to exit from the admin panel: ";
		std::cin >> pass;
		system("cls");
		if ("q" == pass) // Logout from the admin panel
			break;
		if ("admin" == pass) {
			std::cout << "\nThe correct admin password has been entered!\n";
			bool continueWork = true;
			int func = 0;
			do {
				std::cout << "\nPlease select the desired function for working with the database:\n" <<
					"<1> - database output\n<2> - add entry to database\n<3> - edit database entry\n<4> - delete record from database\n<0> - exit: ";
				std::cin >> func;
				system("cls");
				switch (func) {
				case 1:
					ShowMobiles();
					break;
				case 2:
					InviteProduct();
					break;
				case 3:
					EditProduct();
					break;
				case 4:
					DeleteProduct();
					break;
				case 0:
					continueWork = false;
					break;
				default:
					std::cout << "\nInvalid input!\n";
					break;
				}
			} while (continueWork);
		} // finishing work in the admin panel after preliminary succesfull authorization
		else
			std::cout << "\nInvalid admin password!\n";
	} while (true); // exit to the base menu
	std::cout << "\nTermination of work in the admin panel. Exit to the main menu.\n";
}

void
Menu::UserFunctions() { // work with the database in the user panel
			bool continueWork = true;
			int func = 0;
			do {
				std::cout << "\nPlease select the desired function for working with the database:\n" <<
					"<1> - database output\n<2> - buy mobile phone\n<0> - exit: ";
				std::cin >> func;
				system("cls");
				switch (func) {
				case 1:
					ShowMobiles();
					break;
				case 2:
					BuyMobilePhone();
					break;
				case 0:
					continueWork = false;
					break;
				default:
					std::cout << "\nInvalid input!\n";
					break;
				}
			} while (continueWork);
	std::cout << "\nTermination of work in the user panel. Exit to the main menu.\n";
}