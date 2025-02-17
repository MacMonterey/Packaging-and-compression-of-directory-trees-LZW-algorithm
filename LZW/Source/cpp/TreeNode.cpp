#include "TreeNode.h"

TreeNode::TreeNode(const std::string& name, bool isDirectory) : name(name), isDirectory(isDirectory) {}

TreeNode::~TreeNode() {
    for (TreeNode* child : children) {
        delete child;
    }
}

void TreeNode::addChild(TreeNode* child) {
    children.push_back(child);
}