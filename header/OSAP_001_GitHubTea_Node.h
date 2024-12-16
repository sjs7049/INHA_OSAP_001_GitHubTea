/****************************************************************************************
   File Name: OSAP_001_GitHubTea_Node.h
   Copyright (c) 2024 GitHubTea

   This software is distributed under the MIT License.
   For more details on the MIT License, please refer to the LICENSE file in this project.
   This software is provided "as is," without any warranty of any kind.

   Author: GitHubTea
   Date: 2024-11-28
*****************************************************************************************/

#ifndef AVL_TREE_OSAP_001_GITHUBTEA_NODE_H_
#define AVL_TREE_OSAP_001_GITHUBTEA_NODE_H_

class Node {
public:
  Node();
  Node(int key);
  int get_key() const;
  int get_height() const;
  int get_subtree_size() const;
  Node* get_left_node() const;
  Node* get_right_node() const;
  Node* get_parent_node() const;
  void set_key(int);
  void set_height(int);
  void set_subtree_size(int);
  void set_parent_node(Node*);
  void set_right_node(Node*);
  void set_left_node(Node*);

private:
  int key;
  int height;
  int subtree_size; // 서브트리의 노드 개수를 저장하는 변수
  Node* parent;
  Node* left;
  Node* right;
};

#endif // !AVL_TREE_OSAP_001_GITHUBTEA_NODE_H_
