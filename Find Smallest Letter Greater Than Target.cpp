class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int l,r,m,ans=-1;
        l = 0;
        r = letters.size()-1;
        while(l<=r){
            m = l+(r-l)/2;
            if(letters[m]<=target){
                l=m+1;
            } else {
                ans = m;
                r = m-1;
            }
        }
        if(ans==-1)return letters[0];
        return letters[ans];
    }
};
