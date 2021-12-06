#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll gcd(ll a,ll b)
{
	if(a==0)
      		return b;
	if(b==0)
		return a;
	return gcd(b,a%b);
}
ll isprime(ll a)
{
	ll i;
	for(i=2;i<a/2;i++)
	{
		if(a%i==0)
		return 0;
	}
	return 1;
}

ll encrypt(char ch,ll n,ll e)
{
	ll i;
	ll temp =ch;
	for(i=1;i<e;i++)
	{
		temp=(ch*temp)%n;
	}
	return temp;
	
}
char decrypt(ll ch,ll n,ll d)
{

	ll i;
	ll temp = ch;
	for(i=1;i<d;i++)
	{
		ch=(ch*temp)%n;
	}
	return ch;
}


int main()
{
	ll i,len,p,q,n,phi,e,d,cipher[50];
	char text[50];
	cout<<"\nEnter the text to be encrypted\n";
	cin.getline(text,sizeof(text));
	len = strlen(text);
	do
	{
		p=rand()%30;
	}
	while(!isprime(p));
	do
	{
		q=rand()%30;
	}
	while(!isprime(q));

	n=p*q;
	phi=(p-1)*(q-1);
	do
	{
		e=rand()%phi;
	}
 	while(gcd(phi,e)!=1);
        do
	{
		d=rand()%phi;
	}
	while(((d*e)%phi)!=1);
	
	cout<<"\nTwo prime numbers (p and q) are : "<<p<<" "<<q<<"\n";
	cout<<"\n n (p*q) = "<<p<<" * "<<q<<" = "<<n<<"\n";
	cout<<"\n(p-1) * (q-1) = "<<phi<<"\n";
	cout<<"\nPublic key (n,e) = ("<<n<<" , "<<e<<" ) \n";
	cout<<"\nPrivate key (n,d) = ("<<n<<" , "<<d<<" ) \n";
	for(i=0;i<len;i++)
	cipher[i]=encrypt(text[i],n,e);
	cout<<"\nEncrypted message :";
	for(i=0;i<len;i++)
	cout<<cipher[i];
	cout<<endl;
	for(i=0;i<len;i++)
	text[i] = decrypt(cipher[i],n,d);
        cout<<"\nDecrypted message :";
	for(i=0;i<len;i++)
	cout<<text[i];
	cout<<endl;
	return 0;
}
	


	
