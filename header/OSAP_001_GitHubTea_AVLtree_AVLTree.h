/****************************************************************************************
   File Name: OSAP_001_GitHubTea_AVLtree.h
   Copyright (c) 2024 GitHubTea

   This software is distributed under the MIT License.
   For more details on the MIT License, please refer to the LICENSE file in this project.
   This software is provided "as is," without any warranty of any kind.

   Author: GitHubTea
   Date: 2024-11-28
*****************************************************************************************/

#ifndef AVL_TREE_OSAP_001_GITHUBTEA_AVLTREE_AVLTREE_H_
#define AVL_TREE_OSAP_001_GITHUBTEA_AVLTREE_AVLTREE_H_

#include "header/OSAP_001_GitHubTea_AVLtree_Node.h"

class AVLTree {
public:
  // public method 
  AVLTree();                         // normal constructor 
  bool IsRoot(int);                  // AVL Tree에 매개변수 key값을 가진 노드가 루트 노드인지 판별하여 bool로 return
  bool IsExist(int);                 // AVL Tree에 매개변수 key값을 가진 노드가 존재하는지 판별하여 bool로 return
  bool Empty() const;                // AVL Tree가 비어있는지 판별하여 bool로 return
  int Size() const;                  // AVL Tree에 저장된 전체 노드 개수를 int로 return
  int Height() const;                // AVL Tree의 root Node의 높이를 int로 return
  int Height(int);                   // AVL Tree의 매개변수 key값을 가진 노드를 찾아 높이를 int로 return
  int Depth(int);                    // AVL Tree의 매개변수 key값을 가진 노드를 찾아 깊이를 int로 return
  int Find(int);                     // AVL Tree의 매개변수 key값을 가진 노드를 찾아 깊이와 높이의 합을 출력
  int MinDescendant(int);            // AVL Tree의 매개변수 key값을 가진 노드의 서브트리에서 최솟값을 int로 return
  int MaxDescendant(int);            // AVL Tree의 매개변수 key값을 가진 노드의 서브트리에서 최댓값을 int로 return
  int AncestorKeySum(int);           // AVL Tree의 매개변수 key값을 가진 노드를 찾아 부모노드부터 루트까지의 경로의 Node들의 keyW값의 합을 int로 return
  void Insert(int);                  // AVL Tree의 매개변수 key값을 가진 노드를 삽입
  int Rank(int);                     // AVL Tree의 매개변수 key값을 가진 노드를 찾아 순위를 return
  void Erase(int);                   // AVL Tree의 매개변수 key값을 가진 노드를 찾아 깊이와 높이의 합을 출력하고 해당 노드를 삭제

private:
  // attribute
  Node* root_;                       // AVL Tree Root Node
  int size_;                         // AVL Tree 전체 사이즈

  // private method
  int Difference(Node*);             // 매개변수 curNode의 두 자식 노드의 차를 return
  void UpdateHeight(Node*);          // 매개변수 curNode의 높이를 업데이트함
  void UpdateSubtreeSize(Node*);     // 매개변수 curNode의 서브트리 사이즈를 업데이트함
  Node* LeftLeftRotation(Node*);     // Left-Left Rotation 수행 Node*로 return
  Node* RightRightRotation(Node*);   // Right-Right Rotation 수행 Node*로 return
  Node* LeftRightRotation(Node*);    // Left-Right Rotation 수행 Node*로 return
  Node* RightLeftRotation(Node*);    // Right-Left Rotation 수행 후 Node*로 return
  Node* Balance(Node*);              // 매개변수 curNode에 알맞은 회전을 수행 후 Node*로 return
  Node* Search(Node*, int);          // 매개변수 curNode를 root로 하는 AVL Tree에서 key값을 가진 노드를 찾아 Node*로 return
  int FindMin(Node*);                // 서브트리의 노드 중 가장 작은 키값을 int로 return
  int FindMax(Node*);                // 서브트리의 노드 중 가장 큰 키값을 int로 return
};

#endif // !AVL_TREE_OSAP_001_GITHUBTEA_AVLTREE_AVLTREE_H_
