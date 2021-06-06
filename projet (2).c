#include<stdio.h>
#include<stdlib.h>

typedef struct voiture
{    int idVoiture;
   char marque[15];
   char nomVoiture[15];
   char couleur[7];
   int nbplaces;
   int prixjour;
   char Enlocation;
}voiture;


typedef struct
{  char nom_de_loeur[30];
   char prenom_de_loueur[20];
   char marque_de_voiture[30];
   char etat_de_voiture[30];
   int  tarif_de_location;
   int  duree_de_location;
   int  tel_de_loeur;
   char ville[30];
}contr;



typedef struct
{ int jour;
  char mois[20];
  int annee;
}date;





// structure    CONTRAT //
typedef struct contratLocation
{
    float numContrat;
    int idVoiture;
    int idClient;
    date debut;
     date  fin;
    int   cout;
}contrat;






    //  Structure client //
    typedef struct Client
    {
        int idClient;
        char nom[20];
        char prenom[20];
        int cin;
        char adresse[15];
        int telephone;
    }Client;




typedef struct
{ char marque[30];
  char couleur[20];
  int matricule;
  int type_carburant;
}car;





// la fonction REMPLIR CONTRAT //
void remplircontrat()
{   contrat l;
FILE *fichier=fopen("contrat.txt","r");
if(fichier == NULL){
printf("Erreur\n");
}else{
            do{
    fprintf(fichier,"Donner le numero de loueur : \n");
    fscanf(fichier,"%f",&l.numContrat);
    fprintf(fichier,"Donner le id de voiture : \n");
    fscanf(fichier,"%d",&l.idVoiture);
    fprintf(fichier,"Donner le id de client: \n");
    fscanf(fichier,"%d",&l.idClient);
    fprintf(fichier,"Donner le jour de debut de location : \n");
    fscanf(fichier,"%d",&l.debut.jour);
    fprintf(fichier,"Donner le mois de debut de location : \n");
    fscanf(fichier,"%s",l.debut.mois);
    fprintf(fichier,"Donner l année de debut de location : \n");
    fscanf(fichier,"%d",&l.debut.annee);
    fprintf(fichier,"Donner le jour de fin de location : \n");
    fscanf(fichier,"%d",&l.fin.jour);
    fprintf(fichier,"Donner le mois de fin de location : \n");
    fscanf(fichier,"%s",l.fin.mois);
    fprintf(fichier,"Donner l année de fin de location : \n");
    fscanf(fichier,"%d",&l.fin.annee);
    fprintf(fichier,"Donner le prix de location  par jour : \n");
    fscanf(fichier,"%d",&l.cout);
}while(!feof(fichier));
fclose(fichier);
}}



// la fonction pour visualiser les informations contenus dans un contrat //
void visualiserContrat(contrat *C){

int numcontrat;

 printf(">>>>>>>>>>>>>>>>> CONTRAT DE LOCATION D UNE VOITURE <<<<<<<<<<<<<<");
printf("saisir le numero du contrat a visualiser\n");
scanf("%d",&numcontrat);

FILE *fichier=fopen("contrat.txt","r");
if(fichier == NULL){
printf("Erreur\n");
}else{
            do{
                  fscanf(fichier,"%d   %d   %d   %d/%d/%d   %d/%d/%d   %d\n",&C->numContrat,&C->idVoiture,&C->idClient,&C->debut.jour,
                  &C->debut.mois, &C->debut.annee,&C->fin.jour,&C->fin.mois,&C->fin.annee,&C->cout);
                  if(numcontrat == C->numContrat){
                  fprintf(fichier,"Le numero du contrat est   :%d\n",C->numContrat);
                  fprintf(fichier,"L' id du voiture est       :%d\n",C->idVoiture);
                  fprintf(fichier,"L' id du client est        :%d\n",C->idClient);
                  fprintf(fichier,"La date du debut est       :%d/%d/%d\n",C->debut.jour,C->debut.mois,C->debut.annee);
                  fprintf(fichier,"La date du fin est         :%d/%d/%d\n",C->fin.jour,C->fin.mois,C->fin.annee);
                  fprintf(fichier,"Le cout est                :%d\n",C->cout);
                  }

            }while(!feof(fichier));
fclose(fichier);
}
}






