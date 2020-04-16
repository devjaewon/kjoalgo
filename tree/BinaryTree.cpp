// Created by Jaewon Kim on 2020/04/15
// Copyright © 2020 jaewonkim. All rights reserved.

# include <iostream>
# include <stack>
# include <vector>
# include <queue>

using namespace std;

void printOrderedVector(vector<int> ordered_vector);

template <typename Data>
class Node {
// 예제 트리의 간편한 초기화를 위한 멤버 public 화
public:
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
class BinaryTree {
// 예제 트리의 간편한 초기화를 위한 멤버 public 화
public:
    Node<Data> *_root;
    unsigned int _size;

public:
    BinaryTree(const Data& rootData) {
        _root = new Node<Data>(rootData);
        _size = 1;
    }

    void insert(const Data& newData) {
        queue<Node<Data>*> history_queue;

        history_queue.push(_root);

        while (!history_queue.empty()) {
            Node<Data>* node = history_queue.front();
            
            history_queue.pop();
            
            if (!node->_left) {
                node->_left = new Node<Data>(newData);
                _size++;
                break;
            } else {
                history_queue.push(node->_left);
            }

            if (!node->_right) {
                node->_right = new Node<Data>(newData);
                _size++;
                break;
            } else {
                history_queue.push(node->_right);
            }
        }
    }

    void printPathByInorderDFS() {
        stack<Node<Data>*> history_stack;
        Node<Data>* cursor = _root;
        vector<Data> order = {};

        while (cursor || !history_stack.empty()) {
            while (cursor) {
                history_stack.push(cursor);
                cursor = cursor->_left;
            }
            
            cursor = history_stack.top();
            history_stack.pop();
            order.push_back(cursor->_data);
            cursor = cursor->_right;
        }

        printOrderedVector(order);
        cout << endl;
    }
};

int main() {
    BinaryTree<int> tree = BinaryTree<int>{ 1 };
    
    //       1
    //     2   5
    //    3   6  7
    //   4
    tree._root->_left = new Node<int>(2);
    tree._root->_left->_left = new Node<int>(3);
    tree._root->_left->_left->_left = new Node<int>(4);
    tree._root->_right = new Node<int>(5);
    tree._root->_right->_left = new Node<int>(6);
    tree._root->_right->_right = new Node<int>(7);
    
    // inorder traversal:  4 > 3 > 2 > 1 > 6 > 5 > 7
    tree.printPathByInorderDFS();
    // insert and inorder traversal: 4 > 3 > 2 > 8 > 1 > 6 > 5 > 7 
    tree.insert(8);
    tree.printPathByInorderDFS();
}

void printOrderedVector(vector<int> ordered_vector) {
    unsigned int size = ordered_vector.size();

    for (unsigned int i = 0; i < size; ++i) {
        cout << ordered_vector[i];
        if (i < size - 1) cout << " > ";
    }
}

