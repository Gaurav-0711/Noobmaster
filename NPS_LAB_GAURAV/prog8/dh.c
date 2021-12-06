#include<stdio.h>
int compute(int a,int m,int n)
{
	int r;
	int y=1;
	while(m>0)
	{
		r=m%2;
		if(r==1)
			y=(y*a)%n;
		a=a*a%n;
		m=m/2;
	}
	return y;
}

int main()
{
	int p=23,g=5;
	int a,b,A,B;
	srand(time(0));
	a=rand();
        srand(time(0));
	b=rand();
	A=compute(g,a,p);
	B=compute(g,b,p);	
	int keyA = compute(B,a,p);
	int keyB = compute(A,b,p);
	printf("\nALICE'S Secret key is %d\nBob's secret key is %d\n\n",keyA,keyB);
	return 0;
}
