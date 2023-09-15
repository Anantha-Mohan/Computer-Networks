#include<stdio.h>
void main()
{
	int bsize,out,n,in,bucket=0,x;
	printf("Enter number of inputs:");
	scanf("%d",&n);
	printf("Enter bucket size:");
	scanf("%d",&bsize);
	printf("Enter outgoing rate:");
	scanf("%d",&out);
	while(n!=0)
	{
		printf("\n\nEnter input:");
		scanf("%d",&in);
		if(in<=bsize-bucket)
		{
			bucket=bucket+in;
			printf("After incoming status:%d out of %d\n",bucket,bsize);
		}
		else
		{
			x=in-(bsize-bucket);
			printf("Dropping %d packets\n",x);
			printf("After dropping status:%d out of %d\n",bucket,bsize);
			bucket=bsize;
		}
		bucket=bucket-out;
		printf("After outgoing status:%d out of %d\n",bucket,bsize);
		
		n--;
	} 
}
