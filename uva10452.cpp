#include <cstdio>
#include <vector>
#include <string>
using namespace std;

int row, col, sI, sJ;
char letters[8] = {'@', 'I', 'E', 'H', 'O', 'V', 'A', '#'};
char grid[9][9];
vector <string> ans;

void visit(int i, int j, int index){

    if (j-1 >= 0) {
        if (letters[index+1] == grid[i][j-1])
        ans.push_back("left"),visit(i,j-1,index+1);
    }
    if (j+1 < col) {
        if(letters[index+1] == grid[i][j+1])
        ans.push_back("right"),visit(i,j+1,index+1);
    }
    if (i-1 >= 0){
        if(letters[index+1] == grid[i-1][j])
          ans.push_back("forth"),visit(i-1,j,index+1);
    }
}

int main(){
    int i,j,t;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d", &row, &col);
        for(i=0;i<row;i++) scanf("%s", grid[i]);

        for(i=0;i<row;i++) for(j=0;j<col;j++){
           if(grid[i][j]=='@') sI=i,sJ=j;
        }
        ans.clear();
        visit(sI, sJ, 0);
        for(int i=0;i<ans.size()-1;i++)
            printf("%s ",ans[i].c_str());
        printf("%s\n",ans[ans.size()-1].c_str());
    }
    return 0;
}
