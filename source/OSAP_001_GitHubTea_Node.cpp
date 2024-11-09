#include "../header/OSAP_001_GitHubTea_Node.h"

Node::Node(int _key)
    : key{ _key }, parent{ nullptr }, left{ nullptr }
    , right{ nullptr }, height{ 1 } {}

int Node::key_() const {
    return key;
}

int Node::height_() const {
    return height;
}

Node* Node::parent_node_() const {
    return parent;
}

Node* Node::left_node_() const {
    return left;
}

Node* Node::right_node_() const {
    return right;
}

void Node::set_key_(int _key) {
    key = _key;
}

void Node::set_height_(int _height) {
    height = _height;
}

void Node::set_parent_node_(Node* parNode) {
    parent = parNode;
}

void Node::set_right_node_(Node* rNode) {
    right = rNode;
}

void Node::set_left_node_(Node* lNode) {
    left = lNode;
}
