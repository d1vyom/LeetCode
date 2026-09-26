class LFUCache {
private:
    struct Node {
        int key;
        int value;
        int freq;
    };

    int cap;
    int minFreq;
    
    unordered_map<int, list<Node>> freqToList;

    unordered_map<int, list<Node>::iterator> keyToIter;

    void updateFrequency(int key) {
        auto it = keyToIter[key];
        int value = it->value;
        int freq = it->freq;
        
        freqToList[freq].erase(it);
        
        if (freqToList[freq].empty() && minFreq == freq) {
            minFreq++;
        }
        
        freqToList[freq + 1].push_back({key, value, freq + 1});
        
        keyToIter[key] = prev(freqToList[freq + 1].end());
    }

public:
    LFUCache(int capacity) {
        cap = capacity;
        minFreq = 0;
    }

    int get(int key) {
        if (keyToIter.find(key) == keyToIter.end()) {
            return -1;
        }

        updateFrequency(key);
        return keyToIter[key]->value;
    }
    
    void put(int key, int value) {
        if (cap <= 0) return;

        if (keyToIter.find(key) != keyToIter.end()) {
            keyToIter[key]->value = value;
            updateFrequency(key);
            return;
        }

        if (keyToIter.size() == cap) {

            auto nodeToEvict = freqToList[minFreq].front();
            keyToIter.erase(nodeToEvict.key);
            freqToList[minFreq].pop_front();
        }
        
        minFreq = 1;
        freqToList[1].push_back({key, value, 1});
        keyToIter[key] = prev(freqToList[1].end());
    }
};
