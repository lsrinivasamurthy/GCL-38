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


// ----------------------------------------------------------------------------------------------------
unordered_map<TreeNode*, int> heights_memo;

int height(TreeNode *root) {

    if (root == NULL) {
        return 0;
    }

    // If the height of the node has already been calculated, we will return it in O(1) time.
    if (heights_memo.find(root) != heights_memo.end()) {
        return heights_memo[root];
    }

    int left_subtree_height = height(root->left);
    int right_subtree_height = height(root->right);

    int ht = 1 + max(left_subtree_height, right_subtree_height);

    heights_memo[root] = ht;
    return ht;
}

void diameter_util(TreeNode *root, int &result) {

    if (root == NULL) {
        return;
    }

    int lh = height(root->left);
    int rh = height(root->right);

    result = max(result, 1 + lh + rh);

    diameter_util(root->left, result);
    diameter_util(root->right, result);
}

int diameter(TreeNode *root) {

    int result = 0;
    diameter_util(root, result);
    return result;
}

// ----------------------------------------------------------------------------------------------------


// TC: O(n)
// Aux Space: O(n)

// This function returns the height of the tree rooted at the current node and also maintains the
// maximum value of (lh + rh + 1) across all of the nodes in the tree (that is, the diameter).
int height_helper(TreeNode *root, int &diam) {

    if (root == NULL) {
        return 0;
    }

    int left_subtree_height = height_helper(root->left, diam);
    int right_subtree_height = height_helper(root->right, diam);

    diam = max(diam, left_subtree_height + right_subtree_height + 1);

    int ht = 1 + max(left_subtree_height, right_subtree_height);
    return ht;
}

int diameter_simple(TreeNode *root) {

    int diam = 0;
    height_helper(root, diam);
    return diam;
}


int main() {

    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(20);
    root->right = new TreeNode(30);
    root->left->left = new TreeNode(40);
    root->left->right = new TreeNode(60);

    cout << diameter(root) << endl;
    cout << diameter_simple(root) << endl;
}