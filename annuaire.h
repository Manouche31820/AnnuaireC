#ifndef ANNUAIRE_H
#define ANNUAIRE_H

typedef struct Annuaire{
    char tab_nom[30][20];
    char tab_numero[30][20];
} Annuaire;

void suppr_contact(Annuaire *book, char *nom);
void search(Annuaire *book, char *nom);
int nom_check(Annuaire *book, char *nom);
void add_contact(Annuaire *book, char *nom, char *numero);
void print_contacts(Annuaire *book);

#endif