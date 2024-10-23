#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <vector>
#pragma once

template <typename T>
class BinaryTree
{
    protected:
        _depth
    private:
        std::vector<std::vector<T>> _tree;
    public:
        void setDepth(int );
        void setNode(int, int, T);
        T getNode(int, int);
        void display();
        BinaryTree();
        ~BinaryTree();
};

#endif