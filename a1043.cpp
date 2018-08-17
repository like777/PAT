#include<cstdio>
#include<vector>
#include<stack>

using namespace std;

int n;
vector<int> keys;
stack<int> stk;

bool is_bst = true, is_mirror = true;

struct Node
{
	int key;
	Node* left_child;
	Node* right_child;
};

vector<Node> nodes;
int c = 0;

bool checktree(vector<int> keys)
{
	vector<int> left, right;
	bool flag = false;
	for (int i = 1; i < keys.size(); i++)
	{
		if (!flag & keys[i] < keys[0])
		{
			left.push_back(keys[i]);
		}
		else if (flag && keys[i] < keys[0])
		{
			return false;
		}
		else
		{
			flag = true;
			right.push_back(keys[i]);
		}
	}
	if (left.size() > 0)
	{
		return checktree(left);

	}
	if (right.size() > 0)
	{
		return checktree(right);
	}
	return true;
}

bool checkmirror(vector<int> keys)
{
	vector<int> left, right;
	bool flag = false;
	for (int i = 1; i < keys.size(); i++)
	{
		if (!flag & keys[i] >= keys[0])
		{
			left.push_back(keys[i]);
		}
		else if (flag && keys[i] >= keys[0])
		{
			return false;
		}
		else
		{
			flag = true;
			right.push_back(keys[i]);
		}
	}
	if (left.size() > 0)
	{
		return checkmirror(left);

	}
	if (right.size() > 0)
	{
		return checkmirror(right);
	}
	return true;

}

void build_tree(vector<int> keys, int now)
{
	vector<int> left, right;
	for (int i = 1; i < keys.size(); i++)
	{
		if (keys[i] >= keys[0])
		{
			right.push_back(keys[i]);
		}else
		{
			left.push_back(keys[i]);
		}
	}
	if (left.size() > 0)
	{
		nodes[++c].key = left[0];
		nodes[now].left_child = &nodes[c];
		build_tree(left, c);
	}

	if (right.size() > 0)
	{
		nodes[++c].key = right[0];
		nodes[now].right_child = &nodes[c];
		build_tree(right, c);
	}
}

void build_mirror(vector<int> keys, int now)
{
	vector<int> left, right;
	for (int i = 1; i < keys.size(); i++)
	{
		if (keys[i] >= keys[0])
		{
			left.push_back(keys[i]);
		}
		else
		{
			right.push_back(keys[i]);
		}
	}
	if (right.size() > 0)
	{
		nodes[++c].key = right[0];
		nodes[now].right_child = &nodes[c];
		build_mirror(right, c);
	}
	if (left.size() > 0)
	{
		nodes[++c].key = left[0];
		nodes[now].left_child = &nodes[c];
		build_mirror(left, c);
	}
}

void print_tree(Node* root)
{
	if (root->left_child != 0)
	{
		print_tree(root->left_child);
	}
	if (root->right_child != 0)
	{
		print_tree(root->right_child);
	}
	if (!stk.empty())
	{
		printf(" ");
	}
	stk.push(root->key);
	printf("%d", stk.top());
}

int main()
{
	scanf("%d", &n);

	nodes.resize(n);
	for (int i = 0, number; i < n; i++)
	{
		scanf("%d", &number);
		keys.push_back(number);
	}
	nodes[0].key = keys[0];

	if (checktree(keys))
	{
		printf("YES\n");
		nodes[0].key = keys[0];
		build_tree(keys, 0);
		print_tree(&nodes[0]);
	}
	else if (checkmirror(keys))
	{
		printf("YES\n");
		nodes[0].key = keys[0];
		build_mirror(keys, 0);
		print_tree(&nodes[0]);
	}
	else
	{
		printf("NO");
	}

}