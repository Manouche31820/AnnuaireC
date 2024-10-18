#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>


void suppr_contact(char *nom, char tab_nom[30][20], char tab_numero[30][20]){
    int numero = 0;
    int found = 0;
    for (int i = 0; i < 30; i++) {
        if (strcmp(tab_nom[i], nom) == 0) {
            numero = i;
            found = 1;
        }
    }
    if(found == 0){
        printf("Ce contact n'existe pas.\n");
        return;
    }
    else{
        for(int i = numero; i < 30; i++){
            strcpy(tab_nom[i], tab_nom[i+1]);
            strcpy(tab_numero[i], tab_numero[i+1]);
        }
    }

}

void search(char *nom, char **tab_nom, char tab_numero[30][20]){
    int numero = 0;
    for (int i = 0; i < 30; i++) {
        if (strcmp(tab_nom[i], nom) == 0) {
            printf("Le numero de %s est %s\n", tab_nom[i], tab_numero[i]);
            return;
        }
    }
    printf("Ce contact n'existe pas.\n");
}

int nom_check(char *nom, char tab_nom[30][20]) {
    for (int i = 0; i < 30; i++) {
        if (strcmp(tab_nom[i], nom) == 0) {
            return 1;
        }
    }
    return 0;
}

void add_contact(char *nom, char *numero, char tab_nom[30][20], char tab_numero[30][20]){
    int i = 0;int j = 0;int k = 0;
    while (tab_nom[i][0] != 0)
        i++;
    strcpy(tab_nom[i], nom);
    strcpy(tab_numero[i], numero);
    printf("Le contact %s a été ajouté\n", nom);

}

void print_contacts(char tab_nom[30][20], char tab_numero[30][20]){
    int i = 0;int j = 0;
    printf("\n\n");
    printf("*******************************************\n");
    printf("*               ANNUAIRE                  *\n");
    printf("*******************************************\n");
    printf("*                                         *\n");
    printf("*   NOM                        NUMERO     *\n");
    printf("*                                         *\n");
    printf("*******************************************\n");

    while(tab_nom[j][0] != 0){
        j++;
    }
if (tab_nom[i][0] != '\0') {
    for (int i = 0; i != j; i++) {
        printf("*   %-26s%-11s*\n", tab_nom[i], tab_numero[i]);
    }
    printf("*******************************************\n");
} else {
    printf("*     Aucune donnée disponible             *\n");
    printf("*******************************************\n");
}


}