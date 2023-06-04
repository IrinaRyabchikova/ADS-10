// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "tree.h"

int fact(int n) {
  return n == 0 ? 1 : n * fact(n - 1);
}

std::vector<char> getPerm(const Tree& tree, int n) {
  std::vector<char> result = {};
  if (n < 0 || fact(tree.Size()) < n)
    return {};
  return tree.GetPerm(n-1);
}
