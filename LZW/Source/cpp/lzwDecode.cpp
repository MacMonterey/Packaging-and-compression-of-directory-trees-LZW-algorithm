//
// Created by ubuntu on 25-2-17.
//
// --- LZW 解壓縮 ---

#include <string>
#include <vector>
#include <unordered_map>

#include "lzwDecode.h"


std::string lzwDecode(const std::vector<int>& encoded) {
    std::unordered_map<int, std::string> dictionary;
    for (int i = 0; i < 256; ++i) {
        dictionary[i] = std::string(1, (char)i);
    }

    std::string output;
    int next_code = 256;
    int previous_code = encoded[0];
    output += dictionary[previous_code];

    for (size_t i = 1; i < encoded.size(); ++i) {
        int current_code = encoded[i];
        std::string entry;

        if (dictionary.count(current_code)) {
            entry = dictionary[current_code];
        } else {
            entry = dictionary[previous_code] + dictionary[previous_code][0];
        }

        output += entry;
        dictionary[next_code++] = dictionary[previous_code] + entry[0];
        previous_code = current_code;

    }
    return output;
}