#import <stdio.h>
// #ifdef __EMSCRIPTEN__
// #include <emscripten/emscripten.h>
// #else
// #define EMSCRIPTEN_KEEPALIVE
// #endif


// EMSCRIPTEN_KEEPALIVE
int add(int a, int b) {
    return a + b;
}

int main() {
    int answer = add(1, 2);
    printf("1 + 2 = %d\n", answer);
}

