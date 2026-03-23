#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* left;
    Node* right;

    Node(char value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

void preorder(Node* root) {
    // 前序遍歷：根節點 -> 左子樹 -> 右子樹
    if (root == nullptr) return;
    cout << root->data << " "; // 訪問根節點
    preorder(root->left);      // 遞迴走訪左子樹
    preorder(root->right);     // 遞迴走訪右子樹
}

void inorder(Node* root) {
    // 中序遍歷：左子樹 -> 根節點 -> 右子樹
    if (root == nullptr) return;
    inorder(root->left);       // 遞迴走訪左子樹
    cout << root->data << " "; // 訪問根節點
    inorder(root->right);      // 遞迴走訪右子樹
}

void postorder(Node* root) {
    // 後序遍歷：左子樹 -> 右子樹 -> 根節點
    if (root == nullptr) return;
    postorder(root->left);     // 遞迴走訪左子樹
    postorder(root->right);    // 遞迴走訪右子樹
    cout << root->data << " "; // 訪問根節點
}

void deleteTree(Node* root) {
    if (root == nullptr) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    Node* root = new Node('A');
    root->left = new Node('B');
    root->right = new Node('C');
    root->left->left = new Node('D');
    root->left->right = new Node('E');
    root->right->right = new Node('F');

    cout << "Preorder traversal: ";
    preorder(root);
    cout << endl;

    cout << "Inorder traversal: ";
    inorder(root);
    cout << endl;

    cout << "Postorder traversal: ";
    postorder(root);
    cout << endl;

    deleteTree(root);
    return 0;
}
