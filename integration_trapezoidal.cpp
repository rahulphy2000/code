#include<iostream>
#include<cmath>
using namespace std;
float f(float x){
    return sin(x);
}
float integrate(float n){
    int i;
    float a,b,h,sum=0,integral_value;
    a=0;
    b=M_PI/2.0;
    //cout<<"enter no. of divisions "<<endl;
    //cin>>n;
    h=(b-a)/(1.0*n);
    for(i=1;i<n;i++){
      sum=sum+f(a+i*h);
    }
    integral_value=(h/2)*(f(a)+f(b)+2*sum);
    return(integral_value);
}
int main(){
    /*int i,n;
    float a,b,h,sum=0,integral_value;
    a=0;
    b=M_PI/2.0;
    cout<<"enter no. of divisions "<<endl;
    cin>>n;
    h=(b-a)/(1.0*n);
    for(i=1;i<n;i++){
      sum=sum+f(a+i*h);
    }
    integral_value=(h/2)*(f(a)+f(b)+2*sum);

    cout<<"the integral value is "<<integral_value;*/
    int n;
    n=1;
    //cout<<integrate(n);
    while((integrate(n+1)-integrate(n))>=pow(10.0,-4.0)){
        cout<< integrate(n)<<endl;
        n=n+1;
    }
    cout<< "the required number of divisions are "<< n-1;

    return(0);
}