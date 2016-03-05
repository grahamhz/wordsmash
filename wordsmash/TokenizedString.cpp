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

TokenizedString::TokenizedString()
{
    m_sWord = "";
    m_asSylls = StringVector();
}

TokenizedString::TokenizedString(std::string word)
{
    m_sWord = word;
    m_asSylls = tokenize(word);
}

/**
 * Copies
 */

TokenizedString& TokenizedString::operator=(TokenizedString toCopy)
{
    std::swap(m_sWord, toCopy.m_sWord);
    std::swap(m_asSylls, toCopy.m_asSylls);
    return *this;
}

/**
 * Public Methods
 */

StringVector TokenizedString::get_syllables()
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

std::string TokenizedString::get_syllable_string(char cDirection, long lPosition)
{
    std::stringstream stream;
    
    // left tail
    if(cDirection == 'l')
    {
        // don't return the last element of a left tail
        if(lPosition >= m_asSylls.size() - 1)
        {
            lPosition = m_asSylls.size() - 2;
        }
        
        // lPosition is end position
        for(long i = 0; i < lPosition; i++)
        {
            stream << m_asSylls[i];
        }
    }
    else if(cDirection == 'r') // right tail
    {
        // return last element if I wouldn't return anything
        if(lPosition >= m_asSylls.size() - 1)
        {
            stream << m_asSylls.back();
        }
        else
        {
            // lPosition is start position
            for(long i = lPosition; i < m_asSylls.size(); i++)
            {
                stream << m_asSylls[i];
            }
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

StringVector TokenizedString::tokenize(std::string word)
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
