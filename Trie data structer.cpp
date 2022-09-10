//https://www.spoj.com/problems/ADAINDEX/

#include<bits/stdc++.h>
#define int long long int
using namespace std;

const int N=1000000+5;


class Node{
public:
	int eow;
	int cnt;
	Node *ar[26];
	Node()
	{
		cnt=0;
		eow=0;
		for(int i=0;i<26;i++) ar[i]=NULL;
	}
};

void insert(Node *root,string s)
{
	Node *temp=root;
	for(int i=0;i<s.size();i++)
	{
		int index=s[i]-'a';
		
		if(temp->ar[index]==NULL)
		{
			temp->ar[index]=new Node();
		
		}
	
		temp=temp->ar[index];
		temp->cnt++;
	}
	temp->eow++;
}

int search(Node *root,string s)
{
	Node *temp=root;
	for(int i=0;i<s.size();i++)
	{
		int index=s[i]-'a';
		
		if(temp->ar[index]==NULL)
		{
			return 0;
		}
		temp=temp->ar[index];
		
	}
	return (temp->cnt);
}


int32_t main()
{	
//	ios_base::sync_with_stdio(false);
// 	cin.tie(NULL);
 	
 	Node *root=new Node();
 	
 	int n,q;
 	cin>>n>>q;
 	

 	for(int i=1;i<=n;i++)
    {
    	string s;
    	cin>>s;
    	insert(root,s);
	}
	
	for(int i=1;i<=q;i++)
	{
		string s;
		cin>>s;
		cout<<search(root,s)<<"\n";
	}
    
    

}
