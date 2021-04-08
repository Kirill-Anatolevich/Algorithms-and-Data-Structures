#include "additional_function.hpp"

struct Node {
    int value;
    Node* left;
    Node* right;
    Node* parent;
    Node(): value(), left(NULL), right(NULL), parent(NULL) {};
    Node(int val): value(val), left(NULL), right(NULL), parent(NULL) {};
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

};

int main() {
    AVLTree *avltree = new AVLTree;
    (void)avltree;
}