// la fonction louer pour entrer les informations du clients qui a louer la voiture //
void louer()
{


contrat l;

FILE *fichier=fopen("contrat.txt","r");
if(fichier == NULL){
printf("Erreur\n");
}else{
            do{
    fprintf(fichier,"Donner le numero de loueur : \n");
    fscanf(fichier,"%f",&l.numContrat);
    fprintf(fichier,"Donner le id de voiture : \n");
    fscanf(fichier,"%d",&l.idVoiture);
    fprintf(fichier,"Donner le id de client: \n");
    fscanf(fichier,"%d",&l.idClient);
    fprintf(fichier,"Donner le jour de debut de location : \n");
    fscanf(fichier,"%d",&l.debut.jour);
    fprintf(fichier,"Donner le mois de debut de location : \n");
    fscanf(fichier,"%s",l.debut.mois);
    fprintf(fichier,"Donner l année de debut de location : \n");
    fscanf(fichier,"%d",&l.debut.annee);
    fprintf(fichier,"Donner le jour de fin de location : \n");
    fscanf(fichier,"%d",&l.fin.jour);
    fprintf(fichier,"Donner le mois de fin de location : \n");
    fscanf(fichier,"%s",l.fin.mois);
    fprintf(fichier,"Donner l année de fin de location : \n");
    fscanf(fichier,"%d",&l.fin.annee);
    fprintf(fichier,"Donner le prix de location  par jour : \n");
    fscanf(fichier,"%d",&l.cout);
     }while(!feof(fichier));
fclose(fichier);


}
}



void supprimerContrat(contrat *C){

int numcontrat;
printf("sisiar le numero du contrat a supprimer\n");
scanf("%d",&numcontrat);
FILE *f;
FILE *fichier=fopen("contrat.txt","r");
if(fichier == NULL){
printf("Erreur\n");
}else{
                   f=fopen("helpcontrat.txt","w");
                    if(f == NULL){
                    printf("Erreur\n");
                    }else{
                           while(!feof(fichier)){
                           fscanf(fichier,"%d   %d   %d   %d/%d/%d   %d/%d/%d   %d\n",&C->numContrat,&C->idVoiture,&C->idClient,&C->debut.jour,
                           &C->debut.mois, &C->debut.annee,&C->fin.jour,&C->fin.mois,&C->fin.annee,&C->cout);
                           if(numcontrat != C->numContrat){
                           fprintf(f,"%d   %d   %d   %d/%d/%d   %d/%d/%d   %d\n",C->numContrat,C->idVoiture,C->idClient,
                           C->debut.jour,C->debut.mois, C->debut.annee,C->fin.jour,C->fin.mois,C->fin.annee,C->cout);
                           }
                           }
                       fclose(f);
                      }
fclose(fichier);
remove("contrat.txt");
rename("helpcontrat.txt","contrat.txt");

printf(" <<<< FELICITATION!! la suppression du contrat est reussi >>>>>\n");
}
}




// la fonction afficher voiture //
    void afficher(){
        FILE* fichier=NULL;
        char chaine[400] = "";
        fichier=fopen("voiture.txt","r");
        if(fichier != NULL){

           while (fgets(chaine, 400, fichier) != NULL) 
        {
            printf("%s", chaine);
        }
        fclose(fichier);

}
        else{
            fprintf(fichier,"AUCUNNE voiture! \n ");
        fclose(fichier);}
}






// la fonction ajouter voiture //
  void ajouterV()
  {     car v;
        FILE* fichier=NULL;
        fichier=fopen("voiture.txt","a");
        if(fichier != NULL)
        {


        fprintf(fichier,"   Nom            : %s \n",v.marque);
        fprintf(fichier,"   Coleur         : %s \n",v.couleur);
        fprintf(fichier,"   Matricule      : %d \n",v.matricule);
        fprintf(fichier,"   Type carburnat : %d \n",v.type_carburant);

        fclose(fichier);
        }
}







