#pragma once

#include <memory>
#include <stack>

#include "../../../10-forward-declarations/Iterators/PreOrder/State.hpp"
#include "../../../10-forward-declarations/TreeNode.hpp"

namespace SAO::BTree::Iterators::PreOrder {

  template <typename T>
  struct State {
    std::stack<const std::unique_ptr<TreeNode<T>> *> path;
  };

}
