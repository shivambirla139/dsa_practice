#include<bits/stdc++.h>
using namespace std;
#define int int64_t 
 
class SegmentTree{
	public:
	int n;
	vector<int> v,tree;
	SegmentTree(int n){
		this->n = n;
		v.resize(n);
		tree.resize(4*n);
	}
	int build(int low,int high,int ti){
		if(low == high){
			tree[ti] = v[low];
			return v[low];
		}
		int mid = (low+high)/2;
		int left = build(low,mid,2*ti+1);
		int right = build(mid+1,high,2*ti+2);
		int sum = left + right;
		return tree[ti] = sum;
	}
	int query(int low,int high,int l,int r,int ti){
		if(r<low || high<l) return 0;
		if(low>=l && high<=r) return tree[ti];
		int mid = (low+high)/2;
		int left = query(low,mid,l,r,2*ti+1);
		int right = query(mid+1,high,l,r,2*ti+2);
		return left+right;
	}
	void update(int low, int high, int ti,int i, int val){
		if(low==high){
			tree[ti] = val;
			return;
		}
		int mid = (low+high)/2;
		if(i<=mid) update(low, mid,2*ti+1 , i, val);
		else update(mid+1, high,2*ti+2, i, val);
		tree[ti] = tree[2*ti+1] + tree[2*ti+2];
	}
	void build(){
		build(0,n-1,0);
	}
	int query(int l,int r){
		return query(0,n-1,l,r,0);
	}
	void update(int i,int val){
		update(0,n-1,0,i,val);
	}
};
void runcase(){
	int n,q;
	cin>>n>>q;
	SegmentTree st(n);
	for(int i=0;i<n;i++) cin>>st.v[i];
	st.build();
	for(int i=0;i<q;i++){
		int l,r;
		cin>>l>>r;
		cout<<st.query(l-1,r-1)<<endl;
	}
}
int32_t main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	runcase();
}
