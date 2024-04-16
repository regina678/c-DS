#include <iostream>
#include <map>
#include <vector>
#include <queue>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void verticalOrderTraversal(TreeNode* root) {
    if (root == nullptr) return;

    // Map to store nodes at different vertical distances
    std::map<int, std::vector<int>> verticalMap;

    // Queue for level order traversal
    std::queue<std::pair<TreeNode*, int>> q;
    q.push({root, 0});

    // Level order traversal
    while (!q.empty()) {
        TreeNode* node = q.front().first;
        int hd = q.front().second;
        q.pop();

        // Store node's value at its vertical distance in the map
        verticalMap[hd].push_back(node->val);

        // Enqueue left child with horizontal distance hd-1
        if (node->left != nullptr) {
            q.push({node->left, hd - 1});
        }
        // Enqueue right child with horizontal distance hd+1
        if (node->right != nullptr) {
            q.push({node->right, hd + 1});
        }
    }

    // Print nodes in vertical order
    for (auto& pair : verticalMap) {
        std::cout << "Column " << pair.first << ": ";
        for (int val : pair.second) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    // Constructing a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    std::cout << "Vertical Order Traversal:\n";
    verticalOrderTraversal(root);

    return 0;
}
