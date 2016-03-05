//
//  main.cpp
//  wordsmash
//
//  Created by Graham Zuber on 3/4/16.
//  Copyright © 2016 zuber.io. All rights reserved.
//

#include <iostream>
#include <vector>
#include "TokenizedString.h"

int main(int argc, const char * argv[])
{
    // compile list of words
    std::vector<std::string> asWords;
    for(int i = 1; i < argc; i++)
    {
        asWords.push_back(argv[i]);
    }
    
    // make sure min num of words reached
    while(asWords.size() < 2)
    {
        std::string word;
        std::cout << "enter a word: ";
        getline(std::cin, word);
        asWords.push_back(word);
    }
    
    // tokenize
    TokenizedString left(asWords[0]);
    TokenizedString right(asWords[1]);
    
    std::vector<std::string> leftSylls = left.get_syllables();
    std::vector<std::string> rightSylls = right.get_syllables();
    
    for(int i = 0; i < leftSylls.size(); i++)
    {
        std::cout << leftSylls[i] << std::endl;
    }
    
    for(int i = 0; i < rightSylls.size(); i++)
    {
        std::cout << rightSylls[i] << std::endl;
    }

    // exit
    return 0;
}
