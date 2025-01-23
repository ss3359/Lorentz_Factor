//
//  Piano.hpp
//  MUSIC
//
//  Created by Owner on 1/20/25.
//

#ifndef Piano_hpp
#define Piano_hpp

#include <stdio.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <thread>
using namespace std;



class LorentzFactor{
    
private:
    double x;
    double y;
    double z;
    
public:
    double sigma=0.5;
    double rho=0.7;
    double beta=0.6;
    double h = 0.1;
    double t=0;
    LorentzFactor(double x0, double y0, double z0){
        x=x0;
        y=y0;
        z=z0;
    }
    
    double GetX(){return x;}
    double GetY(){return y;}
    double GetZ(){return z;}
    
    double dxdt(double t,double x, double y, double z);
    double dydt(double t,double x, double y, double z);
    double dzdt(double t,double x, double y, double z);
    
    void UpdatePosition();
    
};







bool IsPrime(int n);
int gcd(int a, int b);
bool IsRelativelyPrime(int p, int q);
class RSA{
    RSA(){
        
    }
    vector<int> Primes;
    int p,q;
    int EulerTotient();
    
};

#endif /* Piano_hpp */
