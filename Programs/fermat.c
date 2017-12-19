#include<stdio.h>
#include<time.h>
#include<gmp.h>


void fast_exp(mpz_t x,mpz_t y,mpz_t p,mpz_t ans)
{

	mpz_t res,temp,modres;
	mpz_inits(res,temp,modres,NULL);
	mpz_set_ui(res,1);
		
	while(mpz_cmp_ui(y,0)>0)
	{	
		mpz_mod_ui(modres,y,2);
		if(mpz_cmp_ui(modres,1)==0)
		{	
		mpz_mul(temp,res,x);
		mpz_mod(res,temp,p);
		}
		mpz_div_ui(y,y,2);
		mpz_mul(temp,x,x);
		mpz_set(x,temp);
	}
	mpz_set(ans,res);
}

void fermat_test(mpz_t n)
{
	mpz_t a,n1,ans;
	mpz_inits(a,n1,ans,NULL);
	mpz_set_ui(a,5);
	mpz_sub_ui(n1,n,1);
	fast_exp(a,n1,n,ans);
	
	if(mpz_cmp_ui(ans,1)==0)
		gmp_printf("\n%Zd is probably a prime number : \n\n",n);
	else
		gmp_printf("\n%Zd is not prime number : \n\n",n);
}

void main()
{
	mpz_t a;
	mpz_init(a);
	printf("Enter the number to check prime or not using FEMAT THEOREM :");
	gmp_scanf("%Zd",a);
	fermat_test(a);
}
