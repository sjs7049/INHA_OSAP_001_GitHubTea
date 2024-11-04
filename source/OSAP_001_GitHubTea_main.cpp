#include "../header/OSAP_001_GitHubTea_Node.h"
#include "../header/OSAP_001_GitHubTea_AVLtree.h"
#include "./OSAP_001_GitHubTea_Node.cpp"
#include "./OSAP_001_GitHubTea_AVLtree.cpp"
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int test_cnt{ 1 };
	cin >> test_cnt;

	AVLTree avl;

	string instruction;
	while (test_cnt--)
	{
		cin >> instruction;
		if (instruction == "Empty")
		{
			if (avl.Empty()) {
				cout << 1 << "\n";
			}
			else {
				cout << 0 << "\n";
			}
		}
		else if (instruction == "Size") {
			cout << avl.Size() << "\n";
		}
		else if (instruction == "Height") {
			if (avl.Empty()) {
				cout << -1 << "\n";
			}
			else {
				cout << avl.Height() << "\n";
			}
		}
		else if (instruction == "Find") {
			int x{ 0 };
			cin >> x;
			cout << avl.Depth(x) + avl.Height(x) << "\n";
		}
		else if (instruction == "Insert") {
			int x{ 0 };
			cin >> x;
			avl.Insert(x);
			cout << avl.Depth(x) + avl.Height(x) << "\n";
		}
		else if (instruction == "Ancestor") {
			int x{ 0 };
			cin >> x;
			cout << avl.Depth(x) + avl.Height(x) << " ";
			cout << avl.Ancestor(x) << "\n";
		}
		else if (instruction == "Average") {
			int x{ 0 };
			cin >> x;
			double min_key{ static_cast<double>(min(x, avl.MinDescendant(x))) };
			double max_key{ static_cast<double>(max(x, avl.MaxDescendant(x))) };
			cout << (min_key + max_key) / 2 << "\n";
		}
		else if (instruction == "Rank") {
			int x{ 0 };
			cin >> x;
			int depth_height_sum{ avl.Depth(x) + avl.Height(x) };
			if (depth_height_sum == 0) {
				cout << 0 << "\n";
			}
			else {
				cout << depth_height_sum << "\n";
				cout << avl.Rank(x) << "\n";
			}
		}
		else if (instruction == "Erase") {
			int x{ 0 };
			cin >> x;
			cout << avl.Depth(x) + avl.Height(x) << " ";
			avl.Erase(x);
		}
	}

	return 0;
}