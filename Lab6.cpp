#include "Funcs.h"
int main() {
	int n;
	cout << "Enter the number:";   //задачи n
	cin >> n;
	int beginning = 2;            //початкове число для рівня після n
	TNode* root=new TNode;        //корінь дерева
	root->ident = n;
	vector<TNode*> v;
	make_recur(v, n, beginning, root);   //створюємо дерево
	int level = 0;
	TNode* start = find_start(v);       //знайти корінь у векторі
	give_level(v, level, start);        //задати рівні
	print_tree(n, v);                   //вивести на екран
	deleting(v);                        //видалити динамічні структури
	return 0;
}