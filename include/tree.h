// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <vector>
#include <algorithm>

class Tree {
 private:
    class Node {
      char value;
      std::vector<Node*> childs;
      Node(char val) : value(val) {}
    };
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
        perms.push_back(perm);
      }
      for (Node* child : root->childs) {
        genPerm(child, perm);
      }
      perm.pop_back();
    }

 public:
    Tree(const std::vector<char>& numbers) {
      root = new Node(' ');
      createTree(numbers, root);
      std::vector<char> p;
      genPerm(root, p);
    }
    int GetSize() {
      return root->childs.size();
    }
    std::vector<char> getPerm(int n) {
      return perms[n];
    }
};
#endif  // INCLUDE_TREE_H_