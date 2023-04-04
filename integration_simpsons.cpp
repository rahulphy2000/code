#include<iostream>
#include<cmath>
using namespace std;
float f(float x){
    return sin(x);
}
float integrate(float n){
    int i;
    float a,b,h,sum_odd=0,sum_even=0,integral_value;
    a=0;
    b=M_PI/2.0;

    h=(b-a)/(1.0*n);
    for(i=1;i<n;i=i+2){
      sum_odd+=f(a+i*h);
    }
    for(i=2;i<=(n-2);i=i+2){
      sum_even+=f(a+i*h);
    }
    integral_value=(h/3)*(f(a)+f(b)+4*sum_odd+2*sum_even);
    return(integral_value);
}
int main(){
    int n;
    cout<< "enter n(even only) "<< endl;
    cin>>n;
    cout<<integrate(n);
   /*while(abs((integrate(n+2)-integrate(n)))>=pow(10.0,-4.0)){
        cout<< integrate(n)<<endl;
        n=n+2;
    }
    cout<< "the required number of divisions are "<< n;
*/
    return(0);
}