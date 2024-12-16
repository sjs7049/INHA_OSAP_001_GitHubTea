/****************************************************************************************
   File Name: OSAP_001_GitHubTea_AVLtree.cpp
   Copyright (c) 2024 GitHubTea

   This software is distributed under the MIT License.
   For more details on the MIT License, please refer to the LICENSE file in this
project. This software is provided "as is," without any warranty of any kind.

   Author: GitHubTea
   Date: 2024-11-28
*****************************************************************************************/

#include "../header/OSAP_001_GitHubTea_AVLTree.h";

#include <iostream>
#include <string>

using namespace std;

int AVLTree::difference(Node* temp) {
  int leftHeight = temp->left_node_() ? temp->left_node_()->height_() : 0;
  int rightHeight = temp->right_node_() ? temp->right_node_()->height_() : 0;
  return (leftHeight - rightHeight);
}

void AVLTree::updateHeight(Node* n) {
  if (n != nullptr) {
    int leftHeight = (n->left_node_()) ? n->left_node_()->height_() : 0;
    int rightHeight = (n->right_node_()) ? n->right_node_()->height_() : 0;
    n->height_set(std::max(leftHeight, rightHeight) + 1);
  }
}

void AVLTree::updateSubtreeSize(Node* n) {
  if (n != nullptr) {
    int leftSize = (n->left_node_()) ? n->left_node_()->subtreeSize_() : 0;
    int rightSize = (n->right_node_()) ? n->right_node_()->subtreeSize_() : 0;
    n->subtreeSize_set(leftSize + rightSize + 1);
  }
}

Node* AVLTree::ll(Node* parent) {
  Node* temp = parent->left_node_();
  parent->left_node_set(temp->right_node_());
  if (temp->right_node_() != nullptr) temp->right_node_()->parent_node_set(parent);
  temp->right_node_set(parent);
  temp->parent_node_set(parent->parent_node_());

  if (parent->parent_node_()) {
    if (parent->parent_node_()->left_node_() == parent) {
      parent->parent_node_()->left_node_set(temp);
    } else {
      parent->parent_node_()->right_node_set(temp);
    }
  }
  parent->parent_node_set(temp);

  updateHeight(parent);
  updateHeight(temp);
  updateSubtreeSize(parent);
  updateSubtreeSize(temp);

  return temp;
}

Node* AVLTree::rr(Node* parent) {
  Node* temp = parent->right_node_();
  parent->right_node_set(temp->left_node_());
  if (temp->left_node_() != nullptr) {
    temp->left_node_()->parent_node_set(parent);
  }
  temp->left_node_set(parent);
  temp->parent_node_set(parent->parent_node_());

  if (parent->parent_node_()) {
    if (parent->parent_node_()->left_node_() == parent) {
      parent->parent_node_()->left_node_set(temp);
    } else {
      parent->parent_node_()->right_node_set(temp);
    }
  }
  parent->parent_node_set(temp);

  updateHeight(parent);
  updateHeight(temp);
  updateSubtreeSize(parent);
  updateSubtreeSize(temp);

  return temp;
}

Node* AVLTree::lr(Node* parent) {
  parent->left_node_set(rr(parent->left_node_()));
  return ll(parent);
}

Node* AVLTree::rl(Node* parent) {
  parent->right_node_set(ll(parent->right_node_()));
  return rr(parent);
}

Node* AVLTree::balance(Node* curNode) {
  if (curNode == nullptr) {
    return nullptr;
  }

  int gap = difference(curNode); // 현재 노드의 균형 인수 계산

  if (gap > 1) { // 왼쪽 서브트리가 너무 큰 경우
    if (difference(curNode->left_node_()) >= 0) { // LL 상황
      curNode = ll(curNode);
    } else { // LR 상황
      curNode = lr(curNode);
    }
  } else if (gap < -1) { // 오른쪽 서브트리가 너무 큰 경우
    if (difference(curNode->right_node_()) <= 0) { // RR 상황
      curNode = rr(curNode);
    } else { // RL 상황
      curNode = rl(curNode);
    }
  }

  // 최종 높이 및 서브트리 크기 갱신
  updateHeight(curNode);
  updateSubtreeSize(curNode);
  return curNode;
}

Node* AVLTree::search(Node* curNode, int key) {
  while (curNode != nullptr && curNode->key_() != key) {
    if (key < curNode->key_()) {
      curNode = curNode->left_node_();
    } else {
      curNode = curNode->right_node_();
    }
  }
  return curNode;
}

int AVLTree::findMin(Node* curNode) {
  while (curNode->left_node_() != nullptr) {
    curNode = curNode->left_node_();
  }
  return curNode->key_();
}

