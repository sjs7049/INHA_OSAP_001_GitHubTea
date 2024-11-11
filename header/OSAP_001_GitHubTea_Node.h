#ifndef AVL_TREE_OSAP_001_GITHUBTEA_NODE_H_
#define AVL_TREE_OSAP_001_GITHUBTEA_NODE_H_

class Node {
public:
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