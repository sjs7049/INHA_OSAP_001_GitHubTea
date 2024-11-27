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

    Node(int key);
    int key_() const;
    int height_() const;
    Node* left_node_() const;
    Node* right_node_() const;
    Node* parent_node_() const;

    void set_key_(int);
    void set_height_(int);
    void set_parent_node_(Node*);
    void set_right_node_(Node*);
    void set_left_node_(Node*);

private:
    int key;
    int height;
    Node* parent;
    Node* left;
    Node* right;
};

#endif // !AVL_TREE_OSAP_001_GITHUBTEA_NODE_H_