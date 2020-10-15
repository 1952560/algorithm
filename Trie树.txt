class TrieNode {
public:
  TrieNode* next[26];
  bool isword;
  TrieNode() {
    memset(next, NULL, sizeof(next));
    isword = false;
  }
  ~TrieNode(){
    for (int i = 0; i < 26; i++)
      if (next[i])
        delete next[i];
  }
};

class Trie {
  TrieNode* root;
public:
  Trie() {
    root = new TrieNode();
  }
  ~Trie() {
    delete root;
  }

  void insert(string word) {
    TrieNode* p = root;
    for (int i = 0; i < (int)word.size(); i++) {
      if (p->next[word[i] - 'a'] == NULL)
        p->next[word[i] - 'a'] = new TrieNode();
      p = p->next[word[i] - 'a'];
    }
    p->isword = true;
  }

  bool search(string word) {
    TrieNode* p = root;
    for (int i = 0; i < (int)word.size() && p; i++) {
      p = p->next[word[i] - 'a'];
    }
    return p && p->isword;
  }
};