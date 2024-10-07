#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val){
        value = val;
        left = nullptr;
        right = nullptr;
    }
};

void inorder(TreeNode* root) {
    if (root) {
        inorder(root->left);
        cout << root->value << " ";
        inorder(root->right);
    }
};

void preorder(TreeNode* root) {
    if (root) {
        cout << root->value << " ";
        preorder(root->left);
        preorder(root->right);
    }
};

void postorder(TreeNode* root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        cout << root->value << " ";
    }
};

TreeNode* insert(TreeNode* root, int value) {
    if (root == nullptr) {
        return new TreeNode(value);
    }
    if (value < root->value) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    return root;
};

bool is_mirror(TreeNode* t1, TreeNode* t2) {
    if (!t1 && !t2){
        return true;
    }
    if (!t1 || !t2){
        return false;
    }
    return (t1->value == t2->value) && 
           is_mirror(t1->left, t2->right) && 
           is_mirror(t1->right, t2->left);
};

bool is_symmetric(TreeNode* root) {
    return !root || is_mirror(root->left, root->right);
};

void mirror_tree(TreeNode* root) {
    if (root) {
        swap(root->left, root->right);
        mirror_tree(root->left);
        mirror_tree(root->right);
    }
};

int main (){
    
    TreeNode* root = nullptr;
    root = insert(root, 4);
    insert(root, 5);
    insert(root, 3);
    insert(root, 1);
    

    inorder(root);
    cout<<endl;

    preorder(root);
    cout<<endl;


    postorder(root);
    cout<<endl;

    cout<<(is_symmetric(root) ? "Yes" : "No")<<endl;

    
    return 0;
}