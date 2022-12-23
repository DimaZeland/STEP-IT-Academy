#include<iostream>
#include<string>
#include"Person.h"

//class Group {
//private:
//	std::string its_my_name = "Noname";
//	Person Leader;
//	Person* group;
//	size_t size;
//public:
	
	
	
	
Group::Group() : its_my_name("Noname"), group(nullptr), size(0), Leader() {}

Group::Group(Person leader, Person* def_group, size_t def_size, std::string name): Leader(leader), group(def_group), size(def_size), its_my_name(name) {}

Group::~Group() {
	delete[] group;
	group = nullptr;
}

void
Group::Set_Leader() {
	Leader.Input_Name();
	Leader.Input_Hobby();
	Leader.Input_Birth();
}

void
Group::Set_group(Person* buf_group, size_t Size) {
	
	delete[] group;
	size = Size;
	group = new Person[size];

	for (int i = 0; i < size; ++i) {
		group[i].Set_itsMyName(buf_group[i].Get_Name());
		group[i].Set_itsMyHobby(buf_group[i].Get_Hobby());
		group[i].Set_itsMyBirth(buf_group[i].Get_Birth());
	}
}

std::ostream& operator<<(std::ostream& os, Group& my_Group) {
	os << "\n Group name is " << my_Group.Get_name() <<
		"\nLeader info:\n" << "Leader name is " << my_Group.Leader.Get_Name() <<
		"\nLeader hobby is " << my_Group.Leader.Get_Hobby() <<
		"\nLeader birth is " << my_Group.Leader.Get_Birth() <<
		"\nGroup info:\n" << "Group size: " << my_Group.size << std::endl;
	for (int i = 0; i < my_Group.size; ++i) {
		os << i + 1 << ' ' << my_Group.group[i].Get_Name() << ' ' << my_Group.group[i].Get_Birth() << ' ' << my_Group.group[i].Get_Hobby() << '\n';
	}
	return os;
}
	




