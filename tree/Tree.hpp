// Created by Jaewon Kim on 2020/05/12
// Copyright © 2020 jaewonkim. All rights reserved.

#ifndef Algo_Tree
#define Algo_Tree

/**
 * type declaration
 */
namespace Algo {
    template <typename Key>
    class TreeNode;
    template <typename Key>
    class Tree;
}

/**
 * @description
 *  Tree node abstract class
 */
template <typename Key>
class Algo::TreeNode {
protected:
    // to handle various tree node with same method
    // Child** children
    void* children;
    int children_count;
    Key key;

public:
    void* getChildrenPtr() {
        return children;
    }

    int getChildrenCount() {
        return children_count;
    }

    Key getKey() {
        return key;
    }
};

/**
 * @description
 *  Tree base class
 *  - for tree printing
 */
template <typename Key>
class Algo::Tree {
protected:
    void* root;    
    int size;

public: 
    Tree():
        root(0),
        size(0) {}

    void* getRootPtr() {
        return root;
    }

    int getSize() {
        return size;
    }
};

#endif /* Algo_Tree */

