#include <bits/stdc++.h>
using namespace std;
char s[1005][1005];
char path[1005][1005];
int n , m;
 
bool isBoundary ( int x ,int y)
{
  return (x ==0 || x==n-1 || y == 0 || y == m-1);
}
bool isValid( int x , int y)
{
  return ( x>=0 && x<n && y>=0 && y<m && s[x][y] == '.');
}
 
int main()
{
  cin >> n >> m;
  int x1 = 0 , y1 = 0;
  queue < pair <int , int> > q;
  for (int i = 0 ; i < n ; i++)
  {
    for (int j = 0 ; j < m ; j++)
    {
      cin >> s[i][j];
      if(s[i][j] == 'A')
      {
        x1 = i;
        y1 = j;
      }
      else if(s[i][j] == 'M')
      {
        q.push({i,j});
      }
    }
  }
  q.push({x1,y1});
  if(isBoundary(x1,y1))
  {
    cout << "YES" << endl;
    cout << 0 << endl;
    return 0;
  }
  while(q.size())
  {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();
    if(s[x][y] == 'M')
    {
      if(isValid(x+1,y))
      {
        s[x+1][y] = 'M';
        q.push({x+1,y});
      }
      if(isValid(x-1,y))
      {
        s[x-1][y] = 'M';
        q.push({x-1,y});
      }
      if(isValid(x,y-1))
      {
        s[x][y-1] = 'M';
        q.push({x,y-1});
      }
      if(isValid(x,y+1))
      {
        s[x][y+1] = 'M';
        q.push({x,y+1});
      }
    }
    else if(s[x][y] == 'A')
    {
      if(isBoundary(x,y))
      {
        string ans;
        while(x!=x1 || y!=y1)
        {
          ans += path[x][y];
          if(path[x][y] == 'D') x--;
          else if(path[x][y]=='U') x++;
          else if(path[x][y]=='R') y--;
          else  y++;
        }
        reverse(ans.begin(), ans.end());
        cout<<"YES"<< endl;
        cout<<ans.length()<<endl;
        cout<< ans<< endl;
        return 0;
      }
      if(isValid(x+1,y)) { path[x+1][y] = 'D';q.push({x+1,y}); s[x+1][y] = 'A';}
      if(isValid(x-1,y)) { path[x-1][y] = 'U';q.push({x-1,y}); s[x-1][y] = 'A';}
      if(isValid(x,y+1)) { path[x][y+1] = 'R';q.push({x,y+1}); s[x][y+1] = 'A';}
      if(isValid(x,y-1)) { path[x][y-1] = 'L';q.push({x,y-1}); s[x][y-1] = 'A';}
    }
  }
  cout<< "NO"<< endl;
}
