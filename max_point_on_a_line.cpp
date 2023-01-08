class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if(points.size()==1)
            return 1;
        map<float,int>m;
        int maxi = 0;
        for(int i=0;i<points.size();i++){
            int val=1;
            for(int j=i+1;j<points.size();j++){
                float slope;
                if(points[j][0]-points[i][0]==0)
                    slope=1e5;
                else{
                    slope = (float)(points[j][1]-points[i][1])/(float)(points[j][0]-points[i][0]);
                }
                m[slope]++;
                val = max(val,m[slope]);
            }
            m.clear();
            maxi=max(maxi,val);
        }
        return  maxi+1;
    }
};
