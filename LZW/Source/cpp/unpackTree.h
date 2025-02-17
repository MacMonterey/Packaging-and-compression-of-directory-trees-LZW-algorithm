//
// Created by ubuntu on 25-2-17.
//

// --- 模擬解壓縮與解包 ---

#ifndef UNPACKTREE_H
#define UNPACKTREE_H

#include <string>
#include "TreeNode.h" // 包含 TreeNode.h

void unpackTree(TreeNode* root, const std::string& basePath = "");

#endif //UNPACKTREE_H
