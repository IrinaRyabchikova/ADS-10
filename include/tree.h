// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <vector>
#include <algorithm>

struct Node {
  char value;
  std::vector<Node*> childs;
  explicit Node(char val) : value(val) {}
};

class Tree {
 private:
    std::vector<std::vector<char>> perms;
    Node* root;
    void createTree(const std::vector<char>& numbers, Node* parent) {
      for (char num : numbers) {
        Node* child = new Node(num);
        parent->childs.push_back(child);
        std::vector<char> new_num(numbers);
        new_num.erase(std::find(new_num.begin(), new_num.end(), num));
        createTree(new_num, child);
      }
    }
    void genPerm(Node* root, std::vector<char> perm) {
      perm.push_back(root->value);
      if (root->childs.empty()) {
        std::vector<char> result(perm);
        result.erase(result.begin());
        perms.push_back(result);
      }
      for (Node* child : root->childs) {
        genPerm(child, perm);
      }
      perm.pop_back();
    }

 public:
    explicit Tree(const std::vector<char>& numbers) {
      root = new Node(' ');
      createTree(numbers, root);
      genPerm(root, {});
    }
    int Size() {
      return root->childs.size();
    }
    std::vector<char> getPerm(int n) {
      return perms[n];
    }
};
#endif  // INCLUDE_TREE_H_
