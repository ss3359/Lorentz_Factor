//
//  Piano.cpp
//  MUSIC
//
//  Created by Owner on 1/20/25.
//

#include "Piano.hpp"

#include <stdio.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <thread>
#include <iomanip>
#include <fstream>

using namespace std;

double LorentzFactor::dxdt(double t,double x, double y, double z){
    
    return (sigma)*(y-x);
}
double LorentzFactor::dydt(double t,double x, double y, double z){
    
    return x*(rho-z)-y;
}
double LorentzFactor::dzdt(double t,double x, double y, double z){
    
    return x*y-beta*z;
}



void LorentzFactor::UpdatePosition(){
    double xOld=this->GetX();
    double yOld=this->GetY();
    double zOld=this->GetZ();

    cout<<endl;
    cout<<"Initial Point: "<<endl;
    cout<<xOld<<endl;
    cout<<yOld<<endl;
    cout<<zOld<<endl;
    cout<<endl;
    
    for(int i=0; i<1000; i++){
        double k1=dxdt(t,xOld, yOld, zOld);
        double l1=dydt(t,xOld, yOld, zOld);
        double u1=dzdt(t,xOld, yOld, zOld);
        
        double k2=dxdt(t+(h/2),xOld+h*(k1/2),yOld+h*(l1/2),zOld+h*(u1/2));
        double l2=dydt(t+(h/2),xOld+h*(k1/2),yOld+h*(l1/2),zOld+h*(u1/2));
        double u2=dzdt(t+(h/2),xOld+h*(k1/2),yOld+h*(l1/2),zOld+h*(u1/2));
        
        double k3=dxdt(t+(h/2),xOld+h*(k2/2),yOld+h*(l2/2),zOld+h*(u2/2));
        double l3=dydt(t+(h/2),xOld+h*(k2/2),yOld+h*(l2/2),zOld+h*(u2/2));
        double u3=dzdt(t+(h/2),xOld+h*(k2/2),yOld+h*(l2/2),zOld+h*(u2/2));
        
        
        double k4=dxdt(t+(h/2),xOld+h*(k3/2),yOld+h*(l3/2),zOld+h*(u3/2));
        double l4=dydt(t+(h/2),xOld+h*(k3/2),yOld+h*(l3/2),zOld+h*(u3/2));
        double u4=dzdt(t+(h/2),xOld+h*(k3/2),yOld+h*(l3/2),zOld+h*(u3/2));
        
        
        double NewX=xOld+(h/6)*(k1+2*k2+2*k3+k4);
        double NewY=yOld+(h/6)*(l1+2*l2+2*l3+l4);
        double NewZ=zOld+(h/6)*(u1+2*u2+2*u3+u4);
        
//        ofstream myFile("results.txt");
//        while (myFile.is_open()) {
//            myFile<<"New Point: "<<endl;
//            myFile<<"New Point: "<<endl;
//            myFile<<setprecision(11)<<fixed;
//            myFile<<NewX<<endl;
//            myFile<<NewY<<endl;
//            myFile<<NewZ<<endl;
//            cout<<endl;
//        }
//        
        
        
        cout<<"New Point: "<<endl;
        cout<<setprecision(11)<<fixed; 
        cout<<NewX<<endl;
        cout<<NewY<<endl;
        cout<<NewZ<<endl;
        cout<<endl;
        xOld=NewX; yOld=NewY; zOld=NewZ;
        t+=h;
    }
}










int gcd(int a, int b){
    int n=1,iter=1;
    
    while(iter<=a || iter<=b){
        if(a%iter==0 &&b%iter==0){
            n=iter;
        }
        iter++;
    }
    return n;
}

bool IsRelativelyPrime(int p, int q){
    if(gcd(p, q)==1){
        return true;
    }
    return false;
}
bool IsPrime(int n){
    for(int i=2; i<=n; i++){
        if(n%i==0 && i!=n){
            return false;
        }
    }
    return true;
}

int RSA::EulerTotient(){
    return ((this->p)-1)*((this->q)-1);
    
}
