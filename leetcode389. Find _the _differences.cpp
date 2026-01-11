
using the unordered map 


class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int> mp;
        for(char &ch : s) {
            mp[ch]++;
        }
        for(char &ch : t) {
            mp[ch]--;

        if(mp[ch] < 0) {
            return ch;
        }
        }
        return 'x';
    }
};


using the xor method!!

class Solution {
public:
    char findTheDifference(string s, string t) {
        int XOR = 0;
        for(char &ch : s) {
            XOR ^= ch;
        }
        for(char &ch : t) {
            XOR ^= ch;
        }
        return (char)XOR;

    }
};
