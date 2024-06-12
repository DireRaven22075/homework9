#include <stdio.h>
#include <stdlib.h>

#define MAX 10
struct ListNode {
    int vertex;
    struct ListNode *next;
};
struct List {
    struct ListNode *head;
};
struct Graph {
    int vertex;
    struct List *arr;
    int* visited;
};
typedef struct ListNode Node;
typedef struct List List;
typedef struct Graph Graph;

void menu(char *command) {
    //메뉴 출력
    printf("----------------------------------------------------------------\n");
    printf("                        Graph Searches\n");
    printf("----------------------------------------------------------------\n");
    printf("Initialize Graph = z\n");
    printf("Insert Vertex = v Insert Edge = e\n");
    printf("Depth First Search = d Breath First Search = b\n");
    printf("Print Graph = p Quit = q\n");
    printf("----------------------------------------------------------------\n");
    printf("Enter Command >> ");
    //사용자로부터 명령어 입력받기
    scanf(" %c", command);
    return;
}
int main(void) {
    printf("[2023041004] - [한윤수]\n");
    char command;
    //종료 입력 전까지 무한 반복
    while (1) {
        menu(&command);
        switch(command) {
            case 'z':
                initgraph();
                break;
            case 'v':
                break;
            case 'e':
                break;
            case 'd':
                break;
            case 'b':
                break;
            case 'p':
                break;
            case 'q':
                break;
            default:
                printf("Invalid Command\n");
        }
    }
    printf("Program Terminated...\n");
    return 0;
}
//ToDO
//(b) Graph에 대한 자료구조는 인접리스트(Adjacent List)로 구현한다.
//(c) 최대 Vertex의 수는 10개로 하고, Vertex 번호는 0부터 9까지 부여된다.
//(d) DFS, BFS 탐색시 여러 Edge가 있을 경우 Vertex의 번호가 작은 순으로 탐색한다.
//(e) 구현한 함수들은 적절한 오류처리 기능이 있어야 한다.
//(f) 코드의 기능을 이해할 수 있도록 충분한 주석을 작성한다.