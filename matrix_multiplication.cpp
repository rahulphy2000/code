#include<iostream>
#include<fstream>
using namespace std;
int main(){
float a[10][10],b[10][10],c[10][10],sum=0;
int n,i,j,k;
ifstream in("mat.in");

in >> n;
for(i=0;i<n;++i){
for(j=0;j<n;j++){
in>>a[i][j];
}
}
for(i=0;i<n;i++){
for(j=0;j<n;j++){
in>>b[i][j];
}
}

for(i=0;i<n;i++){
for(j=0;j<n;j++){
for(k=0;k<n;k++){
sum=sum+a[i][k]*b[k][j]	;
}

c[i][j]=sum;
sum=0;
}
}
cout<<"matrix a is :"<<endl;
for(i=0;i<n;i++){
for(j=0;j<n;j++){
cout<<c[i][j]<<" ";
}
cout<<endl;
}


return 0;
}
