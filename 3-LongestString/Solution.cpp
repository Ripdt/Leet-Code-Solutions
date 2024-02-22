class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        string longestSubstring = "", currentSubstring;
        for (const char character : str) {
            const int position = currentSubstring.find(character);
            if (position == -1) currentSubstring += character;
            else {
                longestSubstring = currentSubstring.length() > longestSubstring.length() ? currentSubstring : longestSubstring;
                currentSubstring = currentSubstring.substr(position + 1, currentSubstring.length()) + character;
            }
        }
        return max(longestSubstring.length(), currentSubstring.length());
    }
};