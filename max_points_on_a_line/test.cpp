class Solution {
public:
//判断点是否在直线上，就是判断斜率是否相同
    int maxPoints(vector<Point> &points) {
        int maxLine = 0;
        
        if(points.size() <=2)
            return points.size();

        for (int i=0; i<points.size()-1; i++) {
            int coincident = 0;
            int h = 0;
            map<double, int> pointCounts;
            map<double, int>::iterator it;
            for (int j=i+1; j<points.size(); j++) {
                double slope;
                if (points[i].x==points[j].x && points[i].y==points[j].y) {
                    coincident++;//考虑重复元素，直接在每一条包含该点的直线上都加1
                    continue;
                } else if (points[i].x == points[j].x) {
                    h++;//对于斜率不存在的情况，特殊处理
                    continue;
                } else if (points[i].y == points[j].y) {
                    slope = 0.0; // double类型分正0与负0，在计算机内的表示不一样，故需要在此特别标明
                } else {
                    slope = (double)(points[i].y-points[j].y) / (points[i].x-points[j].x);
                }
                
                it = pointCounts.find(slope);
                if (it!=pointCounts.end())
                    it->second +=1;
                else
                    pointCounts.insert(pair<double,int>(slope,1));
            }
            coincident++;//将索引为i的元素计算在内
            h = h + coincident;//计算重复元素
            if(maxLine < h)
                maxLine = h;
            for(it = pointCounts.begin();it!=pointCounts.end();it++){
                if(maxLine < (it->second+coincident)){
                    maxLine = it->second+coincident;
                }
            }
        }
        return maxLine;
    }
};
