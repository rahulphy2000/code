#include<iostream>
#include<fstream>
using namespace std;
int main(){
    int i,j,n;
    float x[100],y[100],b[100],xr,t1=1,t2=1,sum=0;
    ifstream in("data.dat");
    n=0;
    while(in>>x[n]>>y[n]){
        n=n+1;
    }
    cout<<"enter x value to interpolate its y value :";
    cin>>xr;
for(j=0;j<n;j++){
    t1=1;
    t2=1;
    for(i=0;i<j;i++){
        
        t1=t1*(xr-x[i]);
        t2=t2*(x[j]-x[i]);
        
    }
    for(i=j+1;i<n;i++){
        
        t1=t1*(xr-x[i]);
        t2=t2*(x[j]-x[i]);
        
    }
    b[j]=t1/t2;
}
/*cout << " b[j]'s are :"<<endl;
for(i=0;i<n;i++){
    cout<< "b["<<i<<"] is "<<b[i]<<endl;
}*/
cout<< "the polynomial is :"<< endl;
for(i=0;i<n;i++){

  cout<<"+"<<y[i];
  t2=1;
 for(j=0;j<n;j++){
        if(i!=j){
        cout<<"*(x-"<<x[j]<<")";
        t2=t2*(x[i]-x[j]);
             }
  }
  cout<<"/"<<t2;

}  
cout<<endl;

for(i=0;i<n;i++){
    sum=sum+y[i]*b[i];
}
cout<<"the extrapolated value is "<<sum ;
    return 0;
}