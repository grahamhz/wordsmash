//
//  main.cpp
//  wordsmash
//
//  Created by Graham Zuber on 3/4/16.
//  Copyright © 2016 zuber.io. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_set>
#include "TokenizedString.h"
#include "Smasher.h"

int main(int argc, const char * argv[])
{
    // compile list of words
    StringVector asWords;
    for(int i = 1; i < argc; i++)
    {
        asWords.push_back(argv[i]);
    }
    
    std::string word;
    
    // make sure min num of words reached
    while(asWords.size() < 2)
    {
        std::cout << "enter a word: ";
        getline(std::cin, word);
        asWords.push_back(word);
    }
    
    // tokenize
    TokenizedString left(asWords[0]);
    TokenizedString right(asWords[1]);
    
    // memo it
    std::unordered_set<std::string> memo;
    std::unordered_set<std::string>::const_iterator memoCheck;
    
    // smash it
    Smasher smash(left, right);
    StringVector smashed = smash.smash_it();
    
    // print it
    for(long i = 0; i < smashed.size(); i++)
    {
        if(memo.find(smashed[i]) == memo.end())
        {
            memo.insert(smashed[i]);
            std::cout << std::endl << smashed[i];
        }
    }
    
    // reverse it
    smash.set_strings(right, left);
    smashed = smash.smash_it();
    
    // print it
    for(long i = 0; i < smashed.size(); i++)
    {
        if(memo.find(smashed[i]) == memo.end())
        {
            memo.insert(smashed[i]);
            std::cout << std::endl << smashed[i];
        }
    }
    
    // for sanity
    std::cout << std::endl;

    // exit
    return 0;
}
