#include <stdio.h>
#include <string.h>

struct Tache {
    char title[50];
    char description[100];
    char dataEcheance[11]; // Format : DD-MM-YYYY
    char priorite[10];     // high or low
    char statue[10];   // complete or incompelte
};
struct Tache listTaches[100];
int nombreTaches = 0;

// Fonction pour ajouter une tâche
void ajouterTache() {
    
    printf("Entrez le titre de la tache : ");
    scanf(" %[^\n]", listTaches[nombreTaches].title);
    printf("Entrez la description de la tache : ");
    scanf(" %[^\n]", listTaches[nombreTaches].description);
    printf("Entrez la date de fin de la tache (DD/MM/YYYY) : ");
    scanf(" %s", listTaches[nombreTaches].dataEcheance);
    printf("Entrez la priorite de la tache high-low : ");
    scanf(" %s", listTaches[nombreTaches].priorite);
    printf("Entrez la statue de la thache compelete-incomplete : ");
    scanf("%s",listTaches[nombreTaches].statue);
    nombreTaches++;// Convertir en index 0-based

    printf("Tache ajoutee avec succes.\n");
}


// Fonction pour afficher les tâches
void afficherTaches() {

 for (int i = 0; i < nombreTaches; i++) {
        printf("\nTache %d :\n", i + 1);
        printf("Titre       : %s\n", listTaches[i].title);
        printf("Description : %s\n", listTaches[i].description);
        printf("Echeance    : %s\n", listTaches[i].dataEcheance);
        printf("Priorite    : %s\n", listTaches[i].priorite);
        printf("Statue      : %s\n", listTaches[i].statue);
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
    printf("Entrez la nouvelle date de fin de la tache DD-MM-YYYY : ");
    scanf(" %s", listTaches[index].dataEcheance);
    printf("Entrez la nouvelle priorite high-low: ");
    scanf("%s", listTaches[index].priorite);
    printf("Entrez la nouvelle statue compelete-incomplete : ");
    scanf("%s", listTaches[index].statue);
    printf("Tache modifiee avec succes.\n");
}

// Fonction pour supprimer une tâche
void supprimerTache() {
    int index;

    printf("Entrez le numero de la tache à supprimer (1-%d) : ", nombreTaches);
    scanf("%d", &index);

    if (index < 1 || index > nombreTaches) {
        printf("Numero de tache invalide !\n");
        return;
    }

    index--; // Convertir en index 0-based

    for (int i = index; i < nombreTaches - 1; i++) {
        listTaches[i] = listTaches[i + 1];
    }

    nombreTaches--;
    printf("Tache supprimee avec succes.\n");
}


// Fonction pour flier une tâche
void filtrerTahches() {
    
    if (nombreTaches == 0) {
        printf("Aucune tache a afficher .\n");
        return;

    }
    printf("Entrez la priorite a afficher (1. High / 2. Low ): ");
    int choixPriorite;
    scanf("%d",&choixPriorite);

    char prioriteFiltre[10];
    if (choixPriorite == 1) {
        strcpy(prioriteFiltre, "High");
    } else if (choixPriorite == 2) {
        strcpy(prioriteFiltre,"Low");
    } else {
        printf("Choix invalide. Retour au menu principal.\n ");
        return;
    }

    printf("\nTaches avec priorite '%s' :\n", prioriteFiltre);
    int found = 0;
    for (int i = 0; i < nombreTaches; i++) {


        if (strcmp(listTaches[i].priorite , prioriteFiltre) == 0) {
            printf("\nTache %d :\n", i + 1);    
            printf("Titre       : %s\n", listTaches[i].title);
            printf("Description : %s\n", listTaches[i].description);
            printf("Echeance    : %s\n", listTaches[i].dataEcheance);
            found = 1;


        }
        
      
    }

    if (!found) {
        printf("Aucune tache avec la priorite  trouvee.\n");
}
}

// Fonction principale
int main() {
    int choix;
     do {
        printf("\nMenu :\n");
        printf("1. Ajouter\n");
        printf("2. Afficher\n");
        printf("3. Modifier\n");
        printf("4. Supprimer\n");
        printf("5. Filtrer\n");
        printf("6. Quitter\n");
        printf("Entrez votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:ajouterTache();break;
            case 2:afficherTaches(); break;
            case 3:modifierTache();break;
            case 4:supprimerTache();break;
            case 5:filtrerTahches();break;
            case 6:printf("Au revoir !\n");break;
           default:
                printf("Choix invalide. Veuillez reessayer.\n");
        }
    } while (choix != 6);// Boucle principale
    return 0;// Fin du programme
}
