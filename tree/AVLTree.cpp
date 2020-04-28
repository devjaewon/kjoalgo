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
    
        AVLTree<Data>::rebalance(trace);
    }

    static void rebalance(vector<AVLTreeNode<Data>*> trace) {
        int index = trace.size() - 1;

        while (index >= 0) {
            AVLTreeNode<Data>* parent = trace[index];
            int bf = parent->getBalanceFactor();

            if (bf > 1) {
                int leftBf = parent->_left ? parent->_left->getBalanceFactor() : 0;
                if (leftBf < 0)
                    AVLTree<Data>::rotateLL(parent);
                else
                    AVLTree<Data>::rotateLR(parent);
            } else if (bf < -1) {
                int rightBf = parent->_right ? parent->_right->getBalanceFactor() : 0;
                if (rightBf > 0)
                    AVLTree<Data>::rotateRR(parent);
                else 
                    AVLTree<Data>::rotateRL(parent);
            }
            index--;
        }
    };

    static void rotateLL(AVLTreeNode<Data>* parent) {
        // TODO
    }

    static void rotateLR(AVLTreeNode<Data>* parent) {
        // TODO
    }

    static void rotateRR(AVLTreeNode<Data>* parent) {
        // TODO
    }

    static void rotateRL(AVLTreeNode<Data>* parent) {
        // TODO
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

