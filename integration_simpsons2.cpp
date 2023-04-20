#include<iostream>
#include<cmath>
using namespace std;
float f(float x){
    return(x*x*exp(-x*x));
    //return x*x+sin(x);
    }
float integrate(float a,float b,int n){
    int i;
    float h,sum_odd=0,sum_even=0,integral_value;
    //a=0;
    //b=4;
    
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
float converge_b(float b){
    int n=2;
    float a=0;
    //cout<<integrate(a,b,n)<<endl;
   while(abs((integrate(a,b,n+2)-integrate(a,b,n))/integrate(a,b,n))>=.00001){
        //cout<<"n :"<< n<<" "<<"I : "<< integrate(a,b,n+2)<<endl;
        n=n+2;
    }
   return(integrate(a,b,n)) ;
    //return n;
}
int main(){
    int n;
    float b=.1;

    /*cout<< "enter n(even) "<< endl;
    cin>>n;
    cout<<integrate(a,b,n)<<endl;
   while(abs((integrate(a,b,n+2)-integrate(a,b,n))/integrate(a,b,n))>=.0001){
        cout<<"n :"<< n<<" "<<"I : "<< integrate(a,b,n+2)<<endl;
        n=n+2;
    }*/
    
    while(abs((converge_b(b+.01)-converge_b(b))/converge_b(b))>=.00001){
        cout<<"b :"<<b<<" "<<"I :"<< converge_b(b+.01)<<endl;
        b=b+.01;
    }
    cout << "n is "<< n << endl << "b is "<< b<< endl << "Integral value is  "<< converge_b(b)<<endl;
    

    return(0);
}