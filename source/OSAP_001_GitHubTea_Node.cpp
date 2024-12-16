/****************************************************************************************
   File Name: OSAP_001_GitHubTea_Node.cpp
   Copyright (c) 2024 GitHubTea

   This software is distributed under the MIT License.
   For more details on the MIT License, please refer to the LICENSE file in this project.
   This software is provided "as is," without any warranty of any kind.

   Author: GitHubTea
   Date: 2024-11-28
*****************************************************************************************/

#include "../header/OSAP_001_GitHubTea_Node.h";

Node::Node()
  : key{0},
    parent{nullptr},
    left{nullptr},
    right{nullptr},
    height{1},
    subtree_size{1} {
}
Node::Node(int key)
  : key{key},
    parent{nullptr},
    left{nullptr},
    right{nullptr},
    height{1},
    subtree_size{1} {
}

int Node::get_key() const {
  return key;
}

int Node::get_height() const {
  return height;
}

int Node::get_subtree_size() const {
  return subtree_size;
}

Node* Node::get_left_node() const {
  return left;
}

Node* Node::get_right_node() const {
  return right;
}

Node* Node::get_parent_node() const {
  return parent;
}

void Node::set_key(int key) {
  this->key = key;
}

void Node::set_height(int height) {
  this->height = height;
}

void Node::set_parent_node(Node* parent) {
  this->parent = parent;
}

void Node::set_right_node(Node* right) {
  this->right = right;
}

void Node::set_left_node(Node* left) {
  this->left = left;
}

void Node::set_subtree_size(int subtreeSize) {
  this->subtree_size = subtreeSize;
}
