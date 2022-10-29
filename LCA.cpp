
#include <bits/stdc++.h>

using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
char dr[4] = {'U', 'R', 'D', 'L'};
int vis[200001];
int dis[200001];
int par[400001];
int in[400001];
int out[400001];
vector<int> adj[400001];
vector<int> res;
int timer=0;
map<int, pair<int, int>> mapp;
int ans = -1;
void dfs(int v,int p)
{
    // cout<<v<<endl;

    // vis[v] = 1;
    par[v] = p;
    in[v]=timer++;
    

    for (auto child : adj[v])
    {
        
            dfs(child,v);
       
    }

    out[v]=timer++;

}
void dfs2(int v, int par, vector<int> &ar, vector<int> &dp)
{

    vis[v] = 1;

    bool flag = true;
    for (auto child : adj[v])
    {
        if (vis[child] == 0)
        {
            dfs2(child, v, ar, dp);
            if (!dp[child])
                flag = false;
        }
    }

    if (par == -1)
    {
        if (flag)
        {
            ans = v;
            return;
        }
    }
    else
    {
        if (flag)
        {
            if (ar[par] == ar[v] && mapp[v].second < 1)
            {
                ans = v;
                return;
            }
            if (ar[par] != ar[v] && mapp[v].second <= 1)
            {
                ans = v;
                return;
            }
        }
    }
}
bool isancestor(int x,int y)
{
    return in[x]<in[y]&&out[x]>out[y];
}
void solve()
{

    ans = -1;
    int n, m, k ,q;
    cin >> n>>q;
    timer=0;
    memset(vis,0,sizeof(vis));
    memset(par,-1,sizeof(par));
    for(int i=1;i<=n;i++)
    adj[i].clear();

    m=n-1;
    for(int i=2;i<=n;i++)
    {
        int x,y;
        cin>>x;
        adj[x].push_back(i);
    }

    dfs(1,-1);
    vector<vector<int>>LCA(n+1,vector<int>(32,-1));


    for(int i=1;i<=n;i++)
    {
        LCA[i][0]=par[i];
        for(int j=1;j<32;j++)
        {
            int temp=LCA[i][j-1];
            if(temp!=-1)
            LCA[i][j]=LCA[temp][j-1];
        }   
    }




    while(q--)
    {
        int x,y;
        cin>>x>>y;
        if(x==y)
        {
            cout<<y<<endl;
            continue;
        }

        if(isancestor(x,y))
        {
            cout<<x<<endl;
            continue;;
        }
        else if(isancestor(y,x))
        {
            cout<<y<<endl;
            continue;;
        }
        else
        {
        for(int i=31;i>=0;i--)
        {
            int temp=LCA[x][i];
            if(temp!=-1&&!isancestor(temp,y))
            {
                x=temp;
            }
        }
        cout<<LCA[x][0]<<endl;;
        }

       
    }

  
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // fastio();
    // seive();
    int t;
    // cin>>t;
    t = 1;
    for (int i = 0; i < t; i++)
    {
        // cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}
