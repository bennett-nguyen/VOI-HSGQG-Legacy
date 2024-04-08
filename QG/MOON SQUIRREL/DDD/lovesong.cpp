#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e6+1;
ll trai[maxn],phai[maxn];
ll cnt=0;
ll d[maxn];
ll time1=0;
ll n,m;
ll a[maxn],b[maxn];
bool ghep(ll x){
	if(d[x]==time1)return false;
	d[x]=time1;
	for(int i=1;i<=m;i++){
		if(a[x]==b[i])continue;
		if(phai[i]==0 || ghep(i)){
			trai[x]=i;
			phai[i]=x;
			return true;
		}
		
	}
	return false;
	
}
void doc(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=m;i++)cin>>b[i];
    
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i]!=b[j]){
				if(phai[j]==0){
					trai[i]=j;
					phai[j]=i;
					cnt++;

					break;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(trai[i]==0){
			time1++;
			if(ghep(i)){
				cnt++;
			}
			
		}
	}
	cout<<cnt<<endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("a.inp","r",stdin);
    doc();
//    xuli();
}