void modifierV(voiture *v){
FILE *file1, *file2;
int idvoiture;
printf("Saisir l' id du voiture à modifier : ");
scanf("%d",&idvoiture);
file2 = fopen("voiturehelp.txt", "a");
file1 = fopen("Voiture.txt", "r");

 while (!feof(file1))
    {
  fscanf(file1,"%d  %s  %s  %s  %d  %d  %s \n",&v->idVoiture,v->marque,v->nomVoiture,v->couleur,&v->nbplaces,&v->prixjour,v->Enlocation);
       if (idvoiture != v->idVoiture){
       fprintf(file2,"%d  %s  %s  %s  %d  %d  %s\n",v->idVoiture,v->marque,v->nomVoiture,v->couleur,
       v->nbplaces,v->prixjour,v->Enlocation);
       }else{
                                           idvoiture = v->idVoiture;
                                           printf("saisir le nouveau id \n");
                                           scanf("%d",&v->idVoiture);
                                           printf("entrer  la nouveau  marque\n");
                                           scanf("%s",v->marque);
                                           printf("entrer le nouveau nom\n");
                                           scanf("%s",v->nomVoiture);
                                           printf("entrer nouveau couleur \n");
                                           scanf("%s",v->couleur);
                                           printf("entrer le nouveau nombre de places\n");
                                           scanf("%d",&v->nbplaces);
                                           printf("entrer nouveau prix du jour \n");
                                           scanf("%d",&v->prixjour);
                                           printf("nouveau en location ?\n");
                                           scanf("%s",v-> Enlocation);
                                           fprintf(file2,"%d  %s  %s  %s  %d  %d  %s\n",v->idVoiture,v->marque,v->nomVoiture,v->couleur
                                           ,v->nbplaces,v->prixjour,v->Enlocation);
              }
}

fclose(file1);
fclose(file2);
remove("Voiture.txt");
rename("voiturehelp.txt","Voiture.txt");
printf("<<<<FELICITATION>><\n");

}








// la fonction supprimer voiture //
 void supprimerV(int voiture_a_supprimer )
  {  char ligne[500];
     FILE * fichier;
     FILE * f;
        fichier  = fopen("voiture.txt", "r");
        f = fopen("v.txt", "w");


        while (fgets(ligne, sizeof ligne, fichier))
                                      
               {
               if (ligne[0] != voiture_a_supprimer)
                               

                                
               fputs(ligne, f);
    }


 fclose(fichier);
    fclose(f);

     remove("voiture.txt");
     rename("v.txt","voiture.txt");
    }









// la fonction lister client//
  void listerC()
  {     Client cl;
        FILE* filc=NULL;
        filc=fopen("client.txt","a");
        if(filc != NULL)
        {


        fprintf(filc,"   Id Client            : %d \n",cl.idClient);
        fprintf(filc,"   Nom du Client        : %s \n",cl.nom);
        fprintf(filc,"   Prenom du Client     : %s \n",cl.prenom);
        fprintf(filc,"   CIN du Client        : %d \n",cl.cin);
        fprintf(filc,"   Adresse du Client    : %s \n",cl.adresse);
        fprintf(filc,"   N de tele du Client  : %d \n",cl.telephone);

        fclose(filc);
        }
}





void modifierC()

{FILE *filc=NULL;
 FILE *fc=NULL;
 int idc ;
 Client cl;

 filc=fopen("client.txt","r");
 if (filc != NULL)
 {
     fc=fopen("clienthelp","w");
     if(fc != NULL)
     {
         printf("Entrez l Id du Client qui vous veullez   modifier :   \n ");
         scanf("%d",&idc);
         while(fscanf(filc,"%d %s %s %d %s %d ",&cl.idClient,cl.nom,cl.prenom,&cl.cin,cl.adresse,&cl.telephone))
         {
             if(cl.idClient != idc)
             {
                 fprintf(fc,"%d %s %s %d %s %d ",&cl.idClient,cl.nom,cl.prenom,&cl.cin,cl.adresse,&cl.telephone);
             }
             else
                {puts("Donnez le nouveu Id : \n");
                 scanf("%d",&cl.idClient);
                 fprintf(fc,"%d",cl.idClient);
                 puts("Donnez le nouveu Nom : \n");
                 scanf("%s",cl.nom);
                 fprintf(fc,"%d",cl.nom);
                 puts("Donnez le nouveu Prenom : \n");
                 scanf("%s",cl.prenom);
                 fprintf(fc,"%s",cl.prenom);
                 puts("Donnez le nouveu CIN : \n");
                 scanf("%d",&cl.cin);
                 fprintf(fc,"%d",cl.cin);
                 puts("Donnez le nouveu Adresse : \n");
                 scanf("%s",cl.adresse);
                 fprintf(fc,"%s",cl.adresse);
                 puts("Donnez le nouveu Numero de telephone : \n");
                 scanf("%d",&cl.telephone);
                 fprintf(fc,"%d",cl.telephone);




                }
         }

fclose(fc);


     }else printf("ERREUR");
      fclose(filc);



 }else printf("ERREUR");
       remove("client.txt");
       rename("clienthelp.txt","client.txt");

}








