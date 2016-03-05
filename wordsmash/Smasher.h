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

class Smasher
{
    
public:
    Smasher();
    std::vector<std::string> smash_it(
                                      std::vector<std::string> asLeft,
                                      std::vector<std::string> asRight
                                      );
    
};

#endif /* Smasher_h */
