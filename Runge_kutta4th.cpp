#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;
float f(float x,float y){
    return -2*x*y;
   //return 2*cos(x)-y*cos(x);
}
int main(){
int n;
float x,y,k1,k2,k3,k4,a=-3,b=3,h;
cout<<"enter the no. of divisions";
cin>>n;
x=0;  //initial condition
y=1;
h=(b-a)/(1.0*n);
ofstream out("rk4.dat");
for(x=0;x<b;x+=h){
  out << x << " "<< y<<endl;
  k1=h*f(x,y);
  k2=h*f(x+h/2.0,y+k1/2.0);
  k3=h*f(x+h/2.0,y+k2/2.0);
  k4=h*f(x+h,y+k3);
  y=y+(1.0/6)*(k1+2*k2+2*k3+k4) ;
}
x=0;
y=1;
for(x=0;x>a;x-=h){
  out << x << " "<< y<<endl;
  k1=-h*f(x,y);
  k2=-h*f(x-h/2.0,y+k1/2.0);
  k3=-h*f(x-h/2.0,y+k2/2.0);
  k4=-h*f(x-h,y+k3);
  y=y+(1.0/6)*(k1+2*k2+2*k3+k4) ;
}

    return 0;
}
