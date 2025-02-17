#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

#include "TreeNode.h"
#include "unpackTree.h" // 包含 unpackTree.h
#include "createExampleTree.h"// 包含 createExampleTree.h
#include "deserializeTree.h"// 包含 deserializeTree.h
#include "lzwEncode.h"
#include "lzwDecode.h"
#include "serializeTree.h"
#include "saveAndLoadData.h"




int main() {
    // 建立範例目錄樹
    TreeNode* root = createExampleTree();

    // 序列化
    std::string serializedData = serializeTree(root);
    std::cout << "Serialized Data:\n" << serializedData << std::endl;

    // LZW 壓縮
    std::vector<int> compressedData = lzwEncode(serializedData);
    std::cout << "Compressed Data (LZW Codes): ";
    for (int code : compressedData) {
        std::cout << code << " ";
    }
    std::cout << std::endl;

    // --- 保存壓縮檔到檔案 ---
    if (saveCompressedDataToFile(compressedData, "compressed.lzw")) {
        std::cout << "Compressed data saved to file." << std::endl;
    }

    // --- 从檔案中存取壓縮檔 ---
    std::vector<int> loadedCompressedData = loadCompressedDataFromFile("compressed.lzw");

    // LZW 解壓縮
    std::string decompressedData = lzwDecode(compressedData);
    std::cout << "Decompressed Data:\n" << decompressedData << std::endl;

    // 反序列化
    std::istringstream iss(decompressedData);
    TreeNode* unpackedRoot = deserializeTree(iss);

     // 驗證解壓縮和解包是否正確
    if (unpackedRoot) {
        std::cout << "Unpacked Tree Structure:" << std::endl;
        unpackTree(unpackedRoot); // 輸出到終端機，真實寫入檔案
    }
    // 清理
    delete root;
    if(unpackedRoot) delete unpackedRoot;

    return 0;
}