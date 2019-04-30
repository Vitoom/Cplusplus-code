#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
using namespace std;

class Solution {
    struct Tries {
        string word;
        unordered_map<char, Tries*> char_map;
        bool isStr;
        Tries(): isStr(false), word("") {}
    };

    void insert(string s, Tries*& root) {
        if(!root){
            root = new Tries();
        }
        Tries* current = root;
        for(int i=0; i<s.size(); i++){
            if(current->char_map.find(s[i]) == current->char_map.end()){
                current->char_map[s[i]] = new Tries();
            }
            current = current->char_map[s[i]];
            if(i+1 == s.size()){
                current->word = s;
                current->isStr = true;
            }
        }
    }

public:
    void dfs(vector<vector<char>> board, int i, int j, unordered_set<string>& Set, Tries* root) {
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j] == '#'
           || root->char_map.find(board[i][j])==root->char_map.end()) return;
        char c = board[i][j];
        root = root->char_map[c];
        if(root->isStr)
            Set.insert(root->word);
        dfs(board, i-1, j, Set, root);
        dfs(board, i+1, j, Set, root);
        dfs(board, i, j+1, Set, root);
        dfs(board, i, j-1, Set, root);
        board[i][j] = c;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if(board.empty() || words.empty()) return {};
        Tries* root = NULL;
        unordered_set<string> Set;
        vector<string> ret;
        for(auto w: words){
            insert(w, root);
        }
        for(int i=0; i<board.size(); i++)
            for(int j=0; j<board[0].size(); j++)
                if(root->char_map.find(board[i][j])!=root->char_map.end())
                    dfs(board, i, j, Set, root);
        for(auto s: Set){
            ret.push_back(s);
        }
        return ret;
    }
};

int main() {
    vector<vector<char>> board = {{'o', 'a', 'a', 'n'}, {'e', 't', 'a', 'e'}, {'i', 'h', 'k', 'r'}, {'i', 'f', 'l', 'v'}};
    vector<string> words = {"oath", "pea", "eat", "rain"};
    Solution s;
    vector<string> ret = s.findWords(board, words);
    for(auto r:ret){
        cout<<r<<endl;
    }
    return 0;
}