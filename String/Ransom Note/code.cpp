class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int len = ransomNote.length();
        for(int i = 0; i < len; i++){
            int position = magazine.find(ransomNote[i]);
            if (magazine.find(ransomNote[i]) == string::npos) {
                return false;
            }
            magazine.erase(position, 1);
        }
        return true;
    }
};