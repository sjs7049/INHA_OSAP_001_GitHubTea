/****************************************************************************************
   File Name: OSAP_001_GitHubTea_Node.h
   Copyright (c) 2024 GitHubTea

   This software is distributed under the MIT License.
   For more details on the MIT License, please refer to the LICENSE file in this project.
   This software is provided "as is," without any warranty of any kind.

   Author: GitHubTea
   Date: 2024-11-28
*****************************************************************************************/

#ifndef AVL_TREE_OSAP_001_GITHUBTEA_AVLTREE_NODE_H_
#define AVL_TREE_OSAP_001_GITHUBTEA_AVLTREE_NODE_H_

class Node {
public:
  // public method 

  // 생성자
  Node();        // 기본 생성자 
  Node(int key_); // 매개변수 생성자

  // getter
  int get_key() const;
  int get_height() const;
  int get_subtree_size() const;
  Node* get_parent_node() const;
  Node* get_left_node() const;
  Node* get_right_node() const;

  // setter
  void set_key(int);
  void set_height(int);
  void set_subtree_size(int);
  void set_parent_node(Node*);
  void set_right_node(Node*);
  void set_left_node(Node*);

private:
  int key_;          // 키
  int height_;       // 트리에서의 높이
  int subtree_size_; // 서브트리의 전체 노드 개수
  Node* parent_;     // 부모 노드 포인터
  Node* left_;       // 왼쪽 자식 노드 포인터
  Node* right_;      // 오른쪽 자식 노드 포인터
};


#endif // !AVL_TREE_OSAP_001_GITHUBTEA_AVLTREE_NODE_H_
