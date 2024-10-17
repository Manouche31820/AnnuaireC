#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include "annuaire.h"


int main(){
    int choice = 0;
    char tab_nom[30][20];
    char tab_numero[30][20];
    char nom[100];
    char numero[100];
    memset(tab_nom, '\0', sizeof(tab_nom));
    memset(tab_numero, '\0', sizeof(tab_numero));

    printf("\n\t\tBienvenue dans votre annuaire.\n\n");
    while(1){
        printf("Souhaitez vous:\n\t-1 Afficher vos contacts\n\t-2 Rechercher un contact\n\t-3 Ajouter un contact\n\t-4 Supprimer un contact\n\n\n");
        printf("Tapez votre choix:");
        scanf("%d", &choice);
        printf("Votre choix est %d\n", choice);
        if(choice == 1){
            print_contacts(tab_nom,tab_numero);
        }else if(choice == 2){
            printf("Tapez le nom du contact que vous cherchez:\n");
            scanf("%s", nom);
            search(nom, tab_nom, tab_numero);
        }
        else if(choice == 3){
            printf("Vous avez choisi d'ajouter un contact.\nVeuillez taper le nom du contact à ajouter:\n");
            scanf("%s", nom);
            if (nom_check(nom, tab_nom) == 1) {
                printf("Ce nom existe déjà.\n");
            } else {
                printf("Veuillez taper le numéro du contact à ajouter:\n");
                scanf("%s", numero);
                if (nom_check(numero, tab_numero) == 1) {
                    printf("Ce numéro existe déjà.\n");
                } else {
                    add_contact(nom, numero, tab_nom, tab_numero);
                }
            }    
        } else if (choice == 4) {
            printf("Quel contact souhaitez vous supprimer ?\n");
            scanf("%s", nom);
            suppr_contact(nom, tab_nom, tab_numero);
        } else {
            printf("Votre choix doit être compris entre 1 et 4...\n");
        }
    }
    return(0);
}