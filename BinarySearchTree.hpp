#include <iostream>
#include <string>

#ifndef NODE_HPP
#define NODE_HPP

struct node {
std::string key;
struct node *left, *right;
};

// Function declarations
struct node* newNode(std::string item);
struct node* insert(struct node* node, std::string key);
struct node* search(struct node* root, std::string key);
void inorder(struct node *root);
struct node* deleteNode(struct node* root, std::string key);

#endif 
