// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

#include <string>
#include <iostream>
#include <fstream>

template <class T>
class BST {
 private:
    struct Node {
        T key;
        int count;
        Node* left, * right;
        explicit Node(T k) : key(k), count(1), left(nullptr), right(nullptr) {}
    } *root;

    Node* insert(Node* p, T k);
    int search(Node* p, T k);
    int depth(Node* p, int h);

 public:
    BST() : root(nullptr) {}
    void insert(T k);
    int search(T k);
    int depth();
};

template <class T>
typename BST<T>::Node* BST<T>::insert(Node* p, T k) {
    if (p == nullptr)
        p = new Node(k);
    else if (p->key > k)
        p->left = insert(p->left, k);
    else if (p->key < k)
        p->right = insert(p->right, k);
    else
        p->count++;
    return p;
}

template <class T>
int BST<T>::search(Node* p, T k) {
    if (p == nullptr)
        return 0;
    else if (p->key == k)
        return p->count;
    else if (p->key < k)
        return search(p->right, k);
    else
        return search(p->left, k);
}

template <class T>
int BST<T>::depth(Node* p, int h) {
    if (p == nullptr)
        return h - 1;
    int hl = depth(p->left, h + 1);
    int hr = depth(p->right, h + 1);
    return hl > hr ? hl : hr;
}

template <class T>
void BST<T>::insert(T k) {
    root = insert(root, k);
}

template <class T>
int BST<T>::search(T k) {
    return search(root, k);
}

template <class T>
int BST<T>::depth() {
    return depth(root, 0);
}

#endif  // INCLUDE_BST_H_
