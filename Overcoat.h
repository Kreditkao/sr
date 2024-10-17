#ifndef OVERCOAT_H
#define OVERCOAT_H

#include <string>
#include <iostream>

class Overcoat {
public:
    Overcoat();
    Overcoat(const std::string& name, const std::string& type, const std::string& size, double price);

    // Setters
    void setName(const std::string& name);
    void setType(const std::string& type);
    void setSize(const std::string& size);
    void setPrice(double price);

    // Getters
    std::string getName() const;
    std::string getType() const;
    std::string getSize() const;
    double getPrice() const;

    // Comparison operators
    bool operator==(const Overcoat& other) const;
    bool operator!=(const Overcoat& other) const;
    bool operator>(const Overcoat& other) const;
    bool operator>=(const Overcoat& other) const;
    bool operator<(const Overcoat& other) const;
    bool operator<=(const Overcoat& other) const;

    // Increment and decrement operators
    Overcoat& operator++();    // Prefix increment
    Overcoat operator++(int);  // Postfix increment
    Overcoat& operator--();    // Prefix decrement
    Overcoat operator--(int);  // Postfix decrement

    // Input/output operators
    friend std::ostream& operator<<(std::ostream& os, const Overcoat& overcoat);
    friend std::istream& operator>>(std::istream& is, Overcoat& overcoat);

private:
    std::string name_;
    std::string type_;
    std::string size_;
    double price_;
};

#endif // OVERCOAT_H
