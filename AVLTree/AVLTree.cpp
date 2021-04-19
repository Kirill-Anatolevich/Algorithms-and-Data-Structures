#include "additional_function.hpp"

struct Node {
    int value;
    int balance;
    Node* left;
    Node* right;
    Node* parent;
    Node(): value(), left(NULL), right(NULL), parent(NULL), balance(0) {};
    Node(int val): value(val), left(NULL), right(NULL), parent(NULL), balance(0) {};
};

class AVLTree {
private:
    Node *root;
public:
    AVLTree() {
        root = new Node();
    }

    void RightRotation(Node* node) {
        if (node->left == NULL) {
            return;
        }
        Node *leftSon = node->left;
        if (leftSon->right != NULL) {
            leftSon->right->parent = node;
        }
        leftSon->parent = node->parent;
        if (node->parent == NULL) {
            root = leftSon;
        }
        else if (node == node->parent->right) {
            node->parent->right = leftSon;
        }
        else if (node == node->parent->left) {
            node->parent->left = leftSon;
        }
        leftSon->right = node;
        node->parent = leftSon;
    }

    void LeftRotation(Node* node) {
        if (node->right == NULL) {
            return;
        }
        Node *rightSon = node->right;
        node->right = rightSon->left;
        if (rightSon->left != NULL) {
            rightSon->left->parent = node;
        }
        rightSon->parent = node->parent;
        if (node->parent == NULL) {
            root = rightSon;
        }
        else if (node == node->parent->left) {
            node->parent->left = rightSon;
        }
        else {
            node->parent->right = rightSon;
        }
        rightSon->left = node;
        node->parent = rightSon;
    }

    void Insert(int val) {
        if (root == NULL) {
            root = new Node(val);
            return;
        }
        Insert(root, val);
    }

    void Rebalance(Node *node, int direction) {
        if (direction == 0)  { // Слева
            ++node->balance;
        }
        else {
            --node->balance;
        }
        if (node->balance == 0) {
            return;
        }
        if (node->balance == -1 || node->balance == 0) {
            if (node == root) {
                return;
            }
            if (node->parent->left == node) {
                Rebalance(node->parent, 0);
            }
            else {
                Rebalance(node->parent, 1);
            }
        }
        else {
            if (node->balance == 2) {
                if (node->left->balance == 1) {
                    RightRotation(node);
                }
                else {
                    

    void Insert(Node* node, int val) {
        if (node->value == val) {
            std::cout<<"The item "<<val<<" already was added\n";
            return;
        }
        if (val < node->value) {
            if (node->left == NULL) {
                Node *newNode = new Node(val);
                newNode->parent = node;
                node->left = newNode;
                Rebalance(node);
            }
            else {
                Insert(node->left, val);
            }
        }
    }

};

int main() {
    AVLTree *avltree = new AVLTree;
    (void)avltree;
}
