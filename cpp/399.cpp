#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  map<string, string> table;
  map<pair<string, string>, double> relation;
  double relationNum;

  string findRoot(string current) {
    if (table[current] == current)
      return current;
    relationNum *= relation[pair<string, string>(table[current], current)];
    table[current] = findRoot(table[current]);
    return table[current];
  }

  vector<double> calcEquation(vector<vector<string>> &equations,
                              vector<double> &values,
                              vector<vector<string>> &queries) {

    // speed up!
    // ios::sync_with_stdio(0);

    // start
    for (int i = 0; i < values.size(); i++) {
      auto &eq = equations[i];
      if (table.find(eq[0]) == table.end())
        table[eq[0]] = eq[0];
      if (table.find(eq[1]) == table.end())
        table[eq[1]] = eq[1];

      relation[pair<string, string>(eq[0], eq[1])] = values[i];
      relation[pair<string, string>(eq[1], eq[0])] = 1 / values[i];

      relationNum = 1;
      string firstRoot = findRoot(eq[0]);
      relation[pair<string, string>(firstRoot, eq[0])] = relationNum;

      relationNum = 1;
      string secondRoot = findRoot(eq[1]);
      relation[pair<string, string>(secondRoot, eq[1])] = relationNum;

      table[secondRoot] = firstRoot;
      relation[pair<string, string>(firstRoot, secondRoot)] =
          relation[pair<string, string>(firstRoot, eq[0])] * values[i] /
          relation[pair<string, string>(secondRoot, eq[1])];
    }

    for (auto it = table.cbegin(); it != table.cend(); ++it) {
      relationNum = 1;
      string firstRoot = findRoot(it->first);
      relation[pair<string, string>(firstRoot, it->first)] = relationNum;
    }

    vector<double> ret;

    for (auto &q : queries) {
      if (table.find(q[0]) == table.cend() ||
          table.find(q[1]) == table.cend()) {
        ret.push_back(-1);
        continue;
      }

      string root1 = findRoot(q[0]);
      string root2 = findRoot(q[1]);

      pair<string, string> withRoot1 = pair<string, string>(root1, q[0]);
      pair<string, string> withRoot2 = pair<string, string>(root2, q[1]);
      pair<string, string> element1 = pair<string, string>(q[0], q[1]);
      pair<string, string> element2 = pair<string, string>(q[1], q[0]);

      if (relation.find(element1) != relation.cend())
        ret.push_back(relation[element1]);
      else if (relation.find(element2) != relation.cend())
        ret.push_back(1 / relation[element2]);
      else if (root1 == root2)
        ret.push_back(relation[withRoot2] / relation[withRoot1]);
      else
        ret.push_back(-1);
    }

    // return
    return ret;
  }
};
