#include<string>
#include<iostream>
#include<vector>
#include<fstream>
//#include <windows.h>

class Word {
public:
	std::string rus;
	std::string eng;
	Word(std::string r, std::string e) : rus(r), eng(e) {}
};

class Record;

class WordCollection {
protected:
	std::vector<Word> list;
public:
	WordCollection(std::vector<Word> l) : list(l) {}
	std::string GetEnglishTranslate(std::string rus)const {
		for (auto x : list)
			if (x.rus == rus)
				return x.eng;
		return "there is no translation in the dictionary";
	}

	void ChangeTranslating(std::string rus, std::string eng) {
		bool rewrite = false;
		for (auto x : list)
			if (x.rus == rus) {
				x.eng = eng;
				rewrite = true;
			}
		if (rewrite == false)
			list.push_back(Word(rus, eng));
	}
	friend class Record;
};

class Translator {
protected:
	WordCollection * wordCollection = nullptr;
public:
	Translator(WordCollection * wCollection) : wordCollection(wCollection) {}
	std::string OutputTranslate(std::string r) const { return wordCollection->GetEnglishTranslate(r); }
	void ChangeTranslate(std::string r, std::string e) { wordCollection->ChangeTranslating(r, e); }
	friend class Record;
};

class Facade;

class Record {
protected:
	Translator * translator;
	std::string FilePath = "C:\\Users\\User\\source\\repos\\HomeTask\\HomeTask\\RusEngTranslatorList.csv";
public:
	Record(Translator* tr, std::string filePath) : translator(tr), FilePath(filePath) {
		ReadFile();
	}
	~Record() { RewriteFile(); }
	void RewriteFile()const {
		std::ofstream outFile;
		outFile.open(FilePath);
		outFile << "Ger;Eng;\n";
		for (Word x : translator->wordCollection->list)
			outFile << x.rus << ';' << x.eng << '\n';
		outFile.close();
	}

	void ReadFile() {
		int index = 0;
		std::ifstream inFile;
		inFile.open(FilePath);

		if (!inFile.is_open()) { // failed to open file
			std::cout << "Could not open the file " << FilePath << std::endl;
			std::cout << "Program terminating.\n";
			system("pause");
			std::cin.get();    // keep window open
			exit(EXIT_FAILURE);
		}

		std::string buffer, russian, english;
		char buf = ' ';
		if (inFile.peek()) { //if File is full
			inFile >> buffer; // pass "Ger"
			inFile.get(buf);  // pass ';'
			inFile >> buffer; // pass "Eng"
			inFile.get(buf); // pass ';'

			while (inFile >> russian) { // while !+ EOF
				inFile.get(buf); // pass ';'
				inFile >> english;
				translator->wordCollection->list.push_back(Word(russian, english));
				inFile.get(buf); // pass ';'
			}
		}
		inFile.close();
	}
	friend class Facade;
};

class Facade {
protected:
	Record * record;
public:
	Facade(Record* r) : record(r) {}
	std::string GetTranslateWord(std::string w) { return record->translator->OutputTranslate(w); }
	void ChTranslatingWord(std::string r, std::string e) { record->translator->ChangeTranslate(r, e); }
	std::string GetTranslateText(std::string w) {
		std::string buf, translating;
		for (int i = 0; i < w.size(); ++i) {
		if (isspace(w[i]) == false) {
		buf += w[i];
			}
			else {
			translating += GetTranslateWord(buf);
				translating += w[i];
				buf = "";
			}
		}
		return translating;
	}
};