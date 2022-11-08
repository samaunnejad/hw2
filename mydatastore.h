#ifndef MYDATASTORE_H
#define MYDATASTORE_H

#include<iostream>
#include<string>
#include "user.h"
#include <set>
#include <vector>
#include <map>
#include "datastore.h"


class MyDataStore: public DataStore {

  public:   

    MyDataStore(){};

    ~MyDataStore() { };

    void addProduct(Product *p);

    void addUser(User* u);

    std::vector<Product*> search(std::vector<std::string>& terms, int type);

    void addProductToCart(std::string username, std::vector<Product*> hits, int hitNumber);

    void viewUserCart(std::string username); 

    void userBuyCart(std::string username); 

    void dump(std::ostream& ofile);

    protected:
      std::vector<User*> users; 
      std::vector<Product*> allProducts; 
      std::map<User*, std::vector<Product*>> userCarts;

};
#endif // !MyDATASTORE_H