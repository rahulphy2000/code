#include<iostream>
#include<cmath>
using namespace std;
int main()
{ 
    int n,m;
    float re,im,re1,im1,r_n,theta;
    cout<<"enter real part of the complex number :"<<endl;
    cin>>re;
    cout<<"enter complex part of the complex number :"<<endl;
    cin>>im;
    cout<<"enter n "<<endl;
    cin>>n;
    cout<<"the complex nnumber entered is "<<endl<<re<<"+"<<im<<"i"<<endl;
    cout<<n<<" roots are: "<<endl;
    r_n=pow(sqrt(re*re+im*im),(1.0/n)); //r to the power 1/n
    theta=atan2(im,re);  //argument
    for(m=0;m<n;m++){
        re1=r_n*cos((theta+2*M_PI*m)/n);   
        im1=r_n*sin((theta+2*M_PI*m)/n);
        if(im1>=0){
        cout<<re1<<"+"<<im1<<"i"<<endl;}
        else{cout<<re1<<im1<<"i"<<endl;}
    }
//cout<<sin(M_PI/2);
//cout<<r_n;
    return 0;
}