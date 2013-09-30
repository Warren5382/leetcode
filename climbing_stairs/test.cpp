class Solution {
	public:
		int climbStairs(int n) {
			// Start typing your C/C++ solution below
			// DO NOT write int main() function
			int* res=new int[n];
			res[0]=1;
			res[1]=2;
			for(int i =2; i<n;i++){
				res[i] = res[i-1]+res[i-2];
			}
			return res[n-1];
		}
};
