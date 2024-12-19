/****************************************************************************************
   File Name: OSAP_001_GitHubTea_AVLtree_AVLTree.cc
   Copyright (c) 2024 GitHubTea

   This software is distributed under the MIT License.
   For more details on the MIT License, please refer to the LICENSE file in this
project. This software is provided "as is," without any warranty of any kind.

   Author: GitHubTea
   Date: 2024-11-28
*****************************************************************************************/

#include "header/OSAP_001_GitHubTea_AVLtree_AVLTree.h"

#include <iostream>

using namespace std;

// public method

// default constructor
AVLTree::AVLTree() : 
    root_{nullptr}, 
    size_{0} {
}

// AVL Tree에 매개변수 key값을 가진 노드가 루트 노드인지 판별하여 bool으로 return 
bool AVLTree::IsRoot(int key) {
  /*
    curNode값이 비어있지 않고, curNode의 부모노드가 비어있다면 root이기에
    만족한다면 true, 아니라면 false return
  */
  Node* curNode = Search(root_, key);
  return (curNode != nullptr && curNode->get_parent_node() == nullptr);
}

// AVL Tree에 매개변수 key값을 가진 노드가 존재하는지 판별하여 bool로 return
bool AVLTree::IsExist(int key) {
  /*
    curNode값이 비어있지 않다면 true, 아니라면 false return.
  */
  Node* curNode = Search(root_, key);
  return (curNode != nullptr ? 1 : 0);
}

// AVL Tree가 비어있는지 판별하여 bool로 return
bool AVLTree::Empty() const {
  /*
    size가 0이라면 empty
  */
  return size_ == 0;
}

// AVL Tree에 저장된 전체 노드 개수를 int로 return
int AVLTree::Size() const {
  /*
    root의 높이를 return.
    단 nullptr일 때, 즉 트리가 비어있을 땐 -1을 return
  */
  return size_;
}

// AVL Tree의 root Node의 높이를 int로 return
int AVLTree::Height() const {
  /*
    root의 높이를 return.
    단 nullptr일 때, 즉 트리가 비어있을 땐 -1을 return
  */
  return (root_ ? root_->get_height() : -1);
}

// AVL Tree의 매개변수 key값을 가진 노드를 찾아 높이를 int로 return
int AVLTree::Height(int key) {
  /*
    curNode의 값을 return.
    단 nullptr일 때, 즉 트리에 존재하지 않을 땐 0을 return
  */
  Node* curNode = Search(root_, key);
  return (curNode ? curNode->get_height() : 0);
}

// AVL Tree의 매개변수 key값을 가진 노드를 찾아 깊이를 int로 return
int AVLTree::Depth(int key) {
  /*
    depth++을 실행 후 curNode를 curNode의 부모노드로 설정을
    curNode가 root가 될 때까지 수행.
    while문이 종료되면 depth를 return
  */
  Node* curNode = Search(root_, key);
  if (curNode == nullptr) {
    // curNode가 nullptr일 때, 즉 트리에 존재하지 않을 때 0을 return
    return 0;
  }

  int depth = 0;
  while (curNode != root_) {
    depth++;
    curNode = curNode->get_parent_node();
  }
  return depth;
}

// AVL Tree의 매개변수 key값을 가진 노드를 찾아 깊이와 높이의 합을 출력
int AVLTree::Find(int key) {
  /*
    curNode의 깊이와 높이의 합을 더하여 return.
  */
  Node* curNode = Search(root_, key);
  if (curNode == nullptr) {
    // curNode가 nullptr일 때, 즉 트리에 존재하지 않을 때 0을 return
    return 0;
  }

  int nodeDepth = Depth(key);
  int nodeHeight = Height(curNode->get_key());
  return (nodeDepth + nodeHeight);
}

// AVL Tree의 매개변수 key값을 가진 노드의 서브트리에서 최솟값을 int로 return
int AVLTree::MinDescendant(int key) {
  /*
    FindMin()을 통해 curNode의 서브트리에서 최솟값을 return
    단 nullptr일 때, 즉 트리에 존재하지 않을 때 0을 return
  */
  Node* curNode = Search(root_, key);
  return curNode ? FindMin(curNode) : 0;
}

