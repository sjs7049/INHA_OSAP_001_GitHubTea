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

    AVLTree(); // AVLTree instance에 대한 생성자
    ~AVLTree(); // AVLTree instance에 대한 소멸자

    void set_root(int); // member data root_에 대한 setter
    void set_size(int); // member data size_에 대한 setter
    void set_height(int); // member data height_에 대한 setter

    bool Empty() const; // set이 비어 있다면 1을, 아니라면 0을 return함
    int Size() const; // 현재 tree에 존재하는 node들의 개수를 출력함
    int Height() const; // 전체 tree의 height를 return함
    int Height(int) const; // node의 key를 입력받고, 그 node의 높이를 출력함
    int Depth(int) const; // node의 key를 입력받고, 그 node의 깊이를 출력함
    int Ancestor(int) const; // node의 key를 입력받고, 그 node의 Ancestors들의 key의 합을 return함
    int MinDescendant(int) const; // node의 key를 입력받고, 그 node의 Descendant들 중 가장 작은 key를 return함
    int MaxDescendant(int) const; // node의 key를 입력받고, 그 node의 Descendant들 중 가장 큰 key를 return함
    int Rank(int) const; // node의 key를 입력받고, 그 node의 rank를 출력함
    void Insert(int); // tree에 새로운 Node를 삽입함
    void Erase(int);  // node의 key를 입력받고, 그 node를 삭제함

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
