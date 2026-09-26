class AllOne {
private:
    struct Bucket {
        int count;
        unordered_set<string> keys;
    };

    list<Bucket> buckets;
    
    unordered_map<string, list<Bucket>::iterator> key_to_bucket;

public:
    AllOne() {}

    void inc(string key) {

        if (key_to_bucket.find(key) == key_to_bucket.end()) {

            if (buckets.empty() || buckets.front().count != 1) {
                buckets.push_front({1, {}});
            }
            buckets.front().keys.insert(key);
            key_to_bucket[key] = buckets.begin();
        }

        else {
            auto current_bucket = key_to_bucket[key];
            auto next_bucket = next(current_bucket);
            int next_count = current_bucket->count + 1;

            if (next_bucket == buckets.end() || next_bucket->count != next_count) {
                next_bucket = buckets.insert(next_bucket, {next_count, {}});
            }

            next_bucket->keys.insert(key);
            key_to_bucket[key] = next_bucket;

            current_bucket->keys.erase(key);
            if (current_bucket->keys.empty()) {
                buckets.erase(current_bucket);
            }
        }
    }

    void dec(string key) {

        auto current_bucket = key_to_bucket[key];
        int prev_count = current_bucket->count - 1;

        if (prev_count == 0) {

            key_to_bucket.erase(key);
        } else {
            auto prev_bucket = prev(current_bucket);

            if (current_bucket == buckets.begin() || prev_bucket->count != prev_count) {
                prev_bucket = buckets.insert(current_bucket, {prev_count, {}});
            }

            prev_bucket->keys.insert(key);
            key_to_bucket[key] = prev_bucket;
        }

        current_bucket->keys.erase(key);
        if (current_bucket->keys.empty()) {
            buckets.erase(current_bucket);
        }
    }

    string getMaxKey() {
        if (buckets.empty()) return "";
        return *(buckets.back().keys.begin());
    }

    string getMinKey() {
        if (buckets.empty()) return "";
        return *(buckets.front().keys.begin());
    }
};
