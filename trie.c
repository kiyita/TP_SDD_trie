#include "trie.h"

TTrie creeTrie() {
    TTrie t = (TTrie)malloc(sizeof(Tnode));
    t->val = '\0';
    t->m = false;
    t->fi = NULL;
    t->fr = NULL;
    return t;
}

void ajoutTrie(TTrie *t, const char *s) {
    // Cas de base : chaîne vide
    if (*s == '\0') {
        if (*t == NULL) { // Si le nœud est NULL, on le crée
            *t = creeTrie();
        }
        (*t)->m = true; // Marque la fin d'un mot
        return;
    }

    // Cas 1 : nœud actuel est NULL
    if (*t == NULL) {
        *t = creeTrie(); // Crée un nouveau nœud
        (*t)->val = *s; // Assigne le caractère courant
        // On continue la récursion sur le fils gauche (caractère suivant)
        ajoutTrie(&((*t)->fi), s + 1);
        return;
    }

    // Cas 2 : la valeur du nœud correspond au caractère courant
    if ((*t)->val == *s) {
        ajoutTrie(&((*t)->fi), s + 1); // On continue la récursion sur le fils gauche (caractère suivant)
        return;
    }

    // Cas 3 : la valeur du nœud ne correspond pas au caractère courant
    ajoutTrie(&((*t)->fr), s); // On continue la récursion sur le frère (caractère alternatif)
}

void afficherTrie(TTrie t) {
    if (t == NULL) {
        printf("NULL");
        return;
    }

    // Affiche une oarenthèse et le caractère du nœud courant (ou un espace si c'est la racine)
    if (t->val == '\0') {
        printf("( ");
    } else {
        printf("(%c", t->val);
    }

    // Affiche le fils gauche
    printf(", ");
    afficherTrie(t->fi);

    // Affiche le frère
    printf(", ");
    afficherTrie(t->fr);

    // Ferme la parenthèse
    printf(")");
}

void main() {
    TTrie t = NULL;
    ajoutTrie(&t, "hello");
    ajoutTrie(&t, "world");
    ajoutTrie(&t, "hi");
    afficherTrie(t);
    printf("\n");
}