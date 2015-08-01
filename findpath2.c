
#include<stdio.h>

int path[6][6],start,end;
int ways[300],count = 0,check[300];

int shortest(int a){
    int i,sum,min = -1,result;
    check[a] = 1;
    for(i = 0;i < 6;i++){
        if(check[i] != 1 && path[a][i] > 0){
            sum = path[a][i];
            if(min == -1){
                min = sum;
                result = i;
            }else{
                if(sum < min){
                    min = sum;
                    result = i;
                }
            }
        }
    }
    return result;
}

int f(int s,int e){
    if(path[s][e] == -1){
        int i;
        for(i = 0;i< count;i++){
            switch(ways[i]){
            case 0:
                printf("A ");
                break;
            case 1:
                printf("B ");
                break;
            case 2:
                printf("C ");
                break;
            case 3:
                printf("D ");
                break;
            case 4:
                printf("E ");
                break;
            case 5:
                printf("F ");
                break;

            }
        }
    }else{
        int next = shortest(s);
        ways[count] = next;count++;
        f(next,e);
    }
}

int main(){

    path[0][0] = path[1][1] = path[2][2] = path[3][3] = path[4][4] = path[5][5] = -1;
    path[0][1] = path[1][0] = 7;
    path[0][2] = path[2][0] = 1;
    path[0][3] = path[3][0] = 0;
    path[0][4] = path[4][0] = 2;
    path[0][5] = path[5][0] = 0;

    path[1][2] = path[2][1] = 2;
    path[1][3] = path[3][1] = 1;
    path[1][4] = path[4][1] = 0;
    path[1][5] = path[5][1] = 0;

    path[2][3] = path[3][2] = 21;
    path[2][4] = path[4][2] = 10;
    path[2][5] = path[5][2] = 9;

    path[3][4] = path[4][3] = 0;
    path[3][5] = path[5][3] = 5;

    path[4][5] = path[5][4] = 30;

    scanf("%d %d",&start,&end);
    ways[count] = start;count++;
    f(start,end);

    return 0;
}