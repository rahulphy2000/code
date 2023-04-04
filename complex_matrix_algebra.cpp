#include<iostream>
#include<fstream>
using namespace std;
typedef struct{   //defining structure for complex numbers. "r" is the real part and "im" is the imaginary part
float r, im;
}complex;
typedef struct{   //definig structure for complex matrix. Here elements are complex .
	complex x[10][10];
}matrix;
void printComplex(complex a){  //a function to print the complex numbers.
    if(a.im<0){
cout<<a.r<<a.im<<"i"; // because "-" sign will be there automatically.
}
else{
cout<<a.r<<"+"<<a.im<<"i";
}
}
complex add(complex a,complex b){ //function to add to complex numbers.
complex c;
c.r=a.r+b.r;
c.im=a.im+b.im;
return(c); 
}
complex multiply(complex a,complex b){ //fnction to multiply to complex numbers.
complex c;
c.r=a.r*b.r-a.im*b.im;
c.im=a.im*b.r+a.r*b.im;
return(c);
}

matrix mat_add(matrix a,matrix b,int n){ //function for matrix addition;
matrix c;

int i,j;
for(i=0;i<n;++i){
for(j=0;j<n;j++){
c.x[i][j]=add(a.x[i][j],b.x[i][j]); //arguments should be complex;
}

}
return(c);
}

matrix mat_prod(matrix a,matrix b,int n){ // function for matrix multiplication;
matrix c;
complex sum;
int i,j,k;

for(i=0;i<n;++i){
for(j=0;j<n;j++){
    sum.r=0;   // initialize to zero;
    sum.im=0;
for(k=0;k<n;k++){	
sum=add(sum,multiply(a.x[i][k],b.x[k][j])); //sum=sum+(complex multiplication of two)
}
c.x[i][j]=sum;

}
}
return(c);
}
int main(void){
     //complex fst,snd,thd,frt;
     matrix a,b,c,d,m;
     int i,j,n;
     ifstream in("complex_matrix.in");
     in>>n; //n is the dimension of square matrix it should the 1st number in the file.
     //in>>fst.r>>fst.im>>snd.r>>snd.im>>thd.r>>thd.im>>frt.r>>frt.im;
     for(i=0;i<n;++i){
     for(j=0;j<n;j++){
     in>>a.x[i][j].r;
     in>>a.x[i][j].im;
     }
     }
     for(i=0;i<n;++i){
     for(j=0;j<n;j++){
     in>>b.x[i][j].r;
     in>>b.x[i][j].im;
     }
     }
     c=mat_add(a,b,n);
     m=mat_prod(a,b,n);

    /* a.x[0][0].r=fst.r;
     a.x[0][0].im=fst.im;
     a.x[0][1].r=snd.r;
     a.x[0][1].im=snd.r;
     a.x[1][0].r=thd.r;
     a.x[1][0].im=thd.im;
     a.x[1][1].r=frt.r;
     a.x[1][1].im=frt.im;
     */
     cout<< "a is: "<<"\n";
     for(i=0;i<n;++i){
     for(j=0;j<n;++j){ 
     printComplex(a.x[i][j]);
     cout<<" ";
     }
     cout<<endl;
     }
     cout<< "b is: "<<"\n";
     for(i=0;i<n;++i){
     for(j=0;j<n;++j){ 
     printComplex(b.x[i][j]);
     cout<<" ";
     }
     cout<<endl;
     }
    cout<< "adittion c is: "<<"\n";
     for(i=0;i<n;++i){
     for(j=0;j<n;++j){ 
     printComplex(c.x[i][j]);
     cout<<" ";
     }
     cout<<endl;
     }

     cout<< "multiplication m is: "<<"\n";
     for(i=0;i<n;++i){
     for(j=0;j<n;++j){ 
     printComplex(m.x[i][j]);
     cout<<" ";
     }
     cout<<endl;
     }
    return(0);
}