#ifndef TRIE_H
#define TRIE_H

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

TTrie creeTrie();
void ajoutTrie(TTrie *t, const char *s);
void afficherTrie(TTrie t);
void afficherTrieMeilleur(TTrie t, int niveau);
void supprimerTrie(TTrie *t);
int main();

#endif