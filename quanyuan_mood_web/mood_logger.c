#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("No mood received.\n");
        return 1;
    }
    
    printf("Button Pressed: %s\n", argv[1]);
    return 0;
}
