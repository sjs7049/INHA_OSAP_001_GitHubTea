/****************************************************************************************
   File Name: OSAP_001_GitHubTea_Node_test.cpp
   Copyright (c) 2024 GitHubTea

   This software is distributed under the MIT License.
   For more details on the MIT License, please refer to the LICENSE file in this project.
   This software is provided "as is," without any warranty of any kind.

   Author: GitHubTea
   Date: 2024-11-28
*****************************************************************************************/

#include "header/OSAP_001_GitHubTea_Node.h"
#include <gtest/gtest.h>
#include <iostream>
using namespace testing;
using namespace std;

// 기본 생성자에 대한 테스트
TEST(Node_test, DefaultConstructorTest) {
    Node new_node = Node();
    ASSERT_EQ(new_node.key_(), 0);
    ASSERT_EQ(new_node.height_(), 1);
    ASSERT_EQ(new_node.subtreeSize_(), 1);
    ASSERT_EQ(new_node.left_node_(), nullptr);
    ASSERT_EQ(new_node.right_node_(), nullptr);
    ASSERT_EQ(new_node.parent_node_(), nullptr);
}

// 파라미터 생성자에 대한 테스트
TEST(Node_test, ParameterConstructorTest) {
    Node new_node = Node(3);
    ASSERT_EQ(new_node.key_(), 3);
    ASSERT_EQ(new_node.height_(), 1);
    ASSERT_EQ(new_node.subtreeSize_(), 1);
    ASSERT_EQ(new_node.left_node_(), nullptr);
    ASSERT_EQ(new_node.right_node_(), nullptr);
    ASSERT_EQ(new_node.parent_node_(), nullptr);
}

// 소멸자에 대한 테스트
TEST(Node_test, DestructorTest) {
    Node* dynamic_node = new Node(42); // Node를 동적 할당
    dynamic_node->left_node_set(new Node(21)); // 왼쪽 자식 노드 설정
    dynamic_node->right_node_set(new Node(84)); // 오른쪽 자식 노드 설정

    // Node의 초기 상태를 검증
    EXPECT_EQ(dynamic_node->key_(), 42);
    EXPECT_EQ(dynamic_node->left_node_()->key_(), 21);
    EXPECT_EQ(dynamic_node->right_node_()->key_(), 84);

    // 자식 노드를 먼저 삭제한 후 부모 노드 삭제
    delete dynamic_node->left_node_(); // 왼쪽 자식 노드 삭제
    delete dynamic_node->right_node_(); // 오른쪽 자식 노드 삭제
    delete dynamic_node; // 부모 노드 삭제

    // 메모리 해제 및 리소스 정리가 성공적으로 완료되면 테스트 통과
    SUCCEED();
}

// NodeTestFixture 클래스를 사용한 테스트
class NodeTestFixture : public ::testing::Test {
public:
    NodeTestFixture();
    virtual ~NodeTestFixture();
    void SetUp() override;
    void TearDown() override;

protected:
    Node node_;
    Node left_child_;
    Node right_child_;
};

NodeTestFixture::NodeTestFixture() {}

NodeTestFixture::~NodeTestFixture() {}

/*기본 setup*/
void NodeTestFixture::SetUp() {
    node_ = Node(10);
    left_child_ = Node(5);
    right_child_ = Node(15);
    node_.left_node_set(&left_child_);
    node_.right_node_set(&right_child_);
    left_child_.parent_node_set(&node_);
    right_child_.parent_node_set(&node_);
    std::cout << "⚡ 테스트를 시작합니다. ⚡\n";
}

/*test 종료 시 수행*/
void NodeTestFixture::TearDown() {
    std::cout << "⚡ 테스트가 종료되었습니다. ⚡\n";
}

// key_() 메서드 테스트
TEST_F(NodeTestFixture, KeyMethodTest) {
    EXPECT_EQ(node_.key_(), 10);
}

// height_() 메서드 테스트
TEST_F(NodeTestFixture, HeightMethodTest) {
    EXPECT_EQ(node_.height_(), 1);
}

// subtreeSize_() 메서드 테스트
TEST_F(NodeTestFixture, SubtreeSizeMethodTest) {
    EXPECT_EQ(node_.subtreeSize_(), 1);
}

// left_node_() 메서드 테스트
TEST_F(NodeTestFixture, LeftNodeMethodTest) {
    EXPECT_EQ(node_.left_node_(), &left_child_);
    EXPECT_EQ(left_child_.key_(), 5);
}

// right_node_() 메서드 테스트
TEST_F(NodeTestFixture, RightNodeMethodTest) {
    EXPECT_EQ(node_.right_node_(), &right_child_);
    EXPECT_EQ(right_child_.key_(), 15);
}

// parent_node_() 메서드 테스트
TEST_F(NodeTestFixture, ParentNodeMethodTest) {
    EXPECT_EQ(left_child_.parent_node_(), &node_);
    EXPECT_EQ(right_child_.parent_node_(), &node_);
}

// key_set() 메서드 테스트
TEST_F(NodeTestFixture, KeySetMethodTest) {
    node_.key_set(20);
    EXPECT_EQ(node_.key_(), 20);
}

// height_set() 메서드 테스트
TEST_F(NodeTestFixture, HeightSetMethodTest) {
    node_.height_set(3);
    EXPECT_EQ(node_.height_(), 3);
}

// subtreeSize_set() 메서드 테스트
TEST_F(NodeTestFixture, SubtreeSizeSetMethodTest) {
    node_.subtreeSize_set(5);
    EXPECT_EQ(node_.subtreeSize_(), 5);
}

// left_node_set() 메서드 테스트
TEST_F(NodeTestFixture, LeftNodeSetMethodTest) {
    Node new_left_child = Node(8);
    node_.left_node_set(&new_left_child);
    EXPECT_EQ(node_.left_node_(), &new_left_child);
    EXPECT_EQ(node_.left_node_()->key_(), 8);
}

// right_node_set() 메서드 테스트
TEST_F(NodeTestFixture, RightNodeSetMethodTest) {
    Node new_right_child = Node(18);
    node_.right_node_set(&new_right_child);
    EXPECT_EQ(node_.right_node_(), &new_right_child);
    EXPECT_EQ(node_.right_node_()->key_(), 18);
}

// parent_node_set() 메서드 테스트
TEST_F(NodeTestFixture, ParentNodeSetMethodTest) {
    Node new_parent = Node(25);
    node_.parent_node_set(&new_parent);
    EXPECT_EQ(node_.parent_node_(), &new_parent);
    EXPECT_EQ(node_.parent_node_()->key_(), 25);
}
