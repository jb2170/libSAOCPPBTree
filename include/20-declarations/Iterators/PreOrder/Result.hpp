#pragma once

#include <memory>

#include "../../../10-forward-declarations/Iterators/PreOrder/Result.hpp"

namespace SAO::BTree::Iterators::PreOrder {

  template <typename T>
  struct Result {
    T &data;
  };

}
