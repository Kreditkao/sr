#include "Shop.h"

void Shop::addOvercoat(const Overcoat& overcoat) {
    shop_.push_back(overcoat);
}

void Shop::removeOvercoat(size_t index) {
    if (index < shop_.size()) {
        shop_.erase(shop_.begin() + index);
    }
}

void Shop::editOvercoatSize(size_t index, bool increase) {
    if (index < shop_.size()) {
        int newSize = std::stoi(shop_[index].getSize()) + (increase ? 2 : -2);
        shop_[index].setSize(std::to_string(newSize));
    }
}

std::vector<Overcoat> Shop::findOvercoatsByType(const std::string& type) const {
    std::vector<Overcoat> result;
    for (const auto& overcoat : shop_) {
        if (overcoat.getType() == type) {
            result.push_back(overcoat);
        }
    }
    return result;
}

void Shop::sortOvercoatsByPrice() {
    std::sort(shop_.begin(), shop_.end(), [](const Overcoat& a, const Overcoat& b) {
        return a.getPrice() < b.getPrice();
        });
}

void Shop::displayAllOvercoats() const {
    for (const auto& overcoat : shop_) {
        std::cout << overcoat << std::endl;
    }
}
