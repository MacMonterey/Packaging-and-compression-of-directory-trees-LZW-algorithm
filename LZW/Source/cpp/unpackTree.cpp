//
// Created by ubuntu on 25-2-17.
//

// --- 模擬解壓縮與解包 ---

#include "unpackTree.h"

#include <iostream> // 為了 std::cout
#include <fstream>  // 為了 std::ofstream
#include <filesystem> // 包含 <filesystem>

namespace fs = std::filesystem; // 命名空间别名，简化代码

void unpackTree(TreeNode* root, const std::string& basePath) {
    std::string currentPath = basePath + root->name;

    if (root->isDirectory) {
        std::cout << "Creating directory: " << currentPath << std::endl;
        fs::create_directory(currentPath); // 取消注释，并使用 std::filesystem

        for (TreeNode* child : root->children) {
            unpackTree(child, currentPath + "/");
        }
    } else {
        std::cout << "Writing file: " << currentPath << std::endl;
        std::ofstream outFile(currentPath);
        if (outFile.is_open()) { // 检查文件是否成功打开
            outFile << root->fileContent;
            outFile.close();
            if (!outFile.good()) {  //寫入後檢查
                std::cerr << "Error writing to file: " << currentPath << std::endl;
            }
        } else {
            std::cerr << "Error opening file for writing: " << currentPath << std::endl;
        }
    }
}