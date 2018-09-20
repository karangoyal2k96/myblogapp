#include<bits/stdc++.h>
using namespace std;

list <int > first[26];
list <int > second[26];
string a,b,c;

int func(int curra,int currb,int currc){

	if(currc==c.size()) return 1;
    cout<<curra<<" "<<currb<<" "<<currc<<"\n";
    
	list<int > :: iterator it1,tempit1;
	list<int > :: iterator it2,tempit2;
    tempit1=lower_bound(first[c[currc]-'a'].begin(),first[c[currc]-'a'].end(),curra);
    tempit2=lower_bound(second[c[currc]-'a'].begin(),second[c[currc]-'a'].end(),currb);
	int ans=0;

	for(it1=tempit1;it1!=first[c[currc]-'a'].end();it1++){

		ans+=func(*it1+1,currb,currc+1);
	}
	for(it2=tempit2;it2!=second[c[currc]-'a'].end();it2++){

		ans+=func(curra,*it2+1,currc+1);
	}

	return ans;
}

int main(){

	
	cin>>a>>b>>c;

    for(int i=0;i<a.size();i++){

    	first[a[i]-'a'].push_back(i);
    }

    for(int i=0;i<b.size();i++){

    	first[b[i]-'a'].push_back(i);
    }

    cout<<func(0,0,0);
}
