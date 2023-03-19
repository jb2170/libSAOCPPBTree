#pragma once

#include <memory>
#include <vector>
#include <iostream>

#include "../20-declarations/TreeNode.hpp"

namespace SAO::BTree {

  template <typename T>
  TreeNode<T>::TreeNode(std::unique_ptr<T> data) :
    left(),
    right(),
    data(std::move(data)) {
  }

  template <typename T>
  TreeNode<T>::TreeNode(
    std::unique_ptr<TreeNode<T>> left,
    std::unique_ptr<TreeNode<T>> right,
    std::unique_ptr<T> data
  ) :
    left(std::move(left)),
    right(std::move(right)),
    data(std::move(data)) {
  }

  template <typename T>
  size_t TreeNode<T>::depth(const std::unique_ptr<TreeNode<T>> &this_or_null) {
    if (!this_or_null) {
      return 0;
    }

    return 1 + std::max(
      depth(this_or_null->left),
      depth(this_or_null->right)
    );
  }

  template <typename T>
  void TreeNode<T>::print(const std::unique_ptr<TreeNode<T>> &this_or_null, size_t prefix_length, std::ostream &os) {
    if (!this_or_null) {
      return;
    }

    print(this_or_null->right, prefix_length + 1, os);

    for (size_t i = 0; i < prefix_length; i++) {
      os << "\t";
    }
    os << *this_or_null->data << std::endl;

    print(this_or_null->left, prefix_length + 1, os);
  }

  template <typename T>
  void TreeNode<T>::add(
    std::unique_ptr<TreeNode<T>> &this_or_null,
    std::unique_ptr<T> data
  ) {
    if (!this_or_null) {
      this_or_null = std::make_unique<TreeNode<T>>(std::move(data));
    } else if (*data < *this_or_null->data) {
      add(this_or_null->left, std::move(data));
    } else {
      add(this_or_null->right, std::move(data));
    }
  }

  template <typename T>
  std::unique_ptr<TreeNode<T>> &TreeNode<T>::leftmost_descendent(
    std::unique_ptr<TreeNode<T>> &this_not_null
  ) {
    if (!this_not_null->left) {
      return this_not_null;
    } else {
      return leftmost_descendent(this_not_null->left);
    }
  }

  template <typename T>
  std::unique_ptr<T> TreeNode<T>::remove(
    std::unique_ptr<TreeNode<T>> &this_not_null,
    const T &data
  ) {
    if (data == *this_not_null->data) {
      std::unique_ptr<T> ret = std::move(this_not_null->data);

      if (!this_not_null->left) {
        this_not_null = std::move(this_not_null->right);
      } else if (!this_not_null->right) {
        this_not_null = std::move(this_not_null->left);
      } else {
        std::unique_ptr<TreeNode<T>> &successor = leftmost_descendent(this_not_null->right);
        this_not_null->data = std::move(successor->data);
        successor = std::move(successor->right);
      }

      return ret;
    } else if (data < *this_not_null->data) {
      return remove(this_not_null->left, data);
    } else {
      return remove(this_not_null->right, data);
    }
  }

  template <typename T>
  void TreeNode<T>::invert(std::unique_ptr<TreeNode<T>> &this_or_null) {
    if (!this_or_null) {
      return;
    }

    this_or_null->left.swap(this_or_null->right);

    invert(this_or_null->left);
    invert(this_or_null->right);
  }

}
