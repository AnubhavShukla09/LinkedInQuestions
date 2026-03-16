class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(n==0) return true;
        int cnt = 0, x = flowerbed.size();
        if(x==1) {
            if(flowerbed[0]==0) return n==1;
            return false;
        }
        for(int i = 0; i < x; i++) {
            if(flowerbed[i]==0) {
                if(i==0) {
                    if(flowerbed[i+1]==0) {
                        cnt++;
                        flowerbed[i]=1;
                    }
                } else if(i==x-1) {
                    if(flowerbed[i-1]==0) {
                        cnt++;
                        flowerbed[i]=1;
                    }
                } else {
                    if(flowerbed[i-1]==0 and flowerbed[i+1]==0) {
                        cnt++;
                        flowerbed[i]=1;
                    }
                }
            }
            if(cnt==n) return true;
        }
        return false;
    }
};
