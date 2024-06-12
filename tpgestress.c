//Projet de gestion des ressources d'un club 
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
 struct ressources{
    char reference[10];
    char designation[50];
    int quantite;
   
};
struct reservation{
    char id[10];
    char date[10];
    char reference[10];
    int quantite;
};

typedef struct reservation reserv;
typedef struct ressources ressources;

void ajout( ressources r){
    FILE *fic;
    fic=fopen("ressources.txt","a");
    fprintf(fic,"%s;%s;%d\n",r.reference,r.designation,r.quantite);
    printf("Reference:%s|Designation:%s|Quantite:%d\n",r.reference,r.designation,r.quantite);
    printf("\n");
   
    fclose(fic);

}
int rechercher(char *reference,int qte){
   ressources res;
  
      FILE *fic;
    fic=fopen("ressources.txt","r");
    if(fic==NULL){
        printf("le fichier de la base de donnees n'existe pas.Veuillez verifier le nom!\n");
        return 0;
    }
     while(fscanf(fic,"%[^;];%[^;];%d\n",res.reference,res.designation,&res.quantite)==3)
     {
        if(strcmp(res.reference,reference)==0 && res.quantite==qte)
        return 1;
    }
    return 0;
}
void retirer(char *reference,int quantite){
    int trouve=0,i=0;
    ressources tab[1000];
    FILE *fic;
    fic=fopen("ressources.txt","r");
    if(fic==NULL){
        printf("le fichier de la base de donnees n'existe pas.Veuillez verifier le nom!\n");
        return ;
    }
    
    while(fscanf(fic,"%[^;];%[^;];%d\n",tab[i].reference,tab[i].designation,&tab[i].quantite)==3){
      if(strcmp(tab[i].reference,reference)==0){
        trouve=1;
        if(tab[i].quantite<quantite){
            printf("Erreur:Nous ne disposons en stock que de %d %s.\nRetrait impossible!\n",tab[i].quantite,tab[i].designation);
            return ;
        }
        tab[i].quantite-=quantite;
      }
         
      i+=1;

    }

    fclose(fic);
    if(trouve!=1){
        printf("Element introuvable\n");
        return;
    }
     fic =fopen("ressources.txt","w");
     for(int j=0;j<i;j++){
        if(tab[j].quantite!=0){
        ajout(tab[j]);
      
     }
     }
       printf("Retrait effectue avec succes\n");
     fclose(fic);
    

}
//declaration des fonctions secondaire

void reserver(reserv element){

   if(rechercher(element.reference,element.quantite)==0){
    printf("element inexistant ou quantite invalide!\n");
    return;
   }

    FILE *fic;
    fic=fopen("reservation.txt","a");
    fprintf(fic,"%s;%s;%s;%d\n",element.id,element.date,element.reference,element.quantite);
    printf("Membre:%s |Date:%s |Reference:%s|Quantite:%d\n",element.id,element.date,element.reference,element.quantite);
    printf("\n");
   
    fclose(fic);
    retirer(element.reference,element.quantite);
}

int main(){
    int choix,quantite;
    ressources r;
    char reference[50];
    reserv re;

    printf("Bienvenue dans le module de gestion de ressources\n");
    printf("Quelle operation souhaitez vous effectuer?\n");
    printf("\t1.Faire un don\n\t2.Ajouter un equipement\n\t3.Retirer un equipement\n\t4.Reserver un equipement\n\t5.Afficher la liste des equipements\n\t6.Afficher la liste des elements disponbles\n\t7.Afficher la liste des equipement reserves\n");
     printf("choix:");
     scanf("%d",&choix);
     switch(choix){
        case 1:
            printf("Quel type de don souhaitez vous effectuer?\n");
            printf("\t1.Don materiel\n\t2.Don financier\n");
            switch(choix){
                case 1: 
               
                   break;
                case 2:
              
                    break;
                default:
                 printf("Choix indisponible!\n");
            }
            case 2:
               printf("Quel est la reference de l'equipement? :");
                scanf("%s",r.reference);
                printf("Quelle est sa designation? : ");
                scanf("%s",r.designation);
                printf("Combien d'elements souhaitez vous rajouter? : ");
                scanf("%d",&r.quantite);
                ajout(r);
                 printf("Ajout reussie!!\n");
                sleep(1);
               break;
            case 3:
            printf("Entrez la reference de l'equipement s'il vous plait : ");
            scanf("%s",reference);
            printf("Combien d'elements souhaitez vous retirer? : ");
            scanf("%d",&quantite);
            retirer(reference,quantite);
             break;
             case 4:
                  
                    printf("entrez l'identifiant du membre:");
                    scanf("%s",re.id);
                    printf("entrez la date de reservation (JJ/MM/AAAA):");
                    scanf("%s",re.date);
                    printf("entrez la reference:");
                    scanf("%s",re.reference);
                    printf("entrez la quantite:");
                    scanf("%d",&re.quantite);
                    reserver(re);
             break;
             case 5:
             break;
             case 6:
             break;
             case 7:
             break;
             default:
             printf("choix indisponible\n");
             
     }
}