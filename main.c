#include <stdio.h>
#include <time.h>

void start(){
    FILE *fp = fopen("banner.txt", "r");
    char str[1000];
    while(str != EOF){
        fgets(str, 1, fp);
        printf("%s", str);
    }
}

int main(){
    start();
}
