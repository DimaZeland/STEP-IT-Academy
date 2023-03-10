#pragma once

#include<vector>

class Student {
private:
	std::string its_my_surname = "Noname";
	std::vector<unsigned int> its_my_rating;
	int its_my_number_of_ratings = its_my_rating.size();
	static const unsigned int its_my_max_rating = 12;
	static const unsigned int its_my_min_rating = 1;
public:
	Student(std::string surname = "Noname");
	Student(const Student&);
	~Student();
	friend std::ostream& operator<<(std::ostream& os, Student& obj);
	inline std::string Get_surname() { return its_my_surname; }
	void Set_surname(std::string);
	inline unsigned int Get_number_of_ratings() { its_my_number_of_ratings = its_my_rating.size(); return its_my_number_of_ratings; }
	void Change_rating();
	inline void Push_rating(unsigned int rating) { if (rating > 0 and rating <= its_my_max_rating) its_my_rating.push_back(rating); }
};
