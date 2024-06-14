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

    E remove(T key) {
        E temp = search(key);

        if (temp != E{}) {
            root = removeHelper(key, root);
            numberOfNodes--;
        }

        return temp;
    }

    void preOrderTraversal() const { cout << "Pre-order:"; preOrderTraversalHelper(root); }

    void inOrderTraversal() const { cout << "In-order:"; inOrderTraversalHelper(root); }

    void postOrderTraversal() const { cout << "Post-order:"; postOrderTraversalHelper(root); }

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
        else node->right = insertHelper(key, value, node->right);

        return node;
    }

    BSTNode<T, E>* removeHelper(T key, BSTNode<T, E>* node) {
        if (node == nullptr) return nullptr;

        if (key < node->key) return removeHelper(key, node->left);
        if (key > node->key) return removeHelper(key, node->right);

        if (node->left == nullptr) return node->right;
        if (node->right == nullptr) return node->left;

        BSTNode<T, E>* temp = getMinimumHelper(node->right);
        node->key = temp->key; node->value = temp->value;

        node->right = removeHelper(temp->key, temp);

        return node;
    }

    BSTNode<T, E>* getMinimumHelper(BSTNode<T, E>* node) {
        if (node->left == nullptr) return node;

        return getMinimumHelper(node->left);
    }

    BSTNode<T, E>* getMaximumHelper(BSTNode<T, E>* node) {
        if (node->right == nullptr) return node;

        return getMinimumHelper(node->right);
    }

    void preOrderTraversalHelper(BSTNode<T, E>* node) const {
        if (node != nullptr) {
            cout << " " << node->value;

            preOrderTraversalHelper(node->left);

            preOrderTraversalHelper(node->right);
        }
    }

    void inOrderTraversalHelper(BSTNode<T, E>* node) const {
        if (node != nullptr) {
            inOrderTraversalHelper(node->left);

            cout << " " << node->value;

            inOrderTraversalHelper(node->right);
        }
    }

    void postOrderTraversalHelper(BSTNode<T, E>* node) const {
        if (node != nullptr) {
            postOrderTraversalHelper(node->left);

            postOrderTraversalHelper(node->right);

            cout << " " << node->value;
        }
    }
};

int main() {
    return 0;
}
