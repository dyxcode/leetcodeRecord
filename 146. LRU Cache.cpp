class LRUCache
{
public:
	unordered_map<int, list<pair<int, int>>::iterator> m_map;
	list<pair<int, int>> m_list;
	int size;

	LRUCache(int capacity)
	{
		size = capacity;
	}

	int get(int key)
	{
		auto it = m_map.find(key);
		if (it != m_map.end())
		{
			auto list_it = it->second;
			m_list.splice(m_list.begin(), m_list, list_it);
			return m_list.front().second;
		}
		return -1;
	}

	void put(int key, int value)
	{
		auto it = m_map.find(key);
		if (it != m_map.end())
		{
			auto list_it = it->second;
			m_list.splice(m_list.begin(), m_list, list_it);
			m_list.front().second = value;
		}
		else
		{
			if (m_map.size() == size)
			{
				int k = m_list.back().first;
				m_list.pop_back();
				m_map.erase(k);
			}
			m_list.push_front({key, value});
			m_map.insert({key, m_list.begin()});
		}
	}
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */