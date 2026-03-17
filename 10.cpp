// // Given two strings s and t, return true if t is an anagram of s, and false otherwise.

// Example 1:
// Input: s = "anagram", t = "nagaram"
// Output: true

// Example 2:
// Input: s = "rat", t = "car"
// Output: false

// Constraints:
// 1 <= s.length, t.length <= 5 * 10^4
// s and t consist of lowercase English letters.


class Solution {
public:
    bool isAnagram(string s, string t) {
        //if  size of s and t is not equal 
        if (s.size() != t.size()) return false;

        int freq[256] = {0};
        //traversing over 's' and increasing the freq of character 

        //freq[i] will store the frequency of character with ASCII value i.
        for (char c : s) freq[c]++;
        //traversing over 't' and decreaing the freq of characher
        for (char c : t) freq[c]--;

        for (int i = 0; i < 256; i++) {
            if (freq[i] != 0) return false;
        }

        return true;
    }
};
//time complexity----->o(n)
//space complexity---->Loop over frequency array of size 256 → O(256) ≈ O(1)


// 🚀 Interview Tip
// If the question says:--------->Only lowercase letters (a-z)
// Then you can use:--------------->int freq[26];

class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if(s.size() != t.size())
            return false;
        
        int freq[26] = {0};
        
        for(int i = 0; i < s.size(); i++) {
            freq[s[i] - 'a']++;   // increase for s
            freq[t[i] - 'a']--;   // decrease for t
        }
        
        for(int i = 0; i < 26; i++) {
            if(freq[i] != 0)
                return false;
        }
        
        return true;
    }
};
// TC = O(n)
// SC = O(1)