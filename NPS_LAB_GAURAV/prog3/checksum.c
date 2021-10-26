#include<stdio.h>
unsigned field[10];
unsigned short checksum()
{
	int i;
	int sum =0;
	printf("\nEnter IP header information in 16 bit words\n");
	for(i=0;i<9;i++)
	{
		printf("\nField %d\n",i+1);
		scanf("%x",&field[i]);
		sum = sum+(unsigned short)field[i];
		while(sum>>16)
			sum = (sum & 0xFFFF) + (sum>>16);
	}
	sum = ~sum;
	return (unsigned short)sum;
}
		
int main()
{
	unsigned short result1, result2;
	result1 = checksum();
	printf("\n Computed checksum at sender = %x\n",result1);
	result2 = checksum();
	printf("\n Computed checksum at receiver = %x\n",result2);
	if(result1==result2)
		printf("\n No error\n");
	else
		printf("\n Error in data recieved \n");
	return 0;
}
		
