#include <stdio.h>
#include <stdlib.h>

#pragma region Variable
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
#pragma endregion

#pragma region Function
//메뉴 출력
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
//정점 입력 받기
void getVertex(int *temp) {
    //정상적인 정점을 입력받을 때까지 반복
    while (1) {
        printf("Enter Vertex >> ");
        scanf("%d", temp);
        if (*temp < 0 || *temp >= MAX) {
            printf("Invalid Vertex\n");
            continue;
        }
        return;
    }
}
//새로운 노드 생성
Node* newNode(int vertex) {
    //노드 동적할당
    Node* node = (Node*)malloc(sizeof(Node));
    //노드 초기화
    node->vertex = vertex;
    node->next = NULL;
    return node;
}
//그래프 생성
Graph* initGraph() {
    //그래프 동적할당
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->arr = (List*)malloc(sizeof(List) * MAX);
    graph->visited = (int*)calloc(MAX, sizeof(int));

    //그래프 초기화
    for (int i = 0; i < MAX; i++)
        graph->arr[i].head = NULL;
    printf("Graph is created.\n");
    return graph;
}
//정점 (값) 삽입
void insertVertex(Graph* graph) {
    //그래프가 없을 경우 종료
    if (graph == NULL) {
        printf("Graph is not exist.\n");
        return;
    }
    //정점 변수 선언
    int temp;
    //올바른 정점 입력받을 때까지 반복
    getVertex(&temp);
    //정점이 존재할 경우 함수 종료
    if (graph->arr[temp].head != NULL) {
        printf("Vertex %d is already exist.\n", temp);
        return;
    }
    //정점 추가
    graph->arr[temp].head = newNode(temp);
    printf("Vertex %d is inserted.\n", temp);
    return;
}
//연결선 추가 (from, to) 형태로 입력받기
void insertEdge(Graph* graph) {
    //그래프가 없을 경우 함수 종료
    if (graph == NULL) {
        printf("Graph is not exist.\n");
        return;
    }
    int src, dest;
    //정점 입력 받기 (from, to)
    //올바른 정점 입력받을 때까지 반복
    while (1) {
        printf("Enter Vertex (from to) >> ");
        scanf("%d %d", &src, &dest);
        if (src < 0 || src >= MAX || dest < 0 || dest >= MAX) {
            printf("Invalid Vertex\n");
            continue;
        }
        break;
    }
    //연결선 마지막에 작성
    Node* temp = graph->arr[src].head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode(dest);
    printf("Edge added from %d to %d.\n", src, dest);
    return;
}
//메모리 할당 해제
void freeMemory(Graph* graph) {
    //만약 그래프가 존재하지 않을 경우 함수 종료
    if (graph == NULL) return;
    //그래프의 각 노드들을 동적할당 해제
    for (int i = 0; i < MAX; i++) {
        Node* temp = graph->arr[i].head;
        while (temp != NULL) {
            Node* del = temp;
            temp = temp->next;
            free(del);
        }
    }
    //그래프의 동적할당 해제
    free(graph->arr);
    free(graph->visited);
    free(graph);
    return;
}
//깊이 우선 탐색 시작함수 (탐색 함수는 dfs 재귀 함수로 구현되어 있음)
void dfSearch(Graph* graph) {
    //그래프가 존재하지 않을 경우 함수 종료
    if (graph == NULL) {
        printf("Graph is not exist.\n");
        return;
    }
    int temp;
    getVertex(&temp);
    //방문 여부 초기화
    for (int i = 0; i < MAX; i++) {
        graph->visited[i] = 0;
    }
    //깊이 우선 탐색 시작
    dfs(graph, temp);
    printf("\n");
    return;
}
//깊이 우선 탐색 재귀 함수
void dfs(Graph* graph, int vertex) {
    //방문 여부 체크
    graph->visited[vertex] = 1;
    //출력
    printf("%d ", vertex);
    //인접 노드 탐색
    Node* temp = graph->arr[vertex].head;
    //인접 노드가 존재할 경우 반복
    while (temp != NULL) {
        //방문하지 않은 노드일 경우 재귀 호출
        if (graph->visited[temp->vertex] == 0) {
            dfs(graph, temp->vertex);
        }
        //다음 노드로 이동
        temp = temp->next;
    }
    return;
}
//너비 우선 탐색 함수
void bfSearch(Graph* graph) {
    //그래프가 존재하지 않을 경우 함수 종료
    if (graph == NULL) {
        printf("Graph is not exist.\n");
        return;
    }
    //필요 변수들 선언
    int temp; //정점 입력 받을 변수
    int queue[MAX], front = 0, rear = 0; //큐 변수들
    //정점 입력 받기
    getVertex(&temp);
    //방문 여부 초기화
    for (int i = 0; i < MAX; i++) {
        graph->visited[i] = 0;
    }
    //너비 우선 탐색 시작
    graph->visited[temp] = 1;
    //큐에 정점 삽입
    queue[0] = temp;
    rear++;
    while (front < rear) {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);
        
        Node* list = graph->arr[currentVertex].head;
        while (list != NULL) {
            int adjVertex = list->vertex;
            if (graph->visited[adjVertex] == 0) {
                graph->visited[adjVertex] = 1;
                queue[rear++] = adjVertex;
            }
            list = list->next;
        }
    }
    printf("\n");
    return;
}
//그래프 출력
void printGraph(Graph* graph) {
    //만약 그래프가 존재하지 않을 경우 함수 종료
    if (graph == NULL) {
        printf("Graph is not exist.\n");
        return;
    }
    //그래프 출력 (모든 정점에서 출력)
    for (int v = 0; v < MAX; ++v) {
        Node* p = graph->arr[v].head;
        printf("\n%d ", v);
        while (p != NULL) {
            printf("-> %d", p->vertex);
            p = p->next;
        }
        printf("\n");
    }
    return;
}

#pragma endregion

int main(void) {
    //그래프 선언
    Graph* graph = NULL;
    //학번 출력
    printf("[2023041004] - [한윤수]\n");
    //명령어 변수 선언
    char command;
    //종료 입력 전까지 무한 반복
    while (1) {
        //메뉴 출력 및 명령어 입력
        menu(&command);
        //명령어에 따른 함수 실행
        switch(command) {
            //그래프 생성
            case 'z':
                if (graph != NULL) {
                    printf("Graph is already exist.\n");
                    continue;
                }
                graph = initGraph(); break;
            //정점 삽입
            case 'v': insertVertex(graph); break;
            //연결선 삽입
            case 'e': insertEdge(graph); break;
            //깊이 우선 탐색
            case 'd': dfSearch(graph); break;
            //너비 우선 탐색
            case 'b': bfSearch(graph); break;
            //그래프 출력
            case 'p': printGraph(graph); break;
            //프로그램 종료
            case 'q': goto QUIT; break;
            //잘못된 명령어 입력시
            default: printf("Invalid Command\n"); break;
        }
    }
    //프로그램 종료
    QUIT:
    printf("Program Terminated...\n");
    freeMemory(graph);
    return 0;
}
//ToDO
//(b) Graph에 대한 자료구조는 인접리스트(Adjacent List)로 구현한다.
//(c) 최대 Vertex의 수는 10개로 하고, Vertex 번호는 0부터 9까지 부여된다.
//(d) DFS, BFS 탐색시 여러 Edge가 있을 경우 Vertex의 번호가 작은 순으로 탐색한다.
//(e) 구현한 함수들은 적절한 오류처리 기능이 있어야 한다.
//(f) 코드의 기능을 이해할 수 있도록 충분한 주석을 작성한다.