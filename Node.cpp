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
        if (left == nullptr) {
            left = new Node(new_data);
        } else {
            left->insert(new_data);
        }
    } else if (new_data > data) {
        if (right == nullptr) {
            right = new Node(new_data);
        } else {
            right->insert(new_data);
        }
    }
}

bool Node::isLeaf() {
    return left == nullptr && right == nullptr;
}

int Node::height() {
    if (isLeaf()) {
        return 0;
    }

    int leftHeight = (left != nullptr) ? left->height() + 1 : 0;
    int rightHeight = (right != nullptr) ? right->height() + 1 : 0;
    return max(leftHeight, rightHeight);
}

bool Node::isFull() {
    if (isLeaf()) {
        return true;
    }

    if ((left == nullptr) || (right == nullptr)) {
        return false;
    }

    return left->isFull() && right->isFull();
}

int Node::countNodes() {
    int count = 1;
    if (left != nullptr) {
        count += left->countNodes();
    }
    if (right != nullptr) {
        count += right->countNodes();
    }
    return count;
}