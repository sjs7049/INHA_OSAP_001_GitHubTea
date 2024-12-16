/****************************************************************************************
   File Name: OSAP_001_GitHubTea_AVLtree.cpp
   Copyright (c) 2024 GitHubTea

   This software is distributed under the MIT License.
   For more details on the MIT License, please refer to the LICENSE file in this project.
   This software is provided "as is," without any warranty of any kind.

   Author: GitHubTea
   Date: 2024-11-28
*****************************************************************************************/

#include "../header/OSAP_001_GitHubTea_AVLtree.h"
#include <algorithm>

AVLTree::AVLTree() : root{ NULL }, size{ 0 } {};

bool AVLTree::Empty() const {
    return size == 0;
}

int AVLTree::Size() const {
    return size;
}

int AVLTree::Height() const {
    if (root == NULL) {
        return -1;
    }

    return root->height_();
}


int AVLTree::Height(int x) const {
    Node* curNode = search(root, x);
    if (curNode == NULL) {
        return -1;
    }

    return curNode->height_();
}

int AVLTree::Depth(int key) const {
        Node * curNode = search(root, key);
        if (curNode == NULL) {
            return 0;
        }

        int depth = 0;
        while (curNode != root) {
            depth++;
            curNode = curNode->parent_node_();
        }

        return depth;
    }

int AVLTree::Find(int key) const {
        Node* curNode = search(root, key);
        if (curNode == NULL) {
            return 0;
        }

        int nodeDepth = Depth(key);
        int nodeHeight = Height(curNode->key_());

        return (nodeDepth + nodeHeight);
}

int AVLTree::MinDescendant(int x) const {
    Node* curNode = search(root, x);
    while (curNode->left_node_() != NULL) {
        curNode = curNode->left_node_();
    }

    return curNode->key_();
}

int AVLTree::MaxDescendant(int x) const {
    Node* curNode = search(root, x);
    while (curNode->right_node_() != NULL) {
        curNode = curNode->right_node_();
    }

    return curNode->key_();
}

int AVLTree::Ancestor(int key) const {
    Node* curNode = search(root, key);
    if (curNode == NULL) {
        return -1; // set�� �����ϴ� Ʈ���� �־���. ������ �� �� ���� �� �ƹ��ų� ����.
    }

    int keySum = 0;

    Node* temp = curNode->parent_node_();
    while (temp != NULL) {
        keySum += temp->key_();
        temp = temp->parent_node_();
    }

    return keySum;
}

int AVLTree::Rank(int key) const {
    Node* curNode = search(root, key);
    if (curNode == NULL) {
        return 0;
    }

    int rank = 1;
    Node* temp = root;
    while (temp != NULL) {
        if (key < temp->key_()) {
            temp = temp->left_node_();
        }
        else if (key > temp->key_()) {
            rank += countNodes(temp->left_node_()) + 1;
            temp = temp->right_node_();
        }
        else {
            rank += countNodes(temp->left_node_());
            break;
        }
    }
    return rank;
}

void AVLTree::Insert(int key) {
    if (search(root, key) != NULL) {
        return;
    }

    Node* newNode = new Node(key);
    size++;
    if (root == NULL) {
        root = newNode;
        return;
    }

    Node* curNode = root;
    Node* parNode = NULL;

    while (curNode != NULL) {
        parNode = curNode;
        if (curNode->key_() < key) {
            curNode = curNode->right_node_();
        }
        else {
            curNode = curNode->left_node_();
        }
    }

    newNode->set_parent_node_(parNode);
    if (parNode->key_() < key) {
        parNode->set_right_node_(newNode);
    }
    else {
        parNode->set_left_node_(newNode);
    }

    Node* grandParNode = newNode->parent_node_() ? newNode->parent_node_()->parent_node_() : NULL;
    while (grandParNode != NULL) {
        updateHeight(grandParNode);
        grandParNode = balance(grandParNode);
        grandParNode = grandParNode->parent_node_();
    }

    while (root->parent_node_() != NULL) {
        root = root->parent_node_();
    }
}

