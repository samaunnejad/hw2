#include <sstream>
#include <iomanip>
#include "clothing.h"
#include "util.h"
#include "product.h"
#include <set>
#include <string>

using namespace std;

Clothing::Clothing(const std::string category, const std::string name, double price, int qty, std::string size, std::string brand) :
    Product(category, name, price, qty),
    size_(size),
    brand_(brand)
{

}

Clothing::~Clothing()
{

}

string Clothing::getBrand() const
{
    return brand_;
}

std::string Clothing::getSize() const
{
    return size_;
}

/**
 * default implementation...can be overriden in a future
 * assignment
 */
bool Clothing::isMatch(std::vector<std::string>& searchTerms) const
{
    return false;
}

std::set<std::string> Clothing::keywords() const 
{
    std::set<string> brandName;
    std::set<string> productName;  

    brandName = parseStringToWords(brand_);
    productName = parseStringToWords(name_);
    
    return setUnion(brandName,productName);
    
}

std::string Clothing::displayString() const
{
  std::string toReturn;

  toReturn = category_ + "\n" + name_ + "\n" + std::to_string(price_) + "\n" + std::to_string(qty_) + "\n" + size_ + "\n" + brand_;

  return toReturn;

}

void Clothing::dump(std::ostream& os) const
{
    os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << size_ << "\n" << brand_ << endl;
}



