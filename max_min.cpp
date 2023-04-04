#include<iostream>
#include<fstream>
using namespace std;
int main(void){
int i,j,n;
float a[100],e;
ifstream b("data.in");
n=0;
while(b>>a[n]){
    n=n+1;
}
for(i=0;i<n;++i){
for(j=i+1;j<n;++j){
if(a[i]<a[j]){
e=a[i];
a[i]=a[j];
a[j]=e;
}
}
}
for(i=0;i<n;++i){
cout<<a[i]<<endl;

}
return(0);
}
