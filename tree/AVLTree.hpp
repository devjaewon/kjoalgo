// Created by Jaewon Kim on 2020/04/27
// Updated By Jaewon Kim on 2020/05/14
// Copyright © 2020 jaewonkim. All rights reserved.

#ifndef Algo_AVLTree
#define Algo_AVLTree

#include <iostream>
#include <vector>
#include "./BinarySearchTree.hpp"

/**
 * type declaration
 */
namespace Algo {
    template <typename Key>
    class AVLTreeNode;
    template <typename Key>
    class AVLTree;
}

/**
 * @description
 *  AVL tree node class
 */
template <typename Key>
class Algo::AVLTreeNode : public Algo::BinaryTreeNode<Key> {
    using Node = Algo::AVLTreeNode<Key>;
public:
    AVLTreeNode() : Algo::BinaryTreeNode<Key>() {}
    AVLTreeNode(const Key& new_key) : Algo::BinaryTreeNode<Key>() {
        this->children = new Node*[2] { 0, 0 };
        this->children_count = 2;
        this->key = new_key;
    }

    Node* getLeft() {
        return ((Node**) this->children)[0];
    }

    Node* getRight() {
        return ((Node**) this->children)[1];
    }

    void setLeft(Node* node_ptr) {
        ((Node**) this->children)[0] = node_ptr;
    }

    void setRight(Node* node_ptr) {
        ((Node**) this->children)[1] = node_ptr;
    }

    int getHeight() {
        Node** children = (Node**) this->children;
        Node* left = children[0];
        Node* right = children[1];

        int left_height = left ? left->getHeight() : 0;
        int right_height = right ? right->getHeight() : 0;

        return left_height > right_height ? left_height + 1 : right_height + 1;
    }

    int getBalanceFactor() {
        Node** children = (Node**) this->children;
        Node* left = children[0];
        Node* right = children[1];

        int left_height = left ? left->getHeight() : 0;
        int right_height = right ? right->getHeight() : 0;
 
        return left_height - right_height;
    }
};

/**
 * @description
 *  AVL tree class
 */
template <typename Key>
class Algo::AVLTree : public Algo::BinarySearchTree<Key> {
    using Node = Algo::AVLTreeNode<Key>;
    using Tree = Algo::AVLTree<Key>;
public:
    AVLTree() : Algo::BinarySearchTree<Key>() {}

    /**
     * @description
     *  insert new element
     *  - O(logN) Time Complexity by Big-O
     */
    void insert(const Key& new_key) {
        std::cout << "[LOG] Key " << new_key << " Insertion" << std::endl;

        if (!this->root) {
            this->root = new Node{ new_key };
            return;
        }

        std::vector<Node*> trace;
        Node* cursor = (Node*) this->root;
        bool to_left;
        
        trace.reserve(cursor->getHeight());

        while (cursor) {
            to_left = cursor->getKey() > new_key;
            trace.push_back(cursor);
            cursor = to_left ? cursor->getLeft() : cursor->getRight();
        }

        Node* leaf_node = trace.back();
        Node* new_node = new Node{ new_key };

        if (to_left)
            leaf_node->setLeft(new_node);
        else
            leaf_node->setRight(new_node);
        
        this->root = Tree::rebalance(trace);
    }

    /**
     * @description
     *  rebalance total tree height
     *  - use rotation
     */
    static Node* rebalance(std::vector<Node*> trace) {
        Node* new_root = trace[0];
        int index = trace.size() - 1;

        while (index >= 0) {
            Node* parent = trace[index];
            Node* new_parent = 0;
            int bf = parent->getBalanceFactor();

            if (bf > 1) {
                Node* left = parent->getLeft();
                int left_bf = left ? left->getBalanceFactor() : 0;
                
                if (left_bf < 0) {
                    parent->setLeft(Tree::rotateLeft(left));
                }
                new_parent = Tree::rotateRight(parent);
            } else if (bf < -1) {
                Node* right = parent->getRight();
                int right_bf = right ? right->getBalanceFactor() : 0;

                if (right_bf > 0) {
                    parent->setRight(Tree::rotateRight(right));
                }
                new_parent = Tree::rotateLeft(parent);
            }

            if (new_parent) {
                std::cout << "[ALERT] Rebalance!" << std::endl;
                if (index == 0) {
                    new_root = new_parent;
                } else if (trace[index-1]->getLeft() == parent) {
                    trace[index-1]->setLeft(new_parent);
                } else if (trace[index-1]->getRight() == parent) {
                    trace[index-1]->setRight(new_parent);
                }
            }

            index--;
        }

        return new_root;
    };

    /**
     * @description
     *  left single rotation
     */
    static Node* rotateLeft(Node* parent) {
        Node* new_parent = parent->getRight();

        parent->setRight(new_parent->getLeft());
        new_parent->setLeft(parent);

        return new_parent;
    }

    /**
     * @description
     *  right single rotation
     */
    static Node* rotateRight(Node* parent) {
        Node* new_parent = parent->getLeft();
        
        parent->setLeft(new_parent->getRight());
        new_parent->setRight(parent);

        return new_parent;
    }
};

#endif /* Algo_AVLTree */
