// Created by Jaewon Kim on 2020/05/02
// Updated By Jaewon Kim on 2020/05/14
// Copyright © 2020 jaewonkim. All rights reserved.

#include "./AVLTree.hpp"

int main() {
    Algo::AVLTree<int> tree;
    tree.insert(30);
    tree.insert(10);
    tree.insert(45);
    tree.insert(5);
    tree.printPathByInOrder();
    tree.insert(2);
    tree.printPathByInOrder();
    tree.insert(25);
    tree.printPathByInOrder();
    tree.insert(26);
    tree.insert(27);
    tree.printPathByInOrder();

    return 0;
}

