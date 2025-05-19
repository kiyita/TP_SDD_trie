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

    // Cas 1 : nœud actuel est NULL Caractère courant plus petit
    if (*t == NULL || (*t)->val > *s) {
        TTrie nouveauNoeud = creeTrie(); // Crée un nouveau nœud
        nouveauNoeud->val = *s;// Assigne le caractère courant
        nouveauNoeud->fr = *t; // Le frère devient le nœud actuel
        *t = nouveauNoeud;
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

void afficherTrieMeilleur(TTrie t, int niveau) {
    if (t == NULL) return;

    // Affiche les frères d'abord (pour avoir un affichage du haut vers le bas)
    afficherTrieMeilleur(t->fr, niveau);

    // Indentation selon le niveau
    for (int i = 0; i < niveau; i++) printf("    ");

    // Affiche le caractère et la marque de fin de mot
    printf("%c%s\n", t->val == '\0' ? '*' : t->val, t->m ? " fin" : "");

    // Affiche les fils (niveau + 1)
    afficherTrieMeilleur(t->fi, niveau + 1);
}

void supprimerTrie(TTrie *t) {
    if (*t == NULL) return;

    // Supprime les fils gauche et droit
    supprimerTrie(&((*t)->fi));
    supprimerTrie(&((*t)->fr));

    // Libère la mémoire du nœud courant
    free(*t);
    *t = NULL; // Met le pointeur à NULL
}


// Fonction principale pour tester le trie

int main() {
    TTrie t = NULL;
    ajoutTrie(&t, "hello");
    ajoutTrie(&t, "world");
    ajoutTrie(&t, "hi");
    ajoutTrie(&t, "sauce");
    ajoutTrie(&t, "saucisse");
    ajoutTrie(&t, "saucisson");
    ajoutTrie(&t, "sauvage");
    ajoutTrie(&t, "saugrenu");
    afficherTrieMeilleur(t, 0);
    printf("\n");
    supprimerTrie(&t);
    return 0;
}