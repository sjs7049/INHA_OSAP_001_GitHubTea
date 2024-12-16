/****************************************************************************************
   File Name: OSAP_001_GitHubTea_AVLtree.h
   Copyright (c) 2024 GitHubTea

   This software is distributed under the MIT License.
   For more details on the MIT License, please refer to the LICENSE file in this project.
   This software is provided "as is," without any warranty of any kind.

   Author: GitHubTea
   Date: 2024-11-28
*****************************************************************************************/

#ifndef AVL_TREE_OSAP_001_GITHUBTEA_AVLTREE_H_
#define AVL_TREE_OSAP_001_GITHUBTEA_AVLTREE_H_

#include "./OSAP_001_GitHubTea_Node.h";

class AVLTree {
private:
  Node* root;
  int size;

  int difference(Node*);
  void updateHeight(Node*);
  void updateSubtreeSize(Node*);
  Node* ll(Node* parent);
  Node* rr(Node* parent);
  Node* lr(Node* parent);
  Node* rl(Node* parent);
  Node* balance(Node* curNode);
  Node* search(Node* curNode, int key);
  int findMin(Node* curNode);
  int findMax(Node* curNode);
public:
  AVLTree();
  bool isRoot(int key);
  bool isExist(int key);
  bool Empty();
  int Size();
  int Height();
  int Height(int x);
  int Depth(int key);
  int Find(int key);
  int MinDescendant(int x);
  int MaxDescendant(int x);
  int Ancestor(int key);
  void Insert(int key);
  int Rank(int key);
  void Erase(int key);
};

#endif // !AVL_TREE_OSAP_001_GITHUBTEA_AVLTREE_H_
