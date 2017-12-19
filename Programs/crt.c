#include<stdio.h>
#include<gmp.h>


void egcd(mpz_t a,mpz_t b,mpz_t inv)
{
	mpz_t x,s,t,r,old_s,old_t,old_r,zero,temp,quotient,tempq,temps,add_result,mod_result1,mod_result2;
	mpz_inits(x,s,t,r,old_s,old_t,old_r,zero,temp,quotient,tempq,temps,add_result,mod_result1,mod_result2,NULL);

	mpz_set_ui(s,0);
	mpz_set_ui(t,1);
	mpz_set_ui(old_s,1);
	mpz_set_ui(old_t,0);
	mpz_set(r,b);
	mpz_set(old_r,a);


	while(mpz_cmp(r,zero)!=0)
	{
		mpz_fdiv_q(quotient,old_r,r);

	mpz_set(temp,r);
	mpz_mul(tempq,quotient,temp);
	mpz_sub(r,old_r,tempq);
	mpz_set(old_r,temp);

	mpz_set(temp,s);
	mpz_mul(tempq,quotient,temp);
	mpz_sub(s,old_s,tempq);
	mpz_set(old_s,temp);

	mpz_set(temp,t);
	mpz_mul(tempq,quotient,temp);
	mpz_sub(t,old_t,tempq);
	mpz_set(old_t,temp);
	}
	//gmp_printf("\nGCD(%Zd,%Zd) = %Zd \n\n",a,b,old_r);
	//gmp_printf("Value of X:%Zd and Y:%Zd \n\n",old_s,old_t);

	if(mpz_cmp_ui(old_r,1)!=0)
		printf("Modular inverse doesn't exist\n\n");
	else
	{
		mpz_mod(mod_result1,old_s,b);
		mpz_add(add_result,mod_result1,b);
		mpz_mod(mod_result2,add_result,b);
		mpz_set(inv,mod_result2);
		//gmp_printf("The modular multiplicative inverse is %Zd\n\n",mod_result2);		
	}	

}
void main(void)
{
	int size;
	mpz_t a,b;
		
	mpz_t num1,num2,num3,rem1,rem2,rem3,pp1,pp2,pp3,inv1,inv2,inv3,mul,res1,res2,res3,resf;		
	mpz_inits(a,b,num1,num2,num3,rem1,rem2,rem3,pp1,pp2,pp3,mul,inv1,inv2,inv3,res1,res2,res3,resf,NULL);
	
	mpz_set_ui(num1,3);
	mpz_set_ui(num2,4);
	mpz_set_ui(num3,5);
	
	mpz_set_ui(rem1,2);
	mpz_set_ui(rem2,3);
	mpz_set_ui(rem3,1);
	
	mpz_mul(mul,num1,num2);
	mpz_mul(mul,mul,num3);
	
	mpz_div(pp1,mul,num1);
	mpz_div(pp2,mul,num2);
	mpz_div(pp3,mul,num3);
	
	//gmp_printf("\n %Zd %Zd %Zd \n",pp1,pp2,pp3);
	egcd(pp1,num1,inv1); 
	egcd(pp2,num2,inv2);
	egcd(pp3,num3,inv3);;
	//gmp_printf("\n %Zd %Zd %Zd \n",inv1,inv2,inv3);
	
	mpz_mul(res1,rem1,pp1);
	mpz_mul(res1,res1,inv1);
	
	
	mpz_mul(res2,rem2,pp2);
	mpz_mul(res2,res2,inv2);

	mpz_mul(res3,rem3,pp3);
	mpz_mul(res3,res3,inv3);

	mpz_add(resf,res1,res2);
	mpz_add(resf,resf,res3);
	
	mpz_mod(resf,resf,mul);
		
	
	gmp_printf("%Zd mod %Zd = %Zd\n",resf,num1,rem1);
	gmp_printf("%Zd mod %Zd = %Zd\n",resf,num2,rem2);
	gmp_printf("%Zd mod %Zd = %Zd\n",resf,num3,rem3);
		
}
