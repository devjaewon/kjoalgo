// Created by Jaewon Kim on 2020/04/27
// Copyright © 2020 jaewonkim. All rights reserved.
// [Itrative Method]

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
        vector<AVLTreeNode<Data>*> trace;
        AVLTreeNode<Data>* cursor = _root;
        bool isLeftDirection;

        trace.reserve(_root->getHeight());

        while (cursor) {
            isLeftDirection = cursor->_data > data;
            trace.push_back(cursor);
            cursor = isLeftDirection ? cursor->_left : cursor->_right;
        }

        if (isLeftDirection)
            trace.back()->_left = new AVLTreeNode<Data>(data);
        else
            trace.back()->_right = new AVLTreeNode<Data>(data);
    
        _root = AVLTree<Data>::rebalance(trace);
    }

    static AVLTreeNode<Data>* rebalance(vector<AVLTreeNode<Data>*> trace) {
        AVLTreeNode<Data>* root = trace[0];
        int index = trace.size() - 1;

        while (index >= 0) {
            AVLTreeNode<Data>* parent = trace[index];
            AVLTreeNode<Data>* newParent;
            int bf = parent->getBalanceFactor();

            if (bf > 1) {
                int leftBf = parent->_left ? parent->_left->getBalanceFactor() : 0;
                if (leftBf < 0) {
                    parent->_left = AVLTree<Data>::rotateLeft(parent->_left);
                }
                newParent = AVLTree<Data>::rotateRight(parent);
            } else if (bf < -1) {
                int rightBf = parent->_right ? parent->_right->getBalanceFactor() : 0;
                if (rightBf > 0) {
                    parent->_right = AVLTree<Data>::rotateRight(parent->_right);
                }
                newParent = AVLTree<Data>::rotateLeft(parent);
            }

            if (index == 0) {
                if (newParent) root = newParent;
            } else if (trace[index-1]->_left == parent) {
                trace[index-1]->_left = newParent;
            } else if (trace[index-1]->_right == parent) {
                trace[index-1]->_right = newParent;
            }

            index--;
        }

        return root;
    };

    static AVLTreeNode<Data>* rotateLeft(AVLTreeNode<Data>* parent) {
        AVLTreeNode<Data>* newParent = parent->_right;

        parent->_right = newParent->_left;
        newParent->_left = parent;

        return newParent;
    }

    static AVLTreeNode<Data>* rotateRight(AVLTreeNode<Data>* parent) {
        AVLTreeNode<Data>* newParent = parent->_left;
        
        parent->_left = newParent->_right;
        newParent->_right = parent;

        return newParent;
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

