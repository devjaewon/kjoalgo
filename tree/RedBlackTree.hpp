// Created by Jaewon Kim on 2020/05/04
// Updated By Jaewon Kim on 2020/05/14
// Copyright © 2020 jaewonkim. All rights reserved.

#ifndef Algo_RedBlackTree
#define Algo_RedBlackTree

#include <iostream>
#include "./BinarySearchTree.hpp"

/**
 * type declaration
 */
namespace Algo {
    template <typename Key>
    class RBTNode;
    template <typename Key>
    class RedBlackTree;
}

/**
 * @description
 *  Red black tree class
 */
template <typename Key>
class Algo::RedBlackTree : public Algo::BinarySearchTree<Key> {
public:
    RedBlackTree() : Algo::BinarySearchTree<Key>() {}

    void insert(const Key& new_key) {
        // TODO
    }
};

#endif /* Algo_RedBlackTree */
