#include <stdio.h>
#include "NodePointList.h"
#include "NodePointList.cpp"

Ldata NewPoint(int x, int y) {
	Ldata Npoint = (Point*)malloc(sizeof(Point));
	Npoint->x=x;
	Npoint->y=y;
	Npoint->Next=NULL;
	return Npoint;
}

void SetSortRule(List* plist, int (*comp)(Ldata, Ldata))
{
	plist->comp = comp;
}

int WhoIsPred(Ldata d1, Ldata d2) {
	if(d1->x <d2->x) return 0;
	else if(d1->x == d2->x){
		if(d1->y <d2->y)return 0;
		else return 1;
	}
	else return 1;
}


int main(void){
	List* MyList = (List*)malloc(sizeof(List));
	InItList(MyList);
	printf("\n새로운 노드를 리스트의 앞에 추가\n");
	LInsert(MyList, NewPoint(1,2));
	LInsert(MyList, NewPoint(2,3));
	LInsert(MyList, NewPoint(3,4));
	
	int a,A[10]={6,2,7,9,8,3,5,4,0,1};
	SetSortRule(MyList, WhoIsPred);
	printf("\n오름차순 Sorting Rule 적용 자료 추가\n");
	for(a=0;a<10;a+=2){
		LInsert(MyList, NewPoint(A[a], A[a+1]));	
	}
	
	printf("\n오름차순 정렬 \n");
	Sorting(MyList);
	LPrint(MyList);
	
	Ldata point=(Point*)malloc(sizeof(Point)),rpoint;
	
	printf("\n좌표에 3인 포함된 모든 점 삭제\n");
	if(LFirst(MyList, point)){
		if(point->x ==3 || point->y ==3){
			rpoint = LRemove(MyList);
			printf("(%d %d) 제거 \n", rpoint->x, rpoint->y);
		}
		while(LNext(MyList, point)){
			if(point->x ==3 || point->y == 3){
				rpoint = LRemove(MyList);
				printf("(%d %d) 제거 \n", rpoint->x, rpoint->y);
				free(rpoint);
			}
		}
		printf("\n 남아있는 모든 점 리스트\n");
		LPrint(MyList);
	}
	}
