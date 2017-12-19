#include <stdio.h>
#include <gmp.h>
#include <stdlib.h>
#include <time.h>
void main()
{
	
	
	mpz_t a,b,j,y,s,ss,r,res,res1,n1,n2,i,count,n,t;
	mpz_inits(a,b,j,s,ss,y,r,res,res1,n1,n2,i,count,n,t,NULL);

	int num;

	gmp_randstate_t s1;
	gmp_randinit_mt(s1);
	unsigned long seed;
	seed=time(NULL);
	gmp_randseed_ui(s1,seed);
	mpz_t bt;
	mpz_init(bt);
	mpz_set_ui(bt,10000);
 	
	printf("Enter a number to check Probably prime or not \n");
	gmp_scanf("%Zd",n);
	printf("Enter t(Security paramaeter) :\n");
	gmp_scanf("%Zd",t);
	num=mpz_get_ui(n);

	mpz_sub_ui(n1,n,1);
	mpz_sub_ui(n2,n,3);
	mpz_mod_ui(res,n1,2);
	mpz_sub_ui(ss,s,1);
	
	if(mpz_cmp_ui(res,1)==0)
	{
		mpz_set(r,n1);
		mpz_set_ui(s,0);
	}
	else
	{
		while(mpz_cmp_ui(res1,0)==0)
		{
			mpz_cdiv_q_ui(n1,n1,2);
			mpz_mod_ui(res1,n1,2);
			mpz_add_ui(count,count,1);
		}
		mpz_set(s,count);
		mpz_set(r,n1);
	}
	mpz_sub_ui(n1,n,1);
	
	while(mpz_cmp(i,t)!=0)
	{
		mpz_add_ui(i,i,1);
		mpz_urandomm(a,s1,n2);
		mpz_add_ui(a,a,2);
		mpz_powm(y,a,r,n);
		if(mpz_cmp_ui(y,1)!=0 && mpz_cmp(y,n1)!=0)
		{
			
			mpz_set_ui(j,0);
			while(mpz_cmp(j,s)!=0 )	
			{
				if(mpz_cmp(y,n1)==0)
				{
					printf("%d is probably a prime number\n",num);
					return;
				}
				mpz_mul(y,y,y);
				mpz_mod(y,y,n);
				if(mpz_cmp_ui(y,1)==0)
				{
					printf("%d is a Composite\n",num);
					return;
				}
				mpz_add_ui(j,j,1);
			}
			
			if(mpz_cmp(y,n1)!=0)
			{
				printf("%d is a Composite\n",num);
				return;
  			}

		}
	}
	printf("%d is probably a prime number\n",num);
	
}
