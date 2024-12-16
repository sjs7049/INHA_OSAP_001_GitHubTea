/****************************************************************************************
   File Name: OSAP_001_GitHubTea_AVLtree.cpp
   Copyright (c) 2024 GitHubTea

   This software is distributed under the MIT License.
   For more details on the MIT License, please refer to the LICENSE file in this
project. This software is provided "as is," without any warranty of any kind.

   Author: GitHubTea
   Date: 2024-11-28
*****************************************************************************************/

#include "../header/OSAP_001_GitHubTea_AVLtree.h";

#include <iostream>
#include <string>

using namespace std;

int AVLTree::difference(Node* curNode) {
  int leftHeight =
      (curNode->get_left_node() ? curNode->get_left_node()->get_height() : 0);
  int rightHeight =
      (curNode->get_right_node() ? curNode->get_right_node()->get_height() : 0);
  return (leftHeight - rightHeight);
}

void AVLTree::updateHeight(Node* curNode) {
  if (curNode != nullptr) {
    int leftHeight =
        (curNode->get_left_node() ? curNode->get_left_node()->get_height() : 0);
    int rightHeight =
        (curNode->get_right_node() ? curNode->get_right_node()->get_height()
                                   : 0);
    curNode->set_height(std::max(leftHeight, rightHeight) + 1);
  }
}

void AVLTree::updateSubtreeSize(Node* curNode) {
  if (curNode != nullptr) {
    int leftSize =
        (curNode->get_left_node() ? curNode->get_left_node()->get_subtree_size()
                                  : 0);
    int rightSize = (curNode->get_right_node()
                         ? curNode->get_right_node()->get_subtree_size()
                         : 0);
    curNode->set_subtree_size(leftSize + rightSize + 1);
  }
}

Node* AVLTree::ll(Node* parNode) {
  Node* curNode = parNode->get_left_node();
  parNode->set_left_node(curNode->get_right_node());
  if (curNode->get_right_node() != nullptr)
    curNode->get_right_node()->set_parent_node(parNode);
  curNode->set_right_node(parNode);
  curNode->set_parent_node(parNode->get_parent_node());

  if (parNode->get_parent_node()) {
    if (parNode->get_parent_node()->get_left_node() == parNode) {
      parNode->get_parent_node()->set_left_node(curNode);
    } else {
      parNode->get_parent_node()->set_right_node(curNode);
    }
  }
  parNode->set_parent_node(curNode);

  updateHeight(parNode);
  updateHeight(curNode);
  updateSubtreeSize(parNode);
  updateSubtreeSize(curNode);

  return curNode;
}

Node* AVLTree::rr(Node* parNode) {
  Node* curNode = parNode->get_right_node();
  parNode->set_right_node(curNode->get_left_node());
  if (curNode->get_left_node() != nullptr) {
    curNode->get_left_node()->set_parent_node(parNode);
  }
  curNode->set_left_node(parNode);
  curNode->set_parent_node(parNode->get_parent_node());

  if (parNode->get_parent_node()) {
    if (parNode->get_parent_node()->get_left_node() == parNode) {
      parNode->get_parent_node()->set_left_node(curNode);
    } else {
      parNode->get_parent_node()->set_right_node(curNode);
    }
  }
  parNode->set_parent_node(curNode);

  updateHeight(parNode);
  updateHeight(curNode);
  updateSubtreeSize(parNode);
  updateSubtreeSize(curNode);

  return curNode;
}

Node* AVLTree::lr(Node* parNode) {
  parNode->set_left_node(rr(parNode->get_left_node()));
  return ll(parNode);
}

Node* AVLTree::rl(Node* parNode) {
  parNode->set_right_node(ll(parNode->get_right_node()));
  return rr(parNode);
}

