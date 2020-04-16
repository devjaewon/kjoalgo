// Created by Jaewon Kim on 2020/04/15
// Copyright © 2020 jaewonkim. All rights reserved.

# include <iostream>
# include <stack>
# include <vector>
# include <queue>

using namespace std;

template <typename Data>
class BinarySearchTree;

template <typename Data>
class Node {
    friend class BinarySearchTree<Data>;
private:
    Data _data;
    Node *_left;
    Node *_right;

public:
    Node(const Data& data) {
        _data = data;
        _left = 0;
        _right = 0;
    }
};

template <typename Data>
class BinarySearchTree {
private:
    Node<Data> *_root;
    int size;

public:
    BinarySearchTree(const Data& rootData) {
        _root = new Node<Data>(rootData);
        size = 1;
    }

    // O(logN) Time Complexity using Big-O
    void insert(const Data& data) {
        Node<Data> *cursor = _root;
        
        while (true) {
            bool isBigger = cursor->_data >= data;
            Node<Data> *next = isBigger ? cursor->_right : cursor->_left;

            if (next) {
                cursor = next;
                continue;
            }

            if (isBigger)
                cursor->_right = new Node<Data>(data);
            else
                cursor->_left = new Node<Data>(data);
            
            break;
        }

        size++;
    }
};

int main() {
    BinarySearchTree<int> tree = BinarySearchTree<int>{ 30 };

    tree.insert(10);
    tree.insert(45);
    tree.insert(25);
    tree.insert(5);
    tree.insert(60);
    tree.insert(35);
    
    return 0;
}

