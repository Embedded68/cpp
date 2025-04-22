#include <iostream>
#include <stack>
using namespace std;

// Definition of a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Recursive Inorder Traversal
void inorderRecursive(TreeNode* root) {
    if (!root) return;
    inorderRecursive(root->left);
    cout << root->val << " ";
    inorderRecursive(root->right);
}

// Non-Recursive Inorder Traversal
void inorderNonRecursive(TreeNode* root) {
    stack<TreeNode*> s;
    TreeNode* current = root;

    while (current || !s.empty()) {
        while (current) {
            s.push(current);
            current = current->left;
        }
        current = s.top();
        s.pop();
        cout << current->val << " ";
        current = current->right;
    }
}

//usage
int main() {
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    cout << "Recursive Inorder Traversal: ";
    inorderRecursive(root);
    cout << endl;

    cout << "Non-Recursive Inorder Traversal: ";
    inorderNonRecursive(root);
    cout << endl;

    return 0;
}