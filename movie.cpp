#include <sstream>
#include <iomanip>
#include "movie.h"
#include "util.h"
#include "product.h"
#include <set>
#include <string>

using namespace std;

Movie::Movie(const std::string category, const std::string name, double price, int qty, std::string genre, std::string rating) :
    Product(category, name, price, qty),
    genre_(genre),
    rating_(rating)
{

}

Movie::~Movie()
{

}

string Movie::getGenre() const
{
    return genre_;
}

std::string Movie::getRating() const
{
    return rating_;
}

/**
 * default implementation...can be overriden in a future
 * assignment
 */
bool Movie::isMatch(std::vector<std::string>& searchTerms) const
{
    return false;
}


std::set<std::string> Movie::keywords() const
{
    std::set<string> genreName;
    std::set<string> productName;  

    genreName = parseStringToWords(genre_);
    productName = parseStringToWords(name_);
    
    return setUnion(genreName,productName);
    
}

std::string Movie::displayString() const
{
  std::string toReturn;

  toReturn = category_ + "\n" + name_ + "\n" + std::to_string(price_) + "\n" + std::to_string(qty_) + "\n" + genre_ + "\n" + rating_;

  return toReturn;

}

void Movie::dump(std::ostream& os) const
{
    os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << genre_ << "\n" << rating_ << endl;
}



