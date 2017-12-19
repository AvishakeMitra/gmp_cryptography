#include<stdio.h>
#include<gmp.h>

void jacobix(mpz_t a,mpz_t n)
{
	mpz_t j,temp,modres1,modres2,modres3;
	mpz_inits(temp,modres1,modres2,modres3,j,NULL);
	mpz_set_ui(j,1);
		
	
	while(mpz_cmp_ui(a,0)!=0)
	{	
		
		mpz_mod_ui(modres1,a,2);
		while(mpz_cmp_ui(modres1,2)==0)
		{	
			mpz_div_ui(a,a,2);
			mpz_mod_ui(modres2,n,8);
			mpz_mod_ui(modres3,n,5);
			if((mpz_cmp_ui(modres2,3)==0) || (mpz_cmp_ui(modres2,5)==0))
				mpz_neg(j,j);
		}
	  	mpz_swap(a,n);
		mpz_mod_ui(modres2,a,4);
		mpz_mod_ui(modres3,n,4);
		if((mpz_cmp_ui(modres2,3)==0) || (mpz_cmp_ui(modres2,3)==0)){
			mpz_neg(j,j);}
		mpz_mod(a,a,n);
	}
	if(mpz_cmp_ui(n,1)==0) gmp_printf("\n\nJacobi Symbol outputs : %Zd\n\n",j);
	else printf("\n\nJacobi Symbol outputs : 0\n\n");

}

void main()
{	

	mpz_t k,m;
	int a,b;
	mpz_inits(k,m,NULL);
	printf("Enter a and k(odd prime) : ");
	scanf("%d %d",&a,&b);	
	mpz_set_ui(k,a);
	mpz_set_ui(m,b);
	if(mpz_proab_prime(b,1000)!=0)
	jacobix(k,m);
	else printf("N is not prime");
}
