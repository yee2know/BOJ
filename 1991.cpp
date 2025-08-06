#include <vector>
#include <iostream>
using namespace std;
static int N;
static int tree[26][2];

void preorder(int now){
	if(now==-1) return;
	cout << (char)(now+'A');
	preorder(tree[now][0]);
	preorder(tree[now][1]);
}
void inorder(int now){
	if(now==-1) return;
	inorder(tree[now][0]);
	cout << (char)(now+'A');
	inorder(tree[now][1]);
}
void postorder(int now){
	if(now==-1) return;
	postorder(tree[now][0]);
	postorder(tree[now][1]);
	cout << (char)(now+'A');
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i=0;i<N;i++){
		char node,l,r;
		cin >> node >> l >> r;
		int n = node-'A';
		if(l=='.') tree[n][0]=-1;
		else tree[n][0]=l-'A';
		if(r=='.') tree[n][1]=-1;
		else tree[n][1]=r-'A';
	}
	preorder(0);
	cout << "\n";
	inorder(0);
	cout << "\n";
	postorder(0);
	return 0;
}