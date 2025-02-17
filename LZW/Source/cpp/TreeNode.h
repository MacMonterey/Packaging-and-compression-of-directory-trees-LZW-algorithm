#ifndef TREENODE_H
#define TREENODE_H

#include <string>
#include <vector>

class TreeNode {
public:
    std::string name;
    bool isDirectory;
    std::vector<TreeNode*> children;
    std::string fileContent;

    TreeNode(const std::string& name, bool isDirectory);
    ~TreeNode();
    void addChild(TreeNode* child);
};

#endif