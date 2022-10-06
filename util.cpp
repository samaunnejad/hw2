#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include "util.h"

using namespace std;
std::string convToLower(std::string src)
{
    std::transform(src.begin(), src.end(), src.begin(), ::tolower);
    return src;
}

/** Complete the code to convert a string containing a rawWord
    to a set of words based on the criteria given in the assignment **/
std::set<std::string> parseStringToWords(string rawWords)
{
    
    //Count number of words in rawWords
    stringstream ss(rawWords);

    //store each word
    string word, wordToAdd;

    std::set<string> wordSet;

    //loop through rawWords till we get strings to store in word
    while(ss >> word)
    { 
        //iterate across every character in word
        //when we come across a punctuation mark:
            //check if wordtoAdd is > 1 character in size
            //if so, add wordToAdd to the set of strings to return
        wordToAdd = "";
        for(int i=0; i < word.size(); i++) 
        {
<<<<<<< HEAD
            if(ispunct(word[i]) || word[i] == ' ')
            {
               if(wordToAdd.size() > 1)
               {
                 wordSet.insert(convToLower(wordToAdd));
                 wordToAdd = "";
=======
            if(ispunct(word[i]))
            {
               if(wordToAdd.size() > 1)
               {
                 wordSet.insert(wordToAdd);
>>>>>>> 051d493f486fe3682a802729d1a8283af4c4c474
               }
               else
               {
                   wordToAdd = "";
               }
                
            }
            else 
            {
                wordToAdd+= word[i];
            }

<<<<<<< HEAD
            
        }
        if(wordToAdd.size() > 1)
            {
                wordSet.insert(convToLower(wordToAdd));
            }
=======
            if(wordToAdd.size() > 1)
            {
                wordSet.insert(wordToAdd);
            }
        }


>>>>>>> 051d493f486fe3682a802729d1a8283af4c4c474
    }

    return wordSet;     
}

/**************************************************
 * COMPLETED - You may use the following functions
 **************************************************/

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// trim from start
std::string &ltrim(std::string &s) {
    s.erase(s.begin(), 
	    std::find_if(s.begin(), 
			 s.end(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

// trim from end
std::string &rtrim(std::string &s) {
    s.erase(
	    std::find_if(s.rbegin(), 
			 s.rend(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))).base(), 
	    s.end());
    return s;
}

// trim from both ends
std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
}
