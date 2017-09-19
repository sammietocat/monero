//
// Created by loccs on 9/19/17.
//

#ifndef MONERO_RCTOPS_HPP
#define MONERO_RCTOPS_HPP

namespace rct {
    /***************/
    /*  Functions  */
    /***************/

    /**
     * @brief calculate `aGB = a*G + B` where `a` is a scalar, `G` is the base point, and `B` is a point
     * @param aGB buffer to hold `a*G+B`
     * @param a     an EC scalar
     * @param B     an EC point
     * */
    void addKeys1(key &aGB, const key &a, const key &B);

    //addKeys2
    /**
     * @brief estimate aGbB = aG + bB where a, b are scalars, G is the base point and B is a point
     * @param[out] aGbB     a*G+b*B
     * @param[in] a         a scalar
     * @param[in] b         another scalar
     * @param[in] B         a EC point
     * */
    void addKeys2(key &aGbB, const key &a, const key &b, const key &B);

    /**
     * @brief   compute the hash of a given key vector of length 64
     * @param keys  key vector as message
     * @return  hash of the given key vector
     * */
    key hash_to_scalar(const key64 keys);

    /*
     * @copybrief skGen(key&)
     * @return the generated secret key
     * */
    key skGen();

    /**
     * @brief generates a random scalar which can be used as a secret key or mask
     * @param[out] sk   the generated secret key
     * */
    void skGen(key &sk);

    /**
     * @brief   does a * G where a is a scalar and G is the curve basepoint
     * @param a     a scalar
     * @return  a*G
     * */
    key scalarmultBase(const key &a);

    /**
     * @copybrief scalarmultBase(const key &a)
     * @param[out] aG   a*G
     * @param[in] a     a scalar
     * */
    void scalarmultBase(key &aG, const key &a);
}

#endif //MONERO_RCTOPS_HPP
