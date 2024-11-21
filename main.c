#include <stdio.h>
#include <string.h>

struct Tache {
     char title[50];
     char description[100];
     char dataEcheance[10];//Format : dd/mm/yyyy
     char priorite[10];// low,high

};
    //Table stock des tâches
struct Tache listTaches[100];
int nombreTaches = 0;
// Functions ajouter une tache
void ajouterTache() {
    if (nombreTaches >= 100) {
        printf("La liste des taches est pleine.\n");
        return;
    }
    printf("Entrez le title de la tache : ");
    scanf(" %[^\n]", listTaches[nombreTaches].title);
    printf("Entrez la description de la tache : "); 
    scanf(" %[^\n]", listTaches[nombreTaches].description);
    printf("Entrez la date de fin de la tache (DD/MM/YYYY) : ");
    scanf("%s", listTaches[nombreTaches].dataEcheance);
    printf("Entrez la priorite de la tache (High/Low) : ");
    scanf("%s", listTaches[nombreTaches].priorite);
   
    nombreTaches++;

    printf("Tache ajoutee avec succes.\n");

}

void afficherTaches() {
    if (nombreTaches == 0) {
        printf("Aucune tache a afficher .\n");
        return;
    }
  for (int i = 0; i < nombreTaches; i++) {

    printf("\n Tache %d : \n", i + 1);
    printf("Titre            : %s\n", listTaches[i].title);
    printf("Description      : %s\n", listTaches[i].description);
    printf("Echeance         : %s\n", listTaches[i].dataEcheance);
    printf("Priorite         : %s\n", listTaches[i].priorite);


  }
}
void modifierTache() {
    int index;
    printf("Entrez le numero de la tache a modifier (1-%d): ", nombreTaches);
    scanf("%d",&index);


    if (index < 1 || index > nombreTaches){

        printf("Numero de tache invalide !!!.\n");
        return;

    }

    index--;

    printf("Entrez le nouveau title de la tache : ");
    scanf(" %[^\n]", listTaches[index].title);
    printf("Entrez la nouvelle description de la tache : ");
    scanf(" %[^\n]", listTaches[index].description);
    printf("Entrez la nouvelle date de fin de la tache (DD/MM/YYYY) : ");
    scanf("%s", listTaches[index].dataEcheance);
    printf("Entrez la nouvelle priorite de la tache (High/Low) : ");
    scanf("%s", listTaches[index].priorite);

    printf("Tache modifiee avec succes.\n");

}


int main(){
    ajouterTache();
    afficherTaches();
    modifierTache();
    afficherTaches();
    return 0;
}
