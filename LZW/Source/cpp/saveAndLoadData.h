//
// Created by ubuntu on 25-2-17.
//




#ifndef SAVEANDLOADDATA_H
#define SAVEANDLOADDATA_H

#include <vector>
#include <string>

// 将压缩数据保存到文件
bool saveCompressedDataToFile(const std::vector<int>& data, const std::string& filename);

// 从文件中加载压缩数据
std::vector<int> loadCompressedDataFromFile(const std::string& filename);

#endif


