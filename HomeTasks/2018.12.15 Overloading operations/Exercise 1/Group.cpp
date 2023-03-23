#include<iostream>
#include<string>
#include"Person.h"

Group::Group() : its_my_name("Noname"), size(0), Leader() {}

Group::Group(Person leader, std::vector <Person> def_group, size_t def_size, std::string name) : Leader(leader),
                                                                                                 group(def_group),
                                                                                                 size(def_size),
                                                                                                 its_my_name(name) {}

Group::Group(const Group &obj) {
    its_my_name = obj.its_my_name;
    Leader = obj.Leader;
    group = obj.group;
    size = obj.size;
}

Group::~Group() {}

void
Group::Set_Leader() {
    Leader.Input_Name();
    Leader.Input_SecondName();
    Leader.Input_Birth();
}

void
Group::Set_group(std::vector <Person> buf_group, size_t Size) {
    group = buf_group;
    size = buf_group.size();
}

std::ostream &operator<<(std::ostream &os, Group &my_Group) {
    os << "\n Group name is " << my_Group.Get_name() <<
       "\nLeader info:\n" << "Leader name is " << my_Group.Leader.Get_Name() <<
       "\nLeader second name is " << my_Group.Leader.Get_SecondName() <<
       "\nLeader birth is " << my_Group.Leader.Get_Birth() <<
       "\nGroup info:\n" << "Group size: " << my_Group.size << std::endl;
    for (int i = 0; i < my_Group.size; ++i) {
        os << i + 1 << ' ' << my_Group.group[i].Get_Name() << ' ' << my_Group.group[i].Get_Birth() << ' '
           << my_Group.group[i].Get_SecondName() << '\n';
    }
    return os;
}

std::istream &
operator>>(std::istream &is, Group &Gr) {
    std::string name;
    std::cout << "\nSet group name: ";
    is >> name;
    Gr.Set_name(name);

    for (Person &x: Gr.group)
        is >> x;

    Gr.Set_leader();
    return is;
}

void
Group::Show_Year(unsigned int years) {
    years = 2018 - years;
    for (Person &x: group)
        if (x.Get_Years() < years)
            x.Show_Data();
}

int
Group::AverageYears() {
    int average_years = 0;
    for (Person &x: group)
        average_years += x.Get_Years();
    size = group.size();
    average_years /= size;
    return average_years;
}

void
Group::Set_member() {
    std::cout << "Enter number of person 1-" << group.size() << ":";
    unsigned short int i = 0;
    std::cin >> i;
    if (i > size) {
        std::cout << "invalid output";
        return;
    }
    --i;
    group[i].Set_Data();
}

void
Group::Set_leader() {
    Leader.Set_Data();
}

void
Group::Person_push_back(Person one) {
    group.push_back(one);
}

void
Group::Person_pop() {
    std::cout << "Enter number of person 1-" << group.size() << ":";
    int i = 0;
    std::cin >> i;
    if (i > size) {
        std::cout << "invalid output";
        return;
    }
    --i;
    group.erase(group.begin() + i);
}

Group &
Group::operator=(const Group &other) {
    if (this != &other) {
        Set_name(other.Get_name());
        Set_group(other.group, other.size);
        Leader = other.Leader;
        size = other.size;
    }
    return *this;
}

const Person &
Group::operator[](int i) const {
    if (i >= 0 and i < size)
        return group[i];
    else
        return group[0];
}