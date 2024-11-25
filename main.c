#include <stdio.h>
#include <string.h>


#define MAX_TACHES 100


struct Tache{
    char titre[50];
    char description[100];
    char dateEcheance[11]; // Format : DD/MM/YYYY
    char priorite[10];  // "High" ou "Low"
    char statut[10];  // "Compelete" ou "Incomplete"
};
struct Tache taches[MAX_TACHES];
int nombreTaches = 0;


void ajouterTache(){
   
    printf(" Titre de la tache : ");
    scanf(" %[^\n]", taches[nombreTaches].titre);
    printf(" Description de la tache : ");
    scanf(" %[^\n]", taches[nombreTaches].description);
    printf(" Date d'echeance de la tache [DD/MM/YYYY] : ");
    scanf("%s", taches[nombreTaches].dateEcheance);
    printf(" Priorite [High/Low] : ");
    scanf("%s", taches[nombreTaches].priorite);
    printf(" statut [Compelete/Incomplete] : ");
    scanf("%s", taches[nombreTaches].statut);
    nombreTaches++; 

}

void afficherTaches(){

    for (int i = 0; i < nombreTaches; i++) {
        printf("--------------------\n");
        printf("     Tache %d : \n",i+1);
        printf(" Titre : %s\n", taches[i].titre);
        printf(" Description : %s\n", taches[i].description);
        printf(" Date d'echeance : %s\n", taches[i].dateEcheance);
        printf(" Priorite : %s\n", taches[i].priorite);
        printf(" Statut : %s\n", taches[i].statut);
        printf("--------------------\n");

    }

}


void modifierTache(){
    int index ;
        printf("Entrez le numero de la tache a modifier 1 to %d : ", nombreTaches);
        scanf("%d", &index);
        printf(" 1.Pour modifier la description .\n 2.Pour modifier la date d'echeance .\n 3.Pour modifier la priorite .\n 4.Pour modifier le statut .\n");
    int choix;
        scanf("%d", &choix);
    
        switch (choix) {
    
         case 1:printf("Entrez la nouvelle description de la tache : ");    
           scanf(" %[^\n]", taches[index-1].description);
                    break;
         case 2:
         printf("Entrez la nouvelle date de fin de la tache (DD/MM/YYYY) : ");
         scanf("%s", taches[index-1].dateEcheance);
         break;
         case 3:
         printf("Entrez la nouvelle priorite (1. High / 2. Low) : ");
         scanf("%s", taches[index-1].priorite);
         break;
         case 4:
         printf("Entrez le nouveau statut (1. Compelete / 2. Incomplete) : ");
         scanf("%s", taches[index-1].statut);
         break;
 
         default:
    printf("Choix invalide.\n");
    break;
 }

    printf("Tache %d modifiee avec succes.\n", index);
   
    
    
}



void supprimerTache(){
    printf("Entrez le numero de la tache a supprimer 1 to %d : ", nombreTaches);
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
    do
    {
        printf("\nMenu :\n");
        printf("1. Ajouter une tache \n");
        printf("2. Afficher toutes les taches \n");
        printf("3. Modifier une tache \n");
        printf("4. Supprimer une tache \n");
        printf("5. Filtrer les taches ");
        printf("\n6. Quitter \n");
        printf(" Entrez votre choix : ");
        scanf("%d", &choix);

    
    switch (choix) {
    case 1:ajouterTache();break;
    case 2:afficherTaches();break;
    case 3:modifierTache(); break;
    case 4:supprimerTache(); break;
    case 5:filtrerTahches(); break;
    case 6:printf("Au revoir ! \n"); break;
    default:printf("Choix invalide .\n ");
    }
    
    
} while (choix != 6);

} 
int main(){
    menu();
    return 0;
}