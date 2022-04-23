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

TreeNode *insert(TreeNode *root, int val) {

    if (root == NULL) {
        return new TreeNode(val);
    }

    if (val < root->data) {
        root->left = insert(root->left, val);
    }
    else {
        root->right = insert(root->right, val);
    }

    return root;
}

int get_smallest(TreeNode *root) {

    while (root->left != NULL) {
        root = root->left;
    }
    return root->data;
}

TreeNode *delete_node(TreeNode *root, int val) {

    if (root == NULL) {
        return NULL;
    }

    if (val == root->data) {

        // If no child node is present: Scrap-off the branch.
        if (root->left == NULL and root->right == NULL) {
            return NULL;
        }

        // If a single child is present: Replace the root with the non-NULL child node.
        if (root->left == NULL) {
            return root->right;
        }
        if (root->right == NULL) {
            return root->left;
        }

        // If two child nodes are present: Replace the node with its inorder successor and delete the inorder successor;
        int inorder_succ_val = get_smallest(root->right);
        root->data = inorder_succ_val;

        root->right = delete_node(root->right, inorder_succ_val);
    }

    else if (val < root->data) {
        root->left = delete_node(root->left, val);
    }
    else {
        root->right = delete_node(root->right, val);
    }

    return root;
}

void inorder(TreeNode *rt) {
    if (rt == NULL) {
        return;
    }

    inorder(rt->left);
    cout << rt->data << " ";
    inorder(rt->right);
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


    root = insert(NULL, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    inorder(root);
    cout << endl;

    root = delete_node(root, 20);

    inorder(root);
    cout << endl;

    root = delete_node(root, 30);

    inorder(root);
    cout << endl;

    root = delete_node(root, 50);

    inorder(root);
    cout << endl;
}