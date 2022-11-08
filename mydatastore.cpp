#include <iostream>
#include <sstream>
#include "mydatastore.h"
#include <vector>
#include <map>
#include "util.h"
#include <cmath>

using namespace std;


void MyDataStore::addProduct(Product *p)
{
  allProducts.push_back(p);
}

void MyDataStore::addUser(User* u)
{
  users.push_back(u);
  userCarts[u] = vector<Product*>();
}

void MyDataStore::addProductToCart(string username,vector<Product*> hits, int hitNumber)
{
  if(hitNumber-1 >= hits.size() && hitNumber <=0)
  {
    return; 
  }
  User* isUserMatch = nullptr;  

  for(int i =0; i < users.size(); i++)
  {
    if(username==users[i]->getName())
    {
      isUserMatch =users[i]; 
    }

  }

  if(isUserMatch!= nullptr)
  {
    userCarts[isUserMatch].push_back(hits[hitNumber-1]);
  }
  else{
    cout << "Invalid request" << endl;
  }

}

vector<Product*> MyDataStore::search(vector<string>& terms, int type)
{ 
  vector<Product*> toReturn; 
  //If type equals 0, do And
  if(type==0)
  {
    for(int i=0; i <allProducts.size(); i++)
    { 
      bool isMatch = true; 
      set<string> keywords=allProducts[i]->keywords();
      for(int j=0; j<terms.size(); j++)
      {
        if(keywords.find(terms[j])== keywords.end())
        {
          isMatch = false; 
        }
      }

      if(isMatch)
      {
        toReturn.push_back(allProducts[i]); 
      }
    }
  }
  //Or == 1
  else
  {
    for(int i=0; i <allProducts.size(); i++)
    { 
      bool isMatch = false; 
      set<string> keywords=allProducts[i]->keywords(); 
      
      for(int j=0; j<terms.size(); j++)
      {
        if(keywords.find(terms[j])!= keywords.end())
        {
          isMatch = true; 
        }
      }
      if(isMatch)
      {
        toReturn.push_back(allProducts[i]); 
      }
    }
  }
  return toReturn;
}


void MyDataStore::viewUserCart(string username) 
{
  User* isUserMatch = nullptr;  

  for(int i =0; i < users.size(); i++)
  {
    if(username==users[i]->getName())
    {
      isUserMatch =users[i]; 
    }

  }

  if(isUserMatch!= nullptr)
  {
    for(int i =0; i < userCarts[isUserMatch].size() ; i++)
    {
      cout << "Item " << i+1 << endl;
      cout << userCarts[isUserMatch][i]->displayString();
    }
    
  }
  else{
    cout << "Invalid username" << endl;
  }

}

void MyDataStore::userBuyCart(string username)
{
  User* isUserMatch = nullptr;  
  Product* isProductMatch = nullptr;
  double productPrice; 

  for(int i =0; i < users.size(); i++)
  {
    if(username==users[i]->getName())
    {
      isUserMatch =users[i]; 
    }

  } 

  if(isUserMatch!= nullptr)
  {
    for(int i =0; i < userCarts[isUserMatch].size(); i++)
    {
      if(userCarts[isUserMatch][i]->getQty() > 0)
      {
        productPrice = userCarts[isUserMatch][i]->getPrice();

        if(isUserMatch->getBalance() >= productPrice)
        {
          
          userCarts[isUserMatch][i]->subtractQty(1); 
          
          isUserMatch->deductAmount(productPrice); 

          userCarts[isUserMatch].erase(userCarts[isUserMatch].begin()+i);
          i--; 

        }
      }
    } 

  }
  else
  {
    cout << "Invalid username" << endl;
  }
}

void MyDataStore::dump(std::ostream& ofile){
  ofile << "<products>\n";
  for(int i = 0;i<allProducts.size();i++){
    allProducts[i]->dump(ofile);
  }
  ofile << "</products>\n";
  ofile << "<users>\n";
  for(int i = 0;i<users.size();i++){
    users[i]->dump(ofile);
  }
  ofile << "</users>\n";

  for(int i = 0;i<allProducts.size();i++){
    delete allProducts[i];
  }
  for(int i = 0;i<users.size();i++){
    delete users[i];
  }
}
