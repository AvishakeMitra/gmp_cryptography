#include <stdio.h>
#include <gmp.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	mpz_t a,t,n,n1,n2,n3,n4,r,i,s,j;
	mpz_inits(a,t,n,n1,n2,n3,n4,r,i,s,j,NULL);	

	int jacobi,num;
	
	gmp_randstate_t s1;
	gmp_randinit_mt(s1);
	unsigned long seed;
 	seed=time(NULL);
	gmp_randseed_ui(s1,seed);
	mpz_t bt;
	mpz_init(bt);
	mpz_set_ui(bt,10000);
	
	mpz_set_ui(i,0);
	printf("Enter a number to check Probably prime or not \n");
	gmp_scanf("%Zd",n);
	printf("Enter t(Security paramaeter) :\n");
	gmp_scanf("%Zd",t);
	num=mpz_get_ui(n);
	
	mpz_sub_ui(n1,n,1);
	mpz_sub_ui(n2,n,4);
	mpz_sub_ui(n4,n,3);
	mpz_cdiv_q_ui(n3,n1,2);
		
	while(mpz_cmp(i,t)!=0)
	{
		
		mpz_add_ui(i,i,1);
		mpz_urandomm(a,s1,n4);
		mpz_add_ui(a,a,2);
		mpz_powm(r,a,n3,n);
		if(mpz_cmp_ui(r,1)!=0 && mpz_cmp(r,n1)!=0)
		{
			printf("%d is a Composite\n",num);
			return 0;
		}
		jacobi=mpz_jacobi(a,n);
		
		if(jacobi==-1){
			mpz_set(s,n1);
		}
		else
			mpz_set_ui(s,jacobi);
	
	
		mpz_mod(s,s,n);
		if(mpz_cmp(s,r)!=0)
		{
			printf("%d is a Composite\n",num);
			return 0;
		}
	}
	int number=mpz_get_ui(n);
	printf("%d is probably a prime number\n",num);
	return 0;
}
