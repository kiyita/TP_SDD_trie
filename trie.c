#include "trie.h"

TTrie creeTrie() {
    TTrie t = (TTrie)malloc(sizeof(Tnode));
    t->val = '\0';
    t->m = false;
    t->fi = NULL;
    t->fr = NULL;
    return t;
}

void ajoutTrie(TTrie t, char* s) {
    //Cas de base : chaîne vide
    if (*s == '\0') {
        t->m = true;//Marque la fin d'un mot
    }

    //Cas 1 : noeud actuel NULL
    if (t->fi == NULL) {
        TTrie nouveau = creeTrie();
        nouveau->val = *s;
        t->fi = nouveau;
        ajoutTrie(t->fi, s + 1); //Appel récursif sur le reste du mot
    }

    //Cas 2 : noeud correspond au caractère courant
    else if (t->fi->val == *s) {
        ajoutTrie(t->fi, s + 1); //Appel récursif sur le reste du mot
    }

    //Cas 3 : noeud correspond à un autre caractère
    else {
        TTrie courant = t->fi;
        while (courant->fr != NULL && courant->fr->val < *s) {
            courant = courant->fr;
        }
        
        if (courant->fr == NULL) {
            // Si le noeud suivant est NULL, on crée un nouveau noeud
            TTrie nouveau = creeTrie();
            nouveau->val = *s;
            courant->fr = nouveau;
        }

        ajoutTrie(courant->fr, s + 1); //Appel récursif sur le reste du mot
    }
}

void afficherTrie(TTrie t) {
    if (t == NULL) {
        printf("NULL");
        return;
    }

    // Affiche la racine
    printf("(%c", t->val == '\0' ? ' ' : t->val);

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
    TTrie t = creeTrie();
    ajoutTrie(t, "hello");
    ajoutTrie(t, "world");
    ajoutTrie(t, "hi");
    afficherTrie(t);
    printf("\n");
}