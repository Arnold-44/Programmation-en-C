#ifndef ARTICLE_H
#define ARTICLE_H

//STRUCTURE DE DONNEES

typedef struct Article article;
struct Article{
    char reference [100];
    char designation [100];
    int prix_unitaire;
    int quantite_stock;
    int quantite_seuil;
    char nom_fournisseur [100];

};

//declaration des fonctions
void ajouter(article *a);
int rechercher(char* ref);
void alerter();
int supprimer(char* ref);
void menu();
int capital();


#endif