#include <stdio.h>
#include <string.h>

int main(){
    int a,b,c;
    scanf("%d%d", &a, &b);
    scanf("%d", &c);
    char s[50];
    memset(s, 0, 50);
    // scanf("%s", s);
    printf("%d %d %d\n", a,b,c);
    fgets(s, 50, stdin);
    for(auto c: s){
        printf("%d ", c);
    }
    fgets(s, 50, stdin);
    for(auto c: s){
        printf("%d ", c);
    }
    fgets(s, 50, stdin);
    for(auto c: s){
        printf("%d ", c);
    }
    return 0;
}