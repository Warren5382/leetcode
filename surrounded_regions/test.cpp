class Solution {
	public:
		void solve(vector<vector<char>> &board) {
			// Start typing your C/C++ solution below
			// DO NOT write int main() function
			int N = board.size();
			if (N == 0) return;
			int M = board[0].size();
			if (M == 0) return;
			vector<vector<bool>> mark(N, vector<bool>(M, false));
			vector<int> queX;
			vector<int> queY;
			int dir[4][2] = {0,1,0,-1,1,0,-1,0};
			for(int i = 0; i < N; i++) {
				for(int j = 0; j < M; j++) {
					if(!mark[i][j] && board[i][j]=='O') {
						queX.push_back(i);
						queY.push_back(j);
						mark[i][j]=true;
						int head=0;
						bool onEdge = false;
						if(i==0||j==0||i==N-1||j==M-1) {
							onEdge = true;
						}
						while(head<queX.size()) {
							int nowx = queX[head];
							int nowy = queY[head];
							head++;
							for(int k = 0; k < 4; k++) {
								int nextx = nowx+dir[k][0];
								int nexty = nowy+dir[k][1];
								if(nextx>=0&&nextx<N&&nexty>=0&&nexty<M) {
									if(!mark[nextx][nexty]&&board[nextx][nexty]=='O') {
										mark[nextx][nexty]=true;
										queX.push_back(nextx);
										queY.push_back(nexty);
										if(nextx==0||nexty==0||nextx==N-1||nexty==M-1) {
											onEdge = true;
										}
									}
								}
							}
						}
						if(!onEdge) {
							for(int i = 0; i < queX.size(); i++) {
								board[queX[i]][queY[i]]='X';
							}
						}
						queX.clear();
						queY.clear();
					}
				}
			}
		}
};
