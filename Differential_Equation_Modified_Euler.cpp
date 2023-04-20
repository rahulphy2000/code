#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;
float dydx(float x,float y){
    return -2*x*y;
}
int main(){
     float x,y,a=-3,b=3,h;
    int n;
    cout<<"enter the number of divisions";
    cin>>n;
    x=0;
    y=1;  
    
    h=(b-a)/(1.0*n);
    ofstream out("out.dat");
    for(x=x;x<b;x=x+h){
       out<<x<<" "<<y<<endl;
       y=y+(h/2)*(dydx(x,y)+dydx(x+h,y+h*dydx(x,y)));
      
       
    }
    x=0;
    y=1; 
    for(x=x;x>a;x=x-h){
      out<<x<<" "<<y<<endl;
       y=y-(h/2)*(dydx(x,y)+dydx(x-h,y-h*dydx(x,y)));
       
       
    }

    return 0;
}