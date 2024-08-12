/*

https://www.geeksforgeeks.org/problems/word-break-trie--141631/1
  
*/


class Solution{
    public:
    // A : given string to search
    // B : vector of available strings
    
    class TrieNode{
        public :
        bool isLeaf;
        TrieNode* child[26];
        
        TrieNode(){
            isLeaf = false;
            for(int i=0; i<26; i++)
            child[i] = NULL;
        }
    };
    
    class Trie{
        public :
        TrieNode* root;
        Trie(){
            root = new TrieNode();
        }
        
        void insert(string s){
            TrieNode* temp = root;
            for(int i=0; i<s.size(); i++){
                int ch = s[i] - 'a';
                if(!temp->child[ch]){
                    temp->child[ch] = new TrieNode();
                }
                temp = temp->child[ch];
            }
            temp->isLeaf = true;
        }
        
        bool solve(string s,int start){
            if(start >= s.size()) return true;
            TrieNode* temp = root;
            for(int i=start; i<s.size(); i++){
                int ch = s[i] - 'a';
                if(!temp->child[ch]){
                    return false;
                }
                else{
                    temp = temp->child[ch];
                    if(temp->isLeaf){
                       if(solve(s,i+1)) return true;
                    }
                }
            }
            
            return false;
        }
    };
    
    int wordBreak(string A, vector<string> &B) {
        //code here
        
        Trie *tree = new Trie();
        for(int i=0; i<B.size(); i++)
        tree->insert(B[i]);
        
        return tree->solve(A,0);
    }
};