int AVLTree::findMax(Node* curNode) {
  while (curNode->right_node_() != nullptr) {
    curNode = curNode->right_node_();
  }
  return curNode->key_();
}

AVLTree::AVLTree() {
  root = nullptr;
  size = 0;
}

bool AVLTree::isRoot(int key) {
  Node* curNode = search(root, key);
  return (curNode != nullptr && curNode->parent_node_() == nullptr);
}

bool AVLTree::isExist(int key) {
  return (search(root, key) != nullptr ? 1 : 0);
}

bool AVLTree::Empty() {
  return size == 0;
}

int AVLTree::Size() {
  return size;
}

int AVLTree::Height() {
  return root ? root->height_() : -1;
}

int AVLTree::Height(int x) {
  Node* curNode = search(root, x);
  return curNode ? curNode->height_() : 0;
}

int AVLTree::Depth(int key) {
  Node* curNode = search(root, key);
  if (curNode == nullptr) return 0;

  int depth = 0;
  while (curNode != root) {
    depth++;
    curNode = curNode->parent_node_();
  }
  return depth;
}

int AVLTree::Find(int key) {
  Node* curNode = search(root, key);
  if (curNode == nullptr) {
    return 0;
  }

  int nodeDepth = Depth(key);
  int nodeHeight = Height(curNode->key_());
  return (nodeDepth + nodeHeight);
}

int AVLTree::MinDescendant(int x) {
  Node* curNode = search(root, x);
  return curNode ? findMin(curNode) : 0;
}

int AVLTree::MaxDescendant(int x) {
  Node* curNode = search(root, x);
  return curNode ? findMax(curNode) : 0;
}

int AVLTree::Ancestor(int key) {
  Node* curNode = search(root, key);
  if (curNode == nullptr) return 0;

  int keySum = 0;
  Node* temp = curNode->parent_node_();
  while (temp != nullptr) {
    keySum += temp->key_();
    temp = temp->parent_node_();
  }
  return keySum;
}

void AVLTree::Insert(int key) {
  if (search(root, key) != nullptr) return;

  Node* newNode = new Node(key);
  size++;
  if (root == nullptr) {
    root = newNode;
    return;
  }

  Node* curNode = root;
  Node* parNode = nullptr;

  while (curNode != nullptr) {
    parNode = curNode;
    if (curNode->key_() < key)
      curNode = curNode->right_node_();
    else
      curNode = curNode->left_node_();
  }

  newNode->parent_node_set(parNode);
  if (parNode->key_() < key) {
    parNode->right_node_set(newNode);
  } else {
    parNode->left_node_set(newNode);
  }

  curNode = newNode;
  while (curNode != nullptr) {
    curNode = balance(curNode);
    if (curNode->parent_node_() == nullptr) {
      root = curNode;
    }

    curNode = curNode->parent_node_();
  }
}

int AVLTree::Rank(int key) {
  Node* curNode = search(root, key);
  if (curNode == nullptr) return 0;

  int rank = 1;
  Node* temp = root;
  while (temp != nullptr) {
    if (key < temp->key_()) {
      temp = temp->left_node_();
    } else if (key > temp->key_()) {
      rank += (temp->left_node_() ? temp->left_node_()->subtreeSize_() + 1 : 1);
      temp = temp->right_node_();
    } else {
      rank += (temp->left_node_() ? temp->left_node_()->subtreeSize_() : 0);
      break;
    }
  }
  return rank;
}

void AVLTree::Erase(int key) {
  Node* delNode = search(root, key);
  if (delNode == nullptr) return;

  Node* parNode = delNode->parent_node_();
  Node* childNode;

  if (delNode->left_node_() == nullptr && delNode->right_node_() == nullptr) {
    childNode = nullptr;
  } else if (delNode->left_node_() == nullptr) {
    childNode = delNode->right_node_();
  } else if (delNode->right_node_() == nullptr) {
    childNode = delNode->left_node_();
  } else {
    childNode = delNode->right_node_();
    while (childNode->left_node_() != nullptr)
      childNode = childNode->left_node_();
    delNode->key_set(childNode->key_());
    delNode = childNode;
    parNode = delNode->parent_node_();
    childNode = delNode->right_node_();
  }

  if (parNode == nullptr)
    root = childNode;
  else if (delNode == parNode->left_node_()) {
    parNode->left_node_set(childNode);
  } else {
    parNode->right_node_set(childNode);
  }
  if (childNode != nullptr) {
    childNode->parent_node_set(parNode);
  }

  delete delNode;
  size--;

  Node* curNode = parNode;
  while (curNode != nullptr) {
    updateHeight(curNode);
    updateSubtreeSize(curNode);
    curNode = balance(curNode);
    if (curNode->parent_node_() == nullptr) {
      root = curNode;
    }

    curNode = curNode->parent_node_();
  }
}
