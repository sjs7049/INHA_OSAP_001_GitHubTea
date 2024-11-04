#ifndef AVL_TREE_OSAP_001_GITHUBTEA_NODE_H_
#define AVL_TREE_OSAP_001_GITHUBTEA_NODE_H_


class Node {
public:
	Node(int); // Node class의 생성자. 매개변수로 key를 받음
	~Node() {}; // Node class의 소멸자. 

	int key() const; // member data key_에 대한 getter
	Node* left_node() const; // left child node의 주소에 대한 getter
	Node* right_node() const; //right child node의 주소에 대한 getter
	int height() const; // member data height_에 대한 getter

	void set_key(); // member data key_에 대한 setter
	void set_left_node(Node*); // left child node의 주소에 대한 setter
	void set_right_node(Node*); //right child node의 주소에 대한 setter
	void set_height(int); // member data height_에 대한 getter
private:
	const int key_; // 현재 나의 key
	Node* left_node_; // left child node의 주소
	Node* right_node_; // right child node의 주소
	int height_; // tree 내에서 나의 height
};

#endif // !AVL_TREE_OSAP_001_GITHUBTEA_NODE_H_