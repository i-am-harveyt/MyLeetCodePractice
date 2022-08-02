#include <vector>

using namespace std;

class Solution {
public:
  int countStudents(vector<int> &students, vector<int> &sandwiches) {
    int stop = -1, eaten = 0, size = students.size();

    while (students.size() > 0) {
      if (students[0] == sandwiches[0]) {
        students.erase(students.begin());
        sandwiches.erase(sandwiches.begin());
        eaten++;
        stop = -1;
      } else {
        students.push_back(students[0]);
        students.erase(students.begin());
        if (stop == -1) {
          stop = students.size() - 1;
        } else if (stop == 0) {
          break;
        } else {
          stop--;
        }
      }
    }

    return size - eaten;
  }
};
