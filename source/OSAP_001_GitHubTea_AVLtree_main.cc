/****************************************************************************************
   File Name: OSAP_001_GitHubTea_AVLtree_main.cc
   Copyright (c) 2024 GitHubTea

   This software is distributed under the MIT License.
   For more details on the MIT License, please refer to the LICENSE file in this
project. This software is provided "as is," without any warranty of any kind.

   Author: GitHubTea
   Date: 2024-11-28
*****************************************************************************************/

#include <iostream>

#include "header/OSAP_001_GitHubTea_AVLtree_AVLTree.h"
#include "header/OSAP_001_GitHubTea_AVLtree_Node.h"

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
        /*
          set이 비어 있다면 1, 아니면 0을 출력  
        */ 
        cout << (avl.Empty() ? 1 : 0) << "\n";
      } else if (instruction == "Size") {
        /*
          set에 저장된 원소의 수 출력
        */
        cout << avl.Size() << "\n";
      } else if (instruction == "Height") {
        /*
          AVL 트리의 높이 출력. AVL트리가 비어 있다면 -1 출력.
        */
        cout << avl.Height() << "\n";
      } else if (instruction == "Find") {
        /*
          노드 x의 깊이와 높이의 합을 출력.
          노드 x가 존재하지 않을 시, 0을 출력
        */
        int x;
        cin >> x;
        cout << avl.Find(x) << "\n";
      } else if (instruction == "Insert") {
        /*
          노드 x를 삽입하고, 노드 x의 깊이와 높이의 합을 출력.
          이때 x는 현재 set에 존재하지 않는 값으로 주어짐
        */
        int x;
        cin >> x;
        
        // Insert()로 x값을 AVL트리에 삽입
        avl.Insert(x);
        
        // 깊이와 높이의 합 출력
        cout << avl.Depth(x) + avl.Height(x) << "\n";
      } else if (instruction == "Ancestor") {
        /*
          노드 x의 깊이와 높이의 합, x의 부모로부터 루트까지의
          경로의 노드들의 key 값들의 합을 공백으로 구분하여 출력한다.
          이때 x는 현재 set에 존재하는 원소로만 주어진다.
        */
        int x;
        cin >> x;

        int depth_height_sum = avl.Depth(x) + avl.Height(x);
        int ancestor_key_sum = avl.AncestorKeySum(x);

        if (avl.isExist(x) && avl.isRoot(x)) {        // 루트 노드일 경우
          cout << depth_height_sum << " " << "0\n";   // 깊이와 높이의 합 (공백) 0
        } else {
          cout << depth_height_sum << " " << ancestor_key_sum << "\n";
        }
      } else if (instruction == "Average") {
        /*
          노드 x가 루트인 서브트리에서 노드들의 key 값의
          최솟값, 최댓값의 산술평균을 출력한다.
          이때 x는 현재 set에 존재하는 원소로만 주어진다.
        */
        int x;
        cin >> x;
        int min_key = (avl.MinDescendant(x));
        int max_key = (avl.MaxDescendant(x));
        cout << (min_key + max_key) / 2 << "\n";
      } else if (instruction == "Rank") {
        /*
          노드 x의 깊이와 높이의 합, 순위를 공백으로 구분하여 출력한다.
          만약 노드 x가 없다면 0을 출력한다. 이때 순위는 set에서
          x보다 작은 원소의 수 + 1 로 정의한다.
        */
        int x;
        cin >> x;
        int depth_height_sum = avl.Depth(x) + avl.Height(x);
        if (avl.isExist(x)) {             // set에 존재할 때
          cout << depth_height_sum << " " << avl.Rank(x) << "\n";
        } else {                          // set에 존재하지 않을 때
          cout << "0\n";
        }
      } else if (instruction == "Erase") {
        /*
          노드 x의 깊이와 높이의 합을 출력하고 해당 노드를 삭제한다.
          만약 노드 x가 없다면 0을 출력한다.
        */
        int x;
        cin >> x;
        if (avl.isExist(x)) {             // set에 존재할 때
          cout << avl.Depth(x) + avl.Height(x) << "\n";
          avl.Erase(x);
        } else {                          // set에 존재하지 않을 때
          cout << "0\n";
        }
      }
    }
  }

  return 0;
}
