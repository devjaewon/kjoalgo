// Created by Jaewon Kim on 2020/04/16
// Copyright © 2020 jaewonkim. All rights reserved.

# include <iostream>
# include <stack>
# include <vector>
# include <queue>

using namespace std;

template <typename Data>
class BinarySearchTree;

template <typename Data>
class BSTNode {
    friend class BinarySearchTree<Data>;
public:
    Data _data;
    BSTNode* _left;
    BSTNode* _right;

public:
    BSTNode(const Data& data) {
        _data = data;
        _left = 0;
        _right = 0;
    }
};

template <typename Data>
class BinarySearchTree {
public:
    BSTNode<Data>* _root;
    int size;

public:
    BinarySearchTree(const Data& rootData) {
        _root = new BSTNode<Data>(rootData);
        size = 1;
    }

    // O(H) Time Complexity using Big-O
    void insert(const Data& data) {
        BSTNode<Data>* cursor = _root;
        
        while (true) {
            bool isBigger = data >= cursor->_data;
            BSTNode<Data>* next = isBigger ? cursor->_right : cursor->_left;

            if (next) {
                cursor = next;
                continue;
            }

            if (isBigger)
                cursor->_right = new BSTNode<Data>(data);
            else
                cursor->_left = new BSTNode<Data>(data);
            
            break;
        }

        size++;
    }

    // O(H) Time Complexity using Big-O
    void searchAndPrintPath(const Data& data) {
        BSTNode<Data> *cursor = _root;
        vector<Data> paths;

        while (cursor) {
            Data currentData = cursor->_data;

            paths.push_back(currentData);
            if (currentData == data)
                break;

            bool isBigger = data >= currentData;
            cursor = isBigger ? cursor->_right : cursor->_left;
        }

        unsigned int pathsSize = paths.size();

        cout << "Search Path of " << data << ": ";

        for (unsigned int i = 0; i < pathsSize; ++i) {
            if (pathsSize - 1 > i)
                cout << paths[i] << " > ";
            else 
                cout << paths[i] << endl;
        }
    }
};

int main() {
    BinarySearchTree<int> tree = BinarySearchTree<int>{ 30 };

    //           30
    //    10            45
    // 5     25     35       60
    tree.insert(10);
    tree.insert(45);
    tree.insert(25);
    tree.insert(5);
    tree.insert(60);
    tree.insert(35);
   
    // 30 > 45 > 35 
    tree.searchAndPrintPath(35);
    // 30 > 10 > 5
    tree.searchAndPrintPath(5);
    // 30 > 10 > 25
    tree.searchAndPrintPath(25);
    
    return 0;
}

