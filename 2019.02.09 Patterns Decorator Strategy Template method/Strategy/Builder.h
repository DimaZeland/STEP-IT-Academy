#pragma once

#include<iostream>
#include<string>
#include<vector>

class Sort abstract {
protected:
	std::vector<std::string> container;
public:
	Sort(std::vector<std::string> Container) : container(Container) {}
	virtual ~Sort() {}
	virtual void Sorting()abstract;
	std::vector<std::string >& GetContainer() { return container; }
};

class AlphabetSort : public Sort {
public:
	AlphabetSort(std::vector<std::string> Container) : Sort(Container) {}
	void Sorting()override final {
		for (int k = 0; k < container.size() - 1; ++k) { // sort arr [] by insertion method in ascending order
			int m = 0;
			for (int j = k; j >= 0 && container[j].at(m) >= container[j + 1].at(m); ) {
				if (container[j].at(m) > container[j + 1].at(m)) {
					std::swap(container[j], container[j + 1]);
					--j;
					m = 0;
				}
				else if (container[j].at(m) == false || container[j + 1].at(m) == false) // if all letters match
					break;
				else if (container[j].at(m) == container[j + 1].at(m))
					++m;
			}
		}
	}
};

class SizeSort : public Sort {
public:
	SizeSort(std::vector<std::string> Container) : Sort(Container) {}
	void Sorting()override final {
		for (int k = 0; k < container.size() - 1; ++k) // sort arr [] by insertion method in ascending order
			for (int j = k; j >= 0 && container[j].size() >= container[j + 1].size(); --j)
				if (container[j].size() > container[j + 1].size())
					std::swap(container[j], container[j + 1]);
				else
					for (int m = 0; container[j].at(m) != false && container[j].at(m) >= container[j + 1].at(m); ++m)
						if (container[j].at(m) > container[j + 1].at(m)) {
							std::swap(container[j], container[j + 1]);
							break;
						}
	}
};