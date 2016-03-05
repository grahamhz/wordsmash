//
//  Smasher.cpp
//  wordsmash
//
//  Created by Graham Zuber on 3/4/16.
//  Copyright © 2016 zuber.io. All rights reserved.
//

#include "Smasher.h"

Smasher::Smasher()
{
    m_lLSize = -1;
    m_lRSize = -1;
    m_lLMiddle = -1;
    m_lRMiddle = -1;
}

Smasher::Smasher(TokenizedString left, TokenizedString right)
{
    // set strings
    m_Left = left;
    m_Right = right;
    
    // calculate size and middle
    m_lLSize = left.get_syllable_count();
    m_lRSize = right.get_syllable_count();
    m_lLMiddle = m_lLSize / 2;
    m_lRMiddle = m_lRSize / 2;
}

void Smasher::set_strings(TokenizedString left, TokenizedString right)
{
    // set strings
    m_Left = left;
    m_Right = right;
    
    // calculate size and middle
    m_lLSize = left.get_syllable_count();
    m_lRSize = right.get_syllable_count();
    m_lLMiddle = m_lLSize / 2;
    m_lRMiddle = m_lRSize / 2;
}

/**
 * calculates the max offset you can access lower than the index value
 * @param {long} max: max offset we'd like to access
 * @param {long} index: starting point to calculate offset from
 * @return {long} max offset
 */
long Smasher::get_max_offset(long lMax, long lIndex)
{
    if(lIndex - lMax <= 1)
    {
        return lIndex - 1;
    }
    else
    {
        return lMax;
    }
}

/**
 * calculates the max offset you can access higher than the index value
 * @param {long} max: max offset we'd like to access
 * @param {long} index: starting point to calculate offset from
 * @return {long} max offset
 */
long Smasher::get_max_offset(long lMax, long lIndex, long lSize)
{
    long lLastElem = lSize - 1;
    if( (lIndex + lMax) > lLastElem )
    {
        return lLastElem - lIndex;
    }
    else
    {
        return lMax;
    }
}


std::string Smasher::string_generator(long lLeftOffset, long lRightOffset)
{
    std::stringstream stream;
    stream << m_Left.get_syllable_string('l', m_lLMiddle + lLeftOffset);
    stream << m_Right.get_syllable_string('r', m_lRMiddle + lRightOffset);
    return stream.str();
}



StringVector Smasher::smash_it()
{
    // init vars
    StringVector asSmashed;
    
    if(m_lLSize < 0 || m_lRSize < 0)
    {
        throw;
    }

    // shrink left
    long lLeftCounter = -1 * get_max_offset(m_lVariations, m_lLMiddle); // left offset
    long lRightCounter = -1 * get_max_offset(m_lVariations, m_lRMiddle); // left offset
    
    while(lLeftCounter <= 0 || lRightCounter <= 0)
    {
        asSmashed.push_back(string_generator(lLeftCounter, lRightCounter));
        
        if(lLeftCounter <= 0)
        {
            lLeftCounter++;
        }
        
        if(lRightCounter <= 0)
        {
            lRightCounter++;
        }
    }
    
    // shrink right
    lLeftCounter = get_max_offset(m_lVariations, m_lLMiddle, m_lLSize); // right offset
    lRightCounter = get_max_offset(m_lVariations, m_lRMiddle, m_lRSize); // right offset
    
    while(lLeftCounter <= get_max_offset(m_lVariations, m_lLMiddle, m_lLSize) ||
          lRightCounter <= get_max_offset(m_lVariations, m_lRMiddle, m_lRSize))
    {
        asSmashed.push_back(string_generator(lLeftCounter, lRightCounter));
        
        if(lLeftCounter <= get_max_offset(m_lVariations, m_lLMiddle, m_lLSize))
        {
            lLeftCounter++;
        }
        
        if(lRightCounter <= get_max_offset(m_lVariations, m_lRMiddle, m_lRSize))
        {
            lRightCounter++;
        }
    }
    
    // expand
    lLeftCounter = -1 * get_max_offset(m_lVariations, m_lLMiddle); // left offset
    lRightCounter = get_max_offset(m_lVariations, m_lRMiddle, m_lRSize); // right offset
    
    while(lLeftCounter <= 0 ||
          lRightCounter <= get_max_offset(m_lVariations, m_lRMiddle, m_lRSize))
    {
        asSmashed.push_back(string_generator(lLeftCounter, lRightCounter));
        
        if(lLeftCounter <= 0)
        {
            lLeftCounter++;
        }
        
        if(lRightCounter <= get_max_offset(m_lVariations, m_lRMiddle, m_lRSize))
        {
            lRightCounter++;
        }
    }
    
    // invert
    lLeftCounter = get_max_offset(m_lVariations, m_lLMiddle, m_lLSize); // right offset
    lRightCounter = -1 * get_max_offset(m_lVariations, m_lRMiddle); // left offset
    
    while(lLeftCounter <= get_max_offset(m_lVariations, m_lLMiddle, m_lLSize) ||
          lRightCounter <= 0)
    {
        asSmashed.push_back(string_generator(lLeftCounter, lRightCounter));
        
        if(lLeftCounter <= get_max_offset(m_lVariations, m_lLMiddle, m_lLSize))
        {
            lLeftCounter++;
        }
        
        if(lRightCounter <= 0)
        {
            lRightCounter++;
        }
    }
    
    return asSmashed;
}