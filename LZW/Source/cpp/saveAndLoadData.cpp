//
// Created by ubuntu on 25-2-17.
//

#include "saveAndLoadData.h"
#include <fstream>
#include <iostream>

bool saveCompressedDataToFile(const std::vector<int>& data, const std::string& filename) {
    std::ofstream outFile(filename, std::ios::binary);
    if (outFile.is_open()) {
        for (int code : data) {
            outFile.write(reinterpret_cast<const char*>(&code), sizeof(code));
        }
        outFile.close();
        if (!outFile.good()) {
            std::cerr << "Error writing compressed data to file: "<< filename << std::endl;
            return false; // 写入失败
        }
        return true; // 写入成功
    } else {
        std::cerr << "Error opening file for writing: " << filename << std::endl;
        return false; // 打开文件失败
    }
}

std::vector<int> loadCompressedDataFromFile(const std::string& filename) {
    std::vector<int> data;
    std::ifstream inFile(filename, std::ios::binary);
    if (inFile.is_open()) {
        int code;
        while (inFile.read(reinterpret_cast<char*>(&code), sizeof(code))) {
            data.push_back(code);
        }
        inFile.close();
        if (!inFile.good()) {
            std::cerr << "Error Reading compressed data from file: "<< filename << std::endl;
        }
    } else {
        std::cerr << "Error opening file for reading: " << filename << std::endl;
    }
    return data;
}