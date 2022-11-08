#ifndef CLOTHING_H
#define CLOTHING_H
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include "product.h"
#include <algorithm>


class Clothing: public Product {
public:
    Clothing(const std::string category, const std::string name, double price, int qty, std::string size, std::string brand);
     ~Clothing();

    /**
     * Allows for a more detailed search beyond simple keywords
     */
     bool isMatch(std::vector<std::string>& searchTerms) const;

    std::set<std::string> keywords() const;
    std::string displayString() const;


    /**
     * Outputs the product info in the database format
     */
     void dump(std::ostream& os) const;

    /**
     * Accessors and mutators
     */
    double getPrice() const;
    std::string getName() const;
    int getQty() const;

    std::string getSize() const;
    std::string getBrand() const; 

    void subtractQty(int num);

private:
    std::string size_;
    std::string brand_;

};
#endif