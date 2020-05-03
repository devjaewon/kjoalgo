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
class AVLTree : public BinarySearchTree<Key> {
public:
    AVLTree(const Key& root_key): BinarySearchTree<Key>() {
        this->root = new BinaryTreeNode<Key>(root_key);
        this->size = 1;
    }

    /**
     * @description
     *  insert new element
     *  - O(logN) Time Complexity by Big-O
     */
    void insert(const Key& new_key) {
        cout << "<Key " << new_key << " Insertion>" << endl;

        vector<BinaryTreeNode<Key>*> trace;
        BinaryTreeNode<Key>* cursor = this->root;
        bool is_left_direction;
        
        trace.reserve(cursor->getHeight());

        while (cursor) {
            is_left_direction = cursor->key > new_key;
            trace.push_back(cursor);
            cursor = is_left_direction ? cursor->left : cursor->right;
        }

        if (is_left_direction)
            trace.back()->left = new BinaryTreeNode<Key>(new_key);
        else
            trace.back()->right = new BinaryTreeNode<Key>(new_key);
        
        this->root = AVLTree<Key>::rebalance(trace);
    }

    /**
     * @description
     *  rebalance total tree height
     *  - use rotation
     */
    static BinaryTreeNode<Key>* rebalance(vector<BinaryTreeNode<Key>*> trace) {
        BinaryTreeNode<Key>* new_root = trace[0];
        int index = trace.size() - 1;

        while (index >= 0) {
            BinaryTreeNode<Key>* parent = trace[index];
            BinaryTreeNode<Key>* new_parent = 0;
            int bf = AVLTree<Key>::getBalanceFactor(parent);

            if (bf > 1) {
                int left_bf = parent->left ? AVLTree<Key>::getBalanceFactor(parent->left) : 0;
                if (left_bf < 0) {
                    parent->left = AVLTree<Key>::rotateLeft(parent->left);
                }
                new_parent = AVLTree<Key>::rotateRight(parent);
            } else if (bf < -1) {
                int right_bf = parent->right ? AVLTree<Key>::getBalanceFactor(parent->right) : 0;
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

    static BinaryTreeNode<Key>* rotateLeft(BinaryTreeNode<Key>* parent) {
        BinaryTreeNode<Key>* new_parent = parent->right;

        parent->right = new_parent->left;
        new_parent->left = parent;

        return new_parent;
    }

    static BinaryTreeNode<Key>* rotateRight(BinaryTreeNode<Key>* parent) {
        BinaryTreeNode<Key>* new_parent = parent->left;
        
        parent->left = new_parent->right;
        new_parent->right = parent;

        return new_parent;
    }

    static int getBalanceFactor(BinaryTreeNode<Key>* node) {
        int left_height = node->left ? node->left->getHeight() : 0;
        int right_height = node->right ? node->right->getHeight() : 0;
 
        return left_height - right_height;
    }
};

