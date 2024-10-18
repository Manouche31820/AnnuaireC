#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include "annuaire.h"




int main(){
    int choice = 0;
    Annuaire book;
    char nom[100];
    char numero[100];

    memset(book.tab_nom, '\0', sizeof(book.tab_nom));
    memset(book.tab_numero, '\0', sizeof(book.tab_numero));

printf("\n\t*******************************************\n");
printf("\t*     Bienvenue dans votre annuaire       *\n");
printf("\t*******************************************\n\n");

while(1) {
        printf("\tQue souhaitez-vous faire ?\n");
        printf("\t-------------------------------------------\n");
        printf("\t| 1. Afficher vos contacts                |\n");
        printf("\t| 2. Rechercher un contact                |\n");
        printf("\t| 3. Ajouter un contact                   |\n");
        printf("\t| 4. Supprimer un contact                 |\n");
        printf("\t| 5. Sauvegarder les contacts             |\n");
        printf("\t-------------------------------------------\n\n");

        printf("\tTapez votre choix: ");
        scanf("%d", &choice);

        printf("\n\t-------------------------------------------\n");
        printf("\tVotre choix est : %d\n", choice);
        printf("\t-------------------------------------------\n\n");
        if(choice == 1){
            print_contacts(&book);
        }else if(choice == 2){
            printf("Tapez le nom du contact que vous cherchez:\n");
            scanf("%s", nom);
            search(&book, nom);
        }
        else if(choice == 3){
            printf("Vous avez choisi d'ajouter un contact.\nVeuillez taper le nom du contact à ajouter:\n");
            scanf("%s", nom);
            if (nom_check(&book, nom) == 1) {
                printf("Ce nom existe déjà.\n");
            } else {
                printf("Veuillez taper le numéro du contact à ajouter:\n");
                scanf("%s", numero);
                if (nom_check(&book, numero) == 1) {
                    printf("Ce numéro existe déjà.\n");
                } else {
                    add_contact(&book, nom, numero);
                }
            }    
        } else if (choice == 4) {
            printf("Quel contact souhaitez vous supprimer ?\n");
            scanf("%s", nom);
            suppr_contact(&book, nom);
        }else if(choice == 5){
            sauvegarde(&book);
        }else {
            printf("Votre choix doit être compris entre 1 et 4...\n");
        }
    }
    return(0);
}