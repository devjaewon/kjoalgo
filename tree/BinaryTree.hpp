// Created by Jaewon Kim on 2020/04/15
// Updated By Jaewon Kim on 2020/05/14
// Copyright © 2020 jaewonkim. All rights reserved.

#ifndef Algo_BinaryTree
#define Algo_BinaryTree

#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include "./Tree.hpp"

/**
 * type declaration
 */
namespace Algo {
    template <typename Key>
    class BinaryTreeNode;
    template <typename Key>
    class BinaryTree;
}

/**
 * @description
 *  Binary Tree Node Class
 */
template <typename Key>
class Algo::BinaryTreeNode : public Algo::TreeNode<Key> {
    using Node = Algo::BinaryTreeNode<Key>;
public:
    BinaryTreeNode() : Algo::TreeNode<Key>() {}
    BinaryTreeNode(const Key& new_key) : Algo::TreeNode<Key>() {
        this->children = new Node*[2] { 0, 0 };
        this->children_count = 2;
        this->key = new_key;
    }

    /**
     * @description
     *  getter, setter
     */
    Node* getLeft() {
        return ((Node**) this->children)[0];
    }

    Node* getRight() {
        return ((Node**) this->children)[1];
    }

    void setLeft(Node* node_ptr) {
        ((Node**) this->children)[0] = node_ptr;
    }

    void setRight(Node* node_ptr) {
        ((Node**) this->children)[1] = node_ptr;
    }
};

/**
 * @description
 *  Binary Tree Class
 */
template <typename Key>
class Algo::BinaryTree : public Algo::Tree<Key> {
    using Node = Algo::BinaryTreeNode<Key>;
public:
    BinaryTree() : Algo::Tree<Key>() {}

    /**
     * @description
     *  - iterative implementation using queue
     *  - O(N) Time Complexity by Big-O
     */
    void insert(const Key& new_key) {
        std::cout << "[LOG] Key " << new_key << " Insertion" << std::endl;

        if (!this->root) {
            this->root = new Node{ new_key };
            return;
        }

        std::queue<Node*> trace_queue;

        trace_queue.push((Node*) this->root);

        while (!trace_queue.empty()) {
            Node* node = trace_queue.front();
            Node* left = node->getLeft();
            Node* right = node->getRight();

            trace_queue.pop();
            
            if (!left) {
                node->setLeft(new Node{ new_key });
                this->size++;
                break;
            } else {
                trace_queue.push(left);
            }

            if (!right) {
                node->setRight(new Node{ new_key });
                this->size++;
                break;
            } else {
                trace_queue.push(right);
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
        std::stack<Node*> trace_stack;
        std::vector<Key> order;
        Node* cursor = (Node*) this->root;
        
        while (cursor || !trace_stack.empty()) {
            while (cursor) {
                trace_stack.push(cursor);
                cursor = cursor->getLeft();
            }
            
            cursor = trace_stack.top();
            trace_stack.pop();
            order.push_back(cursor->getKey());
            cursor = cursor->getRight();
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
        std::stack<Node*> trace_stack;
        std::vector<Key> order;
        Node* cursor = (Node*) this->root;

        while (cursor) {
            while (cursor) {
                Node* left = cursor->getLeft();
                Node* right = cursor->getRight();

                order.push_back(cursor->getKey());
                if (right) 
                    trace_stack.push(right);
                cursor = left;
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
        std::stack<Node*> trace_stack;
        std::vector<Key> order;
        Node* cursor = (Node*) this->root;

        do {
           while (cursor) {
               Node* left = cursor->getLeft();
               Node* right = cursor->getRight();

                if (right)
                    trace_stack.push(right);
                trace_stack.push(cursor);
                cursor = left;
            }

            cursor = trace_stack.top();
            trace_stack.pop();  

            if (cursor) {
                Node* right = cursor->getRight();

                if (
                    right
                    && trace_stack.size() > 0
                    && trace_stack.top() == right
                ) {
                    trace_stack.pop();
                    trace_stack.push(cursor);
                    cursor = right;
                } else {
                    order.push_back(cursor->getKey()); 
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
    static void printTraversalOrder(const std::vector<Key>& order, const std::string& prefix) {
        unsigned int size = order.size();

        std::cout << prefix << std::endl;
        for (unsigned int i = 0; i < size; ++i) {
            std::cout << order[i];
            if (i < size - 1)
                std::cout << " > ";
        }
        std::cout << std::endl;
    }
};

#endif /* Algo_BinaryTree */
