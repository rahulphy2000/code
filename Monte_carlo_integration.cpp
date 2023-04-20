#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cmath>
using namespace std;
float f(float x){
    return sin(x);
    
    //return x*x*exp(-x*x);
}
float fmax1(float a,float b){
    float f_max=f(a),x;
    for(x=a;x<=b;x+=.01){
        if(f_max<f(x)){
          f_max=f(x);
        }
    }
    if(f_max<0){
        f_max=0;
    }
    return(f_max);
}
float fmin1(float a,float b){
    float f_min=f(a),x;
    for(x=a;x<=b;x+=0.01){
        if(f_min>f(x)){
          f_min=f(x);
        }
    }
    if(f_min>0){
        f_min=0;
    }

    return(f_min);
}
int main(){
   int i,j,nc1=0,nc2=0,n;
   float x,y,integral,a=0,b=2*M_PI/3;
  cout<<"enter the number of random numbers :";
  cin>>n;
  srand(time(NULL));
  for(i=0;i<n;i++){
    x=rand()/float(RAND_MAX);
    y=rand()/float(RAND_MAX);
    x=a+(b-a)*x;
    y=fmin1(a,b)+(fmax1(a,b)-fmin1(a,b))*y;
    if(y>0)
    {
        if(y<f(x)){
            nc1+=1;
        }
    }
    else{
        if(y>f(x)){
            nc2+=1;
        }
    }
}
integral=(fmax1(a,b)-fmin1(a,b))*(b-a)*(nc1-nc2)/(1.0*n);
cout<<"integral value is : "<<integral;
   
   srand(time(NULL));
    return 0;

}