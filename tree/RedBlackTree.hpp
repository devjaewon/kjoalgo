// Created by Jaewon Kim on 2020/05/04
// Updated By Jaewon Kim on 2020/05/15
// Copyright © 2020 jaewonkim. All rights reserved.

#ifndef Algo_RedBlackTree
#define Algo_RedBlackTree

#include <iostream>
#include <vector>
#include "./BinarySearchTree.hpp"

/**
 * type declaration
 */
namespace Algo {
    template <typename Key>
    class RBTNode;
    template <typename Key>
    class RedBlackTree;
}

/**
 * @description
 *  Red black tree node class
 */
template <typename Key>
class Algo::RBTNode : public Algo::BinaryTreeNode<Key> {
    using Node = Algo::RBTNode<Key>;
public:
    enum class Color { RED, BLACK };

private:
    Color color;

public:
    RBTNode() : Algo::BinaryTreeNode<Key>() {}
    RBTNode(const Key& new_key) : Algo::BinaryTreeNode<Key>() {
        this->children = new Node*[2] { 0, 0 };
        this->children_count = 2;
        this->key = new_key;
        color = Color::RED;
    }

    Node* getLeft() {
        return ((Node**) this->children)[0];
    }

    Node* getRight() {
        return ((Node**) this->children)[1];
    }

    Color getColor() {
        return color;
    }

    void setLeft(Node* node_ptr) {
        ((Node**) this->children)[0] = node_ptr;
    }

    void setRight(Node* node_ptr) {
        ((Node**) this->children)[1] = node_ptr;
    }

    void setColor(Color new_color) {
        color = new_color;
    }
};


/**
 * @description
 *  Red black tree class
 */
template <typename Key>
class Algo::RedBlackTree : public Algo::BinarySearchTree<Key> {
    using Node = Algo::RBTNode<Key>;
    using Tree = Algo::RedBlackTree<Key>;
public:
    RedBlackTree() : Algo::BinarySearchTree<Key>() {}

    /**
     * @description
     *  insert new element
     *  - O(logN) Time Complexity by Big-O
     */
    void insert(const Key& new_key) {
        std::cout << "[LOG] Key " << new_key << " Insertion" << std::endl;

        Node* new_node = new Node{ new_key };
        std::vector<Node*> trace;

        if (!this->root) {
            this->root = new_node;
            trace.push_back(new_node);
        } else {
            Node* cursor = (Node*) this->root;
            bool to_left;

            while (cursor) {
                to_left = cursor->getKey() > new_key;
                trace.push_back(cursor);
                cursor = to_left ? cursor->getLeft() : cursor->getRight();
            }

            Node* parent = trace.back();

            trace.push_back(new_node);
            if (to_left) parent->setLeft(new_node);
            else parent->setRight(new_node);
        }

        this->root = Tree::rebalance(trace);
    }

    /**
     * @description
     *  rebalance tree height
     *  - recoloring
     *  - rotation
     */
    static Node* rebalance(std:: vector<Node*> trace) {
        unsigned int trace_size = trace.size();

        // execption handling
        if (trace_size < 1)
            return 0;

        Node* root = trace[0];
        Node* current;
        Node* parent;
        Node* grand_parent;
        Node* uncle;
        int cursor = trace_size - 1;

        while (cursor >= 0) {
            current = trace[cursor];

            // 1. current is root
            if (cursor == 0) {
                current->setColor(Node::Color::BLACK);
                return current;
            }

            parent = trace[cursor - 1];
            
            // 2. skip when parent color is black
            if (parent->getColor() == Node::Color::BLACK) {
                return root;
            }

            grand_parent = trace[cursor - 2];
            uncle = (
                parent == grand_parent->getLeft()
                ? grand_parent->getRight()
                : grand_parent->getLeft()
            );

            // 3. recoloring and rotation by uncle's color
            if (!uncle || uncle->getColor() == Node::Color::BLACK) {
                // 3-1. rotate and recolor
                bool is_root = cursor == 2;
                bool is_left = !is_root && (trace[cursor - 3]->getLeft() == grand_parent);

                Node* new_root = Tree::rotate(current, parent, grand_parent);
                
                if (is_root)
                    root = new_root;
                else if (is_left)
                    trace[cursor - 3]->setLeft(new_root);
                else
                    trace[cursor - 3]->setRight(new_root);

                return root;
            } else {
                // 3-2. only recolor
                parent->setColor(Node::Color::BLACK);
                uncle->setColor(Node::Color::BLACK);
                grand_parent->setColor(Node::Color::RED);
                cursor -= 2;
            }
        }

        return root;
    }

    /**
     * @description
     *  rotate and recolor process
     */
    static Node* rotate(Node* current, Node* parent, Node* grand_parent) {
        Node* new_parent = grand_parent;

        if (parent == grand_parent->getLeft()) {
            if (current == parent->getRight()) {
                grand_parent->setLeft(Tree::rotateLeft(parent));
            }

            typename Node::Color color_g = grand_parent->getColor();
            typename Node::Color color_p = grand_parent->getLeft()->getColor();

            new_parent = Tree::rotateRight(grand_parent);
            new_parent->setColor(color_g);
            new_parent->getRight()->setColor(color_p);
        } else if (parent == grand_parent->getRight()) {
            if (current == parent->getLeft()) {
                grand_parent->setRight(Tree::rotateRight(parent));
            }

            typename Node::Color color_g = grand_parent->getColor();
            typename Node::Color color_p = grand_parent->getRight()->getColor();

            new_parent = Tree::rotateLeft(grand_parent);
            new_parent->setColor(color_g);
            new_parent->getLeft()->setColor(color_p);
        }

        return new_parent;
    }

    /**
     * @description
     *  single rotation
     */
    static Node* rotateLeft(Node* parent) {
        Node* new_parent = parent->getRight();

        parent->setRight(new_parent->getLeft());
        new_parent->setLeft(parent);

        return new_parent;
    }

    static Node* rotateRight(Node* parent) {
        Node* new_parent = parent->getLeft();
        
        parent->setLeft(new_parent->getRight());
        new_parent->setRight(parent);

        return new_parent;
    }
};

#endif /* Algo_RedBlackTree */
