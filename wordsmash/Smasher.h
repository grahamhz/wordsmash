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
#include <boost/coroutine/coroutine.hpp>
#include "TokenizedString.h"

class Smasher
{
    
public:
    // constructor
    Smasher();
    
    // public member functions
    std::vector<std::string> smash_it(
                                      TokenizedString asLeft,
                                      TokenizedString asRight
                                      );
    
private:
    // private member variables
    static const long m_lVariations = 3;
    
    // private member functions
    long get_max_offset(long max, long middle);
    long get_max_offset(long max, long middle, long size);
    
};

#endif /* Smasher_h */
