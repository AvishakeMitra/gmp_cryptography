#include<stdio.h>
int check_prime(int a)
{
   int c;
 
   for ( c = 2 ; c <= a - 1 ; c++ )
   { 
      if ( a%c == 0 )
     return 0;
   }
   return 1;
}
int jacobi(int a,int n)
{
	int j=1;
	int temp;
	while(a!=0)
	{
		while(a%2==0)
		{	
			a=a/2;
			if((n%8 ==3) || (n%8 ==5))
				j=0-j;
		}
	  	temp=a;
		a=n;
		n=temp;
		if((a%4 ==3) && (n%4 ==3))
			j=0-j;
		a=a%n;
		
	}
	if(n==1) return j;
	else return 0;

}
void main()
{
	int k,n;	
	printf("Enter k and n : ");
	scanf("%d %d",&k,&n);
	if(n<3){ 
printf("Legendre symbol not possible for n < 3"); 
return; 
}
	if(check_prime(n)==0) printf(" n is not prime ");
	else
	printf("\n %d \n",jacobi(k,n));
}
