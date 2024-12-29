#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"article.h"


int main()
{
    article a;
    int c = 0, rec=0;//choix, rechercher;
    char ref[100];//reference;

    do
    {
        menu();//appel de la fonction pour afficher le menu
        scanf("%d", &c);

        switch(c)
        {
            case 0:
                printf("Aurevoir!!!\n\n");
                exit(-1);
                break;
            case 1://ajouter
                printf("Entrer la reference:");
                scanf("%s", a.reference);
                printf("Entrer la designation:");
                scanf("%s", a.designation);
                printf("Entrer le prix unitaire:");
                scanf("%d", &a.prix_unitaire);
                printf("Entrer la quantite en stock:");
                scanf("%d", &a.quantite_stock);
                printf("Entrer la quantite en seuil:");
                scanf("%d", &a.quantite_seuil);
                printf("Entrer le nom du fournisseur:");
                scanf("%s", a.nom_fournisseur);

                ajouter(&a);
                printf("L'article a belle et bien ete ajouter a la boutique.\n");

                break;
            case 2://rechercher
                    printf("Entrer la reference de l'article rechercher:");
                    scanf("%s", ref);

                    rec = rechercher(ref);

                    if(rec == 0)
                        printf("Article a été trouver dans la boutique.\n\n");
                    else
                        printf("Article introuvable.\n\n");

                break;
            case 3://supprimer
                    printf("Entrer la reference de l'article a supprimer:");
                    scanf("%s", ref);

                    rec = supprimer(ref);


                    if(rec == 0)
                        printf("Article a belle été bien supprimer dans la boutique.\n\n");
                    else
                        printf("Article n'a pas été supprimer dans la boutique.\n\n");

                break;
            case 4://liste des articles dont la quantite seuil est null
                    alerter();
                break;
            case 5://Voir le Capital
                    rec = capital();
                    printf("Le capital de votre boutique est de %dfr.\n", rec);
                break;
            
            default: printf("Choix invalide!!!");
        }
    }while(c <= 5);

    return 0;
}