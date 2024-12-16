/****************************************************************************************
   File Name: OSAP_001_GitHubTea_Node.h
   Copyright (c) 2024 GitHubTea

   This software is distributed under the MIT License.
   For more details on the MIT License, please refer to the LICENSE file in this project.
   This software is provided "as is," without any warranty of any kind.

   Author: GitHubTea
   Date: 2024-11-28
*****************************************************************************************/

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
