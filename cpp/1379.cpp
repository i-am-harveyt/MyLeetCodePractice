#include <iostream>
#include <queue>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// BFS method
class SolutionBFS {
public:
  TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned,
                          TreeNode *target) {
    queue<TreeNode *> qo;
    queue<TreeNode *> qc;
    TreeNode *curo = original;
    TreeNode *curc = cloned;
    qo.push(curo);
    qc.push(curc);

    while (!qo.empty()) {
      curo = qo.front();
      qo.pop();
      curc = qc.front();
      qc.pop();

      if (curo == target)
        return curc;

      if (curo->left) {
        qo.push(curo->left);
        qc.push(curc->left);
      }
      if (curo->right) {
        qo.push(curo->right);
        qc.push(curc->right);
      }
    }

    return NULL;
  }
};

// DFS method
class SolutionDFS {
public:
  TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned,
                          TreeNode *target) {
    if (original == NULL)
      return NULL;
    else if (original == target)
      return cloned;
    TreeNode *l = getTargetCopy(original->left, cloned->left, target);
    TreeNode *r = getTargetCopy(original->right, cloned->right, target);
    if (l)
      return l;
    else if (r)
      return r;
    else
      return NULL;
  }
};