int AVLTree::MaxDescendant(int key) {
  /*
    FindMax()을 통해 curNode의 서브트리에서 최댓값을 return
    단 nullptr일 때, 즉 트리에 존재하지 않을 때 0을 return
  */
  Node* curNode = Search(root_, key);
  return curNode ? FindMax(curNode) : 0;
}

// AVL Tree의 매개변수 key값을 가진 노드를 찾아 부모노드부터 루트까지의 경로의 Node들의 key값의 합을 int로 return
int AVLTree::AncestorKeySum(int key) {
  /*
    parNode를 curNode의 부모노드로 설정
    parNode의 key를 keySum에 더한 후
    parNode를 parNode의 부모노드로 설정을 parNode가 root가 될 때까지 수행.
    while문이 종료되면 keySum을 return
  */
  Node* curNode = Search(root_, key);
  if (curNode == nullptr) {
    // curNode가 nullptr일 때, 즉 트리에 존재하지 않을 때 0을 return
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

// AVL Tree의 매개변수 key값을 가진 노드를 삽입
void AVLTree::Insert(int key) {
  if (Search(root_, key) != nullptr) {
    // curNode가 nullptr일 때, 즉 트리에 존재하지 않을 때 0을 return
    return;
  }

  Node* newNode = new Node(key);
  size_++;
  if (root_ == nullptr) {
    // 트리가 비었다면 newNode를 root 노드로 설정하고 return.
    root_ = newNode;
    return;
  }

  // curNode의 포인터를 root로 설정하고 parNode의 포인터는 nullptr로 지정
  Node* curNode = root_;
  Node* parNode = nullptr;

  /*
    curNode의 key값이 Insert의 매개변수인 key값보다 작다면
    curNode의 값을 자신의 오른쪽 자식 노드로 설정, 아니라면 자신의 왼쪽 자식 노드로 설정하여
    AVL Tree의 구조를 맞추며 위치를 찾아감.
    이때 while문의 parNode = curNode는 
    while 문이 끝난 후에 curNode가 parNode가 되도록 함.
  */
  while (curNode != nullptr) {
    parNode = curNode;
    if (curNode->get_key() < key) {
      curNode = curNode->get_right_node();
    } else {
      curNode = curNode->get_left_node();
    }
  }

  /*
    추가할 노드의 부모노드를 parNode로 설정.
    parNode의 key값이 Insert의 매개변수인 key값보다 작다면
    parNode의 오른쪽 자식 노드를 newNode로 설정,
    아니라면 왼쪽 자식 노드로 설정.
  */
  newNode->set_parent_node(parNode);
  if (parNode->get_key() < key) {
    parNode->set_right_node(newNode);
  } else {
    parNode->set_left_node(newNode);
  }

  /*
    urNode를 newNode로 설정하고
    AVL Tree의 균형을 맞추기 위해 부모 노드를 따라 올라가며 balance()를 호출.
    balance() 이후 root 노드가 변경될 수도 있기 때문에 확인하여 root를 갱신.
  */
  curNode = newNode;
  while (curNode != nullptr) {
    curNode = Balance(curNode);
    if (curNode->get_parent_node() == nullptr) {
      root_ = curNode;
    }

    curNode = curNode->get_parent_node();
  }
}

// AVL Tree의 매개변수 key값을 가진 노드를 찾아 순위를 return
int AVLTree::Rank(int key) {
  Node* curNode = Search(root_, key);
  if (curNode == nullptr) {
    // curNode가 nullptr일 때, 즉 트리에 존재하지 않을 때 0을 return
    return 0;
  }

  /*
    rank: 현재 노드까지의 순위를 나타내는 변수로 초기값은 1.
    탐색을 root에서 시작하여 key값과 비교하면서 다음 노드로 이동:
    - key값이 현재 노드보다 크다면, 왼쪽 서브트리의 노드 개수 + 현재 노드를 rank에 더함.
    - key값이 현재 노드보다 작다면 왼쪽 서브트리로 이동.
    - key값이 일치하면, rank에 왼쪽 서브트리의 크기를 더하고 탐색 종료.
  */
  int rank = 1;
  Node* temp = root_;
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

// AVL Tree의 매개변수 key값을 가진 노드를 찾아 깊이와 높이의 합을 출력하고 해당 노드를 삭제
void AVLTree::Erase(int key) {
  Node* delNode = Search(root_, key);
  if (delNode == nullptr) {
    // curNode가 nullptr일 때, 즉 트리에 존재하지 않을 때 0을 return
    return;
  }

  /*
    삭제할 노드의 상태를 확인:
        1. 자식 노드가 없는 경우 : childNode를 nullptr로 설정.
    2. 오른쪽 자식만 있는 경우 : childNode를 오른쪽 자식으로 설정.
    3. 왼쪽 자식만 있는 경우: childNode를 왼쪽 자식으로 설정.
    4. 두 자식 모두 있는 경우:
   - 오른쪽 서브트리의 최솟값 노드(childNode)를 찾아
     delNode의 키 값을 대체.
   - 이후 childNode를 delNode으로 설정하고
     그 자리를 오른쪽 자식으로 채움
  */
  Node* parNode = delNode->get_parent_node();
  Node* childNode;

  if (delNode->get_left_node() == nullptr &&
      delNode->get_right_node() == nullptr) {          // 자식 노드가 없는 경우
    childNode = nullptr;
  } else if (delNode->get_left_node() == nullptr) {    // 오른쪽 자식만 있는 경우
    childNode = delNode->get_right_node();
  } else if (delNode->get_right_node() == nullptr) {   // 왼쪽 자식만 있는 경우
    childNode = delNode->get_left_node();
  } else {
    childNode = delNode->get_right_node();
    while (childNode->get_left_node() != nullptr) {    // 두 자식 모두 있는 경우
      childNode = childNode->get_left_node();
    }
    delNode->set_key(childNode->get_key());
    delNode = childNode;
    parNode = delNode->get_parent_node();
    childNode = delNode->get_right_node();
  }

  /*
    parNode와 childNode 노드의 연결 갱신:
    - delNode가 root인 경우: root를 childNode로 갱신.
    - 아니라면 parNode의 왼쪽 또는 오른쪽 자식 노드를 childNode로 연결.
  */
  if (parNode == nullptr) {
    root_ = childNode;
  } else if (delNode == parNode->get_left_node()) {
    parNode->set_left_node(childNode);
  } else {
    parNode->set_right_node(childNode);
  }
  if (childNode != nullptr) {
    childNode->set_parent_node(parNode);
  }

  /*
    delte delNode 및 size-- 수행.
    이후 parNode를 시작으로 root Node까지
    높이와 서브트리 사이즈를 갱신하고,
    balance 함수 실행.
  */
  delete delNode;
  size_--;

  Node* curNode = parNode;
  while (curNode != nullptr) {
    UpdateHeight(curNode);
    UpdateSubtreeSize(curNode);
    curNode = Balance(curNode);
    if (curNode->get_parent_node() == nullptr) {
      root_ = curNode;
    }

    curNode = curNode->get_parent_node();
  }
}

// private method

// 매개변수 curNode의 두 자식 노드의 차를 return
int AVLTree::Difference(Node* curNode) {
  /*
    curNode의 왼쪽 자식 노드 - 오른쪽 자식 노드를 return.
    만약 각 자식 노드가 존재하지 않는다면 0으로 설정
  */
  int leftHeight =
      curNode->get_left_node() ? curNode->get_left_node()->get_height() : 0;
  int rightHeight =
      curNode->get_right_node() ? curNode->get_right_node()->get_height() : 0;
  return (leftHeight - rightHeight);
}

// 매개변수 curNode의 높이를 업데이트함
void AVLTree::UpdateHeight(Node* curNode) {
  /*
    curNode의 두 자식 노드를 비교하여 더 큰 값의 높이에 1을 더함.
    이때 각 자식 노드가 존재하지 않는다면 0으로 설정
  */
  if (curNode != nullptr) {
    int leftHeight =
        (curNode->get_left_node()) ? curNode->get_left_node()->get_height() : 0;
    int rightHeight =
        (curNode->get_right_node()) ? curNode->get_right_node()->get_height() : 0;
    curNode->set_height(std::max(leftHeight, rightHeight) + 1);
  }
}

// 매개변수 curNode의 서브트리 사이즈를 업데이트함.
void AVLTree::UpdateSubtreeSize(Node* curNode) {
  /*
    curNode의 두 자식 노드를 비교하여 더 큰 값의 높이에 1을 더함
    이때 각 자식 노드가 존재하지 않는다면 0으로 설정
  */
  if (curNode != nullptr) {
    int leftSize =
        (curNode->get_left_node()) ? curNode->get_left_node()->get_subtree_size() : 0;
    int rightSize =
        (curNode->get_right_node()) ? curNode->get_right_node()->get_subtree_size() : 0;
    curNode->set_subtree_size(leftSize + rightSize + 1);
  }
}

// Left-Left Rotation 수행 Node*로 return
Node* AVLTree::LeftLeftRotation(Node* parNode) {
  /*
    LL 회전(Left-Left Rotation) 수행.
    - 불균형이 왼쪽 자식의 왼쪽 서브트리에서 발생했을 때 해결하는 회전 방식.

    curNode를 parNode의 왼쪽 자식 노드로 설정.
    parNode의 왼쪽 자식 노드를 curNode의 오른쪽 자식 노드로 변경.
    curNode의 오른쪽 자식 노드가 존재한다면 해당 노드의 부모를 parNode로 설정.

    curNode의 오른쪽 자식 노드를 parNode로 설정 후
    curNode의 부모 노드를 parNode의 부모 노드로 갱신.
  */
  Node* curNode = parNode->get_left_node();
  parNode->set_left_node(curNode->get_right_node());
  if (curNode->get_right_node() != nullptr)
    curNode->get_right_node()->set_parent_node(parNode);
  curNode->set_right_node(parNode);
  curNode->set_parent_node(parNode->get_parent_node());

  // parNode의 부모 노드가 존재한다면, 부모 노드의 왼쪽 또는 오른쪽 자식 노드를
  // curNode로 설정.
  if (parNode->get_parent_node()) {
    if (parNode->get_parent_node()->get_left_node() == parNode) {
      parNode->get_parent_node()->set_left_node(curNode);
    } else {
      parNode->get_parent_node()->set_right_node(curNode);
    }
  }
  parNode->set_parent_node(curNode);

  // 회전이 끝난 후 parNode와 curNode의 높이와 서브트리 사이즈 갱신
  UpdateHeight(parNode);
  UpdateHeight(curNode);
  UpdateSubtreeSize(parNode);
  UpdateSubtreeSize(curNode);

  return curNode;
}

// Right-Right Rotation 수행 Node*로 return
Node* AVLTree::RightRightRotation(Node* parNode) {
  /*
    RR 회전 (Right-Right Rotation) 수행.
    - 불균형이 오른쪽 자식의 오른쪽 서브트리에서 발생했을 때 해결하는 회전 방식.

    curNode를 parNode의 오른쪽 자식 노드로 설정.
    parNode의 오른쪽 자식 노드를 curNode의 왼쪽 자식 노드로 변경.
    curNode의 왼쪽 자식 노드가 존재한다면 해당 노드의 부모를 parNode로 설정.

    curNode의 왼쪽 자식 노드를 parNode로 설정 후
    curNode의 부모 노드를 parNode의 부모 노드로 갱신.
  */
  Node* curNode = parNode->get_right_node();
  parNode->set_right_node(curNode->get_left_node());
  if (curNode->get_left_node() != nullptr)
    curNode->get_left_node()->set_parent_node(parNode);
  curNode->set_left_node(parNode);
  curNode->set_parent_node(parNode->get_parent_node());

  // parNode의 부모 노드가 존재한다면, 부모 노드의 왼쪽 또는 오른쪽 자식 노드를
  // curNode로 설정.
  if (parNode->get_parent_node()) {
    if (parNode->get_parent_node()->get_left_node() == parNode) {
      parNode->get_parent_node()->set_left_node(curNode);
    } else {
      parNode->get_parent_node()->set_right_node(curNode);
    }
  }
  parNode->set_parent_node(curNode);

  // 회전이 끝난 후 parNode와 curNode의 높이와 서브트리 사이즈 갱신.
  UpdateHeight(parNode);
  UpdateHeight(curNode);
  UpdateSubtreeSize(parNode);
  UpdateSubtreeSize(curNode);

  return curNode;
}

// Left-Right Rotation 수행 Node*로 return
Node* AVLTree::LeftRightRotation(Node* parNode) {
  /*
    LR 회전(Left-Right Rotation) 수행.
    - 불균형이 왼쪽 자식의 오른쪽 서브트리에서 발생했을 때 해결하는 회전 방식.
    
    LR 회전은 두 단계로 구성:
    1. 왼쪽 자식 노드를 기준으로 RR 회전 수행 (오른쪽 회전).
    2. 이후 LL 회전을 통해 균형을 맞춤.
  */
  parNode->set_left_node(RightRightRotation(parNode->get_left_node()));
  return LeftLeftRotation(parNode);
}

// Right-Left Rotation 수행 후 Node*로 return
Node* AVLTree::RightLeftRotation(Node* parNode) {
  /*
    RL 회전 (Right-Left Rotation) 수행.
    - 불균형이 오른쪽 자식의 왼쪽 서브트리에서 발생했을 때 해결하는 회전 방식.

    RL 회전은 두 단계로 구성:
    1. 오른쪽 자식 노드를 기준으로 LL 회전 수행 (왼쪽 회전).
    2. 이후 RR 회전을 통해 균형을 맞춤.
  */
  parNode->set_right_node(LeftLeftRotation(parNode->get_right_node()));
  return RightRightRotation(parNode);
}

// 매개변수 curNode에 알맞은 회전을 수행 후 Node*로 return
Node* AVLTree::Balance(Node* curNode) {
  if (curNode == nullptr) {
    return nullptr;
  }

  int gap = Difference(curNode); // 현재 노드의 균형 인수 계산

  if (gap > 1) {                                        // 왼쪽 서브트리가 너무 큰 경우
    if (Difference(curNode->get_left_node()) >= 0) {    // LL
      curNode = LeftLeftRotation(curNode);
    } else {                                            // LR
      curNode = LeftRightRotation(curNode);
    }
  } else if (gap < -1) {                                // 오른쪽 서브트리가 너무 큰 경우
    if (Difference(curNode->get_right_node()) <= 0) {   // RR
      curNode = RightRightRotation(curNode);
    } else {                                            // RL
      curNode = RightLeftRotation(curNode);
    }
  }

  // 최종 높이 및 서브트리 사이즈 갱신
  UpdateHeight(curNode);
  UpdateSubtreeSize(curNode);
  return curNode;
}

// 매개변수 curNode를 root로 하는 AVL Tree에서 key값을 가진 노드를 찾아 Node*로 return
Node* AVLTree::Search(Node* curNode, int key) {
  /*
    curNode가 비었거나 curNode의 key값이 매개변수의 key값과 같을 때까지
    while문을 수행함. 이때 매개변수의 key값이 curNode의 key값보다 작을 땐
    curNode를 curNode의 왼쪽 자식 노드로, 아니라면 오른쪽 자식 노드로 설정
  */
  while (curNode != nullptr && curNode->get_key() != key) {
    if (key < curNode->get_key()) {
      curNode = curNode->get_left_node();
    } else {
      curNode = curNode->get_right_node();
    }
  }
  return curNode;
}

// 서브트리의 노드 중 가장 작은 키값을 int로 return
int AVLTree::FindMin(Node* curNode) {
  /*
    curNode의 왼쪽 노드가 nullptr일 때까지 내려간 후
    curNode의 key return
  */
  while (curNode->get_left_node() != nullptr) {
    curNode = curNode->get_left_node();
  }
  return curNode->get_key();
}

int AVLTree::FindMax(Node* curNode) {
  /*
    curNode의 오른쪽 노드가 nullptr일 때까지 내려간 후
    curNode의 key return
  */
  while (curNode->get_right_node() != nullptr) {
    curNode = curNode->get_right_node();
  }
  return curNode->get_key();
}
