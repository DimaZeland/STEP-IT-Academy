#include "Car.h"

Car::Car() : Year(0), Color(Car::Red), Brand(Car::BMW) { // default constructor overload
    Model = new char[30];
}

Car::Car(int _year, const char *_model, Colors _color, Brands _brand) : Year(_year), Color(_color),
                                                                        Brand(_brand) { // constructor with formal arguments
    Model = new char[30];
    strcpy(Model, _model);
    Model[strlen(_model) + 1] = '\0';
}

Car::~Car() { // default destructor overload
    delete[] Model;
}

Car::Car(const Car &avto) : Year(avto.Year), Model(new char[30]), Color(avto.Color),
                            Brand(avto.Brand) { // overloaded deep copy constructor
    strcpy(Model, avto.Model);
    Model[strlen(avto.Model) + 1] = '\0';
}

Car &
Car::operator=(const Car &avto) { // overloaded assignment operator (deep)
    if (this == &avto)
        return *this;
    delete[] Model;
    Year = avto.Year;
    Model = new char[30];
    Color = avto.Color;
    Brand = avto.Brand;
    strcpy(Model, avto.Model);
    Model[strlen(avto.Model) + 1] = '\0';
    return *this;
}

void
Car::Fill() { // filling in the class object fields
    std::cout << "\nEnter the Year: ";
    std::cin >> Year;
    std::cout << "\nEnter the Model: ";
    //char ModelBuf[30];
    std::cin >> Model;
    std::cout << "Enter color of the car: 1 - Red, 2 - Blue, 3 - Green: ";
    int color = 0;
    std::cin >> color;
    Color = Colors(color + 1);
    std::cout << "Enter brand of the car: 1 - BMW, 2 - Mercedes, 3 - Audi: ";
    int brand = 0;
    std::cin >> brand;
    Brand = Brands(brand + 1);
}

void
Car::Edit() { // edit the class object
    std::cout << "\nEnter the new Year: ";
    std::cin >> Year;
    std::cout << "\nEnter the new Model: ";
    //char ModelBuf[30];
    std::cin >> Model;
    std::cout << "Enter new color of the car: 1 - Red, 2 - Blue, 3 - Green: ";
    int color = 0;
    std::cin >> color;
    Color = Colors(color + 1);
    std::cout << "Enter new brand of the car: 1 - BMW, 2 - Mercedes, 3 - Audi: ";
    int brand = 0;
    std::cin >> brand;
    Brand = Brands(brand + 1);
}

std::ostream &
operator<<(std::ostream &os, Car &avto) { // output statement overload
    char brand[9]{'\0'};
    switch (avto.Brand) {
        case Car::BMW:
            strcpy(brand, "BMW");
            brand[3] = '\0';
            break;
        case Car::Mercedes:
            strcpy(brand, "Mercedes");
            brand[8] = '\0';
            break;
        case Car::Audi:
            strcpy(brand, "Audi");
            brand[4] = '\0';
            break;
        default:
            strcpy(brand, "BMW\0");
            break;
    }

    char color[6] = " ";
    switch (avto.Color) {
        case Car::Red:
            strcpy(color, "Red");
            color[3] = '\0';
            break;
        case Car::Blue:
            strcpy(color, "Blue");
            color[4] = '\0';
            break;
        case Car::Green:
            strcpy(color, "Green");
            brand[5] = '\0';
            break;
        default:
            strcpy(color, "Red");
            color[3] = '\0';
            break;
    }

    os << "\nBrand: " << brand << ", Model:" << avto.Model << ", Year: " << avto.Year << ", Color" << color
       << std::endl;
    return os;
}