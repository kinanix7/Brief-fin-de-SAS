#include <stdio.h>
#include <string.h>

struct Tache {
     char title[50];
     char description[100];
     char dataEcheance[10];//Format : dd/mm/yyyy
     char priorite[10];// low,high
     char 

};
    //Table stock des tâches
struct Tache listTaches[100];
int nombreTaches = 0;
// Functions Ajouter une tache
void AjouterTache() {
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

void AfficherTaches() {
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


int main(){

}
