#include<iostream>
#include<fstream>
using namespace std;
int main(){
int i,n;
ifstream in("data2.in");
ofstream out("out.dat");
float x[100],y[100],sumx=0,sumy=0,sumxx=0,sumxy=0,m=0,c=0,z;
// cout<<"Enter number of data points "<<endl;
// cin>>n;
/*for(i=0;i<n;i++){
in>>x[i];
in>>y[i];
}*/
n=0;
while(in>>x[n]>>y[n]){
 n=n+1;
 }
  for(i=0;i<n;i++){
  sumx=sumx+x[i];
  sumy=sumy+y[i];
  sumxx=sumxx+x[i]*x[i];
  sumxy+=x[i]*y[i];
  }
  cout<<"given data "<<endl;
  cout <<"x"<<"  "<<"y"<<endl;
 for(i=0;i<n;i++){
 cout<<x[i]<<"  "<<y[i]<<endl;
 }
m=(n*sumxy-sumx*sumy)/(n*sumxx-sumx*sumx);
c=(sumy-m*sumx)/(1.0*n);

for(z=0;z<15;z=z+.1){
out<<z<<" "<<m*z+c<<endl;

}
cout<<"m is "<<m<<endl<<"c is "<<c<<endl;
/*for(z=0;z<15;z=z+.1){
out<<z<<" "<<m*z+c<<endl;
}*/
return(0);
}
