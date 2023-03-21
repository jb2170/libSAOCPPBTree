#pragma once

#include <cstdlib>
#include <memory>
#include <vector>
#include <iostream>

#include "../10-forward-declarations/TreeNode.hpp"

namespace SAO::BTree {

  template <typename T>
  struct TreeNode {
    std::unique_ptr<TreeNode<T>> left;
    std::unique_ptr<TreeNode<T>> right;
    std::unique_ptr<T> data;

    TreeNode(std::unique_ptr<T> data);

    TreeNode(
      std::unique_ptr<TreeNode<T>> left,
      std::unique_ptr<TreeNode<T>> right,
      std::unique_ptr<T> data
    );

    static size_t depth(const std::unique_ptr<TreeNode<T>> &this_or_null);

    static void print(const std::unique_ptr<TreeNode<T>> &this_or_null, size_t prefix_length, std::ostream &os);

    static void add(
      std::unique_ptr<TreeNode<T>> &this_or_null,
      std::unique_ptr<T> &&data
    );

    static std::unique_ptr<TreeNode<T>> &leftmost_descendent(
      std::unique_ptr<TreeNode<T>> &this_not_null
    );

    static std::unique_ptr<T> remove(
      std::unique_ptr<TreeNode<T>> &this_not_null,
      const T &data
    );

    static void invert(std::unique_ptr<TreeNode<T>> &this_or_null);

  };

}
