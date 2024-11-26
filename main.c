#include <stdio.h>
#include <string.h>

struct Tache {
  
    char title[50];
    char description[100];
    char dataEcheance[11]; // Format : DD/MM/YYYY
    char priorite[10];     // "High" ou "Low"
};

// Table des tâches
struct Tache listTaches[100];
int nombreTaches = 0;

// Fonction pour ajouter une tâche
void ajouterTache() {
    if (nombreTaches >= 100) {
        printf("La liste des taches est pleine.\n");
        return;
    }

    printf("Entrez le titre de la tache : ");
    scanf(" %[^\n]", listTaches[nombreTaches].title);

    printf("Entrez la description de la tache : ");
    scanf(" %[^\n]", listTaches[nombreTaches].description);

    printf("Entrez la date de fin de la tache (DD/MM/YYYY) : ");
    scanf(" %s", listTaches[nombreTaches].dataEcheance);

    printf("Entrez la priorite de la tache (1. High / 2. Low) : ");
    
    int choixPriorite;
    scanf("%d", &choixPriorite);

    // Traitement de la priorité
    if (choixPriorite == 1) {
        strcpy(listTaches[nombreTaches].priorite, "High");
    } else if (choixPriorite == 2) {
        strcpy(listTaches[nombreTaches].priorite, "Low");
    } else {
        printf("Choix invalide. Priorite definie sur 'Low'.\n");
        strcpy(listTaches[nombreTaches].priorite, "Low");
    }

    nombreTaches++;
    printf("Tache ajoutee avec succes.\n");
}




// Fonction pour afficher les tâches
void afficherTaches() {
    if (nombreTaches == 0) {
        printf("Aucune tache à afficher.\n");
        return;
    }

    for (int i = 0; i < nombreTaches; i++) {
        printf("\nTache %d :\n", i + 1);
        printf("Titre       : %s\n", listTaches[i].title);
        printf("Description : %s\n", listTaches[i].description);
        printf("Echeance    : %s\n", listTaches[i].dataEcheance);
        printf("Priorite    : %s\n", listTaches[i].priorite);
    }
}




// Fonction pour modifier une tâche
void modifierTache() {
    int index;

    printf("Entrez le numero de la tâche a modifier (1-%d) : ", nombreTaches);
    scanf("%d", &index);

    if (index < 1 || index > nombreTaches) {
        printf("Numero de tache invalide !\n");
        return;
    }

    index--; // Convertir en index 0-based

    printf("Entrez le nouveau titre de la tache : ");
    scanf(" %s", listTaches[index].title);

    printf("Entrez la nouvelle description de la tache : ");
    scanf(" %s", listTaches[index].description);

    printf("Entrez la nouvelle date de fin de la tache (DD/MM/YYYY) : ");
    scanf(" %s", listTaches[index].dataEcheance);

    printf("Entrez la nouvelle priorite (1. High / 2. Low) : ");
    int choixPriorite;
    scanf("%d", &choixPriorite);

    if (choixPriorite == 1) {
        strcpy(listTaches[index].priorite, "High");
    } else if (choixPriorite == 2) {
        strcpy(listTaches[index].priorite, "Low");
    } else {
        printf("Choix invalide. Priorite inchangee.\n");
    }

    printf("Tache modifiee avec succes.\n");
}

// Fonction pour supprimer une tâche
void supprimerTache() {
    int index;
    scanf("%d", &index);
    taches [nombreTaches-1];
    nombreTaches--;
    printf("Tache supprimee avec succes.\n");
}




void filtrerTahches(){

    int choixPriorite;
    printf("Entrez la priorite a afficher (1. High / 2. Low ): ");
    scanf("%d", &choixPriorite);
    char prioriteFiltre[10];
    if (choixPriorite == 1) {
        strcpy(prioriteFiltre, "High");
    } else if (choixPriorite == 2) {
        strcpy(prioriteFiltre, "Low");
    } else {
        printf("Choix invalide. Retour au menu principal.\n ");
        return;
    }

    printf("\nTaches avec priorite '%s' :\n", prioriteFiltre);
    int found = 0;
    for (int i = 0; i < nombreTaches; i++) {

        if (strcmp(taches[i].priorite , prioriteFiltre) == 0) {
            printf("\nTache %d :\n", i + 1);    
            printf("Titre       : %s\n", taches[i].titre);
            printf("Description : %s\n", taches[i].description);
            printf("Echeance    : %s\n", taches[i].dateEcheance);
            printf("Priorite    : %s\n", taches[i].priorite);
            printf("Statut      : %s\n", taches[i].statut);
            found = 1;

        }
        
    }

    if (!found) {
        printf("Aucune tache avec la priorite  trouvee.\n");
    }

}



void menu(){
    int choix;

    do {
        printf("\nMenu :\n");
        printf("1. Ajouter une tache\n");
        printf("2. Afficher toutes les taches\n");
        printf("3. Modifier une tache\n");
        printf("4. Supprimer une tache\n");
        printf("5. Filtrer les taches par priorite\n");
        printf("6. Quitter\n");
        printf("Entrez votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                ajouterTache();
                break;
            case 2:
                afficherTaches();
                break;
            case 3:
                modifierTache();
                break;
            case 4:
                supprimerTache();
                break;
            case 5:
                filtrerTahches();
                break;
            case 6:
                printf("Au revoir !\n");
                break;
            default:
                printf("Choix invalide. Veuillez reessayer.\n");
        }
    } while (choix != 5);

    return 0;
}