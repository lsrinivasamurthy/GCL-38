#include<bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

int height(TreeNode *root) {

    if (root == NULL) {
        return 0;
    }

    int left_subtree_height = height(root->left);
    int right_subtree_height = height(root->right);

    int ht = 1 + max(left_subtree_height, right_subtree_height);

    cout << "Height of " << root->data << ": " << ht << endl;
    return ht;
}

int main() {

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(6);
    root->right->right->right = new TreeNode(7);

    cout << height(root) << endl;
}