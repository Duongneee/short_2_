//C++ 
#include <bits/stdc++.h> 
#define pii pair < int, int >

using namespace std;
int n, m, u, v, w, s, t;
int f[1000009]; // đánh dấu khoảng cách từ đỉnh bắt đầu tới đỉnh hiện tại 
vector < pii > a[100009];   
priority_queue < pii, vector < pii >, greater < pii > > pq;
pii x;

int main() 
{ 
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i=1; i<=m; ++i)
    {
        cin >> u >> v >> w;
        a[u].push_back({w, v});
    }
    cin >> s >> t;
    
    memset(f, -1, sizeof(f));
    pq.push({0, s});
    f[s] = 0;
    while(pq.size())
    {
        x = pq.top();
        pq.pop();
        
        if(x.second == t)
        {
            cout << x.first;
            return 0;
        }
        
        u = x.second; w = x.first;
        if(f[u] != w) // được cập nhật và không còn giá trị w -> không cần phải duyệt nữa vì có đường khác ngắn hơn rồi. 
            continue; 
            
        for(pii c:a[u])
        {
            v = c.second;
            if(f[v] == -1 || f[v] > w + c.first)
            {
                f[v] = w + c.first;
                pq.push({f[v], v});
            }
        }
    }
    cout << -1;
    return 0;
}
