#include<stdio.h>
void afficher(){
      FILE *fichier;
            fichier=fopen("rappel.txt","r");
            if(fichier==NULL){
            printf("liste vide!!!");
            }else{
            char c;
            while((c=fgetc(fichier))!=EOF){
            printf("%c",c);
      
        }
        }
        printf("\n");
        printf("operation terminee!!!\n");
}
int main(){
    int sa=300,de=50,se=1000,sp=1000;
    int choix,a,b,c,d,e,f,g,h,i;
    char date1[10],date2[10],date3[10],libelle[1500];
    float budget,budget3;
    do{
    printf("MODULE DE GESTION DE TACHE\nQuelle operations desirez vous effectuer?\n");
    printf("\t0.Quitter\t1.Menage\n\t2.Renovation\n\t3.Autres\n\t4.afficher l'historique\n");
    scanf("%d",&choix);
    
    switch(choix){
        case 0:
        //sortie du menu
        printf("Merci pour votre passage!\n");
        break;
        case 1:
        
        printf("Entrez la date de l'echeance (jj/mm/aa)\n");
        scanf("%s",date1);
        printf("Le budget minimal pour le menage\n");
        printf("De quoi avez vous besoin (rempilssez les quantites;0 si rien)?\n");
             printf("savon\n");
             scanf("%d",&a);
             printf("detergent\n");
             scanf("%d",&b);
             printf("seau(x)\n");
             scanf("%d",&c);
             printf("serpielere\n");
             scanf("%d",&d);
              budget=a*sa+b*de+c*se+d*sp;
             printf("le budget necessaire pour le menage du %s est: %.2f",date1,budget);
             
             FILE *fichier;
             fichier=fopen("rappel.txt","a");
             fprintf(fichier,"Type: Menage | Echeance : %s | budget: %.2f |",date1,budget);
             if(budget<50){
                printf("statut:En attente de ressources\n");
                 fprintf(fichier,"Statut:En attente de ressources\n");
             }else{
                printf(" Statut:En cours\n");
                 fprintf(fichier,"Statut:En cours\n");
             }
            
             fprintf(fichier,"\n");
             printf("Enregistrement reussie Felicitations!!\n");
             fclose(fichier);

             break;

             case 2:
             printf("Entrez la date d'echeance\n");
             scanf("%s",date2);
             printf("De quoi avez vous besoin (rempilssez les quantites;0 si rien)?\n");
             printf("seaux de peinture\n");
             scanf("%d",&e);
             printf("rouleaux\n");
             scanf("%d",&f);
             printf("planches\n");
             scanf("%d",&g);
             printf("sac de ciment\n");
             scanf("%d",&h);
             printf("Comission ouvrier(deja negociee)\n");
           int ciment=5000,peinture=2500,roul=1000,planches=1500,co=10000;
           float budget2=e*peinture+f*roul+g*planches+h*ciment+i*co;
          printf("le budget necessaire pour la renovation du %s est: %.2f\n",date2,budget2);
            fichier=fopen("rappel.txt","a");
             fprintf(fichier,"Type: Renovation | Echeance : %s | budget: %.2f \n",date2,budget2);
             fprintf(fichier,"\n");
             printf("Enregistrement reussie Felicitations!!\n");
             fclose(fichier);

             break;

             case 3:
              printf("Entrez la date d'echeance\n");
               scanf("%s",date3);
               printf("Veuillez saisir le libelle de votre tache au sein du club(1500 mot maximum)\n");
               scanf("%s",libelle);
               printf("entrez le budget previsionnel(il doit avoir ete valide par les responsablees au prealable)\n");
               scanf("%f",&budget3);
              printf("le budget necessaire pour  %s  du %s est: %.2f\n",libelle,date3,budget3);
            fichier=fopen("rappel.txt","a");
             fprintf(fichier,"Type: Autres | Echeance : %s | budget: %.2f \n",date3,budget3);
             fprintf(fichier,"\n");
             printf("Enregistrement reussie Felicitations!!\n");
             fclose(fichier);

             break;

             case 4:
            printf("***********HISTORIQUE DES TACHES*****************\n");
            afficher();
            break;
            default:
            printf("choix indisponible\n");
    }
    
    }while(choix!=0);
    return 0;

}
