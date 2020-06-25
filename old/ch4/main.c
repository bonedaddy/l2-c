#include <stdio.h>

#define MEME printf("lolwut\n")
#define FOREVER for(;;)
#define main int main() {MEME; LOLS; FOREVER;}
#if !defined(LOLS)
#define LOLS  printf("dude this is cool\n")
#endif

main;