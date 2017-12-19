#include<stdio.h>
#include<gmp.h>
#include<time.h>

void egcd(mpz_t par_1,mpz_t par_2,mpz_t d)
{
	mpz_t zero;
	mpz_init(zero);
	if(mpz_cmp(par_2,zero)==0)
	{
		mpz_abs(par_1,par_1);	
		mpz_set(d,par_1);	
		
	}
	else
	{
	 	mpz_t mod_result;
	 	mpz_init(mod_result);
		mpz_mod(mod_result,par_1,par_2);
		egcd(par_2,mod_result,d);
	}
}
void porho(mpz_t n)
{
	
	mpz_t a,b,d,temp1;
	mpz_inits(a,b,d,temp1,NULL);
	mpz_set_ui(a,2);
	mpz_set_ui(b,2);
	mpz_set_ui(d,1);

	
	while(mpz_cmp_ui(d,1)==0)
	{	
		
		mpz_pow_ui(a,a,2);
		mpz_add_ui(a,a,1);
		mpz_mod(a,a,n);	
		
		mpz_pow_ui(b,b,2);
		mpz_add_ui(b,b,1);
		mpz_mod(b,b,n);	

		mpz_pow_ui(b,b,2);
		mpz_add_ui(b,b,1);
		mpz_mod(b,b,n);
		
		mpz_sub(temp1,a,b);
		egcd(temp1,n,d);
	
	}
	gmp_printf("\n\nThe factor is %Zd\n\n",d);
}



void main(void)
{
	int size;
	mpz_t a,b,n;
	mpz_inits(a,b,n,NULL);
	printf("Enter the number which you want to find the factor : ");
	gmp_scanf("%Zd",n);
	
	porho(n);
	//egcd(a,b);
}
