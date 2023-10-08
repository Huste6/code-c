#include<bits/stdc++.h>
using namespace std;
//pre[r]-pre[l-1]
//O(1)
//2 3  5    8   6
//2 5 10   18   24
int main(){
	/*int n;cin>>n;
	int a[n];
	for(int &x:a) cin>>x;
	int q;cin>>q;
	while(q--){
		int l,r;cin>>l>>r;
		int sum=0;
		for(int i=l;i<=r;i++) sum+=a[i];
		cout<<sum<<endl;
	}
	*/
	int n;cin>>n;
	int a[n];
	for(int &x:a) cin>>x;
	int q;cin>>q;
	int prefix[n+1]={0};
	for(int i=0;i<=n;i++){
		prefix[i]=prefix[i-1]+a[i];
	}
	while(q--){
		int sum=0;
		int l,r;cin>>l>>r;
		sum=-prefix[l-1]+prefix[r];
		cout<<sum<<endl;
	}
	return 0;
}
