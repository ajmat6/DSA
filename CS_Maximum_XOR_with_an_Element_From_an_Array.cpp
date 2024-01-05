#include<algorithm>

class Node
{
	Node* links[2];
	
	public:
	bool containskey(int bit)
	{
		if(links[bit] != NULL) return true;
		else return false;
	}

	void put(int bit, Node* node)
	{
		links[bit] = node;
	}

	Node* get(int bit)
	{
		return links[bit];
	}
};

class Trie
{
	Node* root;
	public:
	Trie()
	{
		root = new Node();
	}

	void insert(int number)
	{
		Node* node = root;
		for(int i=31; i>=0; i--)
		{
			int bit = (number >> i) & 1;
			if(!node -> containskey(bit))
			{
				node -> put(bit, new Node());
			}

			node = node -> get(bit);
		}
	}

	int getMax(int number)
	{
		int maxXOR = 0;
		Node* node = root;
		for(int i=31; i>=0; i--)
		{
			int bit = (number >> i) & 1;
			if(node -> containskey(1 - bit))
			{
				maxXOR = maxXOR | (1 << i);
				node = node -> get(1 - bit);
			}

			else
			{
				node = node -> get(bit);
			}
		}

		return maxXOR;
	}
};

vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries){
	vector<int> ans(queries.size(), 0);
	sort(arr.begin(), arr.end());
	Trie t;

	// vector for sorted order queries:
	vector<pair<int, pair<int, int>>> oq;
	int index = 0;
	for(auto i: queries)
	{
		int x = i[0];
		int a = i[1];
		int queryIndex = index;

		oq.push_back({a, {x, queryIndex}});
		index++;
	}

	// sorting the queries on the basis of arr[i] value to take make trie containing only those numbers that are less than or equal to arr[i]:
	sort(oq.begin(), oq.end());
	index = 0;

	for(int i=0; i<oq.size(); i++)
	{
		int ai = oq[i].first;
		int x = oq[i].second.first;
		int queryIndex = oq[i].second.second;

		while(index < arr.size() && arr[index] <= ai)
		{
			t.insert(arr[index]);
			index++;
		}

		if(index == 0) ans[queryIndex] = -1;
		else
		{
			ans[queryIndex] = t.getMax(x);
		}
	}

	return ans;
}