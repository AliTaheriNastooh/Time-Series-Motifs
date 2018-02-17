#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <cmath>
#include<stack>
using namespace std;

struct node
{
  node **a;
  int act;
  node(int k)
  {
    a = new node*[k];
    for(int i=0;i<k;i++)
      a[i] = NULL;
    act = 0;
  }
};

struct my_data
{
  node *root;
  int k, m, margin;
  string s1;
  my_data(int _m, int _k, int _margin)
  {
    k = _k;
    m = _m;
    margin = _margin;
    root = new node(k);
  }
  void ins(string s)
  {
    node *n = root;
    int l=0, r=s.size()-1, f=0;
    while(l<=r)
    {
      f = (f) ? 0 : 1;
      if(f)
      {
        if(n->a[s[l]-'a']==NULL)
          n->a[s[l]-'a'] = new node(k);
        n = n->a[s[l]-'a'];
        l++;
      }
      else
      {
        if(n->a[s[r]-'a']==NULL)
          n->a[s[r]-'a'] = new node(k);
        n = n->a[s[r]-'a'];
        r--;
      }
    }
    n-> act = 1;
  }
  stack<char> st;
  int dfs(node *n, int p)
  {
    if(n==NULL)
      return 0;
    if(n->act)
    {
      while(!st.empty()){
        cout<<st.top();
        st.pop();
      }
      cout<<endl;
      return 1;
    }
    int res = 0;
    for(int i=s1[p]-'a'-margin; i<=s1[p]-'a'+margin ;i++) if(i>=0 && i<k)
    {
      st.push('a'+i);
      res += dfs(n->a[i], p+1);
      st.pop();
    }
    return res;
  }
  int search(string s)
  {
    int l=0, r=s.size()-1, f=0, q=0;
    while(l<=r)
    {
      f = (f) ? 0 : 1;
      if(f)
        s1[q++] = s[l++];
      else
        s1[q++] = s[r--];
    }
    string tmp="";
    return dfs(root, 0);
  }
};

int main()
{
  clock_t t;
  freopen("sax_dataset_converted_6.txt","r",stdin);
  freopen("out.txt","w",stdout);
  int wordSize,alphabetSize,margin;
  cin>>alphabetSize>>wordSize>>margin;
  my_data d(wordSize, alphabetSize, margin);
  string s[500];
  cout<<"Data of: "<<wordSize<<endl;
  cout<<"Build time: ";
  t = clock();
  for(int i=0;i<500;i++)
  {
    cin>>s[i];
    d.ins(s[i]);
  }
  cout<<(double)(clock()-t)/CLOCKS_PER_SEC*1000000<<" microSecond"<<endl;
  int ans;
  string s2="gjhaab";
  cout<<"Find time: ";
  t=clock();
  ans=d.search(s2);
  cout<<(double)(clock()-t)/CLOCKS_PER_SEC*1000000<<" microSecond"<<endl;
  cout<<"Ans: "<<ans<<endl;
  return 0;
}
