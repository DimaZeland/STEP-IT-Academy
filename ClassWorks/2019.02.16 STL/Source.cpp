#include<array>
#include<algorithm>
#include<ctime>
#include<fstream>
#include<iostream>
#include<string>
#include<vector>


//void CreateFile(std::string FileName);

int main() {
    //1
    srand(time(0));
    std::array<int, 12> arr;
    std::generate(arr.begin(), arr.end(), [] { return rand() % 12; });
    //2
    std::vector<int> v1, v2;
    std::copy(arr.begin(), arr.begin() + arr.size() / 2, v1);
    std::copy(arr.begin() + arr.size() + 1, arr.end(), v2);
    // //std::_Array_iterator<int, 12> buf = arr.begin();// +(arr.size() / 2);

    //3
    std::random_shuffle(v1.begin(), v1.end());
    std::random_shuffle(v2.begin(), v2.end());
    std::cout << "v1\n";
    for (auto &x: v1)
        std::cout << x << '\n';
    std::cout << "v2\n";
    for (auto &x: v2)
        std::cout << x << '\n';
    //4
    std::copy(v1.begin(), v1.end(), arr);
    std::copy(v2.begin(), v2.end(), arr.begin() + arr.size() / 2);
    //5
    std::swap(*std::min_element(arr.begin(), arr.end()), *std::max_element(arr.begin(), arr.end()));
    //6
    std::cout << "\nEnter a integer number: ";
    int i = 0;
    std::cin >> i;
    if (arr.end() == std::find(arr.begin(), arr.end(), i))
        std::cout << "\nElement " << i << " is not in the array.\n";
    else
        std::cout << "\nElement " << i << " is in the array.\n";
    //7







    //std::ofstream fout;
    //fout.open("cppstudio.txt"); // ñâÿçûâàåì îáúåêò ñ ôàéëîì
    //	fout << "Ðàáîòà ñ ôàéëàìè â Ñ++"; // çàïèñü ñòðîêè â ôàéë
    //fout.close();


    //std::string FilePath = "Zeland.txt";
    //std::ofstream onFile;
    //onFile.open(FilePath);
    //if (!onFile.is_open()) { // failed to open file
    //	std::cout << "Could not open the file " << FilePath << std::endl;
    //	std::cout << "Program terminating.\n";
    //	system("pause");
    //	std::cin.get();    // keep window open
    //	exit(EXIT_FAILURE);
    //}
    //onFile.close();






    system("pause");
    return 0;
}


void CreateFile(std::string FileName) {
    std::string buffer = "";
    std::ofstream newFile(FileName);
    do {
        std::cout << "\nWrite a string of <Ctrl+Z> to exit: ";
        std::cin >> buffer;
        newFile << buffer;
    } while (buffer != "q");
}
//
//#include <fstream>
//#include <iostream>
//#include  <string>
//using namespace std;
//#define Line cout<< "______________________________\n";
//
////void createFile(string filename)
////{
////	
////	//cout << "How many lines:"
////	cout << "Write line until appear 'stop'";
////}
////void printFile(string filename)
////{
////	ifstream in(filename);
////	if (!in.is_open())
////	{
////	return;
////	}
////	string line;
////;
////	while (getline(in, line))
////	{
////	cout << line << endl;
////	//getline(in, line);
////
////
////	}
////	//in.close();
////
////}
////void copyFile(string fromFile, string toFile)
////{
////	// char by char
////	
////}
//
//void printFile(fstream &f)
//{
//	f.clear();
//	f.seekg(0);// , ios::beg);
//	char c;
//	//cout << f.rdbuf() << endl;
//	while ((c = f.get()) != EOF)
//		cout << char(c);
//	cout << endl;
//
//}
//
//int main()
//{
//	char line[256];
//	ofstream out("Abc.txt", ofstream::out);// , ios::out);
//	//out.open("Abc.txt");
//	//if(!out.is_open())
//	if (!out) // !out.good()
//	{
//		cout << "Error opening file for write\n";
//		return  EXIT_FAILURE;
//	}
//
//	cout << "Enter 3  lines:\n";
//	for (int i = 0; i < 3; ++i)
//	{
//		cin.getline(line, 256);
//		out << line << "\n";
//	}
//	out.close();
//	cout << "Test printFile new ()\n";
//	//printFile("Abc.txt");
//	//return 0;
//
//
//	//out.open("defg");
//
//	ifstream in("Abc.txt");//,ios:: in 
//	if (!in.is_open())
//	{
//		cout << "Error opening file for read\n";
//		return  EXIT_FAILURE;
//	}
//	Line
//		cout << "All FILE content:\n";
//
//	while (!in.eof())// in.good()        
//	{
//		//in >> line;
//		in.getline(line, 256);
//		cout << line << endl;
//	}
//	in.close();
//
//	fstream f("Abc.txt", ios::in | ios::out);// | ios::ate);// 000011
//	Line
//		cout << "File Content(rdbuf)\n";
//	//cout << f.rdbuf()->in_avail()<< endl;
//	cout << f.rdbuf() << endl;
//
//	Line
//		f.seekg(0); // to begin of file
//	int c;
//	cout << "Symbols of first (file)line\n";
//	while ((c = f.get()) != '\n'   /*10*/)
//		cout << char(c) << ' ';
//	cout << endl;
//
//	Line
//		cout << "Reading was started from symbol  # 10\n";
//	f.seekg(10, ios::beg);
//	while ((c = f.get()) != EOF)
//		cout << char(c) << ' ';
//	cout << endl;
//	f.clear();
//	//f << flush;
//	Line
//
//		if (f.seekp(-10, ios::end)) // ïåðåì³ñòèëè âêàç³âíèê ó ôàéë³ äëÿ çàïèñó íà -10 áàéò â³äíîñíî îçíàêè çàâåðøåííÿ ôàéëó
//		{
//			f.put('*'); //f << '*';

