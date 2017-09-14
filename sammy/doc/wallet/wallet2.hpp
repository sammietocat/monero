/**
 * @file	wallet.hpp
 * @brief		document for wallet2.{h,cpp}
 * */

namespace tools {
	class wallet2 {
    public:

		/**
     * @brief check if we can take up the new rule of a hard fork
     * @details The checking is done as follows
     *  * get the current `height` of the blockchain
     *  * get the starting block height `earliest_height` of the hard fork specified by `version`
     *  * abort with `false` if any error occurs before
     *  * if `height>=earliest_height-early_blocks`, use the hard fork, i.e., return `true`. Otherwise, return `false`
		 *
     * @param version   a flag specify a hard fork
     * @param early_blocks  tolerant block windows before the earliest block for the specific hard fork
     * @return `true` if we are to use the rule of the hard fork
     * */
    bool use_fork_rules(uint8_t version, int64_t early_blocks = 0);

    private:
	};
}
