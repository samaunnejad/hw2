#ifndef MOVIE_H
#define MOVIE_H
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include "product.h"

class Movie: public Product {
public:
    Movie(const std::string category, const std::string name, double price, int qty, std::string genre, std::string rating);
     ~Movie();


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

    std::string getRating() const;
    std::string getGenre() const; 

    void subtractQty(int num);

    private:
        std::string genre_;
        std::string rating_;

};
#endif
