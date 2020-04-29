// Created by Jaewon Kim on 2020/04/29
// Copyright © 2020 jaewonkim. All rights reserved.

#include "./BinaryTree.hpp"
#include "./BinarySearchTree.hpp"

int main() {
    BinarySearchTree<int> tree = BinarySearchTree<int>{ 30 };

    //             30
    //       25          40
    //     15          35
    //   10  17      33
    //             32
    tree.insert(25);
    tree.insert(15);
    tree.insert(17);
    tree.insert(10);
    tree.insert(40);
    tree.insert(35);
    tree.insert(33);
    tree.insert(32);

    // InOrder Traversal: 10 > 15 > 17 > 25 > 30 > 32 > 33 > 35 > 40
    tree.printPathByInOrder();
    // Search Trace: 30 > 25 > 15 > 17
    tree.printSearchTrace(17);

    return 0;
}

