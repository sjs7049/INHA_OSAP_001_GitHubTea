/****************************************************************************************
   File Name: OSAP_001_GitHubTea_AVLtree_test.cpp
   Copyright (c) 2024 GitHubTea

   This software is distributed under the MIT License.
   For more details on the MIT License, please refer to the LICENSE file in this project.
   This software is provided "as is," without any warranty of any kind.

   Author: GitHubTea
   Date: 2024-11-28
*****************************************************************************************/

#define private public
#include "header/OSAP_001_GitHubTea_AVLTree.h"
#undef private
#include "source/OSAP_001_GitHubTea_AVLTree.cpp"
#include <gtest/gtest.h>
#include <iostream>
using namespace testing;
using namespace std;

// 생성자 test
TEST(AVLTree_test, Contructor)
{
    AVLTree avl;
    ASSERT_EQ(avl.Size(), 0); // avl tree가 올바르게 초기화되지 않았다면 즉시 test 종료
}

// insert 함수가 제대로 동작하는지 test
TEST(AVLTree_test, insert)
{
    AVLTree avl;
    avl.Insert(3);            // tree에 node가 insert되어야만 앞으로의 코드가 의미 있음. 따라서 미리 test 진행
    ASSERT_EQ(avl.Size(), 1); // insert method가 올바르게 동작하지 않는다면 즉시 test 종료
}

// AVLTree class를 test하기 위한 fixture
class AVLTreeTestFixture : public ::testing::TestWithParam<int> {
public:
    AVLTreeTestFixture();
    virtual ~AVLTreeTestFixture();
    void SetUp() override;
    void TearDown() override;

protected:
    AVLTree avl_tree_;
    AVLTree empty_avl_tree_;
    private:
};

INSTANTIATE_TEST_CASE_P(
    AVLTreetest,
    AVLTreeTestFixture,
    ::testing::Values(
        1, 100241, 50012, 234191, 300000, 154201
    )
);

// Fixture class의 기본 생성자
AVLTreeTestFixture::AVLTreeTestFixture() {}

// Fixture class의 기본 소멸자
AVLTreeTestFixture::~AVLTreeTestFixture() {}

/*기본 setup*/
void AVLTreeTestFixture::SetUp()
{
    // 균등 분할 방식, 경계값 분석 기법에 기반하여 key 선정
    int test_keys[]{1, 100241, 50012, 234191, 300000, 154201};
    for (const int key : test_keys)
    {
        avl_tree_.Insert(key); // avl tree에 key 삽입
    }
    std::cout<<"⚡ 테스트를 시작합니다. ⚡\n";
}

/*test 종료 시 수행*/
void AVLTreeTestFixture::TearDown()
{
    int test_keys[]{1, 100241, 50012, 234191, 300000, 154201};
    for (const int key : test_keys)
    {
        avl_tree_.Erase(key); // avl tree로부터 모든 key 삭제
    }

    std::cout << "⚡ 테스트가 종료되었습니다. ⚡\n";
}

// Empty() 함수에 대한 test 수행
TEST_F(AVLTreeTestFixture, EmptyMethodTest)
{
    EXPECT_EQ(avl_tree_.Empty(), 0); //tree가 비어있지 않을 경우 0을 return해야 함
    EXPECT_EQ(empty_avl_tree_.Empty(), 1);//tree가 비어 있을 경우 1을 return해야 함
}

// Size() 함수에 대한 test 수행
TEST_F(AVLTreeTestFixture, SizeMethodTest)
{
    EXPECT_EQ(avl_tree_.Size(), 6); // tree에 6개의 test key가 있는 상태
    EXPECT_EQ(empty_avl_tree_.Size(), 0); // tree가 비어 있을 경우 size는 0이 되어야 함 
}

