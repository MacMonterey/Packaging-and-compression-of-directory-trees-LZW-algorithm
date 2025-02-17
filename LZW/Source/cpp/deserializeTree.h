//
// Created by ubuntu on 25-2-17.
//

// --- 目錄樹反序列化 ---

#ifndef DESERIALIZETREE_H
#define DESERIALIZETREE_H


#include <sstream> // 為了 std::istringstream
#include "TreeNode.h" // 包含 TreeNode.h

TreeNode* deserializeTree(std::istringstream& iss);

#endif //DESERIALIZETREE_H
