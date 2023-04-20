#include<iostream>
#include<fstream>
using namespace std;
int main(){
float a[10][10],b[10][10],c[10][10];
ifstream in("mat.in");
int n,i,j;
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
c[i][j]=a[i][j]+b[i][j];
}
}
cout<<"matrix a is :"<<endl;
for(i=0;i<n;i++){
for(j=0;j<n;j++){
cout<<a[i][j]<<" ";
}
cout<<endl;
}

cout<<"matrix b is :"<<endl;
for(i=0;i<n;i++){
for(j=0;j<n;j++){
cout<<b[i][j]<<" ";
}
cout<<endl;
}

cout<<"matrix c is :"<<endl;
for(i=0;i<n;i++){
for(j=0;j<n;j++){
cout<<c[i][j]<<" ";
}
cout<<endl;
}
return(0);
}

