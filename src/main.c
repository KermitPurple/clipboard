#include<stdio.h>
#define CLIPBOARD_IMPLEMENTATION
#include"clipboard.h"

int main(){
    char* clip = load_clipboard();
    printf("old: %s\n", clip);
    printf("success: %d\n", save_clipboard("123"));
    printf("new: %s\n", clip);
    return 0;
}
