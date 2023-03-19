#include <unistd.h>

#include <vector>
#include <iostream>

#include "Tree.hpp"

using namespace SAO::BTree;

int main() {
  Tree<int> t;

  std::cout << "Depth:" << t.depth() << std::endl;
  t.add(std::make_unique<int>(7));
  std::cout << "Depth:" << t.depth() << std::endl;

  t.add(std::make_unique<int>(90));
  t.add(std::make_unique<int>(95));
  t.add(std::make_unique<int>(100));
  t.add(std::make_unique<int>(105));
  t.add(std::make_unique<int>(88));
  t.add(std::make_unique<int>(89));
  t.add(std::make_unique<int>(93));
  t.add(std::make_unique<int>(94));

  t.print(std::cout);

  std::unique_ptr<int> removed = t.remove(90);

  std::cout << std::endl << std::endl << std::endl;
  t.print(std::cout);

  std::cout << "Removed " << *removed << std::endl;

  std::cout << "PreOrder" << std::endl;
  for (const auto result : t.iter_pre_order()) {
    std::cout << result.data << std::endl;
  }

  return EXIT_SUCCESS;
}
