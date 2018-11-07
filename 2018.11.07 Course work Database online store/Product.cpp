#include "Product.h"

Product::Product(int article, double price, int amoung, std::string manufactured, std::string model) // overload base explicit constructor
	: itsMyArticle(article), itsMyPrice(price), itsMyAmoung(amoung), itsMyManufactured(manufactured), itsMyModel(model) {}

Product::Product(int article, double price, int amoung, const char* manufactured, const char* model) // overload base explicit constructor
	: itsMyArticle(article), itsMyPrice(price), itsMyAmoung(amoung), itsMyManufactured(manufactured), itsMyModel(model) {}

Product::Product(const Product& a) // explicit copy-constrictor
	: itsMyArticle(a.itsMyArticle), itsMyPrice(a.itsMyPrice), itsMyAmoung(a.itsMyAmoung), itsMyManufactured(a.itsMyManufactured), itsMyModel(a.itsMyModel) {}

Product&
Product::operator=(const Product& a) { // explicit assignment operator
	if (&a == this)
		return *this;

	itsMyArticle = a.itsMyArticle;
	itsMyPrice = a.itsMyPrice;
	itsMyAmoung = a.itsMyAmoung;
	itsMyManufactured = a.itsMyManufactured;
	itsMyModel = a.itsMyModel;
	return *this;
}

std::ostream&
operator<<(std::ostream& os, const Product& a) { // overload operator<<
	os << "ID: " <<a.itsMyArticle << "\tPrice(UAH): " << a.itsMyPrice << "\tamount: " << 
		a.itsMyAmoung <<
		"\tModel: " << a.itsMyModel << std::endl;
	return os;
}