// Height() 함수에 대한 test 수행
TEST_F(AVLTreeTestFixture, HeightMethodTest)
{
    EXPECT_EQ(avl_tree_.Height(), 3); // 테스트 키들에 대해서, 전체 height는 3이 되어야 함
    EXPECT_EQ(avl_tree_.Height(50012), 2);
    EXPECT_EQ(avl_tree_.Height(154201), 1); //root node에 대한 test
    EXPECT_EQ(avl_tree_.Height(5093), 0); // 해당 key를 가진 node가 없을 경우 0을 return해야 함
    EXPECT_EQ(empty_avl_tree_.Height(), -1); // tree가 비어 있을 경우 -1을 return해야 함
}

// Depth() 함수에 대한 test 수행
TEST_F(AVLTreeTestFixture, DepthMethodTest)
{
    EXPECT_EQ(avl_tree_.Depth(1), 2);
    EXPECT_EQ(avl_tree_.Depth(23094), 0); // 해당 key를 가진 node가 없을 경우 0을 return해야 함
    EXPECT_EQ(empty_avl_tree_.Depth(23094), 0); //tree가 비어 있을 경우에 대한 test
}

// Ancestor() 함수에 대한 test 수행
TEST_F(AVLTreeTestFixture, AncestorMethodTest)
{
    EXPECT_EQ(avl_tree_.Ancestor(154201), 334432); //root node에 대한 test
    EXPECT_EQ(avl_tree_.Ancestor(234191), 100241); //1개의 ancestor를 가질 경우에 대한 test
    EXPECT_EQ(avl_tree_.Ancestor(100241), 0); //2개 이상의 ancestor를 가질 경우에 대한 test
}

// MinDescendant() 함수에 대한 test 수행
TEST_F(AVLTreeTestFixture, MinDescendantMethodTest)
{
    EXPECT_EQ(avl_tree_.MinDescendant(154201), 154201);
    EXPECT_EQ(avl_tree_.MinDescendant(154201), 154201);
    EXPECT_EQ(avl_tree_.MinDescendant(1), 1); //leaf node일 경우 자기 자신을 return 
}

// MaxDescendant() 함수에 대한 test 수행
TEST_F(AVLTreeTestFixture, MaxDescendantMethodTest)
{
    EXPECT_EQ(avl_tree_.MaxDescendant(154201), 154201);
    EXPECT_EQ(avl_tree_.MaxDescendant(234191), 300000);
    EXPECT_EQ(avl_tree_.MaxDescendant(1), 1); //leaf node일 경우 자기 자신을 return
}

// Rank() 함수에 대한 test 수행
TEST_F(AVLTreeTestFixture, RankMethodTest)
{
    EXPECT_EQ(avl_tree_.Rank(1), 1); // rank가 가장 높은 경우
    EXPECT_EQ(avl_tree_.Rank(300000), 6); // rank가 가장 낮은 경우
    EXPECT_EQ(avl_tree_.Rank(300032), 0); // 존재하지 않는 node 
    EXPECT_EQ(empty_avl_tree_.Rank(1), 0); // tree가 비어있을 경우
}

// Erase() 함수에 대한 test 수행
TEST_F(AVLTreeTestFixture, EraseMethodTest)
{
    EXPECT_EQ(avl_tree_.Size(), 6); // node의 개수가 6개인 상태로부터 시작
    avl_tree_.Erase(1); // key가 1인 node를 삭제
    EXPECT_EQ(avl_tree_.Size(), 5); // tree의 size가 5가 되어야 함
    EXPECT_EQ(avl_tree_.Height(1), 0); // key가 1인 node를 tree에서 찾을 수 없어야 함
}

//dirrerence() 함수에 대한 test 수행
TEST_F(AVLTreeTestFixture, DifferenceMethodTest) {
    int balance_factor = avl_tree_.difference(avl_tree_.root);
    EXPECT_EQ(balance_factor, 0);
}

// updateHeight() 함수에 대한 test 수행
TEST_F(AVLTreeTestFixture, UpdateHeightMethodTest)
{
    node* test_node = avl_tree_.search(avl_tree_.root, 50012);
    avl_tree_.updateHeight(test_node);  // 이 함수가 정상적으로 작동해야 함
    EXPECT_EQ(test_node->height, 2); // 예상되는 높이를 확인
}

