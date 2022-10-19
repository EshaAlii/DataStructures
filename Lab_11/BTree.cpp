#include <iostream>
#include "BTree.h"

// BTree DECLARATION

// Constructor
BTree::BTree(){
    // Assume the tree is empty
    root = NULL;
}

// Destructor
BTree::~BTree(){
    // Call on destroy_tree function
    destroy_tree();
}

// Node pointer pointing to the root
Node *BTree::BTree_root(){
    // Create a Node pointer that points to root
    Node *temp = root;

    // Return that pointer
    return temp;
}

// Insert node in tree function
void BTree::insert(int key){
    // See if the tree is empty
    if (root != NULL){
        // If the tree is not empty do a recursion
        insert(key, root);
    }
    
    // Otherwise, if the tree is empty...
    else{
        // We make root into a new node, and set the key value into a key
        root = new Node;
        root->key_value = key;

        // Then define the nodes to the left and right of the node as empty
        root->left = NULL;
        root->right = NULL;
    }
}

// Search for node in tree function
Node *BTree::search(int key){
    // Do a recursive search for the root
    return search(key, root);
}

// Destroy tree function
void BTree::destroy_tree(){
    // Destroy the root of the tree
    destroy_tree(root);
}

// Destroy tree function with leaf node
void BTree::destroy_tree(Node *leaf){

    // If the leaf is not empty
    if (leaf != NULL){

        // We want to do recursion on both left and right branches
        destroy_tree(leaf->left);
        destroy_tree(leaf->right);

        // We also want to delete the leaf
        delete leaf;
    }
}

// Insert node function with leaf node
void BTree::insert(int key, Node *leaf){

    // See if the leaf is greater than key (moving left)
    if (leaf->key_value > key){

        // If the left is not empty do a recursion
        if (leaf->left != NULL){
            insert(key, leaf->left);
        }

        // Otherwise...
        else{   
            // We create a new node to the left and give it a new key
            leaf->left = new Node;
            leaf->left->key_value = key;

            // We then define the nodes to the left and right as empty
            leaf->left->left = NULL;
            leaf->left->right = NULL;
        }
    }

    // See if the leaf is greater than key (moving right) 
    else if (leaf->key_value <= key){

        // If the left is not empty do a recursion
        if (leaf->right != NULL){
            insert(key, leaf->right);
        }

        // Otherwise...
        else{
            // We create a new node to the right and give it a new key
            leaf->right = new Node;
            leaf->right->key_value = key;

            // We then define the nodes to the left and right as empty
            leaf->right->right = NULL;
            leaf->right->left = NULL;
        }
    }
}

// Search node in tree function with leaf node
Node *BTree::search(int key, Node *leaf){
    // If leaf node is not empty...
    if (leaf!= NULL){

        // If the leafs key value is equal to the key, we return the leaf
        if (leaf->key_value == key){
            return leaf;
        }

        // If the leaf is greater than key (moving right) 
        if (leaf->key_value > key){
            // We do a recursion with the next leaf node moving left
            return search(key, leaf->left);
        }
        // Otherwise...
        else{
            // We do a recursion with the next leaf node moving right
            return search(key, leaf->right);
        }
    }

    // Otherwise we just say it's empty
    else{
        return NULL;
    }

}

