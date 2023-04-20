#include<iostream>
#include<fstream>
using namespace std;
typedef struct{
 float m[2];
}mnc;
mnc curvefit(float x[100],float y[100],int n){
mnc m1;
float sumx=0,sumy=0,sumxx=0,sumxy=0;
int i;
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
 m1.m[0]=(n*sumxy-sumx*sumy)/(n*sumxx-sumx*sumx);
m1.m[1]=(sumy-(m1.m[0])*sumx)/(1.0*n);
return(m1);
}

int main(){
int i,n;
mnc m1;
ifstream in("data2.in");
float x[100],y[100];//x1[100];
n=0;
while(in>>x[n]>>y[n]){
 n=n+1;
 }
/* for(i=0;i<n;i++){
   x1[i]=x[i]*x[i];
 }*/
m1=curvefit(x,y,n);
cout<<"m is "<<m1.m[0]<<endl<<"c is "<<m1.m[1]<<endl;

return(0);
}
