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
    subtreeSize{1} {
}
Node::Node(int key)
  : key{key},
    parent{nullptr},
    left{nullptr},
    right{nullptr},
    height{1},
    subtreeSize{1} {
}

int Node::key_() const {
  return key;
}

int Node::height_() const {
  return height;
}

int Node::subtreeSize_() const {
  return subtreeSize;
}

Node* Node::left_node_() const {
  return left;
}

Node* Node::right_node_() const {
  return right;
}

Node* Node::parent_node_() const {
  return parent;
}

void Node::key_set(int key) {
  this->key = key;
}

void Node::height_set(int height) {
  this->height = height;
}

void Node::parent_node_set(Node* parent) {
  this->parent = parent;
}

void Node::right_node_set(Node* right) {
  this->right = right;
}

void Node::left_node_set(Node* left) {
  this->left = left;
}

void Node::subtreeSize_set(int subtreeSize) {
  this->subtreeSize = subtreeSize;
}
