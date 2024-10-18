#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include "annuaire.h"


void suppr_contact(Annuaire *book, char *nom){
    int numero = 0;
    int found = 0;
    for (int i = 0; i < 30; i++) {
        if (strcmp(book->tab_nom[i], nom) == 0) {
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
            strcpy(book->tab_nom[i], book->tab_nom[i+1]);
            strcpy(book->tab_numero[i], book->tab_numero[i+1]);
        }
    }

}

void search(Annuaire *book, char *nom){
    int numero = 0;
    for (int i = 0; i < 30; i++) {
        if (strcmp(book->tab_nom[i], nom) == 0) {
            printf("Le numero de %s est %s\n", book->tab_nom[i], book->tab_numero[i]);
            return;
        }
    }
    printf("Ce contact n'existe pas.\n");
}

int nom_check(Annuaire *book, char *nom) {
    for (int i = 0; i < 30; i++) {
        if (strcmp(book->tab_nom[i], nom) == 0) {
            return 1;
        }
    }
    return 0;
}

void add_contact(Annuaire *book, char *nom, char *numero){
    int i = 0;int j = 0;int k = 0;
    while (book->tab_nom[i][0] != 0)
        i++;
    strcpy(book->tab_nom[i], nom);
    strcpy(book->tab_numero[i], numero);
    printf("Le contact %s a été ajouté\n", nom);

}

void print_contacts(Annuaire *book){
    int i = 0;int j = 0;
    printf("\n\n");
    printf("*******************************************\n");
    printf("*            ANNUAIRE STRUCTURE           *\n");
    printf("*******************************************\n");
    printf("*                                         *\n");
    printf("*   NOM                        NUMERO     *\n");
    printf("*                                         *\n");
    printf("*******************************************\n");

    while(book->tab_nom[j][0] != 0){
        j++;
    }
if (book->tab_nom[i][0] != '\0') {
    for (int i = 0; i != j; i++) {
        printf("*   %-26s%-11s*\n", book->tab_nom[i], book->tab_numero[i]);
    }
    printf("*******************************************\n");
} else {
    printf("*     Aucune donnée disponible             *\n");
    printf("*******************************************\n");
}


}