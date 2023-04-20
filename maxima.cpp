#include<iostream>
#include<fstream>
using namespace std;
int main(){
int i,n;
float a[100],e;
ifstream in("data.in");
cin>>n;
for(i=0;i<n;++i){
in>>a[i];
}
e=a[0];
for(i=1;i<n;++i){
if(e>a[i]){
e=a[i];
}
}
cout<<e<<endl;
return(0);
}
