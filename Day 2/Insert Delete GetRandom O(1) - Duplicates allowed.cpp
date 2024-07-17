/*

https://leetcode.com/problems/insert-delete-getrandom-o1-duplicates-allowed/description/

*/

class RandomizedCollection {
public:

    vector<int> arr;
    unordered_map<int,set<int>> mp;
    int size;

    RandomizedCollection() {
        size = 0;    
    }
    
    bool insert(int val) {
        if(mp[val].empty()){
            arr.push_back(val);
            mp[val].insert(size);
            size++;
            return true;
        }

        arr.push_back(val);
        mp[val].insert(size);
        size++;
        return false;
    }
    
    bool remove(int val) {
        if(mp[val].empty())
        return false;

        int num = arr.back();
        arr.pop_back();

        int idx = *(mp[val].begin());
        mp[val].erase(idx);
        mp[num].insert(idx);
        mp[num].erase(size-1);

        arr[idx] = num;
        size--;
        return true;
    }
    
    int getRandom() {
        return arr[rand()%size];
    }
};
