/*

https://leetcode.com/problems/insert-delete-getrandom-o1/description/

*/

class RandomizedSet {
public:

    vector<int> arr;
    unordered_map<int,int> mp;
    int size;

    RandomizedSet() {
        size = 0;
    }
    
    bool insert(int val) {
        if(mp.find(val) == mp.end()){
            arr.push_back(val);
            mp[val] = size;
            size++;
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(mp.find(val) == mp.end())
        return false;

        int idx = mp[val];

        // if the element is last element
        if(idx == size-1){
            arr.pop_back();
            size--;
            mp.erase(val);
            return true;
        }

        // element is not last element
        mp.erase(val);
        arr[idx] = arr.back();
        arr.pop_back();
        size--;
        mp[arr[idx]] = idx;
        return true;
        
    }
    
    int getRandom() {
        return arr[rand()%size];
    }
};
