#include "Waters.h"

unsigned int Waters::its_my_count = 0;

Waters::Waters(std::string name, unsigned int type, unsigned int width, unsigned int length, unsigned int depth)
	: its_my_name(name), its_my_type(type), its_my_width(width), its_my_length(length),its_my_maximum_depth(depth){
	++its_my_count;
}

Waters::~Waters(){
--its_my_count;
}

void
Waters::Set_type(unsigned int value) {
	if (value > 0 and value < 4)
		its_my_type = value;
}
void
Waters::Set_width(unsigned int value) {
	its_my_width = value;
}
void
Waters::Set_length(unsigned int value) {
	its_my_length = value;
}
void
Waters::Set_depth(unsigned int value) {
	its_my_maximum_depth = value;
}

int
Waters::Comparison_of_areas(Waters& one, Waters& two) {
	if (one.Get_square() > two.Get_square())
		return 1;
	else if (one.Get_square() < two.Get_square())
		return -1;
	else
		return 0;
}

unsigned int
Waters::Get_biggest_waters(std::vector<Waters>& arr, Waters::Water_type type) {
	unsigned int max_square = 0;
	for (Waters& x : arr)
		if (type == x.Get_type() and x.Get_square() > max_square)
			max_square = x.Get_square();
	return max_square;
}