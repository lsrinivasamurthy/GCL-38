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


void inorder(TreeNode *rt) {
    if (rt == NULL) {
        return;
    }

    inorder(rt->left);
    cout << rt->data << " ";
    inorder(rt->right);
}

void preorder(TreeNode *rt) {
    if (rt == NULL) {
        return;
    }

    cout << rt->data << " ";
    preorder(rt->left);
    preorder(rt->right);
}

// TC: O(n^2)
// Todo: Convert the searching part to O(1) by storing the indexes of the inorder array in a hashmap => TC will become O(n).
// Aux space: O(n)
TreeNode *construct_bt_util(vector<int> &inorder, vector<int> &preorder, int in_start, int in_end, int &pre_index) {

    if (in_start > in_end) {
        return NULL;
    }

    TreeNode *root = new TreeNode(preorder[pre_index]);
    pre_index++;

    // Search for the current value in the inorder traversal.
    int index = in_start;
    for (int i = in_start + 1; i <= in_end; i++) {
        if (inorder[i] == root->data) {
            index = i;
            break;
        }
    }

    root->left = construct_bt_util(inorder, preorder, in_start, index - 1, pre_index);
    root->right = construct_bt_util(inorder, preorder, index + 1, in_end, pre_index);

    return root;
}

TreeNode* construct_bt(vector<int> inorder, vector<int> preorder) {

    int pre_index = 0;
    return construct_bt_util(inorder, preorder, 0, inorder.size() - 1, pre_index);
}


int main() {

    TreeNode *root = construct_bt({3, 1, 4, 0, 5, 2}, {0, 1, 3, 4, 2, 5});

    inorder(root);
    cout << endl;
    preorder(root);
    cout << endl;
}

// HW: Build a binary tree from its inorder and postorder traversal.
