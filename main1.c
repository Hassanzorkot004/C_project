#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "reservation.h"


int main()
{
    Reservation res;
    Reservation nouvelleres;
    int choix,n=5,option;
    char id[8];
    char *filename = "Rese.txt";
    Parking TabParkings[100];
    Offre offre;


    do{
            do{
        printf("1-Ajouter une reservation\n");
        printf("2-supprimer une reservation\n");
        printf("3-modifier une reservation\n");
        printf("4-Afficher les reservations \n");
        printf("5-Afficher la liste des places disponibles\n");
        printf("6-voir offre\n");
        printf("0-quittez\n");
        printf("veuillez faire le choix \n");
        scanf("%d",&choix);
        } while((choix>6)||(choix<0));
          
          switch(choix){
            case 1:
                        printf("donner l id de reservation\n");
                        scanf("%s",res.id_reservation);

                        printf("donner le nom du parking:\n ");
                        getchar();
                         fgets(res.parking.nom, sizeof(res.parking.nom), stdin);
                           res.parking.nom[strcspn( res.parking.nom, "\n")] = '\0';

                         printf("donner l id du parking :\n ");
                       scanf("%s",res.parking.id_parking);
                        printf(" donner l adresse du parking:\n");
                        getchar();
                      fgets(res.parking.adresse, sizeof(res.parking.adresse), stdin);
                       res.parking.adresse[strcspn( res.parking.adresse, "\n")] = '\0';
                       printf("donner le type de place(standart ou handicape) :\n");
                         scanf("%s",res.place.type);


                        printf("donnez la date de reservation:\n");
                       scanf("%d %d %d",&(res.date_reservation.jour),&(res.date_reservation.mois),&(res.date_reservation.annee));
                       printf("%d/%d/%d",res.date_reservation.jour,res.date_reservation.mois,res.date_reservation.annee);
                       printf("donnez l heure de debut:\n");
                       scanf("%d%d",&(res.heure_debut.heure),&(res.heure_debut.minute));
                       printf("%d:%d",res.heure_debut.heure,res.heure_debut.minute);
                        printf("donnez l heure de fin:\n");
                       scanf("%d%d",&(res.heure_fin.heure),&(res.heure_fin.minute));
                        printf("%d:%d",res.heure_fin.heure,res.heure_fin.minute);
                        printf("donner le bloc:\n");
                        printf("veuillez faire le choix entre A , B et C\n");
                       scanf("%s",res.place.bloc);
                       printf("donnez le type de vehicule\n");
                       printf("veuillez faire le choix entre voiture ,moto et Camion\n");
                        scanf("%s",res.vehicule.type);
                        printf("donnez la matricule de vehicule\n");
                       scanf("%s",res.vehicule.matricule);
                       printf("donnez le type de service\n");
                       printf("veuillez faire le choix entre: lavage/Maintien/Reservation simplifiee\n");
                       getchar();
                       fgets(res.service.demande_service, sizeof(res.service.demande_service), stdin);
                       res.service.demande_service[strcspn( res.service.demande_service, "\n")] = '\0';

                       printf("donnez le mode de paiement\n");
                       printf("veuillez faire le choix entre paiment en ligne ou sur place\n");
                       getchar();
                      fgets(res.service.paiement, sizeof(res.service.paiement), stdin);
                      res.service.paiement[strcspn( res.service.paiement, "\n")] = '\0';
                            int X=ajouter_reserv(filename , res);
                            if(X==1){
                                printf("ajout avec succes\n");
                            }
                       break;
                case 2: printf("donnez l id de la reservation a supprimer\n");

                          scanf("%s",id);

                          supprimer_reserv(filename, id );
                          break;
                 case 3: 
                 printf("Donnez l'ID de la réservation à modifier: ");
                scanf("%s", id);

                // Initialiser nouvelleres avec les données actuelles de la réservation
                Reservation temp;
                FILE *fp = fopen(filename, "r");
                if (fp != NULL) {
                    while (fscanf(fp, "%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%d/%d/%d|%d:%d|%d:%d|%[^|]|%[^|]|%[^|]|%[^|]|%[^\n]\n",
                                 temp.id_reservation, temp.parking.nom, temp.parking.id_parking, temp.parking.adresse,
                                 temp.place.type,
                                 &temp.date_reservation.jour, &temp.date_reservation.mois,
                                 &temp.date_reservation.annee, &temp.heure_debut.heure,
                                 &temp.heure_debut.minute, &temp.heure_fin.heure, &temp.heure_fin.minute,
                                 temp.place.bloc, temp.vehicule.type, temp.vehicule.matricule,
                                 temp.service.demande_service, temp.service.paiement) != EOF) {
                        if (strcmp(temp.id_reservation, id) == 0) {
                            nouvelleres = temp;
                            break;
                        }
                    }
                    fclose(fp);
                } else {
                    printf("Erreur d'ouverture du fichier\n");
                }

                do {
                    printf("1-Modifier nom du parking\n");
                    printf("2-Modifier ID du parking\n");
                    printf("3-Modifier adresse du parking\n");
                    printf("4-Modifier le type de place\n");
                    printf("5-Modifier la date de réservation\n");
                    printf("6-Modifier l'heure de début\n");
                    printf("7-Modifier l'heure de fin\n");
                    printf("8-Modifier le bloc\n");
                    printf("9-Modifier le type de véhicule\n");
                    printf("10-Modifier la matricule de véhicule\n");
                    printf("11-Modifier le type de service\n");
                    printf("12-Modifier le mode de paiement\n");
                    printf("0-Quitter\n");
                    printf("Choisir une option: ");
                    scanf("%d", &option);

                    while ((option < 0) || (option > 12)) {
                        printf("Option invalide. Veuillez réessayer: ");
                        scanf("%d", &option);
                    }

                    switch (option) {
                        case 1:
                            printf("Donner le nom du parking: ");
                            getchar(); // Consommer le caractère de retour à la ligne
                            fgets(nouvelleres.parking.nom, sizeof(nouvelleres.parking.nom), stdin);
                            nouvelleres.parking.nom[strcspn(nouvelleres.parking.nom, "\n")] = '\0';
                            break;

                        case 2:
                            printf("Donner l'ID du parking: ");
                            scanf("%s", nouvelleres.parking.id_parking);
                            break;

                        case 3:
                            printf("Donner l'adresse du parking: ");
                            getchar(); // Consommer le caractère de retour à la ligne
                            fgets(nouvelleres.parking.adresse, sizeof(nouvelleres.parking.adresse), stdin);
                            nouvelleres.parking.adresse[strcspn(nouvelleres.parking.adresse, "\n")] = '\0';
                            break;

                        case 4:
                            printf("Donner le type de place (standart ou handicape): ");
                            scanf("%s", nouvelleres.place.type);
                            break;

                        case 5:
                            printf("Donnez la date de réservation (jj mm aaaa): ");
                            scanf("%d %d %d", &(nouvelleres.date_reservation.jour), &(nouvelleres.date_reservation.mois), &(nouvelleres.date_reservation.annee));
                            break;

                        case 6:
                            printf("Donnez l'heure de début (hh mm): ");
                            scanf("%d %d", &(nouvelleres.heure_debut.heure), &(nouvelleres.heure_debut.minute));
                            break;

                        case 7:
                            printf("Donnez l'heure de fin (hh mm): ");
                            scanf("%d %d", &(nouvelleres.heure_fin.heure), &(nouvelleres.heure_fin.minute));
                            break;
                        case 8:
                            printf("Donner le bloc (A, B, C): ");
                            scanf("%s", nouvelleres.place.bloc);
                            break;

                        case 9:
                            printf("Donner le type de véhicule (voiture, moto, camion): ");
                            scanf("%s", nouvelleres.vehicule.type);
                            break;

                        case 10:
                            printf("Donner la matricule de véhicule: ");
                            scanf("%s", nouvelleres.vehicule.matricule);
                            break;

                        case 11:
                            printf("Donner le type de service (lavage, maintenance, reservation simplifiee): ");
                            getchar(); // Consommer le caractère de retour à la ligne
                            fgets(nouvelleres.service.demande_service, sizeof(nouvelleres.service.demande_service), stdin);
                            nouvelleres.service.demande_service[strcspn(nouvelleres.service.demande_service, "\n")] = '\0';
                            break;

                        case 12:
                            printf("Donner le mode de paiement (en ligne, sur place): ");
                            getchar(); // Consommer le caractère de retour à la ligne
                            fgets(nouvelleres.service.paiement, sizeof(nouvelleres.service.paiement), stdin);
                            nouvelleres.service.paiement[strcspn(nouvelleres.service.paiement, "\n")] = '\0';
                            break;

                        case 0:
                            printf("Quitter\n");
                            break;
                    }
                } while (option != 0);

                modifier_reserv(filename, id, nouvelleres);
                break;


	


                 case 4: printf("affichage des reservations\n");
                           afficher_reserv(filename);
                           break;
                  case 5:  printf("\n  Affichage des places disponibles    \n");
                           lire_reservations("parking.txt",  TabParkings, n);
                           tri_TabParkings ( TabParkings,  n);
                            break;
                  case 6 : printf("\n======En souscrivant a un abonnement mensuel ou plus vous aurez droit a un service gratuit=========\n");
                          int a;

                      
                                printf("Veuillez choisir le type d abonnement\n");
                                printf("0:mensuel 1:trimestriel 2:Annuel\n");
                                scanf("%d",&offre.type_abonnement);
                                 printf("veuillez faire le choix de service entre: lavage/nMaintenance\nreservation simplifiee\n");
                                 getchar();
                                  fgets(offre.serv.demande_service, sizeof(offre.serv.demande_service), stdin);
                                  offre.serv.demande_service[strcspn(offre.serv.demande_service , "\n")] = '\0';
                                 printf("selectionnez le mode de paiement(en ligne ou sur place\n");
                                 getchar();
                                  fgets(offre.serv.paiement, sizeof(offre.serv.paiement), stdin);
                                  offre.serv.paiement[strcspn(offre.serv.paiement , "\n")] = '\0';
                                float b=calcul_tarif(offre);
                                 printf("tarif:%f",b);
                                 printf("confirmer:1 annuler:0\n");
                                 scanf("%d",&a);

                        
                         if(a==1){
                            int x=tache_supp(filename,offre);
                            if(x==1){
                                  printf("abonnement effectue avec succes");
                            }
                         }
                         break;


                  case 0: printf("merci");
                  break;
           
    }
           
 }while(choix!=0);









    return 0;



}







