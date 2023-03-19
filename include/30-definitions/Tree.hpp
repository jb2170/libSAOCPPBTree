#pragma once

#include <memory>
#include <vector>
#include <iostream>

#include "../20-declarations/Tree.hpp"
#include "../20-declarations/TreeNode.hpp"

namespace SAO::BTree {

  template <typename T>
  Tree<T>::Tree() : root() {}

  template <typename T>
  size_t Tree<T>::depth() {
    return TreeNode<T>::depth(root);
  }

  template <typename T>
  void Tree<T>::print(std::ostream &os) {
    TreeNode<T>::print(root, 0, os);
  }

  template <typename T>
  void Tree<T>::add(std::unique_ptr<T> data) {
    TreeNode<T>::add(root, std::move(data));
  }

  template <typename T>
  std::unique_ptr<T> Tree<T>::remove(const T &data) {
    return TreeNode<T>::remove(root, data);
  }

  template <typename T>
  void Tree<T>::invert() {
    TreeNode<T>::invert(root);
  }

  template <typename T>
  SAO::Iterator::IteratorFactory<Tree<T>, Iterators::PreOrder::Iterator<T>> Tree<T>::iter_pre_order() {
    return SAO::Iterator::IteratorFactory<Tree<T>, Iterators::PreOrder::Iterator<T>>(*this);
  }

}
