//
// Created by loccs on 9/19/17.
//

#ifndef MONERO_RCTTYPES_HPP
#define MONERO_RCTTYPES_HPP

/** atomic units of moneros */
#define ATOMS 64

namespace rct {
    /************/
    /*  Fields  */
    /************/

    typedef unsigned int bits[ATOMS];   ///< a bit vector of length 64
    static const key H; ///< other basepoint H = toPoint(cn_fast_hash(G)), G the basepoint
    /**
     * @brief H2 contains 2^i H in each index, i.e. H, 2H, 4H, 8H, ...
     * @note This is used for the range proofG. \n
     *      You can regenerate this by running python2 Test.py HPow2 in the MiniNero repo
     */
    static const key64 H2;

    /**
     * @brief   container for a **secret** or **public** key of 256(=32*8)-bits
     * @details Can contain a secret or public key similar to secret_key / public_key of crypto-ops,
     *          but uses unsigned chars, also includes an operator for accessing the i'th byte.
     * */
    struct key {
        /**
         * @brief   overload the `[]` operator facilitating the i-th byte of the key
         * @param i     index of byte to access
         * @return the reference to i-th byte of the key
         * */
        unsigned char &operator[](int i);

        /**
         * @brief const-version `[]` operator for the key to access a copy of the i-th byte of the key
         * @param i     index of byte to access
         * @return a copy of the i-th byte of the key
         * */
        unsigned char operator[](int i) const;

        /**
         * @brief overload `==` operator for checking the equality of two key
         * @param k     another key to compare
         * @return `true` if the underlying byte sequences are the same, and `false` otherwise
         * */
        bool operator==(const key &k) const;

        unsigned char bytes[32];    ///< a byte array making up the key
    };
    typedef key key64[64];  ///< a {@link rct::key} vector of length 64

    typedef uint64_t xmr_amount; ///< containers for representing amounts

    /****************/
    /*  Structures  */
    /****************/

    /** container for Borromean signature */
    struct boroSig {
        key64 s0;   ///< 1st random scalar in the ring
        key64 s1;   ///< 2nd random scalar in the ring
        key ee;     ///< shared scalar among all rings
    };
    /**
     * @brief   contains the data for an Borromean sig and the "Ci" values such that  \f$\sum Ci = C\f$
     * @note the signature proves that each Ci is either a Pedersen commitment to 0 or to 2^i,
     *      thus proving that C is in the range of [0, 2^64]
     * */
    struct rangeSig {
        boroSig asig;   ///< Borromean sig
        key64 Ci;   ///< commitment to 0 or 2^i
    };

    /***************/
    /*  Functions  */
    /***************/

    /**
    * @brief extract each bit of a given val into an array from LSB to MSB
    * @note Final result should be `val=amountb[0]+amountb[1]*2+...+amountb[63]*2^63`
    * @param[out] amountb  bit array corresponds to the given value
    * @param[in] val   value to extract bits
    * */
    void d2b(bits  amountb, xmr_amount val);
}

#endif //MONERO_RCTTYPES_HPP_HPP
