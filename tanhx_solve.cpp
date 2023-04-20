#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;
int main(){
float x,f;
ofstream out("out.dat");
for(x=-10;x<2*M_PI;x=x+.01){
f=tanh(1.5*x);

out<<x<<" "<<f<<endl;
}
return(0);
}
