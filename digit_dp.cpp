class Solution {
public:
    long long dp[20][2][2]; 
    // dp[index][started][tight]

    long long solve(string &s, int index, bool started, bool tight) {
        // BASE CASE
        if (index == s.size()) {
            return started; 
            // return 1 if a valid number is formed (ignore leading zeros)
        }

        // MEMOIZATION
        if (dp[index][started][tight] != -1) {
            return dp[index][started][tight];
        }

        int limit = tight ? (s[index] - '0') : 9;
        long long ans = 0;

        // TRY ALL DIGITS
        for (int digit = 0; digit <= limit; digit++) {
            bool newStarted = started || (digit > 0);
            bool newTight = tight && (digit == limit);

            if (!newStarted) {
                // still leading zeros
                ans += solve(s, index + 1, false, newTight);
            } else {
                // valid digit started
                ans += solve(s, index + 1, true, newTight);
            }
        }

        return dp[index][started][tight] = ans;
    }

    long long countNumbers(long long n) {
        string s = to_string(n);
        memset(dp, -1, sizeof(dp));
        return solve(s, 0, false, true);
    }
};


#include<bits/stdc++.h>

using namespace std;

string s;

void fun(string ans, int index, bool last) {

	if (index == s.size()) {
		cout << ans << '\n';
		return;
	}

	int till = (last ? (s[index] - '0') : 9);

	for (int i = 0; i <= till; i++) {
		fun(ans + to_string(i), index + 1, (last && (i == till)) );
	}

}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> s;

	fun("", 0, true);


	return 0;
}
