//
// Author: Varick Erickson
// Date: 2/18/2021
//

#ifndef TREET_H
#define TREET_H

#include <queue>
using namespace std;

// Used to identify the order you wish to traverse the tree
enum Order {PRE_ORDER, POST_ORDER, IN_ORDER};

template<class T>
class TreeT {
public:
    TreeT();
    ~TreeT();
    TreeT(const TreeT<T> otherTree);

    void Add(T value);       // Add value to the tree
    void Remove(T value);    // Remove value from the tree
    bool Contains(T value);  // Determines if value is in the tree

    int Size();     // Number of value in the tree

    // These are used by the iterator
    void ResetIterator(Order traverseOrder);    // Initializes the Iterator
    T GetNextItem();

private:
    struct Node {
        Node* left = nullptr;
        Node* right = nullptr;
        T value;
    };
    Node* root;
    int numNodes;

    // Used for de-constructor
    void DestroyTree(Node* node);

    // Recursive helpers
    bool ContainsHelper(Node* subtree, T value);
    void AddHelper(Node*& subtree, T value);

    // Used for Node removal
    void RemoveHelper(Node*& subtree, T value);
    void DeleteNode(Node*& subtree);
    void GetPredecessor(Node* curr, T& value);

    // Used for iterator
    queue<T> iterArr;     // queue used for the iterator
    void PlacePreOrder(Node* node);
    void PlacePostOrder(Node* node);
    void PlaceInOrder(Node* node);
};


#include "TreeT.cpp"

#endif //TREET_H
