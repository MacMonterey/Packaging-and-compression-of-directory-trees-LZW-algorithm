//
// Created by ubuntu on 25-2-17.
//

// --- 模擬檔案系統建立 ---

#include "createExampleTree.h"


TreeNode* createExampleTree() {
    TreeNode* root = new TreeNode("root", true);

    TreeNode* dir1 = new TreeNode("dir1", true);
    root->addChild(dir1);

    TreeNode* file1 = new TreeNode("file1.txt", false);
    file1->fileContent = "This is the content of file1.";
    dir1->addChild(file1);

    TreeNode* dir2 = new TreeNode("dir2", true);
    root->addChild(dir2);

    TreeNode* file2 = new TreeNode("file2.txt", false);
    file2->fileContent = "Content of file2.";
    dir2->addChild(file2);

    TreeNode* file3 = new TreeNode("file3.txt", false);
    file3->fileContent = "Another file in the root.";
    root->addChild(file3);

    return root;
}