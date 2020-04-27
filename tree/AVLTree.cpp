// Created by Jaewon Kim on 2020/04/27
// Copyright © 2020 jaewonkim. All rights reserved.
// [Recursive Method]

#include <iostream>
#include <stack>
#include <vector>
#include <queue>

using namespace std;

template <typename Data>
class AVLTree;

template <typename Data>
class AVLTreeNode {
    friend class AVLTree<Data>;

private:
    Data _data;
    AVLTreeNode* _left;
    AVLTreeNode* _right;

public:
    AVLTreeNode(const Data& data) {
        _data = data;
        _left = 0;
        _right = 0;
    }

    void balance() {
        int bf = getBalanceFactor();

        if (bf <= -2) {
            int leftBf = _left ? _left->getBalanceFactor() : 0;
            if (leftBf <= -1) rotateLL();
            else rotateLR();
        } else if (bf >=2) {
            int rightBf = _right ? _right->getBalanceFactor() : 0;
            if (rightBf >= 1) rotateRR();
            else rotateRL();
        }
    }

private:
    int getHeight() {
        int leftHeight = _left ? _left->getHeight() : 0;
        int rightHeight = _right ? _right->getHeight() : 0;
        
        return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
    }

    int getBalanceFactor() {
        int leftHeight = _left ? _left->getHeight() : 0;
        int rightHeight = _right ? _right->getHeight() : 0;

        return leftHeight - rightHeight;
    }
    
    void rotateLL() {
        // TODO
    }

    void rotateLR() {
        // TODO
    }

    void rotateRR() {
        // TODO
    }

    void rotateRL() {
        // TODO
    }
};

template <typename Data>
class AVLTree {
private:
    AVLTreeNode<Data>* _root;
    int size;

public:
    AVLTree(const Data& rootData) {
        _root = new AVLTreeNode<Data>(rootData);
        size = 1;
    }

    void insert(const Data& data) {
        AVLTreeNode<Data>* cursor = _root;
        AVLTreeNode<Data>* prev;
        bool isLeftDirection;

        while (cursor) {
            isLeftDirection = cursor->_data > data;
            prev = cursor;
            cursor = isLeftDirection ? cursor->_left : cursor->_right;
        }

        if (isLeftDirection)
            prev->_left = new AVLTreeNode<Data>(data);
        else
            prev->_right = new AVLTreeNode<Data>(data);
    
        _root->balance();
    }
};

int main() {
    //           30
    //    10            45
    // 5            35       60
    AVLTree<int> tree = AVLTree<int>{ 30 };

    tree.insert(10);
    tree.insert(45);
    tree.insert(5);
    tree.insert(35);
    tree.insert(60);

    return 0;
}

