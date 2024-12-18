/****************************************************************************************
   File Name: OSAP_001_GitHubTea_Node_test.cpp
   Copyright (c) 2024 GitHubTea

   This software is distributed under the MIT License.
   For more details on the MIT License, please refer to the LICENSE file in this project.
   This software is provided "as is," without any warranty of any kind.

   Author: GitHubTea
   Date: 2024-11-28
*****************************************************************************************/

#include "header/OSAP_001_GitHubTea_AVLtree_Node.h"
#include <gtest/gtest.h>
#include <iostream>
using namespace testing;
using namespace std;

// 기본 생성자에 대한 테스트
TEST(Node_test, DefaultConstructorTest) {
    Node new_node = Node();
    ASSERT_EQ(new_node.get_key(), 0);
    ASSERT_EQ(new_node.get_height(), 1);
    ASSERT_EQ(new_node.get_subtree_size(), 1);
    ASSERT_EQ(new_node.get_left_node(), nullptr);
    ASSERT_EQ(new_node.get_right_node(), nullptr);
    ASSERT_EQ(new_node.get_parent_node(), nullptr);
}

// 파라미터 생성자에 대한 테스트
TEST(Node_test, ParameterConstructorTest) {
    Node new_node = Node(3);
    ASSERT_EQ(new_node.get_key(), 3);
    ASSERT_EQ(new_node.get_height(), 1);
    ASSERT_EQ(new_node.get_subtree_size(), 1);
    ASSERT_EQ(new_node.get_left_node(), nullptr);
    ASSERT_EQ(new_node.get_right_node(), nullptr);
    ASSERT_EQ(new_node.get_parent_node(), nullptr);
}

// 소멸자에 대한 테스트
TEST(Node_test, DestructorTest) {
    Node* dynamic_node = new Node(42); // Node를 동적 할당
    dynamic_node->set_left_node(new Node(21)); // 왼쪽 자식 노드 설정
    dynamic_node->set_right_node(new Node(84)); // 오른쪽 자식 노드 설정

    // Node의 초기 상태를 검증
    EXPECT_EQ(dynamic_node->get_key(), 42);
    EXPECT_EQ(dynamic_node->get_left_node()->get_key(), 21);
    EXPECT_EQ(dynamic_node->get_right_node()->get_key(), 84);

    // 자식 노드를 먼저 삭제한 후 부모 노드 삭제
    delete dynamic_node->get_left_node(); // 왼쪽 자식 노드 삭제
    delete dynamic_node->get_right_node(); // 오른쪽 자식 노드 삭제
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
    node_.set_left_node(&left_child_);
    node_.set_right_node(&right_child_);
    left_child_.set_parent_node(&node_);
    right_child_.set_parent_node(&node_);
    std::cout << "⚡ 테스트를 시작합니다. ⚡\n";
}

/*test 종료 시 수행*/
void NodeTestFixture::TearDown() {
    std::cout << "⚡ 테스트가 종료되었습니다. ⚡\n";
}

// get_key() 메서드 테스트
TEST_F(NodeTestFixture, GetKeyMethodTest) {
    EXPECT_EQ(node_.get_key(), 10);
}

// get_height() 메서드 테스트
TEST_F(NodeTestFixture, GetHeightMethodTest) {
    EXPECT_EQ(node_.get_height(), 1);
}

// get_subtree_size() 메서드 테스트
TEST_F(NodeTestFixture, GetSubtreeSizeMethodTest) {
    EXPECT_EQ(node_.get_subtree_size(), 1);
}

// get_left_node() 메서드 테스트
TEST_F(NodeTestFixture, GetLeftNodeMethodTest) {
    EXPECT_EQ(node_.get_left_node(), &left_child_);
    EXPECT_EQ(left_child_.get_key(), 5);
}

// get_right_node() 메서드 테스트
TEST_F(NodeTestFixture, GetRightNodeMethodTest) {
    EXPECT_EQ(node_.get_right_node(), &right_child_);
    EXPECT_EQ(right_child_.get_key(), 15);
}

// get_parent_node() 메서드 테스트
TEST_F(NodeTestFixture, GetParentNodeMethodTest) {
    EXPECT_EQ(left_child_.get_parent_node(), &node_);
    EXPECT_EQ(right_child_.get_parent_node(), &node_);
}

// set_key() 메서드 테스트
TEST_F(NodeTestFixture, SetKeyMethodTest) {
    node_.set_key(20);
    EXPECT_EQ(node_.get_key(), 20);
}

// set_height() 메서드 테스트
TEST_F(NodeTestFixture, SetHeightMethodTest) {
    node_.set_height(3);
    EXPECT_EQ(node_.get_height(), 3);
}

// set_subtree_size() 메서드 테스트
TEST_F(NodeTestFixture, SetSubtreeSizeMethodTest) {
    node_.set_subtree_size(5);
    EXPECT_EQ(node_.get_subtree_size(), 5);
}

// set_left_node() 메서드 테스트
TEST_F(NodeTestFixture, SetLeftNodeMethodTest) {
    Node new_left_child = Node(8);
    node_.set_left_node(&new_left_child);
    EXPECT_EQ(node_.get_left_node(), &new_left_child);
    EXPECT_EQ(node_.get_left_node()->get_key(), 8);
}

// get_right_node() 메서드 테스트
TEST_F(NodeTestFixture, SetRightNodeMethodTest) {
    Node new_right_child = Node(18);
    node_.set_right_node(&new_right_child);
    EXPECT_EQ(node_.get_right_node(), &new_right_child);
    EXPECT_EQ(node_.get_right_node()->get_key(), 18);
}

// get_parent_node() 메서드 테스트
TEST_F(NodeTestFixture, SetParentNodeMethodTest) {
    Node new_parent = Node(25);
    node_.set_parent_node(&new_parent);
    EXPECT_EQ(node_.get_parent_node(), &new_parent);
    EXPECT_EQ(node_.get_parent_node()->get_key(), 25);
}
