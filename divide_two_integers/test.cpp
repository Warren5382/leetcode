class Solution {
public:
    int divide(int dividend, int divisor) {
        assert(divisor != 0);
        int res=0;
        int flag=1;
        if((dividend<0 && divisor>0)||(dividend>0 && divisor<0))
            flag=-1;
 
        long long divid=abs((long long)dividend);
        long long divi=abs((long long)divisor);
        long long temp=0;
 
        while(divi<=divid)
        {
            int cnt=1;
            temp=divi;
 
            while((temp<<=1)<=divid)
            {
                cnt<<=1;
            }
            res+=cnt;
            divid-=(temp>>1);
        }
 
        return (int)res*flag;
    }
};
