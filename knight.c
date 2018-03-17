
#include <stdio.h>
 
int chess[10][10];
 
int checkPosition(int x, int y) {
    if(x<10 && y<10 && x>=0 && y>=0) {
        return 1;
    } else {
        return 0;
    }
    
}
 
int nextPostion(int x,int y ,int N) {
    int i= checkPosition(x,y);
    if(N<=0 && i) {
        chess[x][y]=1;
        return ;
    }
    if(!i) {
        return ;
    }
    
    N--;
    nextPostion(x-1,y-2,N);
    nextPostion(x-1,y+2,N);
    nextPostion(x+1,y-2,N);
    nextPostion(x+1,y+2,N);
    nextPostion(x-2,y-1,N);
    nextPostion(x-2,y+1,N);
    nextPostion(x+2,y-1,N);
    nextPostion(x+2,y+1,N);
}
 
int main() {
	int x,y,N;
	scanf("%d %d %d", &x,&y,&N);              			
	nextPostion(x-1,y-1,N);
	int i=0;
	int count=0;
	for(; i<10;i++) {
	        int j=0;
	    	for(; j<10;j++) {
	            count= count+chess[i][j];
	    }   
	}
	printf("%d \n",count);     ]
	
}

