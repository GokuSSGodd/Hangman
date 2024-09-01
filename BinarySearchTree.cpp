#include "BinarySearchTree.hpp"
#include <iostream>
#include <string>

using namespace std;

// Create a new BST node
struct node *newNode(std::string item) {
  struct node *temp = new struct node;
  temp->key = item;
  temp->left = temp->right = NULL;
  return temp;
}

// Inorder traversal of BST
void inorder(struct node *root) {
  if (root != NULL) {
    inorder(root->left);
    cout << root->key << " -> ";
    inorder(root->right);
  }
}

// Iterative method to insert a new key in the BST
struct node *insert(struct node *root, std::string key) {
  // Create a new node
  struct node *newNode = new struct node;
  newNode->key = key;
  newNode->left = newNode->right = NULL;

  // Base case: If the tree is empty
  if (root == NULL) {
    return newNode;
  }

  // Pointer to start traversing from root
  struct node *current = root;

  // Pointer to store the parent of the current node
  struct node *parent = NULL;

  while (true) {
    parent = current;

    // If the given key is less than the current node's key, go to left subtree
    if (key < current->key) {
      current = current->left;
      // Insert the new node if the correct position is found
      if (current == NULL) {
        parent->left = newNode;
        return root;
      }
    }
    // If the given key is greater than the current node's key, go to right
    // subtree
    else if (key > current->key) {
      current = current->right;
      // Insert the new node if the correct position is found
      if (current == NULL) {
        parent->right = newNode;
        return root;
      }
    } else {
      // If the key already exists in the BST, don't insert a new node
      // Here, you can handle it as you see fit
      delete newNode;
      return root;
    }
  }
}

// Search a key in the BST
struct node *search(struct node *root, std::string key) {
  if (root == NULL || root->key == key)
    return root;
  if (root->key < key)
    return search(root->right, key);
  return search(root->left, key);
}

// Find the node with the minimum key
struct node *minValueNode(struct node *node) {
  struct node *current = node;
  while (current && current->left != NULL)
    current = current->left;
  return current;
}

// Delete a node from the BST
struct node *deleteNode(struct node *root, std::string key) {
  if (root == NULL)
    return root;
  if (key < root->key)
    root->left = deleteNode(root->left, key);
  else if (key > root->key)
    root->right = deleteNode(root->right, key);
  else {
    if (root->left == NULL) {
      struct node *temp = root->right;
      delete root;
      return temp;
    } else if (root->right == NULL) {
      struct node *temp = root->left;
      delete root;
      return temp;
    }
    struct node *temp = minValueNode(root->right);
    root->key = temp->key;
    root->right = deleteNode(root->right, temp->key);
  }
  return root;
}
