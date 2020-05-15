// Created by Jaewon Kim on 2020/05/12
// Copyright © 2020 jaewonkim. All rights reserved.

#ifndef Algo_Tree
#define Algo_Tree

#include <iostream>
#include <vector>
#include <stack>
#include <string>

/**
 * type declaration
 */
namespace Algo {
    template <typename Key>
    class TreeNode;
    template <typename Key>
    class Tree;
}

/**
 * @description
 *  Tree node abstract class
 */
template <typename Key>
class Algo::TreeNode {
protected:
    // to handle various tree node with same method
    // Child** children
    void* children;
    // array length
    int children_length;
    // real children count
    int children_count;
    Key key;

public:
    void* getChildrenPtr() {
        return children;
    }

    int getChildrenLength() {
        return children_length;
    }

    int getChildrenCount() {
        return children_count;
    }

    Key getKey() {
        return key;
    }
};

/**
 * @description
 *  Tree base class
 *  - for tree printing
 */
template <typename Key>
class Algo::Tree {
    using Node = TreeNode<Key>;
protected:
    void* root;    
    int size;

public: 
    Tree():
        root(0),
        size(0) {}

    void* getRootPtr() {
        return root;
    }

    int getSize() {
        return size;
    }

    void printTree() {
        Node* root_node = (Node*) root;

        if (!root_node) {
            std::cout << "[LOG] no data" << std::endl;
            return;
        }

        std::stack<Node*> trace;
        std::vector<bool> depth_flag;
        int depth = 0;

        trace.push(root_node);

        while (!trace.empty()) {
            Node* parent = trace.top();
            trace.pop();

            if (!parent) {
                depth_flag.pop_back();
                continue;
            } else if (!trace.empty() && !trace.top()) {
                depth_flag[depth_flag.size() - 1] = false;
            }

            Node** children = (Node**) (parent->getChildrenPtr());
            int children_length = parent->getChildrenLength();
            int children_count = parent->getChildrenCount();
            bool is_last = !trace.empty() && !trace.top();

            printTreeLine(parent->getKey(), depth_flag, is_last);

            // to sense last child
            if (children_count > 0) {
                trace.push(0);
                depth_flag.push_back(true);
            }

            for (int i = children_length - 1; i >= 0; --i) {
                parent = children[i];
                if (!parent) continue;
                trace.push(parent);
            }
        }
    }

private:
    void printTreeLine(
        const Key& key,
        const std::vector<bool>& depth_flag,
        const bool& is_last_child
    ) {
        unsigned int depth_size = depth_flag.size();

        std::cout << "  ";

        if (depth_size < 1) {
            std::cout << key << std::endl;
            return;
        }

        for (int i = 0; i < depth_size - 1; ++i) {
            bool flag = depth_flag[i];

            if (flag)
                std::cout << " |  ";
            else
                std::cout << "    ";
        }
        
        if (is_last_child) {
            std::cout << " `- " << key << std::endl;
        } else {
            std::cout << " |- " << key << std::endl;
        }

        return;
    }
};

#endif /* Algo_Tree */