Node* AVLTree::balance(Node* curNode) {
  if (curNode == nullptr) {
    return nullptr;
  }

  int differences_between_children =
      difference(curNode); // 현재 노드의 균형 인수 계산

  if (differences_between_children > 1) { // 왼쪽 서브트리가 너무 큰 경우
    if (difference(curNode->get_left_node()) >= 0) { // LL 상황
      curNode = ll(curNode);
    } else { // LR 상황
      curNode = lr(curNode);
    }
  } else if (differences_between_children <
             -1) { // 오른쪽 서브트리가 너무 큰 경우
    if (difference(curNode->get_right_node()) <= 0) { // RR 상황
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
  while (curNode != nullptr && curNode->get_key() != key) {
    if (key < curNode->get_key()) {
      curNode = curNode->get_left_node();
    } else {
      curNode = curNode->get_right_node();
    }
  }
  return curNode;
}

int AVLTree::findMin(Node* curNode) {
  while (curNode->get_left_node() != nullptr) {
    curNode = curNode->get_left_node();
  }
  return curNode->get_key();
}

int AVLTree::findMax(Node* curNode) {
  while (curNode->get_right_node() != nullptr) {
    curNode = curNode->get_right_node();
  }
  return curNode->get_key();
}

AVLTree::AVLTree() : root{nullptr}, size{0} {
}

bool AVLTree::isRoot(int key) {
  Node* curNode = search(root, key);
  return (curNode != nullptr && curNode->get_parent_node() == nullptr);
}

bool AVLTree::isExist(int key) {
  Node* curNode = search(root, key);
  return (curNode != nullptr ? 1 : 0);
}

bool AVLTree::Empty() {
  return size == 0;
}

int AVLTree::Size() {
  return size;
}

int AVLTree::Height() {
  return (root ? root->get_height() : -1);
}

int AVLTree::Height(int x) {
  Node* curNode = search(root, x);
  return (curNode ? curNode->get_height() : 0);
}

int AVLTree::Depth(int key) {
  Node* curNode = search(root, key);
  if (curNode == nullptr) {
    return 0;
  }

  int depth = 0;
  while (curNode != root) {
    depth++;
    curNode = curNode->get_parent_node();
  }
  return depth;
}

int AVLTree::Find(int key) {
  Node* curNode = search(root, key);
  if (curNode == nullptr) {
    return 0;
  }

  int nodeDepth = Depth(key);
  int nodeHeight = Height(curNode->get_key());
  return (nodeDepth + nodeHeight);
}

int AVLTree::MinDescendant(int x) {
  Node* curNode = search(root, x);
  return (curNode ? findMin(curNode) : 0);
}

int AVLTree::MaxDescendant(int x) {
  Node* curNode = search(root, x);
  return (curNode ? findMax(curNode) : 0);
}

int AVLTree::Ancestor(int key) {
  Node* curNode = search(root, key);
  if (curNode == nullptr) {
    return 0;
  }

  int keySum = 0;
  Node* temp = curNode->get_parent_node();
  while (temp != nullptr) {
    keySum += temp->get_key();
    temp = temp->get_parent_node();
  }
  return keySum;
}

void AVLTree::Insert(int key) {
  if (search(root, key) != nullptr) {
    return;
  }

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
    if (curNode->get_key() < key)
      curNode = curNode->get_right_node();
    else
      curNode = curNode->get_left_node();
  }

  newNode->set_parent_node(parNode);
  if (parNode->get_key() < key) {
    parNode->set_right_node(newNode);
  } else {
    parNode->set_left_node(newNode);
  }

  curNode = newNode;
  while (curNode != nullptr) {
    curNode = balance(curNode);
    if (curNode->get_parent_node() == nullptr) {
      root = curNode;
    }

    curNode = curNode->get_parent_node();
  }
}

int AVLTree::Rank(int key) {
  Node* curNode = search(root, key);
  if (curNode == nullptr) {
    return 0;
  }

  int rank = 1;
  Node* temp = root;
  while (temp != nullptr) {
    if (key < temp->get_key()) {
      temp = temp->get_left_node();
    } else if (key > temp->get_key()) {
      rank +=
          (temp->get_left_node() ? temp->get_left_node()->get_subtree_size() + 1
                                 : 1);
      temp = temp->get_right_node();
    } else {
      rank += (temp->get_left_node() ? temp->get_left_node()->get_subtree_size()
                                     : 0);
      break;
    }
  }
  return rank;
}

void AVLTree::Erase(int key) {
  Node* delNode = search(root, key);
  if (delNode == nullptr) {
    return;
  }

  Node* parNode = delNode->get_parent_node();
  Node* childNode;

  if (delNode->get_left_node() == nullptr &&
      delNode->get_right_node() == nullptr) {
    childNode = nullptr;
  } else if (delNode->get_left_node() == nullptr) {
    childNode = delNode->get_right_node();
  } else if (delNode->get_right_node() == nullptr) {
    childNode = delNode->get_left_node();
  } else {
    childNode = delNode->get_right_node();
    while (childNode->get_left_node() != nullptr)
      childNode = childNode->get_left_node();
    delNode->set_key(childNode->get_key());
    delNode = childNode;
    parNode = delNode->get_parent_node();
    childNode = delNode->get_right_node();
  }

  if (parNode == nullptr)
    root = childNode;
  else if (delNode == parNode->get_left_node()) {
    parNode->set_left_node(childNode);
  } else {
    parNode->set_right_node(childNode);
  }
  if (childNode != nullptr) {
    childNode->set_parent_node(parNode);
  }

  delete delNode;
  size--;

  Node* curNode = parNode;
  while (curNode != nullptr) {
    updateHeight(curNode);
    updateSubtreeSize(curNode);
    curNode = balance(curNode);
    if (curNode->get_parent_node() == nullptr) {
      root = curNode;
    }

    curNode = curNode->get_parent_node();
  }
}
