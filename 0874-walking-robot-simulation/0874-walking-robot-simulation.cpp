class Solution {
public:
    int robotSim(vector<int>& command, vector<vector<int>>& obstacles) {
        int ans = 0;
        set<pair<int,int>>blocked;
        for(int i=0;i<obstacles.size();i++){
            int x = obstacles[i][0];
            int y = obstacles[i][1];
            blocked.insert({x,y});
        }
        int dir = 0;
        int x =0;
        int y =0;
        for(int i=0;i<command.size();i++){
            if(command[i]>=1&&command[i]<=9){
                int move = command[i];
                while(move>0){
                    if(dir==0){
                        y+=1;
                    }
                    else if(dir==1){
                        x+=1;
                    }
                    else if(dir==2){
                        y-=1;
                    }
                    else{
                        x-=1;
                    }
                    if(blocked.find({x,y})!=blocked.end()){
                            if(dir==0){
                            y-=1;
                        }
                        else if(dir==1){
                            x-=1;
                        }
                        else if(dir==2){
                            y+=1;
                        }
                        else{
                            x+=1;
                        }
                        break;
                    }
                    move--;
                }
            }
            else if(command[i]==-1){
                if(dir==0) dir=1;
                else if(dir==1) dir=2;
                else if(dir==2) dir=3;
                else dir=0;
            }
            else{
                if(dir==0) dir=3;
                else if(dir==1) dir=0;
                else if(dir==2) dir=1;
                else dir=2;
            }
          int curr_dist = x*x+y*y;
          ans = max(ans,curr_dist);
        }
        return ans;
    }
};