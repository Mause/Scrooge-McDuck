import duckdb

def generate_cpp_header(csv_file_path, header_file_path):
    con = duckdb.connect()
    df = con.execute(f"SELECT * FROM read_csv_auto('{csv_file_path}')").fetchdf()
    
    cpp_header = """//===----------------------------------------------------------------------===//
//                         Scrooge
//
// util/eth_uniswap_map.hpp
//
//===----------------------------------------------------------------------===//

//===----This file is auto-generated by scripts/generate_uniswap_map.py----===//

#pragma once

#include <unordered_map>
#include <string>

namespace duckdb {
namespace scrooge {
const std::unordered_map<std::string, std::string> uniswap_addresses = {
"""
    
    for _, row in df.iterrows():
        pair = f'{{"{row["token0_symbol"]}_{row["token1_symbol"]}", "{row["pair_address"]}"}}'
        cpp_header += f"    {pair},\n"
    
    cpp_header = cpp_header.rstrip(",\n") + "\n};\n}}"
    
    with open(header_file_path, 'w') as file:
        file.write(cpp_header)

csv_file_path = 'uniswap_pairs.csv'  
header_file_path = 'eth_uniswap_map.hpp' 
generate_cpp_header(csv_file_path, header_file_path)
