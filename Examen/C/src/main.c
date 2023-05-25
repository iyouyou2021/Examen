#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bibliotheque.h"


typedef struct {
    char titre[50];
    char auteur[50];
    int annee;
} Livre;


Livre bibliotheque[100];
int nombreLivres = 0;


enum Genre {
    ROMAN,
    SCIENCE_FICTION,
    FANTASY,
    THRILLER
};


union InfosSupplementaires {
    int nombrePages;
    float prix;
};

typedef struct {
    Livre livre;
    enum Genre genre;
    union InfosSupplementaires infosSupp;
} LivreAvecInfos;

void afficherMenu();
void ajouterLivre();
void afficherBibliotheque();
void rechercherLivre();

int main() {
    int choix;

    do {
        afficherMenu();
        scanf("%d", &choix);
        getchar(); 

        switch (choix) {
            case 1:
                ajouterLivre();
                break;
            case 2:
                afficherBibliotheque();
                break;
            case 3:
                rechercherLivre();
                break;
            case 4:
                printf("Au revoir !\n");
                break;
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
        }
    } while (choix != 4);

    return 0;
}


void afficherMenu() {
    printf("\nMenu:\n");
    printf("1. Ajouter un livre\n");
    printf("2. Afficher la bibliothèque\n");
    printf("3. Rechercher un livre\n");
    printf("4. Quitter\n");
    printf("Veuillez choisir une option : ");
}


void ajouterLivre() {
    LivreAvecInfos livre;

    printf("\nAjout d'un livre :\n");
    printf("Titre : ");
    fgets(livre.livre.titre, sizeof(livre.livre.titre), stdin);
    livre.livre.titre[strcspn(livre.livre.titre, "\n")] = '\0'; 

    printf("Auteur : ");
    fgets(livre.livre.auteur, sizeof(livre.livre.auteur), stdin);
    livre.livre.auteur[strcspn(livre.livre.auteur, "\n")] = '\0'; 

    printf("Année : ");
    scanf("%d", &livre.livre.annee);
    getchar(); 

    printf("Genre (0-Roman, 1-Science fiction, 2-Fantasy, 3-Thriller) : ");
    scanf("%d", &livre.genre);
    getchar(); 

    switch (livre.genre) {
        case ROMAN:
            printf("Nombre de pages : ");
            scanf("%d", &livre.infosSupp.nombrePages);
            getchar(); 
            break;
        case SCIENCE_FICTION:
            printf("Prix : ");
            scanf("%f", &livre.infosSupp.prix);
            getchar(); 
            break;
        case FANTASY:
            printf("Nombre de pages : ");
            scanf("%d", &livre.infosSupp.nombrePages);
            getchar(); 
            break;
        case THRILLER:
            printf("Prix : ");
            scanf("%f", &livre.infosSupp.prix);
            getchar(); 
            break;
        default:
            printf("Genre invalide.\n");
            return;
    }

    memcpy(&bibliotheque[nombreLivres], &livre.livre, sizeof(Livre));
    nombreLivres++;

    printf("Livre ajouté avec succès.\n");
}

void afficherBibliotheque() {
    printf("\nBibliothèque :\n");

    if (nombreLivres == 0) {
        printf("La bibliothèque est vide.\n");
    } else {
        int i;
        for (i = 0; i < nombreLivres; i++) {
            printf("Livre %d :\n", i + 1);
            printf("Titre : %s\n", bibliotheque[i].titre);
            printf("Auteur : %s\n", bibliotheque[i].auteur);
            printf("Année : %d\n", bibliotheque[i].annee);

            printf("\n");
        }
    }
}

void rechercherLivre() {
    char recherche[50];

    printf("\nRecherche d'un livre :\n");
    printf("Veuillez entrer un titre ou un auteur : ");
    fgets(recherche, sizeof(recherche), stdin);
    recherche[strcspn(recherche, "\n")] = '\0'; 

    int i;
    int trouve = 0;
    for (i = 0; i < nombreLivres; i++) {
        if (strcmp(bibliotheque[i].titre, recherche) == 0 || strcmp(bibliotheque[i].auteur, recherche) == 0) {
            printf("Livre trouvé :\n");
            printf("Titre : %s\n", bibliotheque[i].titre);
            printf("Auteur : %s\n", bibliotheque[i].auteur);
            printf("Année : %d\n", bibliotheque[i].annee);

            printf("\n");
            trouve = 1;
        }
    }

    if (!trouve) {
        printf("Aucun livre trouvé pour la recherche spécifiée.\n");
    }
}
