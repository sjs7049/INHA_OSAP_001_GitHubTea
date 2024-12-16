/****************************************************************************************
   File Name: OSAP_001_GitHubTea_main.cpp
   Copyright (c) 2024 GitHubTea

   This software is distributed under the MIT License.
   For more details on the MIT License, please refer to the LICENSE file in this
project. This software is provided "as is," without any warranty of any kind.

   Author: GitHubTea
   Date: 2024-11-28
*****************************************************************************************/

#include <iostream>

#include "../header/OSAP_001_GitHubTea_AVLtree.h"
#include "../header/OSAP_001_GitHubTea_Node.h"

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int T = 0, Q = 0;
  cin >> T;

  string instruction;
  while (T--) {
    AVLTree avl;
    cin >> Q;
    while (Q--) {
      cin >> instruction;
      if (instruction == "Empty") {
        cout << (avl.Empty() ? 1 : 0) << "\n";
      } else if (instruction == "Size") {
        cout << avl.Size() << "\n";
      } else if (instruction == "Height") {
        cout << avl.Height() << "\n";
      } else if (instruction == "Find") {
        int x;
        cin >> x;
        cout << avl.Find(x) << "\n";
      } else if (instruction == "Insert") {
        int x;
        cin >> x;
        avl.Insert(x);
        cout << avl.Depth(x) + avl.Height(x) << "\n";
      } else if (instruction == "Ancestor") {
        int x;
        cin >> x;
        avl.Ancestor(x);
        int depth_height_sum = avl.Depth(x) + avl.Height(x);
        int ancestor_sum = avl.Ancestor(x);

        if (avl.isExist(x) && avl.isRoot(x)) { // 루트 노드이고 존재할 경우
          cout << depth_height_sum << " "
               << "0\n";
        } else {
          cout << depth_height_sum << " " << ancestor_sum << "\n";
        }
      } else if (instruction == "Average") {
        int x;
        cin >> x;
        int min_key = (avl.MinDescendant(x));
        int max_key = (avl.MaxDescendant(x));
        cout << (min_key + max_key) / 2 << "\n";
      } else if (instruction == "Rank") {
        int x;
        cin >> x;
        int depth_height_sum = avl.Depth(x) + avl.Height(x);
        if (avl.isExist(x)) {
          cout << depth_height_sum << " " << avl.Rank(x) << "\n";
        } else {
          cout << "0\n";
        }
      } else if (instruction == "Erase") {
        int x;
        cin >> x;
        if (avl.isExist(x)) {
          cout << avl.Depth(x) + avl.Height(x) << "\n";
          avl.Erase(x);
        } else {
          cout << "0\n";
        }
      }
    }
  }

  return 0;
}
