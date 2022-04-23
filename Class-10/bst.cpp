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

// TC: O(height)
// Aux Space: O(height)
bool search_rec(TreeNode *root, int find) {

    if (root == NULL) {
        return false;
    }

    if (root->data == find) {
        return true;
    }
    if (find < root->data) {
        return search_rec(root->left, find);
    }
    return search_rec(root->right, find);
}


// TC: O(height)
// Aux space: O(1)
bool search_iter(TreeNode *root, int find) {

    while (root != NULL) {
        if (root->data == find) {
            return true;
        }
        if (find < root->data) {
            root = root->left;
        }
        else {
            root = root->right;
        }
    }
    return false;
}


int main() {

    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(8);

    cout << search_rec(root, 4) << endl;
    cout << search_rec(root, 10) << endl;
    cout << search_rec(root, 7) << endl;

    cout << search_iter(root, 4) << endl;
    cout << search_iter(root, 10) << endl;
    cout << search_iter(root, 7) << endl;
}