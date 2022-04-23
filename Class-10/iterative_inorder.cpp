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


// TC: O(n)
// Aux space: O(n)

void push_left(TreeNode *current, stack<TreeNode*> &s) {

    while (current != NULL) {
        s.push(current);
        current = current->left;
    }
}

void iterative_inorder(TreeNode *root) {

    stack<TreeNode*> s;

    // Initiating the inorder traversal on the root node.
    push_left(root, s);

    while (!s.empty()) {

        TreeNode* current = s.top();
        s.pop();

        cout << current->data << " ";

        // Initiate the inorder traversal of the right subtree.
        push_left(current->right, s);
    }
    cout << endl;
}


int main() {

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);

    iterative_inorder(root);
}