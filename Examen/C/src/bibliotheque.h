#ifndef BIBLIOTHEQUE_H
#define BIBLIOTHEQUE_H

typedef struct {
    char titre[50];
    char auteur[50];
    int annee;
} Livre;

void afficherMenu();
void ajouterLivre();
void afficherBibliotheque();
void rechercherLivre();
void supprimerLivre();
void modifierLivre();
void trierBibliothequeParTitre();
void afficherStatistiques();
void sauvegarderBibliotheque();

#endif