void AVLTree::Erase(int key) {
    Node* delNode = search(root, key);
    if (delNode == NULL) {
        return;
    }

    Node* parNode = delNode->parent_node_();
    Node* childNode;

    if (delNode->left_node_() == NULL && delNode->right_node_() == NULL) {
        childNode = NULL;
    }
    else if (delNode->left_node_() == NULL && delNode->right_node_() != NULL) {
        childNode = delNode->right_node_();
    }
    else if (delNode->left_node_() != NULL && delNode->right_node_() == NULL) {
        childNode = delNode->left_node_();
    }
    else {
        childNode = delNode->right_node_();
        while (childNode->left_node_() != NULL) {
            childNode = childNode->left_node_();
        }
        delNode->set_key_(childNode->key_());
        delNode = childNode;
        parNode = delNode->parent_node_();
        childNode = delNode->right_node_();
    }

    if (parNode == NULL) {
        root = childNode;
        if (childNode != NULL) {
            root->set_parent_node_(NULL);
        }
        updateHeight(root);
    }
    else if (delNode == parNode->left_node_()) {
        parNode->set_left_node_(childNode);
        if (childNode != NULL) {
            childNode->set_parent_node_(parNode);
        }
    }
    else {
        parNode->set_right_node_(childNode);
        if (childNode != NULL) {
            childNode->set_parent_node_(parNode);
        }
    }

    delete delNode;

    while (parNode != NULL) {
        updateHeight(parNode);
        parNode = balance(parNode);
        parNode = parNode->parent_node_();
    }
    if (root && root->parent_node_() != NULL) {
        while (root->parent_node_() != NULL) {
            root = root->parent_node_();
        }
    }
}


// private
int AVLTree::difference(Node* temp) const {
    int leftHeight = temp->left_node_() ? temp->left_node_()->height_() : 0;
    int rightHeight = temp->right_node_() ? temp->right_node_()->height_() : 0;

    return (leftHeight - rightHeight);
}

void AVLTree::updateHeight(Node* curNode) {
    int leftHeight = (curNode->left_node_()) ? curNode->left_node_()->height_() : 0;
    int rightHeight = (curNode->right_node_()) ? curNode->right_node_()->height_() : 0;

    curNode->set_height_(std::max(leftHeight, rightHeight) + 1);
}

Node* AVLTree::ll(Node* parent) {
    Node* temp = parent->left_node_();
    parent->set_left_node_(temp->right_node_());
    if (temp->right_node_() != NULL) {
        temp->right_node_()->set_parent_node_(parent);
    }
    temp->set_right_node_(parent);
    temp->set_parent_node_(parent->parent_node_());
    parent->set_parent_node_(temp);

    updateHeight(parent);
    updateHeight(temp);

    return temp;
}

Node* AVLTree::rr(Node* parent) {
    Node* temp = parent->right_node_();
    parent->set_right_node_(temp->left_node_());
    if (temp->left_node_() != NULL) {
        temp->left_node_()->set_parent_node_(parent);
    }
    temp->set_left_node_(parent);
    temp->set_parent_node_(parent->parent_node_());
    parent->set_parent_node_(temp);

    updateHeight(parent);
    updateHeight(temp);

    return temp;
}

Node* AVLTree::lr(Node* parent) {
    parent->set_left_node_(rr(parent->left_node_()));

    return ll(parent);
}

Node* AVLTree::rl(Node* parent) {
    parent->set_right_node_(ll(parent->right_node_()));

    return rr(parent);
}

Node* AVLTree::balance(Node* curNode) {
    int gap = difference(curNode);
    if (gap > 1) {
        if (difference(curNode->left_node_()) >= 0) {
            curNode = ll(curNode);
        }
        else {
            curNode = lr(curNode);
        }
    }
    else if (gap < -1) {
        if (difference(curNode->right_node_()) <= 0) {
            curNode = rr(curNode);
        }
        else {
            curNode = rl(curNode);
        }
    }

    return curNode;
}

int AVLTree::countNodes(Node* curNode) const {
    if (curNode == NULL) {
        return 0;
    }

    return (1 + countNodes(curNode->left_node_()) + countNodes(curNode->right_node_()));
}

Node* AVLTree::search(Node* curNode, int key) const {
    if (curNode == NULL) {
        return NULL;
    }
    if (curNode->key_() == key) {
        return curNode;
    }
    else if (curNode->key_() < key) {
        return search(curNode->right_node_(), key);
    }
    else {
        return search(curNode->left_node_(), key);
    }
}
