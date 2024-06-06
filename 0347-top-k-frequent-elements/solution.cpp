class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // @ my approach
        unordered_map<int, int> mp;
        for(auto it: nums){
            mp[it]++;
        }
        
        //since map is sorted a/c to keys but we want ans to be soted by valuse
        //so create a another map and push value first then data of map1
        //since there may be duplicate keys so use multimap
        multimap<int, int> multiMap;
        unordered_map<int, int>::iterator it;
        for (it = mp.begin(); it != mp.end(); it++) {
            multiMap.insert({ it->second, it->first });
        }

        
        //not our multimap contans occurance as keya and no as value
        //ans since map is bydefault sorted in asceding order but we hand max
        // occerence first so we traverse from last of map
        vector<int> ansVec;
        multimap<int, int>::reverse_iterator itr2;
        // rbegin() returns to the last value of map
        for (itr2 = multiMap.rbegin(); itr2 != multiMap.rend(); itr2++) {
            ansVec.push_back(itr2->second);

            if(ansVec.size() == k) return ansVec;
        }

        return ansVec;
    }
};
