//
// Created by ubuntu on 25-2-17.
//
// --- LZW 壓縮 ---

#include <string>
#include <vector>
#include <unordered_map>
#include "lzwEncode.h"



std::vector<int> lzwEncode(const std::string& input) {
    std::unordered_map<std::string, int> dictionary;
    for (int i = 0; i < 256; ++i) {
        dictionary[std::string(1, (char)i)] = i;
    }

    std::string current_string;
    std::vector<int> encoded_output;
    int next_code = 256;

    for (char c : input) {
        std::string combined_string = current_string + c;
        if (dictionary.count(combined_string)) {
            current_string = combined_string;
        } else {
            encoded_output.push_back(dictionary[current_string]);
            dictionary[combined_string] = next_code++;
            current_string = std::string(1, c);
        }
    }

    if (!current_string.empty()) {
        encoded_output.push_back(dictionary[current_string]);
    }
    return encoded_output;
}