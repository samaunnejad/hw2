#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include "product.h"

class Book: public Product {
public:
    Book(const std::string category, const std::string name, double price, int qty, std::string isbn, std::string author);
    
    ~Book();

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

    std::string getISBN() const;
    std::string getAuthor() const; 

    void subtractQty(int num);

protected:
  std::string isbn_;
  std::string author_;

};
#endif
