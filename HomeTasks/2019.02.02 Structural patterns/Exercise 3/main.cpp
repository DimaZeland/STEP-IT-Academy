#include<iostream>
#include <Windows.h>
#include"Builder.h"
#include <msclr/marshal.h>
// ���������� ���������� ������������� �������� ��������� ��� � �� ����
// ��� ����������� ����� �������� ��� ����� ��������������� ���� ���, ����� ���� ����������� ������� ����-���� �������: ���� ���������, ����� ���� ��������
using namespace std;

int main() {
    setlocale(LC_CTYPE, "rus");
    //SetConsoleCP(1251);// ��������� ������� �������� win-cp 1251 � ����� �����
    //SetConsoleOutputCP(1251); // ��������� ������� �������� win-cp 1251 � ����� ������
    std::string FilePath = "C:\\Users\\User\\source\\repos\\HomeTask\\HomeTask\\RusEngTranslatorList.csv";
    ofstream *file = new ofstream(FilePath);

    std::vector <Word> list{Word("eins", "one"), Word("zwei", "two"), Word("drei", "three"), Word("vier", "four")};
    WordCollection wordcollection(list);
    Translator translator(&wordcollection);
    Record record(&translator, FilePath);
    Facade facade(&record);
    std::string textpro = "eins zwei drei vier ";
    //std::wstring text = msclr::interop::marshal_as<wstring>(textpro);
    //std::cout << textpro << " to English: " << msclr::interop::marshal_as<string>(facade.GetTranslateText(text)) << std::endl;
    std::cout << "German text " << textpro << " to English: " << facade.GetTranslateText(textpro) << std::endl;


    system("pause");
    return 0;
}