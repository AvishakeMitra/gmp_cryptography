#include<stdio.h>
#include<gmp.h>

void egcd(mpz_t par_1,mpz_t par_2,mpz_t ans)
{
	mpz_t zero;
	mpz_init(zero);
	if(mpz_cmp(par_2,zero)==0)
	{
		mpz_abs(par_1,par_1);		
		mpz_set(ans,par_1);
	}
	else
	{
	 	mpz_t mod_result;
	 	mpz_init(mod_result);
		mpz_mod(mod_result,par_1,par_2);
		egcd(par_2,mod_result,ans);
	}
}

void fast_exp(mpz_t x,int y1,mpz_t p,mpz_t ans)
{

	
	mpz_t res,temp,modres,y;
	mpz_inits(res,temp,modres,y,NULL);
	mpz_set_ui(res,1);
	mpz_set_ui(y,y1);	
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
void poll_p(mpz_t N,int B)
{
	
	mpz_t a,d,temp,temp1;
	int j=2;
	mpz_inits(a,d,temp,temp1,NULL);
	mpz_set_ui(a,2);
	mpz_set(temp1,N);

	while(j<=B)
	{
		fast_exp(a,j,N,a);
		mpz_sub_ui(temp,a,1);
		egcd(temp,N,d);
		if(mpz_cmp_ui(d,1)!=0)	
		{
			gmp_printf("\n\nThe prime factors of %Zd according to the Pollar (P-1) is %Zd \n\n",temp1,d);
			break;
		}
		j=j+1;
	}	
		
}

 void main()
{
	mpz_t a;
	mpz_init(a);
	printf("Enter the number to find the factors : ");
	gmp_scanf("%Zd",a);	
	poll_p(a,100);
}
