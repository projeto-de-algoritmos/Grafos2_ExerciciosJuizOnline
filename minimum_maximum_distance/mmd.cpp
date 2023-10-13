#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
 
vector<ll>dijka(ll node,vector<ll>adj[], ll n){
    
    vector<ll>dist(n+1,1e9);
    dist[node]=0;
    
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> priority_queue;
    
    priority_queue.push({0,node});
    
    while(!priority_queue.empty()){
        
        ll d1 = priority_queue.top().first;
        ll node1 = priority_queue.top().second;
        priority_queue.pop();
        
        for(auto it:adj[node1]){
            if(dist[it]>1+d1){
                dist[it]=1+d1;
                priority_queue.push({1+d1,it});
            }
        }
    }
    return dist;
}
 
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n,k;
        cin>> n>> k;
        unordered_set<ll>st;
        
        for(ll i=0; i<k; i++){
            ll x;
            cin>> x;st.insert(x);
        }

        vector<ll>adj[n+1];
        for(ll i=0;i<n-1;i++){
            ll x,y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        vector<ll>vec1 = dijka(*(st.begin()),adj,n);
        ll node1 = -1;
        ll ans1 = -1;
        
        for(ll i=1;i<=n;i++){
            if(st.find(i)!=st.end() && vec1[i]>ans1){
                ans1 = vec1[i];
                node1=i;
            }
        }

        vector<ll>vec2 = dijka(node1,adj,n);
        ll ansf = -1;
        ll nodef = -1;
        for(ll i=1;i<=n;i++)if(st.find(i)!=st.end() && vec2[i]>ansf)ansf = vec2[i];
        cout<<(ansf+1)/2<<endl;
    }
 
    return 0;
}