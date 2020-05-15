// Created by Jaewon Kim on 2020/05/15
// Copyright © 2020 jaewonkim. All rights reserved.

#include "./RedBlackTree.hpp"

int main() {
  Algo::RedBlackTree<int> tree;

  tree.insert(10);
  tree.insert(20);
  // 10
  //  `- 20
  tree.printTree();
  tree.insert(30);
  // 20
  //  |- 10
  //  `- 30
  tree.printTree();
  tree.insert(40);
  tree.insert(50);
  // 20
  //  |- 10
  //  `- 40
  //      |- 30
  //      `- 50
  tree.printTree();
  tree.insert(15);
  tree.insert(18);
  // 20
  //  |- 15
  //  |   |- 10
  //  |   `- 18
  //  `- 40
  //      |- 30
  //      `- 50
  tree.printTree();
  tree.insert(25);
  tree.insert(38);
  tree.insert(28);
  // 30
  //  |- 20
  //  |   |- 15
  //  |   |   |- 10
  //  |   |   `- 18
  //  |   `- 25
  //  |       `- 28
  //  `- 40
  //      |- 38
  //      `- 50
  tree.printTree();

  return 0;
}
