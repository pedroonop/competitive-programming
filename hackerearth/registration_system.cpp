// C++ implementation of search and insert  operations on Trie
#include <bits/stdc++.h>
using namespace std;
 
const int ALPHABET_SIZE = 26;
 
// trie node
struct TrieNode{
    struct TrieNode *children[ALPHABET_SIZE];
 
    // isEndOfWord is true if the node represents
    // end of a word
    bool isEndOfWord;
   
};
 
// Returns new trie node (initialized to NULLs)
struct TrieNode *getNode(void){
    struct TrieNode *pNode =  new TrieNode;
 
    pNode->isEndOfWord = false;
 
    for (int i = 0; i < ALPHABET_SIZE; i++)
        pNode->children[i] = NULL;
 
    
    return pNode;
}
 
// If not present, inserts key into trie
// If the key is prefix of trie node, just
// marks leaf node
int insert(struct TrieNode *root, string key){
    struct TrieNode *pCrawl = root;
		
		bool end = false;
		
		int cnt = 0;
 
    for (int i = 0; i < (int) key.length(); i++){
        int index = key[i] - 'a';
        
        if(!end) cnt++;
        
        if (!pCrawl->children[index]){
            pCrawl->children[index] = getNode();
						end = true;	
				}
				
        pCrawl = pCrawl->children[index];
    }
 
		return cnt;
 
    // mark last node as leaf
    pCrawl->isEndOfWord = true;
}

// Driver
int main(){
  int T;
  
  cin >> T;
  
  for(int t = 1; t <= T; t++){
		int N;
		cin >> N;
		
		struct TrieNode *root = getNode();	
		
		long long int ans = 0;	
		for(int i = 0; i < N; i++){
			string key;
			cin >> key;
			ans += insert(root, key);
			//printf("\n%d ans %lld\n", i, ans); 
		}
		
		printf("Case #%d: %lld\n", t, ans);
		
	}  
       
  return 0;
}
