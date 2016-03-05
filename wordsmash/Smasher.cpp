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
    
}

/**
 * calculates the max offset you can access lower than the index value
 * @param {long} max: max offset we'd like to access
 * @param {long} index: starting point to calculate offset from
 * @return {long} max offset
 */
long Smasher::get_max_offset(long max, long index)
{
    if(index - max < 0)
    {
        return 0;
    }
    else
    {
        return max;
    }
}

/**
 * calculates the max offset you can access higher than the index value
 * @param {long} max: max offset we'd like to access
 * @param {long} index: starting point to calculate offset from
 * @return {long} max offset
 */
long Smasher::get_max_offset(long max, long index, long size)
{
    long lLastElem = size - 1;
    if( (index + max) > lLastElem )
    {
        return lLastElem;
    }
    else
    {
        return max;
    }
}





std::vector<std::string> Smasher::smash_it(
                                           TokenizedString asLeft,
                                           TokenizedString asRight
                                           )
{
    // init vars
    std::vector<std::string> asSmashed;
    long lLSize = asLeft.get_syllable_count();
    long lRSize = asRight.get_syllable_count();
    
    long lLMiddle = lLSize / 2;
    long lRMiddle = lRSize / 2;
    
    long lLLeftOffset = get_max_offset(m_lVariations, lLMiddle);
    long lRLeftOffset = get_max_offset(m_lVariations, lRMiddle);
    long lLRightOffset = get_max_offset(m_lVariations, lLMiddle, lLSize);
    long lRRightOffset = get_max_offset(m_lVariations, lRMiddle, lRSize);
    
    
    
    
    for(long i = lLMiddle; i < m_lVariations; i++)
    {
        
    }
    
    
    
    return asSmashed;
}