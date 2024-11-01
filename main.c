#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

// #define goal 100

void start(){
    system("cls");
    printf("=== Temp msg ===\n");
}

int setRandom(){
    return rand();
}

int main(){

    start();
    srand(time(NULL));

    int count=0;
    int goal=10;
    int user_input;
    int user_point=0;

    while(user_point < goal){
        count++;
        printf("[STAGE %d] (x%d) - Your Point : %d\n", count, count*count, user_point);
        printf("Guess random number (odd : 1, even : 0) : ");
        scanf("%d", &user_input);
        
        if(user_input < 0 || user_input > 1){
            printf("wrong input\n");
            break;
        }

        Sleep(500);
        printf("\n> Your Guess is %s\n", (user_input==0?"EVEN":"ODD"));
        Sleep(1500);
        printf("> hmmm......\n");
        Sleep(1500);
        printf("> Computer's Choice is : %d (%d)\n", setRandom()%2, setRandom());
        Sleep(1000);

        printf("Press 'ENTER' to next stage...\n");

    }

}