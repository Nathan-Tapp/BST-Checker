/*
Author: Nathan Tapp-Wrinkle
Class: Coms-216
Date: 5/13/2024
Instructor: David Harden
File Name: BSTChecker.h

Description:
This file contains the declaration of the BSTChecker class, which provides functionality
to check the validity of a binary search tree (BST). The BSTChecker class offers a static
method CheckBSTValidity, which takes the root node of a BST as input and returns a pointer
to the first node that violates the BST property, or nullptr if the BST is valid.

Input:
The CheckBSTValidity method expects a pointer to the root node of the binary search tree
as input.

Output:
If the binary search tree is valid, the CheckBSTValidity method returns nullptr. Otherwise,
it returns a pointer to the first node that violates the BST property.

*/
#ifndef BST_CHECKER_H
#define BST_CHECKER_H

#include "Node.h"

class BSTChecker {
public:
    static Node* CheckBSTValidity(Node* root) {
        return CheckBSTValidityRecursive(root, nullptr, nullptr);
    }
private:
    // Helper function to recursively validate the CheckBstValidityRecursive method
    static Node* CheckBSTValidityRecursive(Node* node, Node* minNode, Node* maxNode) {
        if (node == nullptr) {
            return nullptr;
        }
        // Check if the node's key violates the BST property
        if ((minNode != nullptr && node->key < minNode->key) || (maxNode != nullptr && node->key > maxNode->key)) {
            return node;
        }
        // Check if the left child is linking to an ancestor
        if (node->left != nullptr && (node->left == minNode || node->left == maxNode)) {
            return node->left;
        }
        // Check if the right child is linking to an ancestor
        if (node->right != nullptr && (node->right == minNode || node->right == maxNode)) {
            return node->right;
        }
        // Recursively check the left subtree
        Node* lViolation = CheckBSTValidityRecursive(node->left, minNode, node);
        if (lViolation != nullptr) {
            return lViolation;
        }
        // Recursively check the right subtree
        Node* rViolation = CheckBSTValidityRecursive(node->right, node, maxNode);
        if (rViolation != nullptr) {
            return rViolation;
        }
        // If no violations are found, return nullptr
        return nullptr;
    }
};

#endif
