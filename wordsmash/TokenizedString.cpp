//
//  TokenizedString.cpp
//  wordsmash
//
//  Created by Graham Zuber on 3/4/16.
//  Copyright © 2016 zuber.io. All rights reserved.
//

#include "TokenizedString.h"

/**
 * Constructors
 */

TokenizedString::TokenizedString(std::string word)
{
    m_sWord = word;
    m_asSylls = tokenize(word);
}

/**
 * Public Methods
 */

std::vector<std::string> TokenizedString::get_syllables()
{
    return m_asSylls;
}

long TokenizedString::get_syllable_count()
{
    return m_asSylls.size();
}

std::string TokenizedString::get_syllable_string()
{
    return m_sWord;
}

std::string TokenizedString::get_syllable_string(long start)
{
    std::stringstream stream;
    for(long i = start; i < m_asSylls.size(); i++)
    {
        stream << m_asSylls[i];
    }
    return stream.str();
}

std::string TokenizedString::get_syllable_string(long start, long end)
{
    std::stringstream stream;
    for(long i = start; i < m_asSylls.size(); i++)
    {
        stream << m_asSylls[i];
        if(i == end)
        {
            break;
        }
    }
    return stream.str();
}

/**
 * Private Methods
 */

bool TokenizedString::is_vowel(char letter)
{
    // see if it matches a vowel
    if(m_sVowels.find(letter) == std::string::npos)
    {
        return false;
    }
    return true;
}

std::vector<std::string> TokenizedString::tokenize(std::string word)
{
    // init vars
    std::vector<std::string> asTokens;
    std::string syll;
    
    // find syllables
    for(long i = 0; i < word.length(); i++)
    {
        char letter = word.at(i);
        syll += letter;
        
        if(is_vowel(letter) || i == word.length() - 1)
        {
            asTokens.push_back(syll);
            syll = "";
        }
    }
    
    return asTokens;
}
