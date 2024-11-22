
void filtrerTachesParPriorite() {
    if (nombreTaches == 0) {
        printf("Aucune tache a afficher.\n");
        return;
    }

    printf("Entrez la priorite a afficher (1. High / 2. Low) : ");
    int choixPriorite;
    scanf("%d", &choixPriorite);

    char prioriteFiltre[10];
    if (choixPriorite == 1) {
        strcpy(prioriteFiltre, "High");
    } else if (choixPriorite == 2) {
        strcpy(prioriteFiltre, "Low");
    } else {
        printf("Choix invalide. Retour au menu principal.\n");
        return;
    }

    printf("\nTaches avec priorite '%s' :\n", prioriteFiltre);
    int found = 0;
    for (int i = 0; i < nombreTaches; i++) {
        if (strcmp(listTaches[i].priorite, prioriteFiltre) == 0) {
            printf("\nTache %d :\n", i + 1);
            printf("Titre       : %s\n", listTaches[i].title);
            printf("Description : %s\n", listTaches[i].description);
            printf("Echeance    : %s\n", listTaches[i].dataEcheance);
            found = 1;
        }
    }

    if (!found) {
        printf("Aucune tache avec cette priorite trouvee.\n");
    }
}

//7687687687686868768768757765465454634788765434578987654576876876876868687687687577654654546347887654345789876545768768768768686876876875776546545463478876543457898765457687687687686868768768757765465454634788765434578987654576876876876868687687687577654654546347887654345789876545768768768768686876876875776546545463478876543457898765457687687687686868768768757765465454634788765434578987654576876876876868687687687577654654546347887654345789876545768768768768686876876875776546545463478876543457898765457687687687686868768768757765465454634788765434578987654576876876876868687687687577654654546347887654345789876545