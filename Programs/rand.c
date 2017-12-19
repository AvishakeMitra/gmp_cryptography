#include <stdio.h>
#include <gmp.h>

int main (void) {
    mpz_t rand_Num;
    unsigned long int i, seed;
    gmp_randstate_t r_state;

    seed = 123456;

    gmp_randinit_default (r_state);
    gmp_randseed_ui(r_state, seed);

    mpz_init(rand_Num);

    for(i = 0; i < 10; ++i) {
       mpz_urandomb(rand_Num,r_state,14);
       gmp_printf("%Zd\n", rand_Num);
    }

    gmp_randclear(r_state);
    mpz_clear(rand_Num);
    return 0;
}
