// Created by Jaewon Kim on 2020/04/15
// Copyright © 2020 jaewonkim. All rights reserved.

#ifndef AlgoBinaryTree
#define AlgoBinaryTree

# include <iostream>
# include <stack>
# include <vector>
# include <queue>

using namespace std;

template <typename Key>
class BinaryTree;

/**
 * @description
 *  Binary Tree Node Class
 */
template <typename Key>
class BinaryTreeNode {
    friend class BinaryTree<Key>;
protected:
    BinaryTreeNode<Key>* left;
    BinaryTreeNode<Key>* right;
    Key key;

public:
    BinaryTreeNode(const Key& initial_key) {
        left = 0;
        right = 0;
        key = initial_key;
    }
};

/**
 * @description
 *  Binary Tree Class
 */
template <typename Key>
class BinaryTree {
protected:
    BinaryTreeNode<Key>* root;
    unsigned int size;

public:
    BinaryTree(const Key& root_key) {
        root = new BinaryTreeNode<Key>(root_key);
        size = 1;
    }

    /**
     * @description
     *  - iterative implementation using queue
     *  - O(N) Time Complexity by Big-O
     */
    void insert(const Key& new_key) {
        queue<BinaryTreeNode<Key>*> trace_queue;

        trace_queue.push(root);

        while (!trace_queue.empty()) {
            BinaryTreeNode<Key>* node = trace_queue.front();
            
            trace_queue.pop();
            
            if (!node->left) {
                node->left = new BinaryTreeNode<Key>(new_key);
                size++;
                break;
            } else {
                trace_queue.push(node->left);
            }

            if (!node->right) {
                node->right = new BinaryTreeNode<Key>(new_key);
                size++;
                break;
            } else {
                trace_queue.push(node->right);
            }
        }
    }

    /**
     * @description
     *  in-order traversal: left > root > right
     *  - iterative implementation using stack
     *  - O(N) Time Complexity by Big-O
     */
    void printPathByInOrder() {
        stack<BinaryTreeNode<Key>*> trace_stack;
        BinaryTreeNode<Key>* cursor = root;
        vector<Key> order;
        
        while (cursor || !trace_stack.empty()) {
            while (cursor) {
                trace_stack.push(cursor);
                cursor = cursor->left;
            }
            
            cursor = trace_stack.top();
            trace_stack.pop();
            order.push_back(cursor->key);
            cursor = cursor->right;
        }
        
        BinaryTree<Key>::printTraversalOrder(order, "InOrder Traversal:\t");
    }

    /**
     * @description
     *  pre-order traversal: root > left > right
     *  - iterative implementation using stack
     *  - O(N) Time Complexity by Big-O
     */
    void printPathByPreOrder() {
        stack<BinaryTreeNode<Key>*> trace_stack;
        BinaryTreeNode<Key>* cursor = root;
        vector<Key> order;

        while (cursor) {
            while (cursor) {
                order.push_back(cursor->key);
                if (cursor->right) 
                    trace_stack.push(cursor->right);
                cursor = cursor->left;
            }

            if (!trace_stack.empty()) {
                cursor = trace_stack.top();
                trace_stack.pop();
            }
        }

        BinaryTree<Key>::printTraversalOrder(order, "PreOrder Traversal:\t");
    }

    /**
     * @description
     *  post-order traversal: left > right > root
     *  - iterative implementation using stack
     *  - O(N) Time Complexity by Big-O
     */
    void printPathByPostOrder() {
        stack<BinaryTreeNode<Key>*> trace_stack;
        BinaryTreeNode<Key>* cursor = root;
        vector<Key> order;

        do {
           while (cursor) {
                if (cursor->right) {
                    trace_stack.push(cursor->right);
                }
                trace_stack.push(cursor);
                cursor = cursor->left;
            }

            cursor = trace_stack.top();
            trace_stack.pop();  

            if (cursor) {
                if (
                    cursor->right
                    && trace_stack.size() > 0
                    && trace_stack.top() == cursor->right
                ) {
                    trace_stack.pop();
                    trace_stack.push(cursor);
                    cursor = cursor->right;
                } else {
                    order.push_back(cursor->key); 
                    cursor = 0;
                }
            }
        } while (!trace_stack.empty());
        

        BinaryTree<Key>::printTraversalOrder(order, "PostOrder Traversal:\t");
    }

    /**
     * @description
     *  print order vector after format
     */
    static void printTraversalOrder(const vector<Key>& order, const string& prefix) {
        unsigned int size = order.size();

        cout << prefix << endl;
        for (unsigned int i = 0; i < size; ++i) {
            cout << order[i];
            if (i < size - 1)
                cout << " > ";
        }
        cout << endl;
    }
};

#endif /* AlgoBinaryTree */

