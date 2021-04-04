
#include "TreeT.h"


template<class T>
TreeT<T>::TreeT() {
    root = nullptr;
    numNodes = 0;
}

template<class T>
TreeT<T>::~TreeT() {
    DestroyTree(root);
}

template<class T>
void TreeT<T>::DestroyTree(TreeT::Node *node) {
    if (node == nullptr)
        return;

    DestroyTree(node->left);
    DestroyTree(node->right);
    delete node;
}


template<class T>
void TreeT<T>::Add(T value) {
    // Wrapper for AddHelper

    if (root == nullptr) {
        root = new Node;
        numNodes++;
        return;
    }

    AddHelper(root, value); // add value in subtree starting at root
}

template<class T>
void TreeT<T>::AddHelper(Node *&subtree, T value) {

    if (subtree == nullptr) {
        subtree = new Node;
        subtree->value = value;
        numNodes++;
        return;
    }

    if (value < subtree->value) {
        AddHelper(subtree->left, value);  // Add value to left subtree
    }
    else {
        AddHelper(subtree->right, value);  // Add value to left subtree
    }
}

template<class T>
void TreeT<T>::Remove(T item) {
    RemoveHelper(root, item);
}

template<class T>
void TreeT<T>::RemoveHelper(Node*& subtree, T value) {

    if (value == subtree->value) {
        DeleteNode(subtree);  // Found the node. Now delete it.
    }
    else if (value < subtree->value) {
        RemoveHelper(subtree->left, value);    // go left
    }
    else {
        RemoveHelper(subtree->right, value);   // go right
    }
}

template<class T>
void TreeT<T>::DeleteNode(Node *&subtree) {

    T item;
    Node* tempPtr;

    tempPtr = subtree;
    if (subtree->right == NULL && subtree->left == NULL)
    {
        delete tempPtr;
        subtree = NULL;
    }
    else if (subtree->left == NULL)
    {
        subtree = subtree->right;
        delete tempPtr;
    }
    else if (subtree->right == NULL)
    {
        subtree = subtree->left;
        delete tempPtr;
    }
    else {
        GetPredecessor(subtree->left, item);
        subtree->info = item;
        RemoveHelper(subtree->left, item);
    }
}


template<class T>
void TreeT<T>::GetPredecessor(TreeT::Node *curr, T& value) {
    while (curr->right != nullptr) {
        curr = curr->right;
    }
    value = curr->value;
}

template<class T>
bool TreeT<T>::Contains(T value) {
    // Wrapper function for ContainsHelper
    return ContainsHelper(root, value);
}

// Used for recursive version.
template<class T>
bool TreeT<T>::ContainsHelper(Node* subtree, T value) {
    // base case 1
    if (subtree == nullptr) {
        return false;
    }

    // base case 2
    if (subtree->value == value) {
        return true;
    }

    if (value < subtree->value) {
        return ContainsHelper(subtree->left, value);  // look in the left subtree for value
    }
    else {
        return ContainsHelper(subtree->right, value);  // look in the right subtree for value
    }
}

template<class T>
int TreeT<T>::Size() {
    return numNodes;
}

template<class T>
void TreeT<T>::ResetIterator(Order traverseOrder) {
    if (traverseOrder == IN_ORDER)
        PlaceInOrder(root);
    else if (traverseOrder == POST_ORDER)
        PlacePostOrder(root);
    else
        PlacePreOrder(root);
}

template<class T>
T TreeT<T>::GetNextItem() {
    return T();
}

template<class T>
void TreeT<T>::PlacePreOrder(TreeT::Node *node) {

}

template<class T>
void TreeT<T>::PlacePostOrder(TreeT::Node *node) {

}

template<class T>
void TreeT<T>::PlaceInOrder(TreeT::Node *node) {

}






