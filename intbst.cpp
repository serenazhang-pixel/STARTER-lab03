// intbst.cpp
// Implements class IntBST
// Serena Zhang, 1/21/26

#include "intbst.h"

#include <iostream>
using std::cout;

// constructor sets up empty tree
IntBST::IntBST() { 
    root = nullptr;
}

// destructor deletes all nodes
IntBST::~IntBST() {
    clear(root);
}

// recursive helper for destructor
void IntBST::clear(Node *n) {
   if (n == nullptr){
        return;
    }
    clear(n->left);
    clear(n->right);
    delete n;
}

// insert value in tree; return false if duplicate
bool IntBST::insert(int value) {
    if (!root){
        root = new Node(value);
        return false;
    }
    insert(value, root);
    return true;
}

// recursive helper for insert (assumes n is never 0)
bool IntBST::insert(int value, Node *n) {
    if (value == n->info){ // base case if values are equal
        return false;
    }
    if (value < n->info){
        if (!n->left){
            n->left = new Node(value);
            n->left->parent = n;
        }
        else{
            insert(value, n->left);
        }
    }
    if (value > n->info){
        if (!n->right){
            n->right = new Node(value);
            n->right->parent = n;
        }
        else{
            insert(value, n->right);
        }
    }
    return true;
}

// print tree data pre-order
void IntBST::printPreOrder() const {
    printPreOrder(root);
}

// recursive helper for printPreOrder()
void IntBST::printPreOrder(Node *n) const {
    if (!n){
        return;
    }
    cout << n->info << " ";
    printPreOrder(n->left);
    printPreOrder(n->right);
}

// print tree data in-order, with helper
void IntBST::printInOrder() const {
    printInOrder(root);
}
void IntBST::printInOrder(Node *n) const {
    if (!n){
        return;
    }
    printInOrder(n->left);
    cout << n->info << " ";
    printInOrder(n->right);
}

// prints tree data post-order, with helper
void IntBST::printPostOrder() const {
    printPostOrder(root);
}

void IntBST::printPostOrder(Node *n) const {
    if (!n){
        return;
    }
    printPostOrder(n->left);
    printPostOrder(n->right);
    cout << n->info << " ";
}

// return sum of values in tree
int IntBST::sum() const {
    return sum(root);
}

// recursive helper for sum
int IntBST::sum(Node *n) const {
    if (!n){
        return 0;
    }
    return n->info + sum(n->left) + sum(n->right);
}

// return count of values
int IntBST::count() const {
    return count(root);
}

// recursive helper for count
int IntBST::count(Node *n) const {
    if (!n){
        return 0;
    }
    return 1 + count(n->left) + count(n->right);
}

// IMPLEMENT THIS FIRST: returns the node for a given value or NULL if none exists
// Parameters:
// int value: the value to be found
// Node* n: the node to start with (for a recursive call)
// Whenever you call this method from somewhere else, pass it
// the root node as "n"
IntBST::Node* IntBST::getNodeFor(int value, Node* n) const{
    if (!n){
        return nullptr;
    }
    if (n->info == value){
        return n;
    }
    if (!n->left && !n->right){
        return nullptr;
    }
    if (n->info > value){
        return getNodeFor(value, n->left);
    }
    return getNodeFor(value, n->right);
}

// returns true if value is in the tree; false if not
bool IntBST::contains(int value) const {
    if (getNodeFor(value, root)){
        return true;
    }
    return false;
}

// returns the Node containing the predecessor of the given value
IntBST::Node* IntBST::getPredecessorNode(int value) const{
    Node* n = getNodeFor(value, root);
    if (!n){
        return nullptr;
    }
    if (!n->left){
        if (n->parent && n->parent->info < n->info){
            n = n->parent;
            return n;
        }
        return nullptr;
    }
    n = n->left;
    while (n->right){
        n = n->right;
    }
    return n;
}

// returns the predecessor value of the given value or 0 if there is none
int IntBST::getPredecessor(int value) const{
    if (!getPredecessorNode(value)){
        return 0;
    }
    return getPredecessorNode(value)->info;
}

// returns the Node containing the successor of the given value
IntBST::Node* IntBST::getSuccessorNode(int value) const{
    Node* n = getNodeFor(value, root);
    if (!n){
        return nullptr;
    }
    if (!n->right){
        if (n->parent && n->parent->info > n->info){
            n = n->parent;
            return n;
        }
        return nullptr;
    }
    n = n->right;
    while (n->left){
        n = n->left;
    }
    return n;
}

// returns the successor value of the given value or 0 if there is none
int IntBST::getSuccessor(int value) const{
    if (!getSuccessorNode(value)){
        return 0;
    }
    return getSuccessorNode(value)->info;
}

// deletes the Node containing the given value from the tree
// returns true if the node exist and was deleted or false if the node does not exist
bool IntBST::remove(int value){
    Node* n = getNodeFor(value, root);
    if (!n){
        return false;
    }
    if (!n->left && !n->right){ // leaf node
        if (!n->parent){ // only root
            root = nullptr;
        }
        else {
            if (n->parent->left == n){
                n->parent->left = nullptr;
            }
            else {
                n->parent->right = nullptr;
            }
        }
        delete n;
        return true;
    }

    // one child
    if (!n->right || !n->left){
        Node* child = n->left ? n->left : n->right;

        child->parent = n->parent;
        
        // if n is root
        if (!n->parent){
            root = child;
        }
        else {
                if (n->parent->left == n){
                    n->parent->left = child;
                }
                else { 
                    n->parent->right = child;
                }
        }
        delete n;
        return true;
    }
     // two children -- find successor
     int successor = getSuccessor(value);
     if (getSuccessorNode(value)){
        remove(successor);
        n->info = successor;
        return true;
     }
     return false;
}
