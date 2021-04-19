#include "additional_function.hpp"

const int COUNT = 10;

struct Item {
    int key;
    int value;
};

struct Node {
    int value;
    Node* right;
    Node* left;
    Node* parent;
    Node(): value(), right(NULL), left(NULL), parent(NULL) {};
    Node(int& i): value(i), right(NULL), left(NULL), parent(NULL) {};
};

class BinarySearchTree {
    Node* root;
public:
    BinarySearchTree(): root(NULL) {};

    void Insert(int val) {
        if (root == NULL) {
            root = new Node(val);
            std::cout<<"The item "<<val<< " was added successfully"<<'\n';
            return; 
        }
        Insert(root, val);
    }

    void Insert(Node *node, int val) {
        if (node->value == val) {
            std::cout<<"The item "<<val<<" already exists"<<'\n';
            return;
        }
        else if (val < node->value) {
            if (node->left == NULL) {
                node->left = new Node(val);
                node->left->parent = node;
                std::cout<<"The item "<<val<< " was added successfully"<<'\n';
                return;
            }
            Insert(node->left, val);
        }
        else {
            if (node->right == NULL) {
                node->right = new Node(val);
                node->right->parent = node;
                std::cout<<"The item "<<val<< " was added successfully"<<'\n';
                return;
            }
            Insert(node->right, val); 
        }
    }

    void Delete(int val) {
        Node *node = root;
        while (node != NULL && node->value != val) {
            node = (val > node->value)? node->right: node->left;
        }
        if (node == NULL) {
            std::cout<<"The item "<<val<<" no exist"<<'\n'; 
            return;
        }
        else if (node->right == NULL && node->left == NULL) {
            if (node == root) {
               delete root;
            }
            if (node->parent->left == node) {
                node->parent->left = NULL;
                delete node;
            }
            else {
                node->parent->right = NULL;
                delete node;
            }
        }
        else if (node->right == NULL) {
            if (node->parent->left == node) {
                node->parent->left = node->left;
                delete node;
            }
            else { 
                node->parent->right = node->left;
                delete node;
            }
        }
        else if (node->left == NULL) {
            if (node->parent->left == node) {
                node->parent->left = node->right;
                delete node;
            }
            else { 
                node->parent->right = node->right;
                delete node;
            }
        }
        else {
            Node *tmpNode = node->right;
            int tmpValue;
            while (tmpNode->left != NULL) {
                tmpNode = tmpNode->left;
            }
            tmpValue = tmpNode->value;
            Delete(tmpValue);
            node->value = tmpValue;
        }
    }

    void print2DUtil(Node *root, int space) {
        if (root == NULL)
            return;
        space += COUNT;
        print2DUtil(root->right, space);
        std::cout<<'\n';
        for (int i = COUNT; i < space; i++)
            std::cout<<" ";
        std::cout<<root->value<<"\n";
        print2DUtil(root->left, space);
    }

    void print2D() {
        print2DUtil(root, 0);
    }

    void InorderTreeWalk() {
        InorderTreeWalk(root);
    }

    void InorderTreeWalk(Node* node) {
        if (node != NULL) {
            InorderTreeWalk(node->left);
            std::cout<<node->value<<' ';
            InorderTreeWalk(node->right);
        }
    }
};

int main() {
    BinarySearchTree* BSTree = new BinarySearchTree();
    BSTree->Insert(50);
    BSTree->Insert(1);
    BSTree->Insert(53);
    BSTree->Insert(78);
    BSTree->Insert(99);
    BSTree->Insert(69);
    BSTree->print2D();
    BSTree->InorderTreeWalk();
    BSTree->Delete(78);
    BSTree->print2D();
    (void)BSTree;
    BSTree->InorderTreeWalk();
}
