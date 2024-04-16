#include <iostream>
#include <vector>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void inOrderTraversal(TreeNode* root, std::vector<int>& result) {
    if (root == nullptr) return;
    
    inOrderTraversal(root->left, result);
    result.push_back(root->val);
    inOrderTraversal(root->right, result);
}

TreeNode* sortedArrayToBST(std::vector<int>& nums, int start, int end) {
    if (start > end) return nullptr;
    
    int mid = (start + end) / 2;
    TreeNode* root = new TreeNode(nums[mid]);
    
    root->left = sortedArrayToBST(nums, start, mid - 1);
    root->right = sortedArrayToBST(nums, mid + 1, end);
    
    return root;
}

void printInOrder(TreeNode* root) {
    if (root == nullptr) return;
    
    printInOrder(root->left);
    std::cout << root->val << " ";
    printInOrder(root->right);
}

int main() {
    std::vector<int> nums = {5, 2, 7, 1, 9};
    std::sort(nums.begin(), nums.end());

    TreeNode* root = sortedArrayToBST(nums, 0, nums.size() - 1);
    
    std::cout << "Sorted binary tree: ";
    printInOrder(root);
    std::cout << std::endl;
    
    return 0;
}
