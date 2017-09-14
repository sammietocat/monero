/**
 * @file	blockchain.hpp
 * @brief		doc for fields and functions in blockchain.{h,cpp}
 * */

/************/
/*  Fields  */   
/************/

/**
 * @brief anonymous struct specifies the information for hard forks in mainnet/testnet
 * @details The hard forks for the mainnet is different from that of the testnet, where
 *   * For mainnet (specified by `mainnet_hard_forks`),
 *			| version | height		| threshold | finalised time | online time								 |
 *			|:-------:|:---------:|:---------:|:--------------:|:---------------------------:|
 *			| 1				| 1					| 0					| N/A						 | 1,341,378,000							 |
 *			| 2				| 1,009,827 | 0					| 2015-09-20		 | 1,442,763,710 (~2016-03-20) |
 *			| 3				| 1,141,317 | 0					| 2016-03-21		 | 1,458,558,528 (~2016-09-24) |
 *			| 4				| 1,220,516 | 0					| 2016-09-18		 | 1,483,574,400 (~2017-01-05) |
 *			| 5				| 1,288,616 | 0					| 2017-03-14		 | 1,489,520,158 (~2017-04-15) |
 *			| 6				| 1,400,000 | 0					| 2017-08-18		 | 1,503,046,577 (~2017-12-16) |
 *   * For testnet (specified by `testnet_hard_forks`),
 *			| version | height		| threshold | finalised time | online time								 |
 *			|:-------:|:---------:|:---------:|:--------------:|:---------------------------:|
 *			| 1				| 1					| 0					| N/A						 | 1,341,378,000							 |
 *			| 2				| 624,634	  | 0					| 2015-11-20		 | 1,445,355,000 (~2015-11-23) |
 *			| 3				| 800,500	  | 0					|	N/A						 | 1,472,415,034							 |
 *			| 4				| 801,219	  | 0					|	N/A						 | 1,472,415,035							 |
 *			| 5				| 802,660	  | 0					|	N/A						 | 1,472,415,036+86,400*180		 |
 *			| 6				| 971,400	  | 0					| 2017-08-18		 | 1,501,709,789						   |
 *
 * */
static const struct {
  uint8_t version;	///< version starting from 1
  uint64_t height;	///< the starting block height of the fork
  uint8_t threshold;	///< unknown
  time_t time;			///< timestamp in seconds recording the employment of the fork 
}mainnet_hard_forks[6],testnet_hard_forks[6];

/**
 * @brief		the maximum height of block allowed to use policy of version 1 in mainnet
 * */
static const uint64_t mainnet_hard_fork_version_1_till = 1,009,826;
/**
 * @brief		the maximum height of block allowed to use policy of version 1 in testnet
 * */
static const uint64_t testnet_hard_fork_version_1_till = 624,633;
