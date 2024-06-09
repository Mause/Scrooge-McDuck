//===----------------------------------------------------------------------===//
//                         Scrooge
//
// util/eth_maps.hpp
//
//
//===----------------------------------------------------------------------===//

#pragma once

namespace duckdb {
namespace scrooge {
// Event data structure
struct Event {
  string name;
  vector<string> parameterTypes;
  uint8_t id;
};

// Known event signatures and their descriptions
const unordered_map<string, Event> event_signatures = {
    {"0xddf252ad1be2c89b69c2b068fc378daa952ba7f163c4a11628f55a4df523b3ef",
     {"Transfer", {"address", "address", "uint256"}, 0}},
    {"0x8c5be1e5ebec7d5bd14f714f0f3a56d4af4fef1d7f7bb78a0c69d4cdb365d97e",
     {"Approval", {"address", "address", "uint256"}, 1}},
    {"0x1c411e9a96aaffc4e1b98a00ef4a86ce2e058f7d78f2c83971e57f36d39188c7",
     {"Sync", {"uint112", "uint112"}, 2}},
    {"0x4a39dc06d4c0dbc64b70b7bfa42387d156a1b455ad1583a19957f547256c22e5",
     {"TransferSingle",
      {"address", "address", "address", "uint256", "uint256"},
      3}},
    {"0xc3d58168cbe0a160b82265397fa6b10ff1c847f6b8df03e1d36e5e4bba925ed5",
     {"TransferBatch",
      {"address", "address", "address", "uint256[]", "uint256[]"},
      4}},
    {"0x17307eab39c17eae00a0c514c4b17d95e15ee86d924b1cf3b9c9dc7f59e3e5a1",
     {"ApprovalForAll", {"address", "address", "bool"}, 5}}};

const unordered_map<string, string> token_adresses = {
    {"ETH", "0x0000000000000000000000000000000000000000"},  // Ether
    {"USDT", "0xdAC17F958D2ee523a2206206994597C13D831ec7"}, // Tether USD
    {"USDC", "0xA0b86991c6218b36c1d19D4a2e9Eb0cE3606EB48"}, // USD Coin
    {"DAI", "0x6B175474E89094C44Da98b954EedeAC495271d0F"},  // DAI Stablecoin
    {"BNB", "0xB8c77482e45F1F44dE1745F52C74426C631bDD52"},  // Binance Coin
    {"UNI", "0x1f9840a85d5aF5bf1D1762F925BDADdC4201F984"},  // Uniswap
    {"LINK", "0x514910771AF9Ca656af840dff83E8264EcF986CA"}, // Chainlink
    {"WBTC", "0x2260FAC5E5542a773Aa44fBCfeDf7C193bc2C599"}, // Wrapped Bitcoin
    {"LTC", "0x4338665CBB7B2485A8855A139b75D5e34AB0DB94"},  // Litecoin
    {"BUSD", "0x4fabb145d64652a948d72533023f6e7a623c7c53"}, // Binance USD
    {"ANDY", "0x68BbEd6A47194EFf1CF514B50Ea91895597fc91E"}};

const unordered_map<string, string> event_to_hex_signatures = {
    {"TRANSFER",
     "0xddf252ad1be2c89b69c2b068fc378daa952ba7f163c4a11628f55a4df523b3ef"},
    {"APPROVAL",
     "0x8c5be1e5ebec7d5bd14f714f13107d2b7b6e6d2027d8710d3b0b4f43363d9ab8"},
    {"DEPOSIT",
     "0xe1fffcc4923d54a4bdb6e0a28d0b6b7b2fb29a260555b24c75f6b1e7b3bfb123"},
    {"WITHDRAWAL",
     "0x7fcf26fc5cc6d7e6e05e1144b4b68871c514e020f1fc0d7d839bd09f61a8bc86"}};

const unordered_map<string, uint8_t> event_to_enum = {
    {"Transfer", 0},
    {"Approval", 1},
    {"Sync", 2},
    {"Transfer", 0},
};
} // namespace scrooge
} // namespace duckdb
