#include<bits/stdc++.h>
using namespace std;

int main(){
  
  string s;
  cin>>s;
  
  int n = s.size();
  vector<int> freq(26,0);
  
  for(int i=0; i<n; i++)
  freq[s[i]-'a']++;
  
  for(int i=0; i<26; i++)
  if(freq[i]>1)
  cout<<char('a'+i)<<" ,count : "<<freq[i]<<endl;
  
}
