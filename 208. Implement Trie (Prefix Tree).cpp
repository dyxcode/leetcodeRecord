class Trie
{
public:
	/** Initialize your data structure here. */
	struct Node
	{
		bool isend;
		array<Node*, 26> next;

		Node() : isend(false)
		{
		}
	};
	Node* root;
	Trie()
	{
		root = new Node();
		root->next.fill(nullptr);
	}

	inline int getn(char ch)
	{
		return ch - 'a';
	}
	/** Inserts a word into the trie. */
	void insert(string word)
	{
		Node * cur = root;
		for (auto && ch : word)
		{
			if (cur->next[getn(ch)])
				cur = cur->next[getn(ch)];
			else
			{
				cur->next[getn(ch)] = new Node();
				cur = cur->next[getn(ch)];
				cur->next.fill(nullptr);
			}
		}
		cur->isend = true;
	}

	/** Returns if the word is in the trie. */
	bool search(string word)
	{
		Node * cur = root;
		for (auto && ch : word)
		{
			if (!cur->next[getn(ch)])
				return false;
			cur = cur->next[getn(ch)];
		}
		return cur->isend;
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix)
	{
		Node * cur = root;
		for (auto && ch : prefix)
		{
			if (!cur->next[getn(ch)])
				return false;
			cur = cur->next[getn(ch)];
		}
		return true;
	}
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */