#include<bits/stdc++.h>
using namespace std;


int main(){
    
	int n,k;
	cin>>n>>k;

	long long int dp[1002][2002][4];
	long long int mod=998244353;
	for(int i=1;i<=1000;i++){
		for(int  j=1;j<=2000;j++){
			for(int k=1;k<=4;k++) dp[i][j][k]=0;
		}
	}

	dp[1][1][1]=1;
	dp[1][1][2]=0;
	dp[1][1][3]=0;
	dp[1][1][4]=1;
	dp[1][2][1]=0;
	dp[1][2][2]=1;
	dp[1][2][3]=1;
	dp[1][2][4]=0;

	for(int i=2;i<=1000;i++){
		for(int j=1;j<=2000;j++){

			dp[i][j][1]=(((dp[i-1][j-1][4]+dp[i-1][j][1])%mod+dp[i-1][j][2])%mod+dp[i-1][j][3])%mod;
			dp[i][j][2]=(((dp[i-1][j-2][3]+dp[i-1][j-1][4])%mod+dp[i-1][j-1][1])%mod+dp[i-1][j][2])%mod;
			dp[i][j][3]=(((dp[i-1][j][3]+dp[i-1][j-2][2])%mod+dp[i-1][j-1][1])%mod+dp[i-1][j-1][4])%mod;
			dp[i][j][4]=(((dp[i-1][j-1][1]+dp[i-1][j][4])%mod+dp[i-1][j][2])%mod+dp[i-1][j][3])%mod;
		}
	}
	cout<<(((dp[n][k][1]+dp[n][k][2])%mod+dp[n][k][3])%mod+dp[n][k][4])%mod;
}