#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char titre[50];
    char auteur[50];
    int annee;
} Livre;

typedef enum {
    ROMAN,
    SCIENCE_FICTION,
    FANTASY,
    THRILLER
} Genre;

typedef union {
    int nombrePages;
    float prix;
} InfosSupplementaires;

typedef struct {
    Livre livre;
    Genre genre;
    InfosSupplementaires infosSupp;
} LivreAvecInfos;

LivreAvecInfos bibliotheque[100];
int nombreLivres = 0;

void afficherMenu();

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
    scanf("%d", (int *)&livre.genre);
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

    bibliotheque[nombreLivres] = livre;
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
            printf("Titre : %s\n", bibliotheque[i].livre.titre);
            printf("Auteur : %s\n", bibliotheque[i].livre.auteur);
            printf("Année : %d\n", bibliotheque[i].livre.annee);

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
        if (strcmp(bibliotheque[i].livre.titre, recherche) == 0 || strcmp(bibliotheque[i].livre.auteur, recherche) == 0) {
            printf("Livre trouvé :\n");
            printf("Titre : %s\n", bibliotheque[i].livre.titre);
            printf("Auteur : %s\n", bibliotheque[i].livre.auteur);
            printf("Année : %d\n", bibliotheque[i].livre.annee);

            printf("\n");
            trouve = 1;
        }
    }

    if (!trouve) {
        printf("Aucun livre trouvé pour la recherche spécifiée.\n");
    }
}

void supprimerLivre() {
    char recherche[50];

    printf("\nSuppression d'un livre :\n");
    printf("Veuillez entrer un titre ou un auteur du livre à supprimer : ");
    fgets(recherche, sizeof(recherche), stdin);
    recherche[strcspn(recherche, "\n")] = '\0';

    int i;
    int trouve = 0;
    for (i = 0; i < nombreLivres; i++) {
        if (strcmp(bibliotheque[i].livre.titre, recherche) == 0 || strcmp(bibliotheque[i].livre.auteur, recherche) == 0) {
            printf("Livre trouvé :\n");
            printf("Titre : %s\n", bibliotheque[i].livre.titre);
            printf("Auteur : %s\n", bibliotheque[i].livre.auteur);
            printf("Année : %d\n", bibliotheque[i].livre.annee);

            printf("Confirmez-vous la suppression de ce livre ? (Oui/Non) : ");
            char choix[4];
            fgets(choix, sizeof(choix), stdin);
            choix[strcspn(choix, "\n")] = '\0';

            if (strcmp(choix, "Oui") == 0 || strcmp(choix, "oui") == 0) {
                int j;
                for (j = i; j < nombreLivres - 1; j++) {
                    bibliotheque[j] = bibliotheque[j + 1];
                }

                nombreLivres--;
                printf("Livre supprimé avec succès.\n");
            } else {
                printf("Suppression annulée.\n");
            }

            trouve = 1;
            break;
        }
    }

    if (!trouve) {
        printf("Aucun livre trouvé pour la recherche spécifiée.\n");
    }
}

void modifierLivre() {
    char recherche[50];

    printf("\nModification d'un livre :\n");
    printf("Veuillez entrer un titre ou un auteur du livre à modifier : ");
    fgets(recherche, sizeof(recherche), stdin);
    recherche[strcspn(recherche, "\n")] = '\0';

    int i;
    int trouve = 0;
    for (i = 0; i < nombreLivres; i++) {
        if (strcmp(bibliotheque[i].livre.titre, recherche) == 0 || strcmp(bibliotheque[i].livre.auteur, recherche) == 0) {
            printf("Livre trouvé :\n");
            printf("Titre : %s\n", bibliotheque[i].livre.titre);
            printf("Auteur : %s\n", bibliotheque[i].livre.auteur);
            printf("Année : %d\n", bibliotheque[i].livre.annee);

            printf("Entrez le nouveau titre : ");
            fgets(bibliotheque[i].livre.titre, sizeof(bibliotheque[i].livre.titre), stdin);
            bibliotheque[i].livre.titre[strcspn(bibliotheque[i].livre.titre, "\n")] = '\0';

            printf("Entrez le nouvel auteur : ");
            fgets(bibliotheque[i].livre.auteur, sizeof(bibliotheque[i].livre.auteur), stdin);
            bibliotheque[i].livre.auteur[strcspn(bibliotheque[i].livre.auteur, "\n")] = '\0';

            printf("Entrez la nouvelle année : ");
            scanf("%d", &bibliotheque[i].livre.annee);
            getchar();

            printf("Livre modifié avec succès.\n");
            trouve = 1;
            break;
        }
    }

    if (!trouve) {
        printf("Aucun livre trouvé pour la recherche spécifiée.\n");
    }
}

