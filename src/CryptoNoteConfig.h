// Copyright (c) 2011-2016 The Cryptonote developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#pragma once

#include <cstdint>
#include <initializer_list>

namespace CryptoNote {
namespace parameters {

const uint64_t CRYPTONOTE_MAX_BLOCK_NUMBER                   = 500000000;
const size_t   CRYPTONOTE_MAX_BLOCK_BLOB_SIZE                = 500000000;
const size_t   CRYPTONOTE_MAX_TX_SIZE                        = 1000000000;
//TODO Currency-specific address prefix
const uint64_t CRYPTONOTE_PUBLIC_ADDRESS_BASE58_PREFIX       = 0x30261a;
//TODO Choose maturity period for your currency
const size_t   CRYPTONOTE_MINED_MONEY_UNLOCK_WINDOW          = 10;
const uint64_t CRYPTONOTE_BLOCK_FUTURE_TIME_LIMIT            = 60 * 60 * 2;

const size_t   BLOCKCHAIN_TIMESTAMP_CHECK_WINDOW             = 60;

//TODO Specify total number of available coins
//TODO ((uint64_t)(-1)) equals to 18446744073709551616 coins
//TODO or you can define number explicitly UINT64_C(858986905600000000)
const uint64_t MONEY_SUPPLY                                  = UINT64_C(10000000000000000);
const unsigned EMISSION_SPEED_FACTOR                         = 19;
static_assert(EMISSION_SPEED_FACTOR <= 8 * sizeof(uint64_t), "Bad EMISSION_SPEED_FACTOR");

//TODO Define number of blocks for block size median calculation
const size_t   CRYPTONOTE_REWARD_BLOCKS_WINDOW               = 100;
const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE     = 30000; //size of block (bytes) after which reward for block calculated using block size
const size_t   CRYPTONOTE_COINBASE_BLOB_RESERVED_SIZE        = 600;
//TODO Define number of digits
const size_t   CRYPTONOTE_DISPLAY_DECIMAL_POINT              = 8;
//TODO Define minimum fee for transactions
const uint64_t MINIMUM_FEE                                   = 100000;
const uint64_t DEFAULT_DUST_THRESHOLD                        = MINIMUM_FEE;

//TODO Define preferred block's target time
const uint64_t DIFFICULTY_TARGET                             = 60; // seconds
const uint64_t EXPECTED_NUMBER_OF_BLOCKS_PER_DAY             = 24 * 60 * 60 / DIFFICULTY_TARGET;
//TODO There are options to tune CryptoNote's difficulty retargeting function.
//TODO We recommend not to change it.
const size_t   DIFFICULTY_WINDOW                             = EXPECTED_NUMBER_OF_BLOCKS_PER_DAY; // blocks
const size_t   DIFFICULTY_CUT                                = 60;  // timestamps to cut after sorting
const size_t   DIFFICULTY_LAG                                = 15;
static_assert(2 * DIFFICULTY_CUT <= DIFFICULTY_WINDOW - 2, "Bad DIFFICULTY_WINDOW or DIFFICULTY_CUT");

const size_t   MAX_BLOCK_SIZE_INITIAL                        =  20 * 1024;
const uint64_t MAX_BLOCK_SIZE_GROWTH_SPEED_NUMERATOR         = 100 * 1024;
const uint64_t MAX_BLOCK_SIZE_GROWTH_SPEED_DENOMINATOR       = 365 * 24 * 60 * 60 / DIFFICULTY_TARGET;

const uint64_t CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS     = 1;
const uint64_t CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_SECONDS    = DIFFICULTY_TARGET * CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS;

const uint64_t CRYPTONOTE_MEMPOOL_TX_LIVETIME                = 60 * 60 * 24;     //seconds, one day
const uint64_t CRYPTONOTE_MEMPOOL_TX_FROM_ALT_BLOCK_LIVETIME = 60 * 60 * 24 * 7; //seconds, one week
const uint64_t CRYPTONOTE_NUMBER_OF_PERIODS_TO_FORGET_TX_DELETED_FROM_POOL = 7;  // CRYPTONOTE_NUMBER_OF_PERIODS_TO_FORGET_TX_DELETED_FROM_POOL * CRYPTONOTE_MEMPOOL_TX_LIVETIME = time to forget tx

const size_t   FUSION_TX_MAX_SIZE                            = CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE * 30 / 100;
const size_t   FUSION_TX_MIN_INPUT_COUNT                     = 12;
const size_t   FUSION_TX_MIN_IN_OUT_COUNT_RATIO              = 4;

const char     CRYPTONOTE_BLOCKS_FILENAME[]                  = "blocks.dat";
const char     CRYPTONOTE_BLOCKINDEXES_FILENAME[]            = "blockindexes.dat";
const char     CRYPTONOTE_BLOCKSCACHE_FILENAME[]             = "blockscache.dat";
const char     CRYPTONOTE_POOLDATA_FILENAME[]                = "poolstate.bin";
const char     P2P_NET_DATA_FILENAME[]                       = "p2pstate.bin";
const char     CRYPTONOTE_BLOCKCHAIN_INDICES_FILENAME[]      = "blockchainindices.dat";
const char     MINER_CONFIG_FILE_NAME[]                      = "miner_conf.json";
} // parameters

//TODO Put here the name of your currency
const char     CRYPTONOTE_NAME[]                             = "stopkimcoin";
const char     GENESIS_COINBASE_TX_HEX[]                     = "010a01ff0001f89bf98647029b2e4c0281c0b02e7c53291a94d1d0cbff8883f8024f5142ee494ffbbd08807121019e80ec0db4572d5ef8efe5dfe5e5d1a27f7565d6b8f3d01301b161ed2b0a2b96";


const uint8_t  CURRENT_TRANSACTION_VERSION                   =  1;
const uint8_t  BLOCK_MAJOR_VERSION_1                         =  1;
const uint8_t  BLOCK_MINOR_VERSION_0                         =  0;

const size_t   BLOCKS_IDS_SYNCHRONIZING_DEFAULT_COUNT        =  10000;  //by default, blocks ids count in synchronizing
const size_t   BLOCKS_SYNCHRONIZING_DEFAULT_COUNT            =  200;    //by default, blocks count in blocks downloading
const size_t   COMMAND_RPC_GET_BLOCKS_FAST_MAX_COUNT         =  1000;

//TODO This port will be used by the daemon to establish connections with p2p network
const int      P2P_DEFAULT_PORT                              = 42211;
//TODO This port will be used by the daemon to interact with simlewallet
const int      RPC_DEFAULT_PORT                              = 42212;

const size_t   P2P_LOCAL_WHITE_PEERLIST_LIMIT                =  1000;
const size_t   P2P_LOCAL_GRAY_PEERLIST_LIMIT                 =  5000;

const size_t   P2P_CONNECTION_MAX_WRITE_BUFFER_SIZE          = 16 * 1024 * 1024; // 16 MB
const uint32_t P2P_DEFAULT_CONNECTIONS_COUNT                 = 8;
const size_t   P2P_DEFAULT_WHITELIST_CONNECTIONS_PERCENT     = 70;
const uint32_t P2P_DEFAULT_HANDSHAKE_INTERVAL                = 60;            // seconds
const uint32_t P2P_DEFAULT_PACKET_MAX_SIZE                   = 100000000;      // 100000000 bytes maximum packet size
const uint32_t P2P_DEFAULT_PEERS_IN_HANDSHAKE                = 250;
const uint32_t P2P_DEFAULT_CONNECTION_TIMEOUT                = 5000;          // 5 seconds
const uint32_t P2P_DEFAULT_PING_CONNECTION_TIMEOUT           = 2000;          // 2 seconds
const uint64_t P2P_DEFAULT_INVOKE_TIMEOUT                    = 60 * 2 * 1000; // 2 minutes
const size_t   P2P_DEFAULT_HANDSHAKE_INVOKE_TIMEOUT          = 5000;          // 5 seconds
const char     P2P_STAT_TRUSTED_PUB_KEY[]                    = "8f80f9a5a434a9f1510d13336228debfee9c918ce505efe225d8c94d045fa115";

//TODO Add here your network seed nodes
const std::initializer_list<const char*> SEED_NODES = {
  "52.15.191.165:42211",         //node1
  "54.82.33.203:42211",          //node2
  "54.165.44.110:42211",         //node3
  "13.59.228.116:42211"          //node4
};

struct CheckpointData {
  uint32_t height;
  const char* blockId;
};

#ifdef __GNUC__
__attribute__((unused))
#endif

// You may add here other checkpoints using the following format:
// {<block height>, "<block hash>"},
const std::initializer_list<CheckpointData> CHECKPOINTS = {
  { 1, "1f42462bd584972bb41aed3281eb091c49ddddce82c9d39274553e87139900c4" },
  { 100, "535abee8b90aa63764b1d94718842b06d9671b5929d8be68da3606cfea15a130" },
  { 1000, "b99a5e258eb2e7070f6b9be70a7b7e02294ddc4fa08e1bfe24f5bd8d3717d42d" },
  { 5050, "f7c69399330e4f5f92a75fd8956ef8abea0c76b59e597e109692ea1b84d69cd4" },
  { 10000, "75e529d11832824f1c9aef45e2c5446ea6b79c0d0df71fe7da5c184b8a0b7bae" },
  { 13095, "ad10f04bcd6f4bb7d22c590c38f441c2238de977181050f36a7a817d8dd42894" }
};
} // CryptoNote

#define ALLOW_DEBUG_COMMANDS
