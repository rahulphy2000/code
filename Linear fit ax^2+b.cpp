#include<iostream>
#include<fstream>
using namespace std;
typedef struct
{
	float data[100];
}coordinate;

typedef struct
{
	float a,b,N;
}parameter;

coordinate x,y,t;
parameter fit;

int input()
{
	int i=0,j=0;
	ifstream in("Data.txt");
	while(in>>x.data[i]>>y.data[i])
	{
		i=i+1;
	}
	for(j=0;j<i;j++)
	{
		t.data[j]=x.data[j]*x.data[j];
	}
	fit.N=i;
}
int linearfit()
{
	int i;
	int N=fit.N;
	float sumxiyi,sumxi,sumyi,sumxi2,m,c,f;
	sumxiyi=0;
	sumxi=0;
	sumyi=0;
	sumxi2=0;
    for(i=0;i<N;i++)
    {
    	sumxiyi=sumxiyi+t.data[i]*y.data[i];
    	sumxi=sumxi+t.data[i];
    	sumyi=sumyi+y.data[i];
    	sumxi2=sumxi2+t.data[i]*t.data[i];
	}
	fit.a=(N*sumxiyi-sumxi*sumyi)/(N*sumxi2-sumxi*sumxi);
	fit.b=(sumyi-(fit.a)*sumxi)/N;
}

int output()
{
	float f;
	cout<<"The best fit line is "<<fit.a<<"*x^2+"<<fit.b;
	ofstream out("Line.txt");
	int N=fit.N;
	float lb=x.data[0];
	float ub=x.data[N-1];
	for(f=lb;f<=ub;f=f+0.01)
	{
		out<<f<<" "<<(fit.a*f*f+fit.b)<<endl;	
	}
}
int main()
{
	input();
	linearfit();
	output();
}

