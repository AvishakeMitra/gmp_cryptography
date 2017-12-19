#include<stdio.h>
#include<gmp.h>
#include<time.h>

void egcd(mpz_t par_1,mpz_t par_2)
{
	mpz_t zero;
	mpz_init(zero);
	if(mpz_cmp(par_2,zero)==0)
	{
		mpz_abs(par_1,par_1);		
		gmp_printf("\n%Zd\n",par_1);
	}
	else
	{
	 	mpz_t mod_result;
	 	mpz_init(mod_result);
		mpz_mod(mod_result,par_1,par_2);
		egcd(par_2,mod_result);
	}
}

void main(void)
{
	int size;
	mpz_t a,b;
	gmp_randstate_t state;
	mpz_init(a);
	mpz_init(b);
	
	printf("Enter the size of the number to find GCD : ");
	scanf("%d",&size);
	gmp_randinit_default(state);
	mpz_rrandomb(a, state, size);
	mpz_rrandomb(b, state, size);
	gmp_printf("Two randomly generated number is  : %Zd and %Zd ",a,b);
	egcd(a,b);
}
