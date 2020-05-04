// Created by Jaewon Kim on 2020/05/04
// Copyright © 2020 jaewonkim. All rights reserved.

#include <iostream>
#include "./BinarySearchTree.hpp"

using namespace std;

template <typename Key>
class RedBlackTree : public BinarySearchTree<Key> {
public:
    RedBlackTree(const Key& root_key): BinarySearchTree() {
        this->root = new BinaryTreeNode<Key>(root_key);
        this->size = 1;
    }

    void insert(const Key& new_key) {
        // TODO
    }
};

