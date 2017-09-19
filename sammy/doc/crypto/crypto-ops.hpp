//
// Created by loccs on 9/19/17.
//

#ifndef MONERO_CRYPTO_OPS_HPP
#define MONERO_CRYPTO_OPS_HPP

/**
 * @brief estimate `s=c-ab`
 * @details
        Input:
          a[0]+256*a[1]+...+256^31*a[31] = a
          b[0]+256*b[1]+...+256^31*b[31] = b
          c[0]+256*c[1]+...+256^31*c[31] = c

        Output:
          s[0]+256*s[1]+...+256^31*s[31] = (c-ab) mod l
          where l = 2^252 + 27742317777372353535851937790883648493.
 * @param[out] s    scalar equals to `c-ab`
 * @param[in] a     a scalar
 * @param[in] b     a scalar
 * @param[in] c     a scalar
*/
void sc_mulsub(unsigned char *s, const unsigned char *a, const unsigned char *b, const unsigned char *c);

#endif //MONERO_CRYPTO_OPS_HPP
