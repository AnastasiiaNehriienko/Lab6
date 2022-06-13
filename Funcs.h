#include "Structs.h"
void make_recur(vector<TNode*>& v, int n, int now, TNode* parent) {   //рекурсивно додаємо нащадків
	if (now > n) {
		v.push_back(parent);   //якщо це був останній рівень, де числа =n, то додаємо вершину
		return;
	}
	TNode* node_l = new TNode;
	TNode* node_r=new TNode;
	node_l->parent = parent;   //лівий начадок
	node_r->parent = parent;   //правий нащадок
	parent->left = node_l;
	parent->right = node_r;
	node_l->ident = now;
	node_r->ident = now;
	make_recur(v, n, now + 1, node_l);
	v.push_back(parent);       //додаємо до вектору
	make_recur(v, n, now + 1, node_r);
}
void give_level(vector<TNode*>& v, int level, TNode* start) {    //задати рівні
	if (!start->left){                       //якщо не мають нащадків
		start->level_num = level;            //зберігаємо рівень
	return;
	}
	give_level(v, level + 1, start->left);   //нащадки матимуть на рівень більше
	give_level(v, level + 1, start->right);  //...
	start->level_num = level;
}
TNode* find_start(vector<TNode*>& v) {   //знайти корінь дерева
	int i = 0;
	bool found = false;
	int needed = 0;
	while (i < v.size() && !found) {
		if (v[i]->parent == NULL) {   //якщо не має предків
			found = true;
			needed = i;
		}
		i++;
	}
	return v[needed];                //повернути знайдений корінь
}
void print_tree(int n, vector<TNode*>& v) {    //Друкування структури дерева
	int space_amount = v.size();
	for (int i = 0; i < n; ++i) {
		space_amount /= 2;
		for (int j = 0; j < v.size(); ++j) {   //номер рівня
			if (v[j]->level_num == i) {        //якщо число має такий рівень
				for (int k = 0; k < space_amount; ++k)
					cout << " ";
				cout << v[j]->ident<<" ";
				for (int k = 0; k < space_amount; ++k)
					cout << " ";
				
			}
		}
		cout << endl;
	}
	/*for (int i = 0; i < n; ++i) {
		space_amount /= 2;
		for (int j = 0; j < v.size(); ++j) {
			if (v[j]->level_num == i) {
				cout << v[j]->ident << " ";

			}
		}
		cout << endl;
	}*/   //числа після n=8 можна отримати у неформатованому під вигляд дерева форматі через цей закоментований код
}
void deleting(vector<TNode*>& v) {   //видалення динамічних структур
	int x = v.size();
	for (int i = 0; i < x; i++) {
		delete v[i];
	}
}