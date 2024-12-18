/****************************************************************************************
   File Name: OSAP_001_GitHubTea_AVLtree_AVLTree.h
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

/**
 * @class AVLTree
 * @brief AVL Tree를 구현한 클래스
 * @details AVL Tree는 균형 이진 탐색 트리의 일종으로, 삽입과 삭제 시 높이
 * 균형을 유지한다.
 */
class AVLTree {
public:
  /**
   * @brief AVLTree의 기본 생성자
   */
  AVLTree();

  /**
   * @brief AVL Tree에 매개변수 key값을 가진 노드가 루트 노드인지 판별
   * @param key 확인할 노드의 key 값
   * @return 루트 노드라면 true, 아니면 false
   */
  bool IsRoot(int);

  /**
   * @brief AVL Tree에 매개변수 key값을 가진 노드가 존재하는지 판별
   * @param key 확인할 노드의 key 값
   * @return 존재하면 true, 아니면 false
   */
  bool IsExist(int);

  /**
   * @brief AVL Tree가 비어있는지 판별
   * @return 비어있으면 true, 아니면 false
   */
  bool Empty() const;

  /**
   * @brief AVL Tree에 저장된 전체 노드 개수를 반환
   * @return AVL Tree의 전체 노드 개수
   */
  int Size() const;

  /**
   * @brief AVL Tree의 root Node의 높이를 반환
   * @return 루트 노드의 높이, 트리가 비어있으면 -1
   */
  int Height() const;

  /**
   * @brief AVL Tree의 매개변수 key값을 가진 노드를 찾아 높이를 반환
   * @param key 확인할 노드의 key 값
   * @return 노드의 높이, 존재하지 않으면 0
   */
  int Height(int);

  /**
   * @brief AVL Tree의 매개변수 key값을 가진 노드를 찾아 깊이를 반환
   * @param key 확인할 노드의 key 값
   * @return 노드의 깊이, 존재하지 않으면 0
   */
  int Depth(int);

  /**
   * @brief AVL Tree의 매개변수 key값을 가진 노드를 찾아 깊이와 높이의 합을 반환
   * @param key 확인할 노드의 key 값
   * @return 깊이와 높이의 합, 존재하지 않으면 0
   */
  int Find(int);

  /**
   * @brief AVL Tree의 매개변수 key값을 가진 노드의 서브트리에서 최솟값을 반환
   * @param key 확인할 노드의 key 값
   * @return 서브트리의 최솟값, 존재하지 않으면 0
   */
  int MinDescendant(int);

  /**
   * @brief AVL Tree의 매개변수 key값을 가진 노드의 서브트리에서 최댓값을 반환
   * @param key 확인할 노드의 key 값
   * @return 서브트리의 최댓값, 존재하지 않으면 0
   */
  int MaxDescendant(int);

  /**
   * @brief AVL Tree의 매개변수 key값을 가진 노드의 조상 노드들의 key값의 합을
   * 반환
   * @param key 확인할 노드의 key 값
   * @return 조상 노드들의 key 값의 합, 존재하지 않으면 0
   */
  int AncestorKeySum(int);

  /**
   * @brief AVL Tree에 매개변수 key값을 가진 노드를 삽입
   * @param key 삽입할 노드의 key 값
   */
  void Insert(int);

  /**
   * @brief AVL Tree의 매개변수 key값을 가진 노드를 찾아 순위를 반환
   * @param key 확인할 노드의 key 값
   * @return key값을 가진 노드의 순위, 존재하지 않으면 0
   */
  int Rank(int);

  /**
   * @brief AVL Tree의 매개변수 key값을 가진 노드를 삭제
   * @param key 삭제할 노드의 key 값
   */
  void Erase(int);

private:
  /// attribute
  Node* root_;                       // AVL Tree Root Node
  int size_;                         // AVL Tree 전체 사이즈

  // private method
  int Difference(Node*);             // 매개변수 curNode의 두 자식 노드의 차를 반환
  void UpdateHeight(Node*);          // 매개변수 curNode의 높이를 업데이트
  void UpdateSubtreeSize(Node*);     // 매개변수 curNode의 서브트리 크기를 업데이트
  Node* LeftLeftRotation(Node*);     // Left-Left Rotation 수행
  Node* RightRightRotation(Node*);   // Right-Right Rotation 수행
  Node* LeftRightRotation(Node*);    // Left-Right Rotation 수행
  Node* RightLeftRotation(Node*);    // Right-Left Rotation 수행
  Node* Balance(Node*);              // 매개변수 curNode에 알맞은 회전을 수행
  Node* Search(Node*, int);          // 매개변수 curNode를 root로 하는 AVL Tree에서 key값을 가진 노드를 검색
  int FindMin(Node*);                // 서브트리의 노드 중 가장 작은 키값을 반환
  int FindMax(Node*);                // 서브트리의 노드 중 가장 큰 키값을 반환
};

#endif // !AVL_TREE_OSAP_001_GITHUBTEA_AVLTREE_AVLTREE_H_
