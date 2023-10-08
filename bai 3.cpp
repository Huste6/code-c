#include<iostream>
#include<map>
using namespace std;
map<string,int> mp;

int main()
{
	string str; int n1;
	while(1){
		cin >> str;
		if(str=="-1"){
			break;
		}
		cin >> n1;
		cin.ignore();
		mp.insert({str,n1});
	}
	int m; cin >> m;
	cin.ignore();
	long long tong=0;
	map<string,int> tmp;
	while(m--)
	{
		string tam;
		int k;
		cin >> tam; 
		cin >> k;
		cin.ignore();
		tmp.insert({tam,k});
	}
	for(auto i : tmp)
	{
		tong+=i.second*mp[i.first];
	}
	cout << tong;
	return 0;
}
