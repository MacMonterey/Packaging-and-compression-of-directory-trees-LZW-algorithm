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
    std::cout << "序列化後的資料:\n" << serializedData << std::endl;

    // LZW 壓縮
    std::vector<int> compressedData = lzwEncode(serializedData);
    std::cout << "壓縮後的資料 (LZW 編碼): ";
    for (int code : compressedData) {
        std::cout << code << " ";
    }
    std::cout << std::endl;

    // --- 保存壓縮檔到檔案 ---
    if (saveCompressedDataToFile(compressedData, "compressed.lzw")) {
        std::cout << "壓縮檔已儲存到檔案。" << std::endl; // 中文化輸出
    }

    // --- 从檔案中存取壓縮檔 ---
    std::vector<int> loadedCompressedData = loadCompressedDataFromFile("compressed.lzw");

    // LZW 解壓縮
    std::string decompressedData; // 在 if 外部宣告，以便在 if-else 块外部访问
    if (!loadedCompressedData.empty()) {
        decompressedData = lzwDecode(loadedCompressedData);
        std::cout << "從檔案解壓縮後的資料:\n" << decompressedData << std::endl; // 中文化輸出
    } else {
        decompressedData = lzwDecode(compressedData);
        std::cout << "從原始資料解壓縮後的資料:\n" << decompressedData << std::endl; // 中文化輸出
    }

    // 反序列化
    std::istringstream iss(decompressedData);
    TreeNode* unpackedRoot = deserializeTree(iss);

    // 8. 解包，建立實際的檔案和目錄
    if (unpackedRoot) {
        std::cout << "解包後的目錄樹結構:" << std::endl; // 中文化輸出
        unpackTree(unpackedRoot);
    }

     // 驗證解壓縮和解包是否正確
    if (unpackedRoot) {
        std::cout << "Unpacked Tree Structure:" << std::endl;
        unpackTree(unpackedRoot); // 輸出到終端機，真實寫入檔案
    }
    // 清理
    delete root;
    if (unpackedRoot) {
        delete unpackedRoot;
    }

    return 0;
}