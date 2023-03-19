#pragma once

#include <unistd.h>

#include "../../../20-declarations/Iterators/PreOrder/Iterator.hpp"
#include "../../../20-declarations/Iterators/PreOrder/Result.hpp"
#include "../../../20-declarations/Iterators/PreOrder/State.hpp"
#include "../../../20-declarations/Tree.hpp"
#include "../../../20-declarations/TreeNode.hpp"

namespace SAO::BTree::Iterators::PreOrder {

  template <typename T>
  Iterator<T>::Iterator(const Tree<T> &iterable) : SAO::Iterator::Iterator<Tree<T>, State<T>, Result<T>>(iterable) {
    if (iterable.root) {
      this->state.path.push(&iterable.root);
    }
  }

  template <typename T>
  Result<T> Iterator<T>::operator*() {
    return Result<T> {.data = *(*this->state.path.top())->data};
  }

  template <typename T>
  bool Iterator<T>::operator!=(const ssize_t &i) {
    return !this->state.path.empty();
  }

  template <typename T>
  void Iterator<T>::operator++() {
    const std::unique_ptr<TreeNode<T>> *head = this->state.path.top();
    this->state.path.pop();
    if ((*head)->right) {
      this->state.path.push(&(*head)->right);
    }
    if ((*head)->left) {
      this->state.path.push(&(*head)->left);
    }
  }

}
