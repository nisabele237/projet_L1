#include<stdio.h>
typedef struct etd{
    char Numero[20];
    char nom[30];
    char prenom[45];
    int age;
    char coordonnees[20];
   char role[20];
   char horaire[8];
    char filiere[11];
    
}e;
 void enregistrer(struct etd e,int c){
    FILE *fichier;
    fichier=fopen("membres.txt","a");      
        fprintf(fichier,"Numero: %s | Nom:%s | prenom:%s|  Role:%s| Age:%d | Filiere:%s| Coordonnees :%s | Horaire:%s | tranches: %d\n",e.Numero,e.nom, e.prenom, e.role,e.age,e.filiere, e.coordonnees,e.horaire,c);
        fprintf(fichier,"\n");
        printf("Ajout reussi!!!"); 
    fclose(fichier); 
        
  }

  void afficher(struct etd e){
  FILE *fichier;
  fichier=fopen("membres.txt","r");
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
int choix;
int num , montant , nbr ;
int n=0,c;
struct etd e;
do{
printf("\t Quelle operation souhaitez vous effectuer?\n");
printf("\t    0.Quitter le menu\n");
printf("\t    1.Enregistrer un membre\n");
printf("\t    2.Payement des frais\n");
printf("\t    3.Afficher la liste des etudiants\n");

scanf("%d",&choix);

switch (choix){
        case 0:
        printf("Merci et a une prochaine fois!!!\n");
        break;
        case 1:
             printf("BIENVENUE!!\n");
             printf("Entrez votre numero\n");
             scanf("%s",e.Numero);
             printf("Entrez votre nom\n");
              scanf("%s",e.nom);
              printf("Entrez votre role dans le club\n");
              scanf("%s",e.role);
              printf("Entrez votre age\n"); 
               scanf("%d",&e.age);
              printf("Entrez votre filiere\n");
               scanf("%s",e.filiere);
               printf("entrez vos coordonnees\n");
               scanf("%s",e.coordonnees);
               printf("entrez vos horaires(9h-11h/12h-14h/15h-17h)");
               scanf("%s",e.horaire);
              printf("En combien de tranches souhaitez vous payer? : ");
              scanf("%d",&c);
               enregistrer(e,c);
                 if(c==3){
              printf("Bien vouloir vous acquiter du montant prevu a la caisse \n Renseigner vous sur les delais de versement des deux dernieres tranches\n");
              }else if(c==2){
              printf("Bien vouloir vous acquiter du montant prevu a la caisse \n Renseigner vous sur les delais de versement de la  derniere tranche\n");
              }else if(c==1){
              printf("Bien vouloir vous acquiter du montant prevu a la caisse pour finaliser votre inscription\n ");
              }else{
              printf("Les payements ne peuvent s'effectuer ainsi \n");
              }
              break;
        case 2:
         
          printf("Entrer Votre numéro \n");
          scanf("%d",&num);
          printf("Nombre de Tranche(s) soldée(s) : 1 ? 2 ? 3 ? \n");
          scanf("%d",&nbr);
          printf("Entrer le montant versé\n");
          scanf("%d",&montant);
          FILE * fic=NULL ;
          fic=fopen("Revenus.txt","a");
          fprintf(fic,"Numéro : %d , Nombre de tranches soldées : %d , Montant : %d ", num ,nbr , montant);
          printf("Soldé !\n");
          fclose(fic);
        break;
        case 3:
        printf("*******************la liste des membres:********************\n");
         afficher(e);
        break;
        
        default:
        printf("Choix indisponible: veuillez reeffectuer votre choix\n");
        

}
 } while(choix!=0);

      return 0;


  }