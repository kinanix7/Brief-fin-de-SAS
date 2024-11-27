#include <stdio.h>
#include <string.h>

#define MAX_TACHES 100
struct Tache {
    int id;
    char title[50];
    char description[100];
    char dataEcheance[11]; // Format : DD-MM-YYYY
    char priorite[10];     // high or low
    char statue[10];       // complete or incomplete
};

int numbreTaches = 0;

void AjouterTache(struct Tache *list_tache, int id) {
    list_tache->id = id;
    printf("Entrez le titre de la tache : ");
    scanf(" %[^\n]", list_tache->title);
    printf("Entrez la description de la tache : ");
    scanf(" %[^\n]", list_tache->description);
    printf("Entrez la date de la tache (DD/MM/YYYY) : ");
    scanf(" %s", list_tache->dataEcheance);

    while (1) { // Infinite loop for priority validation
        printf("Entrez la priorite de la tache (high/low) : ");
        scanf(" %s", list_tache->priorite);
        if (strcmp(list_tache->priorite, "high") == 0 || strcmp(list_tache->priorite, "low") == 0) {
            break; 
        } else {
            printf("Priorite invalide. Veuillez saisir 'high' ou 'low'.\n");
        }
    }
    printf("Entrez la statue de la tache (complete/incomplete) : ");
    scanf(" %s", list_tache->statue);
}

void AfficherTache(struct Tache list_tache) {
    if (list_tache.id != 0) { // Check if task is valid
        printf("---------------------------------------------------------\n");
        printf("Id : %d\nTitre : %s\nDescription : %s\nDataEcheance : %s\nPriorite : %s\nStatut : %s\n",
               list_tache.id, list_tache.title, list_tache.description, 
               list_tache.dataEcheance, list_tache.priorite, list_tache.statue);
        printf("---------------------------------------------------------\n");
    }
}

void ModifierTache(struct Tache *list_tache, char new_value[], int field) {
    switch (field) {
        case 1:
            strcpy(list_tache->title, new_value);
            break;
        case 2:
            strcpy(list_tache->description, new_value);
            break;
        case 3:
            strcpy(list_tache->dataEcheance, new_value);
            break;
        case 4:
            strcpy(list_tache->priorite, new_value);
            break;
        case 5:
            strcpy(list_tache->statue, new_value);
            break;
        default:
            printf("Invalid field.\n");
            break;
    }
}

void SupprimerTache(struct Tache *list_tache) {
    list_tache->id = 0; // Mark task as deleted
}

void FiltrerTaches(struct Tache list_tache[], int id , char filter_Priority[]) {
    int found = 0;
    for (int i = 0; i < id; i++)
    {
        if (strcmp(list_tache[i].priorite , filter_Priority) == 0)
        {
            AfficherTache(list_tache[i]);
            found = 1;
        }
        
    }if (!found)
    {
       printf("Note found");
    }
    
    
}
int main() {
    struct Tache list_tache[MAX_TACHES];
    int choix;
    int id = 0, id_modifier, id_supprimer, field;
    char new_value[100], filter_Priority[100];

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
            case 1:
                if (id < MAX_TACHES) {
                    AjouterTache(&list_tache[id], id + 1);
                    id++;
                } else {
                    printf("Nombre maximum de taches atteint.\n");
                }
                break;
            case 2:
                for (int i = 0; i < id; i++) {
                    if (list_tache[i].id != 0) { // Display only valid tasks
                        AfficherTache(list_tache[i]);
                    }
                }
                break;
            case 3:
                printf("Entrez l'id de la tache a modifier : ");
                scanf("%d", &id_modifier);
                if (id_modifier > 0 && id_modifier <= id && list_tache[id_modifier - 1].id != 0) {
                    printf("1. Titre\n2. Description\n3. DateEcheance\n4. Priorite\n5. Statut\n");
                    printf("Entrez le champ a modifier : ");
                    scanf("%d", &field);
                    printf("Entrez la nouvelle valeur : ");
                    scanf(" %[^\n]", new_value);
                    ModifierTache(&list_tache[id_modifier - 1], new_value, field);
                } else {
                    printf("ID invalide.\n");
                }
                break;
            case 4:
                printf("Entrez l'id de la tache a supprimer : ");
                scanf("%d", &id_supprimer);
                if (id_supprimer > 0 && id_supprimer <= id && list_tache[id_supprimer - 1].id != 0) {
                    SupprimerTache(&list_tache[id_supprimer - 1]);
                    printf("Tache supprimee avec succes.\n");
                } else {
                    printf("ID invalide.\n");
                }
                break;

                case 5:
                printf("Entrez la priorite a filtrer high or low : ");
                scanf(" %s",filter_Priority);
                FiltrerTaches(list_tache, id, filter_Priority);
                break;
            case 6:
                printf("Goodbye!\n");
                break;
            default:
                printf("Choix invalide. Veuillez reessayer.\n");
                break;
        }
    } while (choix != 6);

    return 0;
}
