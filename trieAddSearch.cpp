/*
Design a data structure that supports the following two operations:

void addWord(word)
bool search(word)
search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means
it can represent any one letter.

For example:

addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true
Note:
You may assume that all words are consist of lowercase letters a-z.
*/


class node {
    public:
    bool isword;
    node* children[26];
    node(): isword(false){
        memset(children, NULL, sizeof(node*) * 26);
    }
};

class WordDictionary {
public:
    node* root;
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new node();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        node *temp = root;
        for(int i=0;i<word.size();i++){
            if(temp->children[word[i]-'a']==NULL){
                temp->children[word[i]-'a'] = new node();
            }
            temp = temp->children[word[i]-'a'];
        }
        temp->isword = true;
    }
    
    bool srch(const char *ch,node* root){
        if(root==NULL) return false;
        if(*ch=='\0') return root->isword;
        if(*ch!='.')
            return srch(ch+1,root->children[*ch - 'a']);
        else{
            for(int i=0;i<26;i++){
                if(srch(ch+1,root->children[i]))
                    return true;
            }
            return false;
        }
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return srch(word.c_str(),root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */
