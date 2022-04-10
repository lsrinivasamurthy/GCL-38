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
// Aux Space: O(height)
void preorder(TreeNode *root) {

    if (root == NULL) {
        return;
    }

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// TC: O(n)
// Aux Space: O(height)
void postorder(TreeNode *root) {
    if (root == NULL) {
        return;
    }
    
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

// TC: O(n)
// Aux Space: O(height)
void inorder(TreeNode *root) {
    if (root == NULL) {
        return;
    }
    
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// --------------------------------------------------------------------------------------------------
void get_kth_level_util(TreeNode *root, int current_level, int k, vector<int> &result) {

    if (root == NULL) {
        return;
    }

    if (current_level == k) {
        result.push_back(root->data);
        return;
    }
    get_kth_level_util(root->left, current_level + 1, k, result);
    get_kth_level_util(root->right, current_level + 1, k, result);
}

vector<int> get_kth_level(TreeNode *root, int k) {

    vector<int> result;
    get_kth_level_util(root, 0, k, result);
    return result;
}

// TC: O(height * n)
// Aux Space: O(n)
void level_order_brute(TreeNode *root) {

    int k = 0;
    while(true) {
        vector<int> kth_level = get_kth_level(root, k);
        if (kth_level.size() == 0) {
            break;
        }
        for (int i : kth_level) {
            cout << i << " ";
        }
        k++;
    }
    cout << endl;
}

// --------------------------------------------------------------------------------------------------

// TC: O(n)
// Aux Space: O(n)
void level_order(TreeNode *root) {

    if (root == NULL) {
        return;
    }
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode *current = q.front();
        q.pop();

        cout << current->data << " ";

        if (current->left != NULL) {
            q.push(current->left);
        }
        if (current->right != NULL) {
            q.push(current->right);   
        }
    }
}

int main() {

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    cout << "Preorder: ";
    preorder(root);
    cout << endl;
    
    cout << "Postorder: ";
    postorder(root);
    cout << endl;

    cout << "Inorder: ";
    inorder(root);
    cout << endl;

    cout << "Level order via Brute: ";
    level_order_brute(root);

    cout << "Level order optimal: ";
    level_order(root);
    cout << endl;
}