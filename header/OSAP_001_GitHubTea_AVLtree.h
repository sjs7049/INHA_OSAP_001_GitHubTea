/*
   File Name: FileName.cpp
   Copyright (c) 2024 GitHubTea

   This software is distributed under the MIT License.
   For more details on the MIT License, please refer to the LICENSE file in this project.
   This software is provided "as is," without any warranty of any kind.

   Author: GitHubTea
   Date: 2024-11-28
*/ 

#ifndef AVL_TREE_OSAP_001_GITHUBTEA_AVLTREE_H_
#define AVL_TREE_OSAP_001_GITHUBTEA_AVLTREE_H_

#include "OSAP_001_GitHubTea_Node.h"
class AVLTree 
{
public:
	AVLTree(); // AVLTree instance에 대한 생성자
	bool Empty() const; // set이 비어 있다면 1을, 아니라면 0을 return 함.
	int Size() const;
	int Height() const;
	int Height(int x) const;
	int Depth(int key) const;
	int Find(int key) const;
	int MinDescendant(int x) const;
	int MaxDescendant(int x) const;
	int Ancestor(int key) const;
	int Rank(int key) const;
	void Insert(int key);
	void Erase(int key);
private:
	Node* root;
	int size;

	int difference(Node*) const;
	void updateHeight(Node*);
	Node* ll(Node*);
	Node* rr(Node*);
	Node* lr(Node*);
	Node* rl(Node*);
	Node* balance(Node*);
	int countNodes(Node*) const;
	Node* search(Node*, int) const;
};

#endif // !AVL_TREE_OSAP_001_GITHUBTEA_AVLTREE_H_