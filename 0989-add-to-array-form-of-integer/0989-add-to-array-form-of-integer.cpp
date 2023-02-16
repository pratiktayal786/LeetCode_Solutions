class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        
        int i = num.size()-1;
        int car = 0;
        
        while(k > 0 && i >= 0){
            int x = k%10;
            k /= 10;
            x += car;
            
            car = (num[i] + x)/10;
            num[i] = (num[i] + x)%10;
            i--;
        }
        while(i >= 0 and car){
            int x = num[i];
            num[i] = (x + car)%10;
            car = (x+car)/10;
            i--;
        }
        while(k > 0){
            int x = k%10;
            k /= 10;
            num.insert(num.begin(), (x+car)%10);
            car = (x+car)/10;
        }
        if(car) num.insert(num.begin(), car);
        return num;
    }
};