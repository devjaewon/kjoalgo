// Created by Jaewon Kim on 2020/04/16
// Updated By Jaewon Kim on 2020/05/14
// Copyright © 2020 jaewonkim. All rights reserved.

#ifndef Algo_BinarySearchTree
#define Algo_BinarySearchTree

#include <iostream>
#include <vector>
#include "./BinaryTree.hpp"

/**
 * type declaration
 */
namespace Algo {
    template <typename Key>
    class BinarySearchTree;
}

/**
 * @description
 *  Binary search tree class
 */
template <typename Key>
class Algo::BinarySearchTree : public Algo::BinaryTree<Key> {
    using Node = Algo::BinaryTreeNode<Key>;
public:
    BinarySearchTree() : Algo::BinaryTree<Key>() {}

    /**
     * @description
     *  inset element
     *  - O(H) Time Complexity by Big-O
     */
    void insert(const Key& new_key) {
        std::cout << "[LOG] Key " << new_key << " Insertion" << std::endl;
    
        if (!this->root) {
            this->root = new Node{ new_key };
            return;
        }

        Node* cursor = (Node*) this->root;
        
        while (true) {
            bool isBigger = new_key >= cursor->getKey();
            Node* next = isBigger ? cursor->getRight() : cursor->getLeft();

            if (next) {
                cursor = next;
                continue;
            }

            if (isBigger)
                cursor->setRight(new Node { new_key });
            else
                cursor->setLeft(new Node { new_key });
            
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
        Node* cursor = (Node*) this->root;
        std::vector<Key> order;

        while (cursor) {
            Key current_key = cursor->getKey();

            order.push_back(current_key);

            if (current_key == key)
                break;

            bool isBigger = key >= current_key;
            cursor = isBigger ? cursor->getRight() : cursor->getLeft();
        }

        Algo::BinaryTree<Key>::printTraversalOrder(order, "Search Trace:\t");
    }
};

#endif /* Algo_BinarySearchTree */
