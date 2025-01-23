//
//  main.cpp
//  MUSIC
//
//  Created by Owner on 1/20/25.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <thread>
#include "Piano.hpp"

using namespace std; 
int main() {
 
    LorentzFactor L(0.0, 1.0, 1.05);
    L.UpdatePosition();
    
    return 0;
}
