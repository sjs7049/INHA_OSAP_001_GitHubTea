/****************************************************************************************
   File Name: OSAP_001_GitHubTea_Node.cpp
   Copyright (c) 2024 GitHubTea

   This software is distributed under the MIT License.
   For more details on the MIT License, please refer to the LICENSE file in this project.
   This software is provided "as is," without any warranty of any kind.

   Author: GitHubTea
   Date: 2024-11-28
*****************************************************************************************/

#include "header/OSAP_001_GitHubTea_AVLtree_Node.h"

// public method  

// 기본 생성자
Node::Node()
  : key_{0},
    height_{1},
    subtree_size_{1},
    parent_{nullptr},
    left_{nullptr},
    right_{nullptr} {
}

// 매개변수 생성자
Node::Node(int key_)
  : key_{key_},
    height_{1},
    subtree_size_{1},
    parent_{nullptr},
    left_{nullptr},
    right_{nullptr} {
}

// getter
int Node::get_key() const {
  return key_;
}

int Node::get_height() const {
  return height_;
}

int Node::get_subtree_size() const {
  return subtree_size_;
}

Node* Node::get_left_node() const {
  return left_;
}

Node* Node::get_right_node() const {
  return right_;
}

Node* Node::get_parent_node() const {
  return parent_;
}

// setter
void Node::set_key(int key_) {
  this->key_ = key_;
}

void Node::set_height(int height_) {
  this->height_ = height_;
}

void Node::set_subtree_size(int subtree_size) {
  this->subtree_size_ = subtree_size;
}

void Node::set_parent_node(Node* parent) {
  this->parent_ = parent;
}

void Node::set_right_node(Node* right) {
  this->right_ = right;
}

void Node::set_left_node(Node* left) {
  this->left_ = left;
}
