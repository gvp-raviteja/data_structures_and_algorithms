/*
Given a list of words (without duplicates), please write a program that returns all concatenated words in the given list of words.
A concatenated word is defined as a string that is comprised entirely of at least two shorter words in the given array.

Example:
Input: ["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"]
Output: ["catsdogcats","dogcatsdog","ratcatdogcat"]

Explanation: "catsdogcats" can be concatenated by "cats", "dog" and "cats"; 
 "dogcatsdog" can be concatenated by "dog", "cats" and "dog"; 
"ratcatdogcat" can be concatenated by "rat", "cat", "dog" and "cat".

Note:
The number of elements of the given array will not exceed 10,000
The length sum of elements in the given array will not exceed 600,000.
All the input string will only include lower case letters.
The returned elements order does not matter.
*/

// Solution using trie, memory limit exceeded in leetcode.

class node {
    public:
    bool isword;
    node* children[26];
    node(): isword(false){
        memset(children, NULL, sizeof(node*) * 26);
    }
};


class Solution {
public:
    node* root;
    Solution(){
        root = new node();
    }
    int isConcat = 0;
    void addWord(string word) {
        if(word.size()!=0){
            node *temp = root;
            for(int i=0;i<word.size();i++){
                if(temp->children[word[i]-'a']==NULL){
                    temp->children[word[i]-'a'] = new node();
                }
                temp = temp->children[word[i]-'a'];
            }
            temp->isword = true;
        }
    }
    
    bool search(node *temp,string word, int index){
        if(index == word.size() || temp==NULL){
            if(isConcat && temp!=NULL && temp->isword){
                isConcat = false;
                return true;
            }
            return false;
        }
        if(temp->isword){
            isConcat++;
            //cout << word[index] << endl;
            if(search(root,word,index))
                return true;
            isConcat--;
        }
        
        return search(temp->children[word[index]-'a'],word,index+1);
    }
    
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> conc;
        for(int i=0;i<words.size();i++)
            addWord(words[i]);
        for(int i=0;i<words.size();i++){
            //cout << words[i];
            if(search(root,words[i],0))
                conc.push_back(words[i]);
        }
        cout << conc.size();
        return conc;
    }
};
