struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    // integer
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM =
            chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }

    // pair
    size_t operator()(const pair<int,int>& p) const {
        static const uint64_t FIXED_RANDOM =
            chrono::steady_clock::now().time_since_epoch().count();

        uint64_t x = ((uint64_t)p.first << 32) | (uint32_t)p.second;
        return splitmix64(x + FIXED_RANDOM);
    }

    // vector
    size_t operator()(const vector<int>& v) const {
        static const uint64_t FIXED_RANDOM =
            chrono::steady_clock::now().time_since_epoch().count();

        uint64_t hash = FIXED_RANDOM;
        for (int x : v) {
            hash = splitmix64(hash ^ x);
        }
        return hash;
    }
};


Usage : 

unordered_map<uint64_t, int, custom_hash> mp1;
unordered_map<pair<int,int>, int, custom_hash> mp2;
unordered_map<vector<int>, int, custom_hash> mp3;

unordered_set<uint64_t, custom_hash> s1;
unordered_set<pair<int,int>, custom_hash> s2;
unordered_set<vector<int>, custom_hash> s3;
