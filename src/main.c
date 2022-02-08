#include<stdio.h>
#define CLIPBOARD_IMPLEMENTATION
#include"clipboard.h"

int main(){
    printf("%s\n", load_clipboard());
    printf("%d\n", save_clipboard("123"));
    return 0;
}
