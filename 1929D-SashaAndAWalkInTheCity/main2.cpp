    #include<stdio.h>
    #include<vector>
    typedef long long ll;
    const int N=3e5+5;
    const ll mod=998244353;
    std::vector<int> v[N];
    int t,n;
    ll dp[N];
    auto dfs = [
    	DFS = [](auto &&self,int u,int fa) -> void {
    		ll mul=1;
    		for(auto i:v[u]) if(i!=fa) self(self,i,u),mul=mul*dp[i]%mod;
    		dp[u]=(mul+1)%mod;
    	}
    ](int u,int fa) -> void {DFS(DFS,u,fa);};
    int main(){
    	scanf("%d",&t);
    	while(t--){
    		scanf("%d",&n);
    		for(int i=1;i<=n;i++) v[i].clear(),dp[i]=0;
    		for(int i=1,x,y;i<n;i++) scanf("%d%d",&x,&y),v[x].emplace_back(y),v[y].emplace_back(x);
    		dfs(1,-1);
    		ll ans=0;
    		for(int i=1;i<=n;i++) ans=(ans+dp[i])%mod;
    		printf("%lld\n",((ans-n+1)%mod+mod)%mod);
    	}
    	return 0;
    }
    	  	     		    				      	 	 	