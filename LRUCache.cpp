struct keyValue
{
	int key;
	int value;
	keyValue(int key,int value) : key(key), value(value) {}
};


class LRUCache {
public:
	LRUCache(int capacity)
	{
		this->capacity = capacity;
	}

	int get(int key)
	{
		if (map.find(key) == map.end())
		{
			return-1; //not here sorry
		}

		//it is here
		//if there was a function move, we could just move it to the front and map still points to the same node (you can do it if you implement the queue yourself hehe..)
		//since there is not, we need to delete the node and create it again 
		queue.push_front(*(map[key])); //since map[key] is n iterator push the value of it
		queue.erase(map[key]); //delete node
		map[key] = queue.begin(); //point again to it

		return (*map[key]).value; //the value dereferencing the iterator
	}

	void put(int key, int value)
	{
		keyValue kV(key, value);
		
		//if this key is already in cache O(1)
		if (map.find(key) != map.end()) 
		{ //since it is override its value
			queue.erase(map[key]); //map[key] returns iterator delete form queue to push it in the begining O(1)
			map.erase(key);       //delete this key
	          //since it ise dont delete the last one delete this so we can put it again on the front
		}

		//it can not go true if it is already in cache because we erased and and the capacity decreases
		if (queue.size() == capacity) //if this goes true it means is not in cache and its full 
		{
			map.erase(queue.back().key); //delete the key LRU
			queue.pop_back(); //remove the least recently used , the last one			
		}

		queue.push_front(kV); //push the value on the front
		map[key] = queue.begin();//assign the iterator to map
	}

private:
	int capacity;
	list<keyValue>queue; 				  //list of values (double linked list)
	unordered_map<int, list<keyValue>::iterator> map; //key, and pointer to the list node
};