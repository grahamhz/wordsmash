//
//  Smasher.h
//  wordsmash
//
//  Created by Graham Zuber on 3/4/16.
//  Copyright © 2016 zuber.io. All rights reserved.
//

#ifndef Smasher_h
#define Smasher_h

#include <stdio.h>
#include <iostream>
#include <vector>
#include <tuple>
#include <boost/coroutine/coroutine.hpp>
#include "TokenizedString.h"

class Smasher
{
    
public:
    // constructors
    Smasher();
    Smasher(TokenizedString left, TokenizedString right);
    
    // public member functions
    void set_strings(TokenizedString left, TokenizedString right);
    StringVector smash_it();
    
private:
    // private member variables
    static const long m_lVariations = 3;
    TokenizedString m_Left;
    TokenizedString m_Right;
    long m_lLSize;
    long m_lRSize;
    long m_lLMiddle;
    long m_lRMiddle;
    
    // private member functions
    long get_max_offset(long lMax, long lIndex);
    long get_max_offset(long lMax, long lIndex, long lSize);
    std::string string_generator(long lLeftOffset, long lRightOffset);
    
};

#endif /* Smasher_h */
