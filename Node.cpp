#include "Node.h"
#include <iostream>

using namespace std;

Node::Node(int t_data, Node* t_left, Node* t_right) {
    data = t_data;
    left = t_left;
    right = t_right;
}

void Node::insert(int new_data) {
    if (new_data < data) {
        if (left == nullptr)
            left = new Node(new_data);
        else
            left->insert(new_data);
    } else {
        if (right == nullptr)
            right = new Node(new_data);
        else
            right->insert(new_data);
    }
}

bool Node::isLeaf() {
    return (left == nullptr && right == nullptr);
}

int Node::height() {
    if (left == nullptr && right == nullptr)
        return 0; // Height of leaf node is 0
    else {
        int left_height = (left == nullptr) ? -1 : left->height();
        int right_height = (right == nullptr) ? -1 : right->height();
        return 1 + max(left_height, right_height);
    }
}

bool Node::isFull() {
    if (left == nullptr && right == nullptr)
        return true; // Leaf node is considered full
    else if (left != nullptr && right != nullptr)
        return (left->isFull() && right->isFull());
    else
        return false; // One child only
}

int Node::countNodes() {
    if (this == nullptr)
        return 0;
    else
        return 1 + (left ? left->countNodes() : 0) + (right ? right->countNodes() : 0);
}