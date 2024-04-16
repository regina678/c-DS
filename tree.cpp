#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void reverseTree(TreeNode* root) {
    if (root == nullptr) return;
    
    reverseTree(root->left);
    reverseTree(root->right);
    
    std::swap(root->left, root->right);
}

// Utility function to print the tree (in-order traversal)
void printTree(TreeNode* root) {
    if (root == nullptr) return;
    
    printTree(root->left);
    std::cout << root->val << " ";
    printTree(root->right);
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    
    std::cout << "Original tree: ";
    printTree(root);
    std::cout << std::endl;
    
    reverseTree(root);
    
    std::cout << "Reversed tree: ";
    printTree(root);
    std::cout << std::endl;
    
    return 0;
}
