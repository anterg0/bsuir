#include <iostream>

struct Node {
    std::string data;
    int key;
    Node* left;
    Node* right;

    Node(std::string data, int key) : data(data), key(key), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    Node* root;

    Node* insert(Node* node, std::string data, int key) {
        if (node == nullptr) {
            return new Node(data, key);
        }

        if (key < node->key) {
            node->left = insert(node->left, data, key);
        } else if (key > node->key) {
            node->right = insert(node->right, data, key);
        }

        return node;
    }

    Node* search(Node* node, int key) {
        if (node == nullptr || node->key == key) {
            return node;
        }

        if (key < node->key) {
            return search(node->left, key);
        } else {
            return search(node->right, key);
        }
    }

    Node* findMin(Node* node) {
        if (node == nullptr) {
            return nullptr;
        }

        while (node->left != nullptr) {
            node = node->left;
        }

        return node;
    }

    Node* remove(Node* node, int key) {
        if (node == nullptr) {
            return nullptr;
        }

        if (key < node->key) {
            node->left = remove(node->left, key);
        } else if (key > node->key) {
            node->right = remove(node->right, key);
        } else {
            if (node->left == nullptr && node->right == nullptr) {
                delete node;
                node = nullptr;
            } else if (node->left == nullptr) {
                Node* temp = node;
                node = node->right;
                delete temp;
            } else if (node->right == nullptr) {
                Node* temp = node;
                node = node->left;
                delete temp;
            } else {
                Node* temp = findMin(node->right);
                node->data = temp->data;
                node->key = temp->key;
                node->right = remove(node->right, temp->key);
            }
        }

        return node;
    }

    void printInOrder(Node* node) {
        if (node != nullptr) {
            printInOrder(node->left);
            std::cout << "Key: " << node->key << ", Data: " << node->data << std::endl;
            printInOrder(node->right);
        }
    }

    void printPreOrder(Node* node) {
        if (node != nullptr) {
            std::cout << "Key: " << node->key << ", Data: " << node->data << std::endl;
            printPreOrder(node->left);
            printPreOrder(node->right);
        }
    }

    void printPostOrder(Node* node) {
        if (node != nullptr) {
            printPostOrder(node->left);
            printPostOrder(node->right);
            std::cout << "Key: " << node->key << ", Data: " << node->data << std::endl;
        }
    }
    Node* rotateRight(Node* node) {
        Node* pivot = node->left;
        node->left = pivot->right;
        pivot->right = node;
        return pivot;
    }
    Node* rotateLeft(Node* node) {
        Node* pivot = node->right;
        node->right = pivot->left;
        pivot->left = node;
        return pivot;
    }


    int getHeight(Node* node) {
        if (node == nullptr) {
            return 0;
        }
        int leftHeight = getHeight(node->left);
        int rightHeight = getHeight(node->right);
        return std::max(leftHeight, rightHeight) + 1;
    }

    void balanceTree(Node* node) {
        if (node == nullptr) {
            return;
        }

        int balanceFactor = getHeight(node->left) - getHeight(node->right);

        if (balanceFactor > 1) {
            if (getHeight(node->left->left) >= getHeight(node->left->right)) {
                node = rotateRight(node);
            } else {
                node->left = rotateLeft(node->left);
                node = rotateRight(node);
            }
        } else if (balanceFactor < -1) {
            if (getHeight(node->right->right) >= getHeight(node->right->left)) {
                node = rotateLeft(node);
            } else {
                node->right = rotateRight(node->right);
                node = rotateLeft(node);
            }
        }

        balanceTree(node->left);
        balanceTree(node->right);
    }
public:
    BinarySearchTree() : root(nullptr) {}
    void insert(std::string data, int key) {
        root = insert(root, data, key);
    }

    void balanceTree() {
        balanceTree(root);
    }

    void search(int key) {
        Node* result = search(root, key);

        if (result != nullptr) {
            std::cout << "Key: " << result->key << ", Data: " << result->data << std::endl;
        } else {
            std::cout << "Key not found." << std::endl;
        }
    }

    void remove(int key) {
        root = remove(root, key);
    }

    void printInOrder() {
        printInOrder(root);
    }

    void printPreOrder() {
        printPreOrder(root);
    }

    void printPostOrder() {
        printPostOrder(root);
    }
    Node* getRoot() const {
        return root;
    }
};

class MyBinarySearchTree : public BinarySearchTree {
    int countNodesWithOneChild(Node* node) {
        if (node == nullptr) {
            return 0;
        }
        int count = 0;
        if ((node->left == nullptr && node->right != nullptr) || (node->left != nullptr && node->right == nullptr)) {
            count = 1;
        }
        count += countNodesWithOneChild(node->left) + countNodesWithOneChild(node->right);
        return count;
    }
public:
    int countNodesWithOneChild() {
        return countNodesWithOneChild(getRoot());
    }
};
