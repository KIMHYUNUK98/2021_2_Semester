#include <iostream> 
#include <string>
#include <algorithm> 
#include <queue>
#include <cstring>

using namespace std; 

int dx[8] = {1,2,2,1,-1,-2,-2,-1};
int dy[8] = {-2,-1,1,2,2,1-1,-2};

int main(void) { 
    cin.tie(NULL); 
    
    int num = 0;
    cin >> num;

    int srcx, srcy, destx, desty;

    for(int i = 0 ; i < num; i++) {
        int len = 0;
        cin >> len;
        cin >> srcx >> srcy;
        cin >> destx >> desty;

        int visited[301][301] = {0,};
        int count[301][301] = {0,};
        memset(count, 0, sizeof(count));
        memset(visited, 0, sizeof(visited));

        queue<pair<int,int>> q;

        q.push({srcy, srcx});
        visited[srcy][srcx] = 1;
        if(srcy == desty && srcx == destx) {
            cout << 0 << endl;
            continue;
        }
        int answer = 0;
        int end = 0;

        while(!q.empty()) {
            int nodey = q.front().first;
            int nodex = q.front().second;
            q.pop();

            for(int k = 0 ; k < 8 ; k++) {
                int tempy = nodey + dy[k];
                int tempx = nodex + dx[k];
                if(tempy >= 0 && tempy <= len-1 && tempx >= 0 && tempx <= len-1 
                    && visited[tempy][tempx] == 0) {
                        count[tempy][tempx] = count[nodey][nodex] + 1;
                        visited[tempy][tempx] = 1;
                        q.push({tempy, tempx});
                        if(tempy == desty && tempx == destx) {
                            end = 1;
                            answer = count[tempy][tempx];
                        }
                    }
            }
            if(end == 1) break;
        }
        cout << answer << endl;
    }
    

    return 0; 
}