// Created by Jaewon Kim on 2020/04/15
// Copyright © 2020 jaewonkim. All rights reserved.

# include <iostream>
# include <stack>
# include <vector>
# include <queue>

using namespace std;

void printOrderedVector(vector<int> ordered_vector);

template <typename Data>
class BinaryTreeNode {
// 예제 트리의 간편한 초기화를 위한 멤버 public 화
public:
    Data _data;
    BinaryTreeNode* _left;
    BinaryTreeNode* _right;

public:
    BinaryTreeNode(const Data& data) {
        _data = data;
        _left = 0;
        _right = 0;
    }
};

template <typename Data>
class BinaryTree {
// 예제 트리의 간편한 초기화를 위한 멤버 public 화
public:
    BinaryTreeNode<Data>* _root;
    unsigned int _size;

public:
    BinaryTree(const Data& rootData) {
        _root = new BinaryTreeNode<Data>(rootData);
        _size = 1;
    }

    // O(N) Time Complexity using Big-O
    void insert(const Data& newData) {
        queue<BinaryTreeNode<Data>*> history_queue;

        history_queue.push(_root);

        while (!history_queue.empty()) {
            BinaryTreeNode<Data>* node = history_queue.front();
            
            history_queue.pop();
            
            if (!node->_left) {
                node->_left = new BinaryTreeNode<Data>(newData);
                _size++;
                break;
            } else {
                history_queue.push(node->_left);
            }

            if (!node->_right) {
                node->_right = new BinaryTreeNode<Data>(newData);
                _size++;
                break;
            } else {
                history_queue.push(node->_right);
            }
        }
    }

    // left > root > right
    // O(N) Time Complexity using Big-O
    void printPathByInorderDFS() {
        stack<BinaryTreeNode<Data>*> history_stack;
        vector<Data> order;
        BinaryTreeNode<Data>* cursor = _root;

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

        cout << "InorderDFS:\t";
        printOrderedVector(order);
        cout << endl;
    }

    // root > left > right
    // O(N) Time Complexity using Big-O
    void printPathByPreorderDFS() {
        stack<BinaryTreeNode<Data>*> history_stack;
        vector<Data> order;
        BinaryTreeNode<Data>* cursor = _root;

        while (cursor) {
            while (cursor) {
                order.push_back(cursor->_data);
                if (cursor->_right) 
                    history_stack.push(cursor->_right);
                cursor = cursor->_left;
            }

            if (!history_stack.empty()) {
                cursor = history_stack.top();
                history_stack.pop();
            }
        }

        cout << "PreorderDFS:\t";
        printOrderedVector(order);
        cout << endl;
    }

    // left > right > root
    void printPathByPostorderDFS() {
        stack<BinaryTreeNode<Data>*> history_stack;
        vector<Data> order;
        BinaryTreeNode<Data>* cursor = _root;

        do {
           while (cursor) {
                if (cursor->_right) {
                    history_stack.push(cursor->_right);
                }
                history_stack.push(cursor);
                cursor = cursor->_left;
            }

            cursor = history_stack.top();
            history_stack.pop();  

            if (!cursor) continue;

            if (
                cursor->_right
                && history_stack.size() > 0
                && history_stack.top() == cursor->_right
            ) {
                history_stack.pop();
                history_stack.push(cursor);
                cursor = cursor->_right;
            } else {
                order.push_back(cursor->_data); 
                cursor = 0;
            }
        } while (!history_stack.empty());

        cout << "PostorderDFS:\t";
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
    tree._root->_left = new BinaryTreeNode<int>(2);
    tree._root->_left->_left = new BinaryTreeNode<int>(3);
    tree._root->_left->_left->_left = new BinaryTreeNode<int>(4);
    tree._root->_right = new BinaryTreeNode<int>(5);
    tree._root->_right->_left = new BinaryTreeNode<int>(6);
    tree._root->_right->_right = new BinaryTreeNode<int>(7);
    
    // inorder traversal:  4 > 3 > 2 > 1 > 6 > 5 > 7
    tree.printPathByInorderDFS();
    // preorder traversal: 1 > 2 > 3 > 4 > 5 > 6 > 7
    tree.printPathByPreorderDFS();
    // postorder traversal: 4 > 3 > 2 > 6 > 7 > 5 > 1
    tree.printPathByPostorderDFS();
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

