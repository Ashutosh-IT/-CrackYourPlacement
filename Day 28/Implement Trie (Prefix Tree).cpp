/*

https://leetcode.com/problems/implement-trie-prefix-tree/description/

*/


// Approach 1 : using 2d array
class Trie {
public:

    vector<vector<int>> trie = vector<vector<int>>(50000,vector<int>(30,0));
    vector<vector<bool>> end = vector<vector<bool>>(50000,vector<bool>(30,0));

    int size = 0;

    Trie() { size = 0; }
    
    void insert(string word) {
        int row = 0;
        for(int i=0; i<word.size(); i++){
            int ch = word[i] - 'a' + 1;
            if(trie[row][ch] == 0){
                size += 1;
                trie[row][ch] = size;
            }
            else {} //do nothing
            row = trie[row][ch];
            if(i == word.size()-1) end[row][ch] = true;
        }
    }
    
    bool search(string word) {
        int row = 0;
        for(int i=0; i<word.size(); i++){
            int ch = word[i] - 'a' + 1;
            if(trie[row][ch] == 0)
            return false;

            else {} //do nothing
            row = trie[row][ch];
            if(i == word.size()-1 && end[row][ch]) return true;
        }
        return false;
    }
    
    bool startsWith(string prefix) {
        int row = 0;
        for(int i=0; i<prefix.size(); i++){
            int ch = prefix[i] - 'a' + 1;
            if(trie[row][ch] == 0)
            return false;

            else {} //do nothing
            row = trie[row][ch];
        }
        return true;
    }
};





// Approach 2 : using trees
class Trie {

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

   TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* temp = root;
        for(int i=0; i<word.size(); i++){
            int ch = word[i] - 'a';
            if(!temp->child[ch]){
                temp->child[ch] = new TrieNode();
            }
            temp = temp->child[ch];
        }
        temp->isLeaf = true;
    }
    
    bool search(string word) {
        TrieNode* temp = root;
        for(int i=0; i<word.size(); i++){
            int ch = word[i] - 'a';
            if(!temp->child[ch]){
                return false;
            }
            temp = temp->child[ch];
        }
        return temp->isLeaf;
    }
    
    bool startsWith(string word) {
        TrieNode* temp = root;
        for(int i=0; i<word.size(); i++){
            int ch = word[i] - 'a';
            if(!temp->child[ch]){
                return false;
            }
            temp = temp->child[ch];
        }
        return true;
    }
};
