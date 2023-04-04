#include<iostream>
#include<fstream>
using namespace std;
typedef struct{
	float x[10][10];
}matrix;

matrix mat_add(matrix a,matrix b,int n){
matrix c;
int i,j;
for(i=0;i<n;++i){
for(j=0;j<n;j++){
c.x[i][j]=a.x[i][j]+b.x[i][j];
}
}
return(c);
}

matrix mat_prod(matrix a,matrix b,int n){
matrix c;
float sum=0;
int i,j,k;
for(i=0;i<n;++i){
for(j=0;j<n;j++){
for(k=0;k<n;k++){	
sum+=a.x[i][k]*b.x[k][j];
}
c.x[i][j]=sum;
sum=0;
}
}
return(c);
}
void matprint(matrix a,int n){
    int i,j;
    for(i=0;i<n;++i){
for(j=0;j<n;j++){
cout<<a.x[i][j]<<" ";
}
cout<<endl;
}
}

int main(){
matrix a,b,c,d;
int i,j,n;
float sum;
ifstream in("mat.in");
	in>>n;
for(i=0;i<n;++i){
for(j=0;j<n;j++){
in>>a.x[i][j];
}
}
for(i=0;i<n;++i){
for(j=0;j<n;j++){
in>>b.x[i][j];
}
}
cout<<"Matrix A :"<<endl;
matprint(a,n);
cout<<"Matrix B :"<<endl;
matprint(b,n);
c=mat_add(a,b,n);
d=mat_prod(a,b,n);
cout<<"Addition of A and B matrices :"<<endl;
matprint(c,n);
cout<<"Multiplication of A and B matrices :"<<endl;
matprint(d,n);
return 0;
}
