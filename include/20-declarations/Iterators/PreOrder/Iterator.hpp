#pragma once

#include "../../../../subprojects/libSAOCPPIterator/include/20-declarations/Iterator.hpp"
#include "../../../10-forward-declarations/Iterators/PreOrder/Iterator.hpp"
#include "../../../10-forward-declarations/Iterators/PreOrder/Result.hpp"
#include "../../../10-forward-declarations/Iterators/PreOrder/State.hpp"
#include "../../../10-forward-declarations/Tree.hpp"
#include "../../../10-forward-declarations/TreeNode.hpp"

namespace SAO::BTree::Iterators::PreOrder {

  template <typename T>
  struct Iterator : SAO::Iterator::Iterator<Tree<T>, State<T>, Result<T>> {
    Iterator(const Tree<T> &iterable);

    Result<T> operator*();

    bool operator!=(const ssize_t &i);

    void operator++();
  };

}
