#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int main(){
    int i,n_total,n_circle=0;
    float x,y,pi;
    srand(time(NULL));
    
   cout<< "enter no. of random numbers :";
   cin>>n_total;
   for(i=0;i<n_total;i++){
    x=rand()/float(RAND_MAX);
    y=rand()/float(RAND_MAX);
      x=-1+2*x;
      y=-1+2*y;
      if(x*x+y*y<=1){
         n_circle=n_circle+1;
      }
   }
    pi=(4.0*n_circle)/(1.0*n_total);
    cout<<"the value of pi is :"<<pi;
    return(0);
}
