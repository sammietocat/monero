#ifndef RCTSIGS_H
#define RCTSIGS_H

#include <cstddef>
#include <mutex>
#include <vector>
#include <tuple>

#include "crypto/generic-ops.h"

extern "C" {
#include "crypto/random.h"
#include "crypto/keccak.h"
}

#include "crypto/crypto.h"

#include "rctTypes.h"
#include "rctOps.h"

using namespace std;
using namespace crypto;
namespace rct {

    /**************/
    /*  Funtions  */
    /**************/

    /**
     * @brief generate a Borromean signature
     * @param x  secret key vector, where `x_i` can be paired with either `P1_i` or `P2_i`
     * @param P1    a public key vector
     * @param P2    another public key vector, where `{P1_i,P2_i}`  is treated as a ring
     * @param indices   bit flag specify which of `P1_i` and `P2_i` is the public key is paired with `x_i`
     * @return the signature generated from the given ring set
     * @note Borromean (c.f. gmax/andytoshi's paper) \n
     *      Message to sign is empty?
     * */
    boroSig genBorromean(const key64 x, const key64 P1, const key64 P2, const bits indices);

    /**
     * @brief   verify a given Borromean signature
     * @param bb    Borromean signature to verify
     * @param P1    a signing pubkey vector
     * @param P2    another signing pubkey vector, where `P1_i` is combined with `P2_i` to build a ring
     * @return  true if the signature is valid; false, otherwise
     * */
    bool verifyBorromean(const boroSig &bb, const key64 P1, const key64 P2);

    /**
	 * @brief	Multilayered Spontaneous Anonymous Group Signatures (MLSAG signatures)
     * @details	This is a just slghtly more efficient version than the ones described below
     *  (will be explained in more detail in Ring Multisig paper). These are a.k.a. MG signatures
     *  in earlier drafts of the ring ct paper, c.f. http://eprint.iacr.org/2015/1098 section 2.
		+ `keyImageV` just does `I_i = xx_i * H_p(xx_i * G)` for each `i`
		+ `Gen` creates a signature which proves that for some column in the key matrix `pk`, and
            the signer knows a secret key for each row in that column
		+ `Ver` verifies that the MG sig was created correctly
     *
     * @param message message to sign
     * @param pk    the mix-in matrix
     * @param xx    real seckey vector
     * @param index     column index of the real pubkey vector
     * @param dsRows    double-spending rows
     * @return the MLSAG signature as specified by {@link rct::mgSig}
	*/
    mgSig MLSAG_Gen(const key &message, const keyM &pk, const keyV &xx, const unsigned int index, size_t dsRows);

    /**
     * @brief gives C, and mask such that \f$\sum C_i = C\f$
     * @details c.f. http://eprint.iacr.org/2015/1098 section 5.1
     *  and `Ci=a_i*G+b_i*H` is a commitment to either 0 or 2^i, i=0,...,63, thus this proves that "amount" is in [0, 2^64] \n
     *  mask is `a=a_0+...+a_63`, amount is `b=b_0*2^0+...+b_i*2^i+...+b_63*2^63 (b_i={0,1})` such that `C = aG + bH`
     * @param[out] C    the generated commitment
     * @param[out] mask     the mask values in the commitment
     * @param[in] amount    amount to commit for
     * @note anti-counterpart is  {@link verRange} verifies that \f$\sum C_i = C\f$ and
     *      that each \f$C_i\f$ is a commitment to 0 or 2^i
     * */
    rangeSig proveRange(key & C, key & mask, const xmr_amount & amount);
}
