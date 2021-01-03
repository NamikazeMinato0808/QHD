#include <iostream>
#include <vector>
using namespace std;

long dp[10000]; //dp[i]: so luong dong xu can it nhat
long trace[10000];

int main(){
	cout<<"Nhap so tien can doi: ";
	int S;
	cin>>S;
	cout<<"Nhap so luong cac menh gia tien: ";
	int n;
	cin>>n;
	cout<<"Nhap cac menh gia tien: ";
	vector<int>t(n);
	for(int i=0;i<n;i++){
		cin>>t[i];
	}
	dp[0]=0;
	for(int i=1;i<=S;i++){
		dp[i]=100000;
		for(int j=0;j<t.size();j++){
			int prevState=i-t[j];
			if(prevState>=0){
				if(dp[prevState]+1<dp[i]){
					dp[i]=dp[prevState]+1;
					trace[i]=t[j];
				}
			}
		}
	}
	if(dp[S]==100000){
		cout<<"Khong co cach doi\n";
	}
	else{
		cout<<"So coin can it nhat la: "<<dp[S]<<endl;
		cout<<"Cac xu can: ";
		while(S!=0){
			cout<<trace[S]<<" ";
			S=S-trace[S];
		}
		cout<<endl;
	}
}
