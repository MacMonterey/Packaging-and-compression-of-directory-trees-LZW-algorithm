//
// Created by ubuntu on 25-2-17.
//

// --- 目錄樹反序列化 ---

#include "deserializeTree.h"

TreeNode* deserializeTree(std::istringstream& iss) {
    std::string line;
    if (!std::getline(iss, line)) {
        return nullptr;
    }

    char type = line[0];
    std::string name = line.substr(2);

    if (type == 'd') {
        TreeNode* dirNode = new TreeNode(name, true);
        while (std::getline(iss, line) && line != "e") {
            iss.seekg(-line.size() - 1, std::ios_base::cur); // 回溯一行
            TreeNode* child = deserializeTree(iss);
            if (child) {
                dirNode->addChild(child);
            }
        }
        return dirNode;

    } else if (type == 'f') {
        TreeNode* fileNode = new TreeNode(name, false);
        std::getline(iss, line); // 讀取大小
        size_t size = std::stoi(line.substr(2));
        std::getline(iss, line);
        fileNode->fileContent = line.substr(0, size); // 可能包含換行符號
        return fileNode;
    }
    return nullptr;
}
