#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
HDBEAFCG
HDEBFGCA
ABDHECFG
*/
char mid[100];
char beh[100];
struct tree {
	tree *root;
	tree *left;
	tree *right;
	char name;
};
tree *generate(int start, int end, tree *root, int target) {
	if (start > end)return NULL;
	int local;
	tree *main;
	main = (tree*)malloc(sizeof(tree));
	*main = { root, NULL,NULL,beh[target] };
	if (start == end)return main;
	for (int i = 0;; i++) {
		if (mid[i] == beh[target]) {
			local = i;
			break;
		}
	}
	int q = local - start;
	int h = end - local;
	//printf("%d", local);
	main->left = generate(start, local - 1, main, target - h - 1);
	main->right = generate(local + 1, end, main, target - 1);
	return main;
}
void output(tree *maintree) {
	printf("%c", maintree->name);
	if (maintree->left != NULL)output(maintree->left);
	if (maintree->right != NULL)output(maintree->right);
	return;
}
int main() {
	scanf("%s", &mid);
	scanf("%s", &beh);
	int start = 0;
	int end = strlen(mid) - 1;
	tree *maintree = generate(start, end, NULL, end);//生成
	output(maintree);//输出前序遍历
}