#include<iostream>
#include<cmath>
using namespace std;
int main(){
    
    float L=10,h1=5,h2=5,mu=1.2,x,mx,s1,s2,p,sini,sinr,r,mr=0;
    mx=h1+pow((L*L+h2*h2),.5);
    
    for(x=0;x<L;x+=0.001){
            s1=pow((h1*h1+x*x),.5);
            s2=pow((h2*h2+(L-x)*(L-x)),.5);
            p=s1+mu*s2;
            sini=x/s1;
            sinr=(L-x)/s2;
            r=sini/sinr;
            if(mx>p){
                mx=p;
                mr=r;
                
            }

    }
    cout << mr<<endl;
    return 0;
}