// updateSubtreeSize() 함수에 대한 test 수행
TEST_F(AVLTreeTestFixture, UpdateSubtreeSizeMethodTest)
{
    node* test_node = avl_tree_.search(avl_tree_.root, 50012);
    avl_tree_.updateSubtreeSize(test_node);  // 하위 트리 크기가 갱신되어야 함
    EXPECT_EQ(test_node->subtreeSize, 2); // 예상되는 서브트리 크기
}

// ll() 함수에 대한 test 수행
TEST_F(AVLTreeTestFixture, LLMethodTest)
{
    node* parent = avl_tree_.search(avl_tree_.root, 50012);
    node* new_parent = avl_tree_.ll(parent);  // 왼쪽-왼쪽 회전
    EXPECT_EQ(new_parent->key, 1);  // 회전 후 부모 노드가 변경되어야 함
}

// rr() 함수에 대한 test 수행
TEST_F(AVLTreeTestFixture, RRMethodTest)
{
    node* parent = avl_tree_.search(avl_tree_.root, 234191);
    node* new_parent = avl_tree_.rr(parent);  // 오른쪽-오른쪽 회전
    EXPECT_EQ(new_parent->key, 300000);  // 회전 후 부모 노드가 변경되어야 함
}


TEST_F(AVLTreeTestFixture, BalanceMethodTest)
{
    avl_tree_.Insert(600000); // 불균형을 유발할 값 삽입
    avl_tree_.Insert(700000);

    int initial_balance = avl_tree_.difference(avl_tree_.root);  // 불균형 트리일 경우 1보다 크거나 -1보다 작음
    EXPECT_NE(initial_balance, 0);  // 균형 잡히지 않은 트리여야 하므로, 0이 아니어야 함

    node* unbalanced_node = avl_tree_.search(avl_tree_.root, 50012);
    node* balanced_node = avl_tree_.balance(unbalanced_node);
    int final_balance = avl_tree_.difference(avl_tree_.root);
    EXPECT_EQ(final_balance, -1); 

    EXPECT_NE(balanced_node, nullptr);  // 균형 작업 후 null이 아니어야 함
}


// search() 함수에 대한 test 수행
TEST_F(AVLTreeTestFixture, SearchMethodTest)
{
    node* found_node = avl_tree_.search(avl_tree_.root, 50012);
    EXPECT_EQ(found_node->key, 50012);  // 찾은 노드가 올바른 key를 가지고 있어야 함

    node* not_found_node = avl_tree_.search(avl_tree_.root, 999999);  // 존재하지 않는 key
    EXPECT_EQ(not_found_node, nullptr);  // 찾을 수 없는 노드는 nullptr을 반환해야 함
}

// findMin() 함수에 대한 test 수행
TEST_F(AVLTreeTestFixture, FindMinMethodTest)
{
    int min_key = avl_tree_.findMin(avl_tree_.root);
    EXPECT_EQ(min_key, 1);  // 최소값은 1이어야 함
}

// findMax() 함수에 대한 test 수행
TEST_F(AVLTreeTestFixture, FindMaxMethodTest)
{
    int max_key = avl_tree_.findMax(avl_tree_.root);
    EXPECT_EQ(max_key, 300000);  // 최대값은 300000이어야 함
}


// isRoot() 함수에 대한 test 수행
TEST_F(AVLTreeTestFixture, IsRootMethodTest)
{
    EXPECT_EQ(avl_tree_.root->key, 100241);
}

//isExist() 함수에 대한 test 수행
TEST_P(AVLTreeTestFixture, IsExistMethodTest)
{
    int key = GetParam();
    EXPECT_TRUE(avl_tree_.isExist(key)); //삽입된 key 전체에 대해서 true
    EXPECT_FALSE(avl_tree_.isExist(123422)); //해당 키가 없을 경우 false
}

//Find() 함수에 대한 test 수행
TEST_F(AVLTreeTestFixture, FindMethodTest)
{
    EXPECT_EQ(avl_tree_.Find(1), 3);
}
