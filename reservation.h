  #ifndef RESERVATION_H
#define RESERVATION_H

typedef struct {
    char type[20];
    char  bloc[5];
    int places_disponibles;
}Place;



 typedef struct{
      char nom[50];
      char id_parking[10];
      char adresse[100];
       Place place ;
       float tarif;

      }Parking;


 typedef struct {
     char type[10];
    char matricule[10];
 }Vehicule;
 typedef struct{
    char paiement[50];
    char demande_service[50];
 } Service;
 typedef struct {
    int jour;
    int mois;
    int annee;
} Date;
typedef struct {
   Service serv;
   int type_abonnement;
   Date date_abonmt;
   Parking p;
}Offre;

typedef struct {
    int heure;
    int minute;
} Heure;
typedef struct{
    char id_reservation[10];
     Parking parking;
    Place place;
    Date date_reservation;
    Heure heure_debut;
    Heure heure_fin;
    Vehicule vehicule;
    Service service;
    Offre offre;
} Reservation;

int ajouter_reserv(char *filename , Reservation res);
void modifier_reserv(char *filename, char *id , Reservation nouvelleres );
void supprimer_reserv(char *filename, char *id );
void afficher_reserv(char *filename);
void tri_TabParkings (Parking TabParkings[], int n);
void lire_reservations(const char* nom_fichier, Parking TabParkings[], int n);
float calcul_tarif(Offre offre);
int tache_supp(char *filename,Offre offre);
 #endif


	

