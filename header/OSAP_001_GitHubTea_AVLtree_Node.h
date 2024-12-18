/****************************************************************************************
   File Name: OSAP_001_GitHubTea_AVLtree_Node.h
   Copyright (c) 2024 GitHubTea

   This software is distributed under the MIT License.
   For more details on the MIT License, please refer to the LICENSE file in this
project. This software is provided "as is," without any warranty of any kind.

   Author: GitHubTea
   Date: 2024-11-28
*****************************************************************************************/

#ifndef AVL_TREE_OSAP_001_GITHUBTEA_AVLTREE_NODE_H_
#define AVL_TREE_OSAP_001_GITHUBTEA_AVLTREE_NODE_H_

/**
 * @class Node
 * @brief AVL Tree의 노드를 나타내는 클래스
 * @details 각 Node 객체는 트리의 키, 높이, 서브트리 크기, 부모 및 자식 노드에
 * 대한 정보를 포함한다.
 */
class Node {
public:
  /// @brief 기본 생성자
  Node();

  /// @brief 매개변수를 사용한 생성자
  /// @param key_ 노드의 초기 key 값
  Node(int key_);

  /// @brief 노드의 key 값을 반환
  /// @return 노드의 key 값
  int get_key() const;

  /// @brief 노드의 높이를 반환
  /// @return 노드의 높이
  int get_height() const;

  /// @brief 서브트리의 노드 개수를 반환
  /// @return 서브트리의 노드 개수
  int get_subtree_size() const;

  /// @brief 부모 노드를 반환
  /// @return 부모 노드의 포인터
  Node* get_parent_node() const;

  /// @brief 왼쪽 자식 노드를 반환
  /// @return 왼쪽 자식 노드의 포인터
  Node* get_left_node() const;

  /// @brief 오른쪽 자식 노드를 반환
  /// @return 오른쪽 자식 노드의 포인터
  Node* get_right_node() const;

  /// @brief 노드의 key 값을 설정
  /// @param key 설정할 key 값
  void set_key(int key);

  /// @brief 노드의 높이를 설정
  /// @param height 설정할 높이 값
  void set_height(int height);

  /// @brief 서브트리의 노드 개수를 설정
  /// @param size 설정할 서브트리 크기
  void set_subtree_size(int size);

  /// @brief 부모 노드를 설정
  /// @param parent 설정할 부모 노드 포인터
  void set_parent_node(Node* parent);

  /// @brief 오른쪽 자식 노드를 설정
  /// @param right 설정할 오른쪽 자식 노드 포인터
  void set_right_node(Node* right);

  /// @brief 왼쪽 자식 노드를 설정
  /// @param left 설정할 왼쪽 자식 노드 포인터
  void set_left_node(Node* left);

private:
  int key_;          ///< 노드의 key 값
  int height_;       ///< 트리에서의 높이
  int subtree_size_; ///< 서브트리의 전체 노드 개수
  Node* parent_;     ///< 부모 노드의 포인터
  Node* left_;       ///< 왼쪽 자식 노드의 포인터
  Node* right_;      ///< 오른쪽 자식 노드의 포인터
};

#endif // AVL_TREE_OSAP_001_GITHUBTEA_AVLTREE_NODE_H_
