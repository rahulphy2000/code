#include<iostream>
#include<cmath>
using namespace std;
float f(float x){         //function to be integrated
    return(x*x*exp(-x*x));
    }
float integrate(float a,float b,int n){       //subroutine for integration
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
typedef struct{            //strtucture definition for the next subroutine to return two values(integral value and n)
    float I;
    int num;
}conv;
conv converge(float b){    // converge subroutine for n convergence.for a particular "b" or "a".
    conv c;
    int n=2;
    float a=0;
   while(abs((integrate(a,b,n+2)-integrate(a,b,n)))>=.000001){
        n=n+2;
    }
    c.I=integrate(a,b,n);
    c.num=n;
   return(c) ;
}
int main(){
    //int n;
    float b=1;
    cout<<"b :"<<b<<" "<<" I :"<< converge(b).I<<" n :"<<converge(b).num<<endl;
    while(abs((converge(b+0.01).I-converge(b).I)/converge(b).I)>=.00001){                  //using n covergence for different b's or a's
        cout<<"b :"<<b<<" "<<" I :"<< converge(b+.01).I<<" n :"<<converge(b+.01).num<<endl;
        b=b+.01;
    }
    cout << "n is "<< converge(b).num << endl << "b is "<< b<< endl << "Integral value is  "<< converge(b).I<<endl;   //result
    //cout << converge_b(.5)<<endl;
    //cout<< n;
    return(0);
}