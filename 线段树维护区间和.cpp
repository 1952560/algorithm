#include<iostream>
#include<queue>
using namespace std;

#define int long long

struct Node
{
    int l, r;
    int sum; //以及其他信息
    int addv;
} tree[100005*4];

int a[100005];

void build(int o,int l,int r) {
    tree[o].l = l;
    tree[o].r = r;
    tree[o].addv = 0;
    if(l==r) { //叶子
        tree[o].sum = a[l];
        return;
    }
    build(o*2,l,(l+r)/2);
    build(o*2+1,(l+r)/2+1,r);
    tree[o].sum = tree[o * 2].sum + tree[o * 2 + 1].sum;
}

void pushdown(int o)
{
    if(tree[o].l<tree[o].r) {
        tree[o*2].sum += tree[o].addv*(tree[o*2].r - tree[o*2].l + 1);
        tree[o*2+1].sum += tree[o].addv * (tree[o*2+1].r - tree[o*2+1].l + 1);
        tree[o*2].addv += tree[o].addv;
        tree[o*2+1].addv += tree[o].addv;
    }
    tree[o].addv = 0;
}

int query(int o,int a,int b) {
    if (tree[o].l >= a && tree[o].r <= b) { //被包含
        return tree[o].sum;
    }
    pushdown(o);
    int mid = (tree[o].l + tree[o].r) / 2;
    int result = 0;
    if (a <= mid)
        result += query(o * 2, a, b);
    if (b > mid)
        result += query(o * 2 + 1, a, b);
    return result;
}

void update(int o,int a,int b,int x) {
    if(tree[o].l>=a&&tree[o].r<=b) {
        tree[o].addv += x;
        tree[o].sum += x*(tree[o].r-tree[o].l+1);
    }
    else {
        int mid = (tree[o].l + tree[o].r) / 2;
        if (a <= mid)
            update(o*2, a, b, x);
        if (b > mid)
            update(o*2+1, a, b, x);
        tree[o].sum = tree[o * 2].sum + tree[o * 2 + 1].sum + (tree[o].r - tree[o].l + 1) * tree[o].addv;
    }
}

signed main()
{
	int n,m;
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	build(1,1,n);
	for(int i=0,opt,x,y,k;i<m;i++)
	{
		scanf("%lld%lld%lld",&opt,&x,&y);
		if(opt==1)
		{
			scanf("%lld",&k);
			update(1,x,y,k);
		}
		else
		{
			cout<<query(1,x,y)<<"\n";
		}
	}
}
