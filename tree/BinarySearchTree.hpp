// Created by Jaewon Kim on 2020/04/16
// Copyright © 2020 jaewonkim. All rights reserved.

# include <iostream>
# include <stack>
# include <vector>
# include <queue>
# include "./BinaryTree.hpp"

using namespace std;

/**
 * @description
 *  Binary Search Tree Class
 */
template <typename Key>
class BinarySearchTree : public BinaryTree<Key> {
public:
    BinarySearchTree(const Key& key): BinaryTree<Key>(key) {};

    /**
     * @description
     *  inset element
     *  - O(H) Time Complexity by Big-O
     */
    void insert(const Key& new_key) {
        BinaryTreeNode<Key>* cursor = this->root;
        
        while (true) {
            bool isBigger = new_key >= cursor->key;
            BinaryTreeNode<Key>* next = isBigger ? cursor->right : cursor->left;

            if (next) {
                cursor = next;
                continue;
            }

            if (isBigger)
                cursor->right = new BinaryTreeNode<Key>(new_key);
            else
                cursor->left = new BinaryTreeNode<Key>(new_key);
            
            break;
        }

        this->size++;
    }

    /**
     * @description
     *  search element and print trace
     *  - O(H) Time Complexity by Big-O
     */
    void printSearchTrace(const Key& key) {
        BinaryTreeNode<Key> *cursor = this->root;
        vector<Key> order;

        while (cursor) {
            Key current_key = cursor->key;

            order.push_back(current_key);

            if (current_key == key)
                break;

            bool isBigger = key >= current_key;
            cursor = isBigger ? cursor->right : cursor->left;
        }

        BinaryTree<Key>::printTraversalOrder(order, "Search Trace:\t");
    }
};

