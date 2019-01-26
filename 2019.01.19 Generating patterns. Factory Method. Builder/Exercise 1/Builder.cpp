#include "Builder.h"

std::ostream&
operator<<(std::ostream& os, const House* pHouse) {
	os << "\nHouse basement: " << pHouse->basement << ", House wall: " << pHouse->wall << ", House roof: " << pHouse->roof <<
		", House windows: " << pHouse->windows << ", House doors: " << pHouse->doors << std::endl;
	return os;
}

std::ostream&
operator<<(std::ostream& os, const Cost* pHouse) {
	os << "\nHouse basement: " << pHouse->basement << ", House wall: " << pHouse->wall << ", House roof: " << pHouse->roof <<
		", House windows: " << pHouse->windows << ", House doors: " << pHouse->doors << std::endl;
	return os;
}

std::ostream&
operator<<(std::ostream& os, AbstractHouse* pHouse) {
	if (dynamic_cast<House*>(pHouse)) {
		House* hpHouse = dynamic_cast<House*>(pHouse);
		return os << hpHouse;
	}
	if (dynamic_cast<Cost*>(pHouse)) {
	Cost* ppHouse = dynamic_cast<Cost*>(pHouse);
		return os << ppHouse;
	}
}

void
Director::ConstructBuilding(Builder* builder) {
	builder->Reset();
	builder->SetBasement();
	builder->SetWall();
	builder->SetRoof();
	builder->SetWindows();
	builder->SetDoors();
}

AbstractHouse*
Application::MakeBuilding(Builder* DynamicPointer) {
	director = new Director;
	pBuilder = DynamicPointer;
	director->ConstructBuilding(pBuilder);
	return pBuilder->GetResult();
}
