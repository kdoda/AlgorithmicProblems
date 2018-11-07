#include <iostream>
#include <unordered_map>

using namespace std;

//Given 2 words, return true if second word has a substring that is also an anagram of word 1.
//LGE, GOOGLE - True
//GEO, GOOGLE - False
//The anagram should be a substring

//constant time, at the very most 256 iterations
//this approach over vectors is better, because it uses less space in average
//and also faster since it compares the size first 
bool equalMaps(unordered_map<char, int> &pm,
	unordered_map<char, int> &sm)
{
	if (pm.size() != sm.size())
		return false;

	for (unordered_map<char, int>::iterator it = pm.begin();
		it != pm.end();
		++it)
	{
		if (sm.find(it->first) == sm.end() //if this key is not in the map
			|| sm[it->first] != it->second) //if it is there, check the values
			return false;
	}

	return true;
}

bool isSubstringAnagram(string p, string s)
{
	unordered_map<char, int> pm; //patternMap, char frequency for p (pattern) string
	for (int i = 0; i < p.size(); ++i)
		pm[p[i]]++;

	//sMap, going to be the map for char freq for every possible substring
	unordered_map<char, int> sm;
	int begin = 0; //the first position of the window
	//we are going to use the sliding window concept, so we can solve it in O(n + m), n = p.size(), m s.size()
	for (int i = 0; i < p.size(); ++i) //process the first substring
		sm[s[i]]++;

	for (int i = p.size(); i < s.size(); ++i, ++begin)
	{
		//check if the current substring is anagram to p
		if (equalMaps(pm, sm))
			return true;

		char c = s[begin]; //begin char 

		sm[c]--; //move the sliding window be decrementing the freq of the first
		if (sm[s[begin]] == 0)//remove it now
			sm.erase(c);

		// add the new char, of the end of the window
		sm[s[i]]++;
	}

	return equalMaps(pm, sm); //the last one
}

int main()
{
	cout << isSubstringAnagram("GEO", "GOOGLE") << endl; //0
	cout << isSubstringAnagram("LGE", "GOOGLE") << endl; //1
}