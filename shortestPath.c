#include<stdio.h>

int path[6][6];
int start,end; // A = 0,B = 1 ,... , F = 5

int ways[300];
int count = 0;

int s[300];
int c = 0;

int findPath(int a,int b){
    if(a==b){
    	int o;
    	for(o=0;o<count;o++){
    		printf("%d ",ways[o]);
    	}
    	printf("\n");
    	return -1;
    }else{
    	int i,sum,p;
    	for(i=0;i<6;i++){
    		int j,z=0;
    		for(j=0;j<count;j++){
    			if(ways[j] == i){
    				z = 1;
    			}
    		}
    		if(z == 0){
    			ways[count] = i;count++;
    			int d = findPath(i,b);
    			count--;
    			
    			if(d == -1){
    				sum == path[a][i];
    			}else if(d<sum){
    				sum = d;
    				p = i;
    			}
    		}
    	}
    	s[c] = p;c++;
    }
}

int main(){

    path[1][1] = path[2][2] = path[3][3] = path[4][4] = path[5][5] = 0;
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
    ways[count] = start;
    findPath(start,end);
    
    int i;
    for(i=0;i<6;i++){
    	//printf("%d ",s[i]);
    }
    
    return 0;
}