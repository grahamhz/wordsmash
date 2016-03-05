//
//  TokenizedString.h
//  wordsmash
//
//  Created by Graham Zuber on 3/4/16.
//  Copyright © 2016 zuber.io. All rights reserved.
//

#ifndef TokenizedString_h
#define TokenizedString_h

#include <stdio.h>
#include <iostream>
#include <vector>
#include <sstream>
#include <utility>

typedef std::vector<std::string> StringVector;

class TokenizedString
{
    
public:
    // constructors
    TokenizedString();
    TokenizedString(std::string word);
    
    // copies
    TokenizedString& operator=(TokenizedString toCopy);
    
    // public member functions
    StringVector get_syllables();
    long get_syllable_count();
    std::string get_syllable_string();
    std::string get_syllable_string(char cDirection, long llPosition);
    
private:
    // private member variables
    const std::string m_sVowels = "aAeEiIoOuUyY";
    std::string m_sWord;
    StringVector m_asSylls;
    
    // private member functions
    bool is_vowel(char letter);
    StringVector tokenize(std::string word);
    
};

#endif /* TokenizedString_h */
