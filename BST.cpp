#include "BST.h"
#include <iostream>
using namespace std;

/**
 * Default constructor
 */
BinarySearchTree::BinarySearchTree() {

    root = nullptr;
}

/**
 * Traverse the tree in order
 */
void BinarySearchTree::InOrder() {
    inOrder(root);
}

/**
 * Insert a Course
 */
void BinarySearchTree::Insert(Course course) {
    // Create a temporary new node

    // if root equal to null ptr
    if (root == nullptr) {
        // root is equal to new node bid
        Node* newNode = new Node(course);
        root = newNode;
    }
    else {
        addNode(root, course);
    }
}

/**
 * Search for a Course
 */
Course BinarySearchTree::Search(string courseId) {
    // set current node equal to root
    Node* currNode = root;

    while (currNode != nullptr) {
        // keep looping downwards until bottom reached or matching bidId found
        // if match found, return current bid
        
        if (currNode->course.id == courseId) {
            return currNode->course;
        }
        else {
            // if bid is smaller than current node then traverse left
            if (courseId < currNode->course.id) {
                currNode = currNode->left;
            }
            else {
                // else larger so traverse right
                currNode = currNode->right;
            }
        }

    }

    Course course;
    return course;
}


/**
 * Add a bid to some node (recursive)
 *
 * @param node Current node in tree
 * @param course Course to be added
 */
void BinarySearchTree::addNode(Node* node, Course course) {
    Node* newNode = new Node(course);
    if (course.id < node->course.id) {
        // if node is larger then add to left
        if (node->left == nullptr) {
            // if no left node
            // this node becomes left
            node->left = newNode;
        }
        else {
            // else recurse down the left node
            addNode(node->left, course);
        }
    }
    else {
        // add to right
        if (node->right == nullptr) {
            // if no right node
            // this node becomes right
            node->right = newNode;
        }
        else {
            // else recurse down the right node
            addNode(node->right, course);
        }
    }
}

/**
 * Print out tree inorder (recursive)
 *
 * @param node Current node in tree
 */
void BinarySearchTree::inOrder(Node* node) {
    if (node != nullptr) {
        inOrder(node->left);
        node->course.print();
        inOrder(node->right);
    }
}