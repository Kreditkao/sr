#ifndef SHOP_H
#define SHOP_H

#include "Overcoat.h"
#include <vector>
#include <algorithm>

class Shop {
public:
    void addOvercoat(const Overcoat& overcoat);
    void removeOvercoat(size_t index);
    void editOvercoatSize(size_t index, bool increase);
    std::vector<Overcoat> findOvercoatsByType(const std::string& type) const;
    void sortOvercoatsByPrice();

    void displayAllOvercoats() const;

    std::vector<Overcoat> shop_;
};

#endif 
