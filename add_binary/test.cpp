class Solution {
	public:
		string addBinary(string a, string b) {
			// Start typing your C/C++ solution below
			// DO NOT write int main() function
			int la = a.size();
			int lb = b.size();
			string sum = la > lb ? a : b;
			int overflow = 0;
			for( int i = 0; i < sum.size(); i ++ )
			{
				char ca = i < la ? a[la - i - 1] : '0';
				char cb = i < lb ? b[lb - i - 1] : '0';
				int bit = ca - '0' + cb - '0' + overflow;
				overflow = bit / 2;
				sum[sum.size() - i - 1] = bit % 2 + '0';
			}
			if(overflow)
			{
				sum = "1" + sum;
			}
			return sum;
		}
};
