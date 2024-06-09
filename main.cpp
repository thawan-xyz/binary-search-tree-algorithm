#include <iostream>
using namespace std;

template <typename T, typename E>
class BSTNode {
public:
    T key;
    E value;
    BSTNode<T, E>* left;
    BSTNode<T, E>* right;

    BSTNode(T key, E value) : key(key), value(value), left(nullptr), right(nullptr) {}

    ~BSTNode() = default;

    bool operator == (const BSTNode& other) const { return key == other.key; }

    bool operator != (const BSTNode& other) const { return key != other.key; }

    bool operator < (const BSTNode& other) const { return key < other.key; }

    bool operator <= (const BSTNode& other) const { return key <= other.key; }

    bool operator > (const BSTNode& other) const { return key > other.key; }

    bool operator >= (const BSTNode& other) const { return key >= other.key; }

};

template <typename T, typename E>
class BinarySearchTree {
public:
    BinarySearchTree() : numberOfNodes(0), root(nullptr) {}

    ~BinarySearchTree() = default;

    E search(T key) const { return searchHelper(key, root); }

    void insert(T key, E value) { root = insertHelper(key, value, root); numberOfNodes++; }

private:
    int numberOfNodes;
    BSTNode<T, E>* root;

    E searchHelper(T key, BSTNode<T, E>* node) const {
        if (node == nullptr) return E{};

        if (key < node->key) return searchHelper(key, node->left);
        if (key > node->key) return searchHelper(key, node->right);

        return node->value;
    }

    BSTNode<T, E>* insertHelper(T key, E value, BSTNode<T, E>* node) {
        if (node == nullptr) return new BSTNode<T, E>(key, value);

        if (key < node->key) node->left = insertHelper(key, value, node->left);
        else node->right = insertHelper(key, value, node->left);

        return node;
    }
};

int main() {
    return 0;
}
