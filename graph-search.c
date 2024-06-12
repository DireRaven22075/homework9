#include <stdio.h>
void menu(char *command) {
    printf("----------------------------------------------------------------\n");
    printf("                        Graph Searches\n");
    printf("----------------------------------------------------------------\n");
    printf("Initialize Graph = z\n");
    printf("Insert Vertex = v Insert Edge = e\n");
    printf("Depth First Search = d Breath First Search = b\n");
    printf("Print Graph = p Quit = q\n");
    printf("----------------------------------------------------------------\n");
    printf("Enter Command >> ");
    scanf(" %c", command);
    return;
}
int main(void) {
    printf("[2023041004] - [한윤수]\n");
    char command;
    while (1) {
        menu(&command);
        switch(command) {
            case 'z':
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