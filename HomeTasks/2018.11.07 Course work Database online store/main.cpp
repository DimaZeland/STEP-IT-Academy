#include"Product.h"

int main() {
	std::string FilePath = "C:\\Users\\User\\source\\repos\\HomeTask\\HomeTask\\Mobiles.csv"; // default database file path
	std::cout << "Beyond the default, the program uses a database located in the following path:\n\"" << FilePath <<
		"\"\nWould you like to change the path to the database file? <Y/N>: ";
	char ch = ' ';
	std::cin >> ch;
	system("cls");
	switch (ch) {
	case 'Y': case 'y':
		std::cout << "\nEnter new database file path: ";
		std::cin >> FilePath;
		break;
	default:
		break;
	}
	Menu Object(FilePath); // read database file

	bool continueWorkProgram = true;
	do	{
	std::cout << "\nSelect the desired access type (User/Admin) <U/A> or <q> to exit from the program: "; //selection of database access type
	std::cin >> ch;
	system("cls");
	switch (ch) {
	case 'A': case 'a':
		Object.AdminFunctions();
		break;
	case 'U': case 'u':
		Object.UserFunctions();
		break;
	case 'q': case 'Q':
		continueWorkProgram = false;
		break;
	default:
		std::cout << "\nInvalid input!\n";
		break;
	}
	} while (continueWorkProgram);
	std::cout << "\nExit from the program. Bye!\n";
	system("pause");
	return 0;
}