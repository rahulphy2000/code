#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;
 float delta(float x[100],float y[100],int i,int j){
    if(j==1){
        return(y[i+1]-y[i]);
    }
    else{
        return(delta(x,y,i+1,j-1)-delta(x,y,i,j-1));
    }
 }

 
int main(){
    int n,i,j;
    float x[100],y[100],a[100],t,t1,h,xr,sum; 
    ifstream in("data.dat");
    n=0;
    while(in>>x[n]>>y[n]){
        n=n+1;
    }
    h=x[1]-x[0];
    a[0]=1;
    t=1;
    for(i=1;i<n;i++){
        t=t*i;
        a[i]=delta(x,y,0,i)/(t*pow(h,i));
    }
    cout<< " the points are -------"<<endl;
    for(i=0;i<n;i++){
        cout << x[i] << " " << y[i]<< endl;
    }
    cout << "a[i]'s are -------"<<endl;
    for(i=0;i<n;i++){
        cout<<"a"<<"["<<i<<"] is " << a[i]<<" "<<endl;
    }
    cout<< "the polynomial is ------"<<endl;
     cout << y[0];
        
        for(i=1;i<n;i++){
            if(a[i]>0){
            cout<<"+";
            }
              cout<<a[i];
        for(j=0;j<i;j++){
             cout<<"*(x-"<<x[j]<<")";
        }
        }  
    cout<<endl<<"enter an intermediate point to calculate its interpolated value ";
    cin >> xr;
    sum=y[0];
    for(i=1;i<n;i++){
        t1=1;
        for(j=0;j<i;j++){
        t1=t1*(xr-x[j]);
        }
        sum=sum+a[i]*t1;
    }
    cout << " interpolated value is "<<sum;
    return 0;
}