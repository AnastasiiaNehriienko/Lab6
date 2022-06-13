#include <iostream>
#include <vector>
using namespace std;
struct TNode {
	int ident;   //число
	int level_num;   //номер рівня
	TNode* parent, *left, * right;   //покажчики на предка та нащадків
	TNode() { parent = NULL; left = NULL; right = NULL; level_num = -1; }
};
