//
// Created by ubuntu on 25-2-17.
//
// --- 目錄樹序列化 (前序遍歷) ---


#include <string>
#include <vector>
#include <sstream>

#include "TreeNode.h"
#include "serializeTree.h"


std::string serializeTree(TreeNode* node) {
    std::ostringstream oss;
    if (node->isDirectory) {
        oss << "d:" << node->name << "\n"; // d 代表目錄
        for (TreeNode* child : node->children) {
            oss << serializeTree(child);
        }
        oss << "e\n"; // e 代表目錄結束
    } else {
        oss << "f:" << node->name << "\n"; // f 代表檔案
        oss << "s:" << node->fileContent.size() << "\n";  // 檔案大小
        oss << node->fileContent << "\n";
    }
    return oss.str();
}