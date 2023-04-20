#include<iostream>
#include<cmath>
using namespace std;
float f(float x){
    return(sin(x)/x);
    }
float integrate(float a,float b,int n){
    int i;
    float h,sum_odd=0,sum_even=0,integral_value;    
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
typedef struct{
    float I;
    int num;
}conv;
conv converge(float a){
    conv c;
    int n=2;
    float b=1;
   while(abs((integrate(a,b,n+2)-integrate(a,b,n)))>=.000001){
        n=n+2;
    }
    c.I=integrate(a,b,n);
    c.num=n;
   return(c) ;
}
int main(){
    //int n;
    float a=.5;
    cout<<"a :"<<a<<" "<<" I :"<< converge(a).I<<" n :"<<converge(a).num<<endl;
    while(abs((converge(a/10.0).I-converge(a).I)/converge(a).I)>=.00001){
        cout<<"a :"<<a<<" "<<" I :"<< converge(a/10.0).I<<" n :"<<converge(a/10.0).num<<endl;
        a=a/10.0;
    }
    cout << "n is "<< converge(a).num << endl << "a is "<< a<< endl << "Integral value is  "<< converge(a).I<<endl;
    //cout << converge_b(.5)<<endl;
    //cout<< n;
    return(0);
}