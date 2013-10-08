class Solution {
	public:
		bool isPalindrome(int x) {
			//cout<<sizeof(long long);
			if(x < 0)
				return false;
			long long xx = x;
			long long s = 1;
			while(xx / s)
				s *= 10;
			s /= 10;
			long long e = 10;
			//if(s < e) cout<<s<<"vs"<<e<<"forx"<<x;
			while(s >= e) {
				long long sd = (xx / s);
				long long ed = (xx % e) / (e / 10);
				if(sd!=ed) {
					//cout<<sd<<"vs"<<ed<<"at"<<s;
					return false;
				}
				//cout<<sd<<"vs"<<ed<<"at"<<s;
				xx = xx % s;
				s /= 10;
				e *= 10;
			}
			return true;
		}
};
