// Created by Jaewon Kim on 2020/04/27
// Copyright © 2020 jaewonkim. All rights reserved.
// [Itrative Method]

#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include "./BinarySearchTree.hpp"

using namespace std;

template <typename Key>
class AVLTree;

template <typename Key>
class AVLTreeNode : public BinaryTreeNode<Key> {
public:
    AVLTreeNode(const Key& key): BinaryTreeNode<Key>(key) {}

    int getHeight() {
        int left_height = left ? left->getHeight() : 0;
        int right_height = right ? right->getHeight() : 0;
        
        return left_height > right_height ? left_height + 1 : right_height + 1;
    }

    int getBalanceFactor() {
        int left_height = left ? left->getHeight() : 0;
        int right_height = right ? right->getHeight() : 0;

        return left_height - right_height;
    }
};

template <typename Key>
class AVLTree : public BinarySearchTree<Key> {
public:
    AVLTree(const Key& root_key): BinarySearchTree<Key>() {
        this->root = new AVLTreeNode<Key>(root_key);
        this->size = 1;
    }

    /**
     * @description
     *  insert new element
     *  - O(logN) Time Complexity by Big-O
     */
    void insert(const Key& new_key) {
        cout << "<Key " << new_key << " Insertion>" << endl;

        vector<AVLTreeNode<Key>*> trace;
        AVLTreeNode<Key>* cursor = dynamic_cast<AVLTreeNode<Key>*>(this->root);
        bool is_left_direction;
        
        trace.reserve(cursor->getHeight());

        while (cursor) {
            is_left_direction = cursor->key > new_key;
            trace.push_back(cursor);
            cursor = is_left_direction ? cursor->left : cursor->right;
        }

        if (is_left_direction)
            trace.back()->left = new AVLTreeNode<Key>(new_key);
        else
            trace.back()->right = new AVLTreeNode<Key>(new_key);
        
        this->root = AVLTree<Key>::rebalance(trace);
    }

    /**
     * @description
     *  rebalance total tree height
     *  - use rotation
     */
    static AVLTreeNode<Key>* rebalance(vector<AVLTreeNode<Key>*> trace) {
        AVLTreeNode<Key>* new_root = trace[0];
        int index = trace.size() - 1;
        while (index >= 0) {
            AVLTreeNode<Key>* parent = trace[index];
            AVLTreeNode<Key>* new_parent = 0;
            int bf = parent->getBalanceFactor();

            if (bf > 1) {
                int left_bf = parent->left ? parent->left->getBalanceFactor() : 0;
                if (left_bf < 0) {
                    parent->left = AVLTree<Key>::rotateLeft(parent->left);
                }
                new_parent = AVLTree<Key>::rotateRight(parent);
            } else if (bf < -1) {
                int right_bf = parent->right ? parent->right->getBalanceFactor() : 0;
                if (right_bf > 0) {
                    parent->right = AVLTree<Key>::rotateRight(parent->right);
                }
                new_parent = AVLTree<Key>::rotateLeft(parent);
            }

            if (new_parent) {
                cout << "Rebalance!" << endl;
                if (index == 0) {
                    new_root = new_parent;
                } else if (trace[index-1]->left == parent) {
                    trace[index-1]->left = new_parent;
                } else if (trace[index-1]->right == parent) {
                    trace[index-1]->right = new_parent;
                }
            }

            index--;
        }

        return new_root;
    };

    static AVLTreeNode<Key>* rotateLeft(AVLTreeNode<Key>* parent) {
        AVLTreeNode<Key>* new_parent = parent->right;

        parent->right = new_parent->left;
        new_parent->left = parent;

        return new_parent;
    }

    static AVLTreeNode<Key>* rotateRight(AVLTreeNode<Key>* parent) {
        AVLTreeNode<Key>* new_parent = parent->left;
        
        parent->left = new_parent->right;
        new_parent->right = parent;

        return new_parent;
    }
};

