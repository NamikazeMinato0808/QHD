#include <iostream>
using namespace std;

long S[10000];
long dp[10000];
long trace[10000];

int main(){
	int n;
	cout<<"Nhap so luong phan tu trong mang: ";
	cin>>n;
	cout<<"Nhap mang: ";
	for(int i=0;i<n;i++){
		cin>>S[i];
	}
	for(int i=n-1;i>=0;i--){
		trace[i]=-1;
		dp[i]=1;
		for(int j=i+1;j<n;j++){
			if(S[j]>S[i] && dp[j]+1>dp[i]){
				dp[i]=dp[j]+1;
				trace[i]=j;
			}
		}
	}
	int resPos=0;
	for(int i=0;i<n;i++){
		if(dp[resPos]<dp[i]) resPos=i;
	}
	cout<<"So luong phan tu trong day con khong giam dai nhat: "<<dp[resPos]<<endl;
	cout<<"Day con khong giam dai nhat: ";
	int P=resPos;
	while(P!=-1){
		cout<<S[P]<<" ";
		P=trace[P];
	}
	cout<<endl;
}
