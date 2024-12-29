#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"article.h"

/*
struct Article{
    char reference [100];
    char designation [100];
    int prix_unitaire;
    int quantite_stock;
    int quantite_seuil;
    char nom_fournisseur [100];

};
*/
void ajouter(article *a){
    FILE *f = NULL;
    f = fopen("article.txt", "a");//ouverture en mode ajout"a"

    if(f == NULL) exit(-1);//teste si l'ouverture a reussis

    fprintf(f, "%s %s %d %d %d %s", a->reference, a->designation, a->prix_unitaire, a->quantite_stock, a->quantite_seuil, a->nom_fournisseur);//ecriture dans le fichier
    fclose(f);//fermeture du fichier
}

int rechercher(char* ref)
{
    article a;

    FILE *f = NULL;
    f = fopen("article.txt", "r");//ouverture en mode lecture
    if(f == NULL) exit(-1);//test si l'ouverture a echouer

    while(fscanf(f, "%s %s %d %d %d %s",a.reference, a.designation, &a.prix_unitaire, &a.quantite_stock, &a.quantite_seuil, a.nom_fournisseur) != EOF)//on atteint pas la fin du fichier
    {
        if(strcmp(a.reference, ref) == 0){
            fclose(f);//fermeture du fichier
            return a.quantite_stock;//pour dire qu'on a trouver l'article
        }
    }
    fclose(f);
    return -1;//article introuvable
}

int capital(){
    article a;
    int capital = 0;

    FILE *f = NULL;

    f = fopen("article.txt", "r");
    if(f == NULL) exit(-1);

    while(fscanf(f, "%s %s %d %d %d %s",a.reference, a.designation, &a.prix_unitaire, &a.quantite_stock, &a.quantite_seuil, a.nom_fournisseur) != EOF)//on atteint pas la fin du fichier
    {
        capital += a.prix_unitaire * a.quantite_stock; 
    }

    fclose(f);
    return capital;
}

void alerter()
{
    article a;

    FILE *f = NULL;
    f = fopen("article.txt", "r");
    if(f == NULL) exit(-1);

    printf("\t==== LISTES DES ARTICLES DONC QUANTITE EN STOCK SONT NULL====\t\n\n");

    while(fscanf(f,"%s %s %d %d %d %s", a.reference, a.designation, &a.prix_unitaire, &a.quantite_stock, &a.quantite_seuil, a.nom_fournisseur) != EOF)//on atteint pas la fin du fichier
    {
        if(a.quantite_stock == 0)
        {
            printf("\tReference:%s\n", a.reference);
            printf("\tDesignation:%s\n", a.designation);
            printf("\tQuantite En Stock:%d\n", a.quantite_stock);
            printf("\tNom Du Fournisseur:%s\n", a.nom_fournisseur);

            printf("\n\n");
        }

        fclose(f);
    }
    
}

int supprimer(char* ref)
{

    if(rechercher(ref) == 0)// si l'article qu'on veut supprimer est present
    {
        article a[100];
        int i = 0, j = 0;

        FILE *f = NULL;
        f = fopen("article.txt", "r");
        if(f == NULL) exit(-1);

        while(fscanf(f,"%s %s %d %d %d %s", a[i].reference, a[i].designation, &a[i].prix_unitaire, &a[i].quantite_stock, &a[i].quantite_seuil, a[i].nom_fournisseur) != EOF)//on cherche a copier sa dans le tableau d'article
        {
            i++;
        }
        fclose(f);

        f = fopen("article.txt", "w");//on ouvre en mode 'w'
        /*on vas recrire tous les articles sauf celui donc on veut supprimer*/
        while(i>j)
        {
            if(strcmp(a[j].reference, ref) != 0)
            {
                fprintf(f, "%s %s %d %d %d %s", a[j].reference, a[j].designation, a[j].prix_unitaire, a[j].quantite_stock, a[j].quantite_seuil, a[j].nom_fournisseur);//ecriture dans le fichier
            }
            j++;
        }
        fclose(f);
        return 0;//l'article a été supprimer

    }else{
        return 1;//l'article est n'a pas ete supprimer
    }
    
}

void menu()
{
    printf("\t ===== BIENVENUE DANS VOTRE MAGASIN QUE VOULIEZ-VOUS FAIRE? ===== \t\n\n");
    printf("\t[0].Quitter.\n");
    printf("\t[1]-Ajouter un article.\n");
    printf("\t[2]-Rechercher un article.\n");
    printf("\t[3]-Supprimer un article.\n");
    printf("\t[4]-Afficher la liste des articles dont la quantite seuil est null.\n");
    printf("\t[5]-Voir le Capital.\n");
    
    printf("\tFaites un choix:");

}



