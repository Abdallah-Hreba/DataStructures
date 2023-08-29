#include <bits/stdc++.h>
using namespace std;
//class to construct the BST nodes
template <class T>
class node {
public:
    node<T>* leftChild;
    node<T>* rightChild;
    T data;

    node(const T& val) : leftChild(nullptr), rightChild(nullptr), data(val) {}
};
//the BST class
template <class T>
class BSTNode {
private:
    node<T>* root;

public:
    BSTNode() : root(nullptr) {}//constructor

    T* searchBST(const T& key) const {//public function to search for a key in our BST
        return searchBST(root, key);
    }

    void breadthFirst() {//function to traverse our BST using breadthfirst
        if (root) {
            queue<node<T>*> q;
            q.push(root);

            while (!q.empty()) {
                node<T>* current = q.front();
                q.pop();
                cout << current->data << " ";

                if (current->leftChild)
                    q.push(current->leftChild);

                if (current->rightChild)
                    q.push(current->rightChild);
            }
        }
    }
    //public function to insert a node in our BST
    void insertBST(const T& value) {
        root = insertBST(root, value);
    }
    //public function to delete a node from our BST
    void DeleteBST(const T& key) {
        root = DeleteBST(root, key);
    }
    //public function to make sure that our BST is in order
    void InOrder() {
        InOrder(root);
    }
    //public function to find the minimum value in the BST
    node<T>* findMinValueNode() {
        if (root)
            return minValueNode(root);
        else
            return nullptr;
    }

private://the inner functions responsible for our public functions work
    //function to search for a key in our BST
    T* searchBST(node<T>* root, const T& key) const {
        if (!root || root->data == key)
            return (root ? &(root->data) : nullptr);

        if (key < root->data)
            return searchBST(root->leftChild, key);
        else
            return searchBST(root->rightChild, key);
    }
    //function to insert a node in our BST
    node<T>* insertBST(node<T>* root, const T& value) {
        if (!root)
            return new node<T>(value);

        if (value < root->data)
            root->leftChild = insertBST(root->leftChild, value);
        else if (value > root->data)
            root->rightChild = insertBST(root->rightChild, value);

        return root;
    }
    //function to delete a node in our BST
    node<T>* DeleteBST(node<T>* root, const T& key) {
        if (!root)
            return root;

        if (key < root->data)
            root->leftChild = DeleteBST(root->leftChild, key);
        else if (key > root->data)
            root->rightChild = DeleteBST(root->rightChild, key);
        else {
            if (!root->leftChild) {
                node<T>* temp = root->rightChild;
                delete root;
                return temp;
            } else if (!root->rightChild) {
                node<T>* temp = root->leftChild;
                delete root;
                return temp;
            }

            node<T>* temp = minValueNode(root->rightChild);
            root->data = temp->data;
            root->rightChild = DeleteBST(root->rightChild, temp->data);
        }

        return root;
    }
    //function to find the minimum value in the BST
    node<T>* minValueNode(node<T>* node) {
        while (node->leftChild)
            node = node->leftChild;
        return node;
    }
    //function to make sure that our BST is in order
    void InOrder(node<T>* root) {
        if (root) {
            InOrder(root->leftChild);
            cout << root->data << " ";
            InOrder(root->rightChild);
        }
    }

};

int main() {
    BSTNode<int> bst;//intializing our BST of type integer

    // Inserting values into the BST
    bst.insertBST(50);
    bst.insertBST(30);
    bst.insertBST(70);
    bst.insertBST(20);
    bst.insertBST(40);
    bst.insertBST(60);
    bst.insertBST(80);

    // Printing the BST using breadth-first traversal
    cout << "Breadth-First Traversal: ";
    bst.breadthFirst();
    cout << endl;

    // Searching for a value in the BST
    int searchKey = 40;
    int* searchResult = bst.searchBST(searchKey);
    if (searchResult)
        cout << "Value " << searchKey << " found in the BST." << endl;
    else
        cout << "Value " << searchKey << " not found in the BST." << endl;

    // Deleting a value from the BST
    int deleteKey = 30;
    bst.DeleteBST(deleteKey);
    cout << "BST after deleting " << deleteKey << ": ";
    bst.breadthFirst();
    cout << endl;

    // In-Order traversal of the BST
    cout << "In-Order Traversal: ";
    bst.InOrder();
    cout << endl;

    node<int>* minNode = bst.findMinValueNode();
    if (minNode)
        cout << "Node with minimum value: " << minNode->data << endl;
    else
        cout << "BST is empty." << endl;

    return 0;
}