#ifndef CLIPBOARD_H

#include<stdbool.h>

bool save_clipboard(const char*);
char* load_clipboard();


#ifdef CLIPBOARD_IMPLEMENTATION

#include<stdio.h>
#include<stdlib.h>

bool save_clipboard(const char* string){
#ifdef __APPLE__
    char* cmd = NULL;
    if(asprintf(&cmd, "printf '%s' | pbcopy", string) <= 0)
        return false;
    FILE* pipe = popen(cmd, "r");
    if(pipe == NULL)
        return false;
    pclose(pipe);
    free(cmd);
    return true;
#else
    return false
#endif
}

char* load_clipboard(){
#ifdef __APPLE__
    FILE* pipe = popen("pbpaste", "r");
    if(pipe == NULL)
        return NULL;
    char* result = NULL;
    size_t capacity = 0;
    getdelim(&result, &capacity, '\0', pipe);
    pclose(pipe);
    return result;
#else
    return NULL
#endif
}


#endif // CLIPBOARD_IMPLEMENTATION
#endif // CLIPBOARD_H
