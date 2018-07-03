#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n;
vector<int> post;
vector<int> in;

struct Node
{
	int key, left_child, right_child;
}nodes[31];

void build_tree(vector<int> postorder, vector<int> inorder)
{
	int last = postorder[postorder.size() - 1];
	vector<int>::iterator it = find(inorder.begin(), inorder.end(), last);
	vector<int> left_postorder,left_inorder, right_postorder, right_inorder;
	for (int i = 0; i < it - inorder.begin(); i++)
	{
		left_postorder.push_back(postorder[i]);
		left_inorder.push_back(inorder[i]);
	}
	for (int i = it - inorder.begin() + 1; i < inorder.size(); i++)
	{
		right_postorder.push_back(postorder[i - 1]);
		right_inorder.push_back(inorder[i]);
	}
	nodes[last].key = last;
	if (left_postorder.size() > 0)
	{
		nodes[last].left_child = left_postorder[left_postorder.size() - 1];
		build_tree(left_postorder, left_inorder);
	}
	if (right_postorder.size() > 0)
	{
		nodes[last].right_child = right_postorder[right_postorder.size() - 1];
		build_tree(right_postorder, right_inorder);
	}


}

int main()
{
	scanf("%d", &n);

	for (int i = 0, temp; i < n; i++)
	{
		scanf("%d", &temp);
		post.push_back(temp);
	}
	for (int i = 0, temp; i < n; i++)
	{
		scanf("%d", &temp);
		in.push_back(temp);
	}

	build_tree(post, in);
	queue<int> que;
	que.push(post[post.size() - 1]);

	while (!que.empty())
	{
		if (nodes[que.front()].left_child != 0)
		{
			que.push(nodes[que.front()].left_child);
		}
		if (nodes[que.front()].right_child != 0)
		{
			que.push(nodes[que.front()].right_child);
		}
		if (que.front() != post[post.size() - 1])
		{
			printf(" ");
		}
		printf("%d", que.front());
		que.pop();
	}
}