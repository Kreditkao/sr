#include "Overcoat.h"


Overcoat::Overcoat() : name_(""), type_(""), size_(""), price_(0.0) {}
Overcoat::Overcoat(const std::string& name, const std::string& type, const std::string& size, double price)
    : name_(name), type_(type), size_(size), price_(price) {}

// Setters
void Overcoat::setName(const std::string& name) {
    name_ = name;
}
void Overcoat::setType(const std::string& type) {
    type_ = type;
}
void Overcoat::setSize(const std::string& size) {
    size_ = size;
}
void Overcoat::setPrice(double price) {
    price_ = price;
}

// Getters
std::string Overcoat::getName() const {
    return name_;
}
std::string Overcoat::getType() const {
    return type_;
}
std::string Overcoat::getSize() const {
    return size_;
}
double Overcoat::getPrice() const {
    return price_;
}

//operators
bool Overcoat::operator==(const Overcoat& other) const {
    return type_ == other.type_;
}
bool Overcoat::operator!=(const Overcoat& other) const {
    return !(*this == other);
}
bool Overcoat::operator>(const Overcoat& other) const {
    return price_ > other.price_;
}
bool Overcoat::operator>=(const Overcoat& other) const {
    return price_ >= other.price_;
}
bool Overcoat::operator<(const Overcoat& other) const {
    return price_ < other.price_;
}
bool Overcoat::operator<=(const Overcoat& other) const {
    return price_ <= other.price_;
}

// Increment and decrement operators
Overcoat& Overcoat::operator++() {
    size_ = std::to_string(std::stoi(size_) + 1);
    return *this;
}
Overcoat Overcoat::operator++(int) {
    Overcoat temp = *this;
    ++(*this);
    return temp;
}
Overcoat& Overcoat::operator--() {
    size_ = std::to_string(std::stoi(size_) - 1);
    return *this;
}
Overcoat Overcoat::operator--(int) {
    Overcoat temp = *this;
    --(*this);
    return temp;
}


std::ostream& operator<<(std::ostream& os, const Overcoat& overcoat) {
    os << "Name: " << overcoat.name_ << ", Type: " << overcoat.type_
        << ", Size: " << overcoat.size_ << ", Price: " << overcoat.price_;
    return os;
}

std::istream& operator>>(std::istream& is, Overcoat& overcoat) {
    std::cout << "Enter name: ";
    is >> overcoat.name_;
    std::cout << "Enter type (men/women/kids): ";
    is >> overcoat.type_;
    std::cout << "Enter size: ";
    is >> overcoat.size_;
    std::cout << "Enter price: ";
    is >> overcoat.price_;
    return is;
}
