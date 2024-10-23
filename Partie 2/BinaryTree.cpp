#include "BinaryTree.h"
#include <stdexcept>
template <typename T>
void BinaryTree<T>::setDepth(int N) {
    if (N<0){
        throw std::invalid_argument("ERROR : Depht ",N," value is negative.");
    }
    _depth = N;
    _tree.resize(N+1); 
    for (int i = 0; i <= N; ++i) {
        _tree[i].resize(i + 1); 
    }
}
template <typename T>
void BinaryTree<T>::setNode(int step, int node, T value) {
    if (step < 0 || step > _depth) {
        throw std::out_of_range("Error : step ",step," out of range.");
    }
    if (node < 0 || node >= _tree[step].size()) {
        throw std::out_of_range("Erreur : node ",node," out of range.");
    }
    _tree[step][node] = value;
}

template <typename T>
T BinaryTree<T>:: getNode(int step, int node){
    if (step < 0 || step > _depth) {
        throw std::out_of_range("Error : step ",step," out of range.");
    }
    if (node < 0 || node >= _tree[step].size()) {
        throw std::out_of_range("Erreur : node ",node," out of range.");
    }
    return _tree[step][node];
}
template <typename T>
BinaryTree<T>::~BinaryTree()
{

}
template<typename T>
void BinaryTree<T>:: display(){};