void trierBibliothequeParTitre() {
    int i, j;
    LivreAvecInfos temp;

    for (i = 0; i < nombreLivres - 1; i++) {
        for (j = 0; j < nombreLivres - i - 1; j++) {
            if (strcmp(bibliotheque[j].livre.titre, bibliotheque[j + 1].livre.titre) > 0) {
                temp = bibliotheque[j];
                bibliotheque[j] = bibliotheque[j + 1];
                bibliotheque[j + 1] = temp;
            }
        }
    }

    printf("La bibliothèque a été triée par titre.\n");
}

void afficherStatistiques() {
    int i;
    int nombreRomans = 0;
    int nombreScienceFiction = 0;
    int nombreFantasy = 0;
    int nombreThrillers = 0;

    printf("\nStatistiques de la bibliothèque :\n");

    printf("Nombre total de livres : %d\n", nombreLivres);

    for (i = 0; i < nombreLivres; i++) {
        switch (bibliotheque[i].genre) {
            case ROMAN:
                nombreRomans++;
                break;
            case SCIENCE_FICTION:
                nombreScienceFiction++;
                break;
            case FANTASY:
                nombreFantasy++;
                break;
            case THRILLER:
                nombreThrillers++;
                break;
        }
    }

    printf("Nombre de romans : %d\n", nombreRomans);
    printf("Nombre de livres de science fiction : %d\n", nombreScienceFiction);
    printf("Nombre de livres de fantasy : %d\n", nombreFantasy);
    printf("Nombre de thrillers : %d\n", nombreThrillers);
}

void sauvegarderBibliotheque() {
    FILE *fichier;
    int i;

    fichier = fopen("bibliotheque.txt", "w");

    if (fichier == NULL) {
        printf("Impossible d'ouvrir le fichier de sauvegarde.\n");
        return;
    }

    for (i = 0; i < nombreLivres; i++) {
        fprintf(fichier, "Titre : %s\n", bibliotheque[i].livre.titre);
        fprintf(fichier, "Auteur : %s\n", bibliotheque[i].livre.auteur);
        fprintf(fichier, "Année : %d\n", bibliotheque[i].livre.annee);
        fprintf(fichier, "\n");
    }

    fclose(fichier);

    printf("La bibliothèque a été sauvegardée dans le fichier 'bibliotheque.txt'.\n");
}

void afficherMenu() {
    printf("\nMenu :\n");
    printf("1. Ajouter un livre\n");
    printf("2. Afficher la bibliothèque\n");
    printf("3. Rechercher un livre\n");
    printf("4. Supprimer un livre\n");
    printf("5. Modifier un livre\n");
    printf("6. Trier la bibliothèque par titre\n");
    printf("7. Afficher les statistiques\n");
    printf("8. Sauvegarder la bibliothèque\n");
    printf("9. Quitter\n");
    printf("Veuillez entrer votre choix : ");
}

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
                supprimerLivre();
                break;
            case 5:
                modifierLivre();
                break;
            case 6:
                trierBibliothequeParTitre();
                break;
            case 7:
                afficherStatistiques();
                break;
            case 8:
                sauvegarderBibliotheque();
                break;
            case 9:
                printf("Au revoir !\n");
                break;
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
        }
    } while (choix != 9);

    return 0;
}
