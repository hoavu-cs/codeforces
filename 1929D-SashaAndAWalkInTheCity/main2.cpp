    #include<bits/stdc++.h>
    using namespace std;
    #define rep(s,e,i) for (int i = s; i <= e; ++i)
    #define pb push_back
    #define tcs int T;cin>>T;while(T--)
    const int MOD=998244353,N=3*1e5+2;
    vector<int>adj[N];int ans;
     
    int dfs(int ind,int par){long long ans1=1;for(auto ch:adj[ind]){
    if(ch!=par){int z=dfs(ch,ind);ans1=(ans1*z)%MOD;ans=(ans+z-1)%MOD;}}return ans1+1;}
     
    signed main(){tcs{int n,x,y;cin>>n;rep(1,n-1,i){cin>>x>>y;adj[x].pb(y);adj[y].pb(x);}
    ans=0;cout<<(dfs(1,-1)+ans)%MOD<<endl;rep(1,n,i){adj[i].clear();}}}