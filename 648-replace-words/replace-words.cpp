class Trie{
public: 
    Trie* children[26];
    bool isEnd;

    Trie() {
        for(int i=0; i<26; i++){
            children[i] = nullptr;
        }

        isEnd = false;
    }
};

class Solution {
public:
    Trie* root;

    Solution() {
        root = new Trie();
    }

    void insert(string word){
        Trie* node = root;

        for(char c: word){
            int i = c-'a';
            if(node->children[i] == nullptr){
                node->children[i] = new Trie();
            }

            node = node->children[i];
        }

        node->isEnd = true;
    }

    string search(string word){
        Trie* node = root;
        string res;

        for(char c: word){
            int i = c-'a';
            if(node->children[i] == nullptr){
                return word;
            }

            res += c;
            if(node->children[i]->isEnd){
                return res;
            }

            node = node->children[i];
        }

        return word;
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        // 09.06.24 (potd 08.06.24)
        for(string w: dictionary){
            insert(w);
        }

        stringstream ss(sentence);
        string word, res;

        while(ss >> word){
            if(!res.empty()){
                res += " ";
            }

            res += search(word);
        }

        return res;
    }
};