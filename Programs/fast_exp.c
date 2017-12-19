#include<stdio.h>
#include<time.h>
#include<gmp.h>


void fast_exp(mpz_t x,mpz_t y,mpz_t p)
{

	mpz_t res,temp,temp1,temp3,modres;
	mpz_inits(res,temp,temp1,temp3,modres,NULL);
	mpz_set_ui(res,1);
	mpz_set(temp1,x);
	mpz_set(temp3,y);
	
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
	gmp_printf("\n%Zd ^ %Zd mod %Zd = %Zd\n\n",temp1,temp3,p,res);
}
		
void main(void)
{
	unsigned long int seed;
	int size1,size2,size3;
	mpz_t x;
	mpz_t y;
	mpz_t p,temp1,temp2;
	mpz_inits(x,y,p,temp1,temp2,NULL);

	gmp_randstate_t s;
	gmp_randinit_mt(s);
	seed=time(NULL);	
	gmp_randseed_ui(s,seed);
	printf("Enter the no of bits of Base,Exponent and mod : ");
	scanf("%d%d%d",&size1,&size2,&size3);
	
			
	mpz_rrandomb(x, s, size1);
	mpz_rrandomb(y, s, size2);
	mpz_rrandomb(p, s, size3);
	mpz_powm(temp1,x,y,p);
	
	gmp_printf("\nUsing mpz function %Zd ^ %Zd mod %Zd = %Zd\n\n",x,y,p,temp1);
 	fast_exp(x,y,p);	
}