// la fonction SUPPRIMER CLIENT pour supprimer le client convenable //

void supprimerC(int client_a_supprimer )
  {  char ligne[500];
     FILE * filc;
     FILE * fclient;
        filc  = fopen("client.txt", "r");
        fclient = fopen("c.txt", "w");


        while (fgets(ligne, sizeof ligne, filc))
                                      
               {
               if (ligne[0] != client_a_supprimer)
                               

                                
               fputs(ligne, fclient);
    }


 fclose(filc);
    fclose(fclient);

     remove("client.txt");
     rename("c.txt","client.txt");
    }








//la fonction main /:
void main(){
         int n,a,b,c,choix;
          contrat C;
          voiture v;
          int voiture_a_supprimer ;
          Client cl;
          int client_a_supprimer;
          while(n!=4) {

  printf("===================================================\n \n");
  printf("            Menu Principal            \n \n \n");
  printf("===================================================\n \n");
  printf("    Location............................. 1 \n");
  printf("    Gestion voitures..................... 2 \n");
  printf("    Gestion clients ..................... 3 \n");
  printf("    Quitter.............................. 4 \n");
  printf("    \n \n \n");
  printf("                   votre choix : ");
  scanf("%d",&n);
  printf("    \n \n \n");
  switch(n)

{        case 1:
             //LOCATION D UNE VOITURE //

             printf("             \n  \n ");
             printf("\n           Visualiser contrat ................ 1 \n");
             printf("\n           Louer voiture ..................... 2 \n");
             printf("\n           Retourner voiture  ................ 3 \n");
             printf("\n           Modifier contrat .................. 4 \n");
             printf("\n           Suprimer contrat .................. 5 \n");
             printf("\n           Retour ........... ................ 6 \n");
             printf("\n \n \n ");
             printf("                            Votre choix :   ");
             scanf("%d",&a);
             printf("    \n \n \n");
              //pour le retour //
              while(a != 6)
              {


             switch(a)
                   {
                   	  case 1:
                           visualiserContrat(&C);
                   	      break;
                      case 2:
                          louer();
                          break;
                      case 3:

                          break;
                      case 4:

                         break;
                      case 5:
                         supprimerContrat(&C);
                         break;
                      case 6:
                          break;


				   }

             break;
 }
       case 2:
             //GESTIONS VOITURES //
             printf("\n=============================================\n");
             printf("               GESTION DES VOITURES              ");
             printf("\n=============================================\n");

             printf(">>> Veuillez Choisir l'une de ces commandes : \n\n");
             printf("Liste des voitures...................... 1\n");
             printf("Ajouter voiture ........................ 2\n");
             printf("Modifier voiture ....................... 3\n");
             printf("Supprimer voiture ...................... 4\n");
             printf("RETOUR ................................. 5");

             printf("\n=============================================");


            printf("\n \t \t           Votre choix :   ");
            scanf("%d",&choix);
            printf("\n");
            printf("\n ");

            //retour//
            while(choix != 5)
            {


               switch(choix)
                 {
                  case 1:
                      afficher();
                      break;
                  case 2:
                      ajouterV();
                      break;
                  case 3:
                      modifierV(&v);
                      break;
                  case 4:
                        printf("donner le numero de voiture a supprimer  \n \n");
                        scanf("%d",&voiture_a_supprimer);
                      supprimerV(voiture_a_supprimer );
                      break;
                  case 5:
                    break;


 }


                 }


        case 3:
            //GESTIONS DES CLIENTS //
            printf("                 Gestion des clients            ");
            printf("\n \n ");
            printf("\n          Liste des clients ................. 1 \n");
            printf("\n          Ajouter clients ................... 2 \n");
            printf("\n          Modifier clients  ................. 3 \n");
            printf("\n          Suprimer clients .................. 4 \n");
            printf("\n          Retour ........... ................ 5 \n");
            printf("                             Votre choix :   ");
            scanf("%d",&c);
            printf("    \n \n \n");
                switch(c)
                {
                    case 1:
                         //liste des clients//
                         listerC();
                         break;
                    case 2 :
                         break;
                    case 3:
                        modifierC();
                        break;
                    case 4:
                        printf("donner le numero de client a supprimer  \n \n");
                        scanf("%d",&client_a_supprimer);
                        supprimerC(client_a_supprimer);
                        break;
                    case 5:
                        break;

                }

            break;

        case 4:
        	break;


}

          }
}

