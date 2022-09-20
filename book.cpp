#include <sstream>
#include <iomanip>
#include <set>
#include <string>
#include "book.h"
#include "util.h"
#include "product.h"

using namespace std;

Book::Book(const std::string category, const std::string name, double price, int qty, std::string isbn, std::string author):

    Product(category, name, price, qty),
    isbn_(isbn),
    author_(author)
{

}

Book::~Book()
{

}

std::string Book::getISBN() const
{
    return isbn_;
}

std::string Book::getAuthor() const
{
    return author_;
}

/**
 * default implementation...can be overriden in a future
 * assignment
 */
bool Book::isMatch(std::vector<std::string>& searchTerms) const
{

    return false;
}

std::set<std::string> Book::keywords()  const
{
    std::set<string> authorName; 
    std::set<string> isbnNumber;
    std::set<string> bookName;  
    std::set<string> toReturn; 


    authorName = parseStringToWords(author_);
    isbnNumber = parseStringToWords(isbn_);
    bookName = parseStringToWords(name_);

    toReturn = setUnion(authorName, isbnNumber);
    

    return setUnion(toReturn, bookName);
    
}

std::string Book::displayString() const
{
  std::string toReturn;

  toReturn = category_ + "\n" + name_ + "\n" + std::to_string(price_) + "\n" + std::to_string(qty_) + "\n" + isbn_ + "\n" + author_;

  return toReturn;

}

void Book::dump(std::ostream& os) const
{
    os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << isbn_ << "\n" << author_ << endl;
}



