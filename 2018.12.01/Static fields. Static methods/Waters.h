#pragma once

#include<vector>
#include<string>

class Waters
{
private:
	std::string its_my_name = "Noname";
	unsigned int its_my_type = rates;
	unsigned int its_my_width = 0;
	unsigned int its_my_length = 0;
	unsigned int its_my_maximum_depth = 0;
	static unsigned int its_my_count;
public:
	enum Water_type { rates = 1, sea, lake };
	Waters(std::string = "Noname", unsigned int type = 1, unsigned int width = 0, unsigned int length = 0, unsigned int depth = 0);
	~Waters();
	inline unsigned int Get_type() { return its_my_type; }
	inline unsigned int Get_width() { return its_my_width; }
	inline unsigned int Get_length() { return its_my_length; }
	inline unsigned int Get_depth() { return its_my_maximum_depth; }
	inline unsigned int Get_count() { return its_my_count; }
	void Set_type(unsigned int);
	void Set_width(unsigned int);
	void Set_length(unsigned int);
	void Set_depth(unsigned int);
	inline unsigned int Get_volume() { return its_my_length * its_my_width*its_my_maximum_depth; }
	inline unsigned int Get_square() { return its_my_length * its_my_width; }
	static inline bool Same_type(Waters& one, Waters& two) {return one.Get_type() == two.Get_type();}
	static int Comparison_of_areas(Waters& one, Waters& two);
	static unsigned int Get_biggest_waters(std::vector<Waters>&, Water_type);
};

