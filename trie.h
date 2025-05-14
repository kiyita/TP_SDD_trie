#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct snode Tnode;
typedef Tnode* TTrie;

// Structure noeud
struct snode {
    char val;
    bool m;
    TTrie fi;
    TTrie fr;
};