#include <stdio.h>
#include <string.h>
// Task struct
struct Task {
     char title[50];
     char description[100];
     char dueDate[10];//Format : dd/mm/yyyy
     char priority[10];// low,high

};
    //Table stock des tâches
struct Task taskList[100];
int taskCont = 0;
// Functions Ajouter une tache
void addTask() {
    if (taskCont >= 100) {
        printf("La liste des taches est pleine.\n");
        return;
    }
    
    printf("Entrez le titre de la tache : ");
    scanf("%[^\n]", taskList[taskCont].title);
    printf("Entrez la description de la tache : "); 
    scanf("%[^\n]", taskList[taskCont].description);
    printf("Entrez la date de fin de la tache (dd/mm/yyyy) : ");
    scanf("%s", taskList[taskCont].dueDate);
    printf("Entrez la priorite de la tache (low,high) : ");
    scanf("%s", taskList[taskCont].priority);
    taskCont++;

    printf("Tache ajoutee avec succes.\n");

}

