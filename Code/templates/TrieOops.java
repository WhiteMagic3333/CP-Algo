public class Trie {
    boolean is_word;
    Trie children[]; //syntax

    public Trie() {
        is_word = false;
        children = new Trie[26];
    }
    
    public void insert(String word) {
        Trie cur = this;
        for (int i = 0; i < word.length(); i++) {
        	if (cur.children[word.charAt(i) - 'a'] == null) {
        		cur.children[word.charAt(i) - 'a'] = new Trie();
        	}
        	cur = cur.children[word.charAt(i) - 'a'];
        }
        cur.is_word = true;
    }
    
    public boolean search(String word) {
        Trie cur = this;
        for (int i = 0; i < word.length(); i++) {
        	if (cur.children[word.charAt(i) - 'a'] == null) {
        		return false;
        	}
        	cur = cur.children[word.charAt(i) - 'a'];
        }
        return cur.is_word;
    }
    
    public boolean startsWith(String prefix) {
        Trie cur = this;
        for (int i = 0; i < word.length(); i++) {
        	if (cur.children[word.charAt(i) - 'a'] == null) {
        		return false;
        	}
        	cur = cur.children[word.charAt(i) - 'a'];
        }
        return true;
    }
}

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * boolean param_2 = obj.search(word);
 * boolean param_3 = obj.startsWith(prefix);
 */