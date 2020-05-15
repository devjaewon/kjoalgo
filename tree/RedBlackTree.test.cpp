// Created by Jaewon Kim on 2020/05/15
// Copyright © 2020 jaewonkim. All rights reserved.

#include "./RedBlackTree.hpp"

int main() {
  Algo::RedBlackTree<int> tree;

  tree.insert(10);
  tree.insert(20);
  tree.insert(30);
  tree.insert(40);
  tree.insert(50);
  tree.insert(18);
  tree.insert(25);
  tree.insert(38);
  tree.insert(28);

  return 0;
}
