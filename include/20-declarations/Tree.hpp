#pragma once

#include <memory>
#include <vector>

#include "../../subprojects/libSAOCPPIterator/include/Iterator.hpp"
#include "../10-forward-declarations/Iterators/PreOrder/Iterator.hpp"
#include "../10-forward-declarations/Tree.hpp"
#include "../10-forward-declarations/TreeNode.hpp"

namespace SAO::BTree {

  template <typename T>
  struct Tree {
    std::unique_ptr<TreeNode<T>> root;

    Tree();

    size_t depth();

    void print(std::ostream &os);

    void add(std::unique_ptr<T> data);

    std::unique_ptr<T> remove(const T &data);

    void invert();

    SAO::Iterator::IteratorFactory<Tree<T>, Iterators::PreOrder::Iterator<T>> iter_pre_order();

  };

}
