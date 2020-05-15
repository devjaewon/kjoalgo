// Created by Jaewon Kim on 2020/04/29
// Updated By Jaewon Kim on 2020/05/14
// Copyright © 2020 jaewonkim. All rights reserved.

#include "./BinaryTree.hpp"

int main() {
    Algo::BinaryTree<int> tree;

    tree.insert(1);
    tree.insert(2);
    tree.insert(3);
    tree.insert(4);
    tree.insert(5);
    tree.insert(6);
    tree.insert(7);
    tree.insert(8);

    // 1
    // |- 2
    // |   |- 4
    // |   |  `- 8
    // |   `-5
    // `- 3
    //     |- 6
    //     `- 7
    tree.printTree();
    // InOrder Traversal:  8 > 4 > 2 > 5 > 1 > 6 > 3 > 7
    tree.printPathByInOrder();
    // PreOrder Traversal: 1 > 2 > 4 > 8 > 5 > 3 > 6 > 7
    tree.printPathByPreOrder();
    // PostOrder Traversal: 8 > 4 > 5 > 2 > 6 > 7 > 3 > 1
    tree.printPathByPostOrder();

    return 0;
}

