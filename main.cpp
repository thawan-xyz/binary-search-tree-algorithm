#include <iostream>
using namespace std;

// Definition of the template class for the binary search tree node
template <typename T, typename E>
class BSTNode {
public:
    T key; // Key of the node
    E value; // Value associated with the key
    BSTNode<T, E>* left; // Pointer to the left child node
    BSTNode<T, E>* right; // Pointer to the right child node

    // Constructor to initialize the node with a key and value, and null children
    BSTNode(T key, E value) : key(key), value(value), left(nullptr), right(nullptr) {}

    // Default destructor
    ~BSTNode() = default;

    // Overloading the equality operator
    bool operator == (const BSTNode& other) const { return key == other.key; }

    // Overloading the inequality operator
    bool operator != (const BSTNode& other) const { return key != other.key; }

    // Overloading the less than operator
    bool operator < (const BSTNode& other) const { return key < other.key; }

    // Overloading the less than or equal to operator
    bool operator <= (const BSTNode& other) const { return key <= other.key; }

    // Overloading the greater than operator
    bool operator > (const BSTNode& other) const { return key > other.key; }

    // Overloading the greater than or equal to operator
    bool operator >= (const BSTNode& other) const { return key >= other.key; }

};

// Definition of the template class for the binary search tree
template <typename T, typename E>
class BinarySearchTree {
public:
    // Constructor to initialize an empty binary search tree
    BinarySearchTree() : numberOfNodes(0), root(nullptr) {}

    // Default destructor
    ~BinarySearchTree() = default;

    // Public method to search for a key in the tree
    E search(T key) const { return searchHelper(key, root); }

    // Public method to insert a key-value pair into the tree
    void insert(T key, E value) { root = insertHelper(key, value, root); numberOfNodes++; }

    // Public method to remove a key from the tree
    E remove(T key) {
        E temp = search(key);

        // If the key is found, remove the node and decrement the node count
        if (temp != E{}) {
            root = removeHelper(key, root);
            numberOfNodes--;
        }

        return temp;
    }

    // Public method to perform pre-order traversal
    void preOrderTraversal() { cout << "Pre-order:"; preOrderTraversalHelper(root); }

    // Public method to perform in-order traversal
    void inOrderTraversal() { cout << "In-order:"; inOrderTraversalHelper(root); }

    // Public method to perform post-order traversal
    void postOrderTraversal() { cout << "Post-order:"; postOrderTraversalHelper(root); }

private:
    int numberOfNodes; // Number of nodes in the tree
    BSTNode<T, E>* root; // Root node of the tree

    // Private helper method for searching a key in the tree
    E searchHelper(T key, BSTNode<T, E>* node) const {
        // If the node is null, return a default value
        if (node == nullptr) return E{};

        // Recursively search in the left or right subtree based on the key
        if (key < node->key) return searchHelper(key, node->left);
        if (key > node->key) return searchHelper(key, node->right);

        // If the key is found, return the value
        return node->value;
    }

    // Private helper method for inserting a key-value pair into the tree
    BSTNode<T, E>* insertHelper(T key, E value, BSTNode<T, E>* node) {
        // If the node is null, create a new node
        if (node == nullptr) return new BSTNode<T, E>(key, value);

        // Recursively insert in the left or right subtree based on the key
        if (key < node->key) node->left = insertHelper(key, value, node->left);
        else node->right = insertHelper(key, value, node->right);

        // Return the node recursively
        return node;
    }

    // Private helper method for removing a key from the tree
    BSTNode<T, E>* removeHelper(T key, BSTNode<T, E>* node) {
        // If the node is null, return null
        if (node == nullptr) return nullptr;

        // Recursively remove from the left or right subtree based on the key
        if (key < node->key) return removeHelper(key, node->left);
        if (key > node->key) return removeHelper(key, node->right);

        // If the node to be removed is found, handle the three cases
        if (node->left == nullptr) return node->right;
        if (node->right == nullptr) return node->left;

        // Replace the current node with the smallest node in the right subtree
        BSTNode<T, E>* temp = getMinimumHelper(node->right);
        node->key = temp->key; node->value = temp->value;

        // Remove the node temp from the right subtree
        node->right = removeHelper(temp->key, temp);

        // Return the node recursively
        return node;
    }

    // Private helper method to find the minimum node in a subtree
    BSTNode<T, E>* getMinimumHelper(BSTNode<T, E>* node) {
        // If the current node has no right child, it is the minimum node
        if (node->left == nullptr) return node;

        // Continue searching in the left subtree for the minimum node
        return getMinimumHelper(node->left);
    }

    // Private helper method to find the maximum node in a subtree
    BSTNode<T, E>* getMaximumHelper(BSTNode<T, E>* node) {
        // If the current node has no right child, it is the maximum node
        if (node->right == nullptr) return node;

        // Continue searching in the right subtree for the maximum node
        return getMinimumHelper(node->right);
    }

    // Private helper method to perform pre-order traversal recursively
    void preOrderTraversalHelper(BSTNode<T, E>* node) {
        if (node != nullptr) {
            // Process the current node
            cout << " " << node->value;

            // Recursively traverse the left subtree
            preOrderTraversalHelper(node->left);

            // Recursively traverse the right subtree
            preOrderTraversalHelper(node->right);
        }
    }

    // Private helper method to perform in-order traversal recursively
    void inOrderTraversalHelper(BSTNode<T, E>* node) {
        if (node != nullptr) {
            // Recursively traverse the left subtree
            inOrderTraversalHelper(node->left);

            // Process the current node
            cout << " " << node->value;

            // Recursively traverse the right subtree
            inOrderTraversalHelper(node->right);
        }
    }

    // Private helper method to perform post-order traversal recursively
    void postOrderTraversalHelper(BSTNode<T, E>* node) {
        if (node != nullptr) {
            // Recursively traverse the left subtree
            postOrderTraversalHelper(node->left);

            // Recursively traverse the right subtree
            postOrderTraversalHelper(node->right);

            // Process the current node
            cout << " " << node->value;
        }
    }
};

int main() {
    return 0;
}
