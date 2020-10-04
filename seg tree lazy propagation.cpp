#include<bits/stdc++.h>
using namespace std;

int max(int a, int b)
{
	return a>b ? a:b;
}

int n, q, a[100010], l, r, x, y;
int tree[400020];
int lazy[400020];
char t;

void build(int node, int start, int end)
{
	if(start == end)
	{
		tree[node] = a[start];
	}
	else
	{
		int mid = (start + end)/2;
		build(2*node + 1, start, mid);
		build(2*node + 2, mid + 1, end);
		tree[node] = min( tree[2*node + 1], tree[2*node + 2] );
	}
}

void updaterange(int node, int start, int end, int l, int r, int val)
{
	if(lazy[node] != 0)
	{
		tree[node] += (end - start + 1)*lazy[node];
		if(start != end)
		{
			lazy[2*node + 1] += lazy[node];
			lazy[2*node + 2] += lazy[node];
		}
		lazy[node] = 0;
	}
		if(start > end || start > r || end < l)
		return;

	if(start >= l && end <= r)
	{
		tree[node] += (end - start + 1)*val;
		if(start != end)
		{
			lazy[2*node + 1] += val;
			lazy[2*node + 2] += val;
		}
		return;
	}
	int mid = (start + end)/2;
	updaterange(2*node + 1, start, mid, l, r, val);
	updaterange(2*node + 2, mid+1, end, l, r, val);

	tree[node] = tree[node*2 + 1] + tree[node*2 + 1];
}

int queryrange(int node, int start, int end, int l, int r)
{
	if(start > end or start > r or end < l)
        return 0;
    if(lazy[node] != 0)
    {
        tree[node] += (end - start + 1) * lazy[node];
        if(start != end)
        {
            lazy[node*2 + 1] += lazy[node];
            lazy[node*2 + 2] += lazy[node];
        }
        lazy[node] = 0;
    }
    if(start >= l and end <= r)
        return tree[node];
    int mid = (start + end)/2;
    int p1 = queryRange(node*2 + 1, start, mid, l, r);
    int p2 = queryRange(node*2 + 2, mid + 1, end, l, r);
    return (p1 + p2);
}

int main()
{
	//call initialiser to put all lazy to zero
	cin>>n>>q;
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	build(0, 0, n-1);
	for (int i = 0; i < q; ++i)
	{
		cin>>t;
		if(t == 'q')
		{
			//find min
			cin>>l>>r;
			cout<<queryrange(0, 0, n-1, l-1, r-1)<<endl;
		}
		else
		{
			//updaterange
			cin>>x>>y;
			updaterange(0, 0, n-1, x-1, y);
		}
	}
}
