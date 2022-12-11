#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "sujet1.h"
#define TAILLE_MAX 1000



void permuter(Logement *a, Logement *b){//permute 2 structures
	Logement tmp;
	tmp=*a;
	*a=*b;
	*b=tmp;}
	
void trirapid(Logement tab[M], int first, int last){ //algo de tri rapide
	int pivot, i, j;
	if(first<last){
		pivot=first;
		i=first;
		j=last;
		while(i<j){
			while(tab[i].distance<=tab[pivot].distance && i<last){
				i++;}
			while(tab[j].distance >tab[pivot].distance){
				j--;}
			if (i<j){
				permuter(&tab[i],&tab[j]);}
				
			}
			permuter(&tab[pivot], &tab[j]);
			trirapid(tab,first,j-1);
			trirapid(tab, j+1, last);
		}
		
	}

int main(void){ 
	FILE* fichier=NULL; //crée le pointeur fichier
	char chaine[TAILLE_MAX] =""; //chaine contient les lignes du fichier csv
	int distance_2; //variable qui prend pour valeur les distances au carré
	
	fichier = fopen("airbnb_donnees_propre.csv", "r");  //fichier devient pointeur sur le .csv
	if (fichier != NULL) //vérifie que le fichier est ouvert
	{
		Logement tab[M]; //crée un tableau de structures
		float x[3]={1,1,1}; //on initialise arbitrairement x
		
		int compteur=0;  //compte le nombre de ligne
		while(fgets(chaine, TAILLE_MAX, fichier) != NULL)//lire tout le doc
		{	
			fscanf(fichier, "%f,%f,%f,%f,%f,%f,%f,%f,%f", &tab[compteur].id, &tab[compteur].accommodates, &tab[compteur].bedrooms, &tab[compteur].bathrooms, &tab[compteur].beds, &tab[compteur].price, &tab[compteur].minimum_nights, &tab[compteur].maximum_nights, &tab[compteur].number_of_review); // remplit le tableau structure par structure
			//printf("%f,%f,%f,%f,%f,%f,%f,%f,%f!!\n", tab[compteur].id, tab[compteur].accommodates, tab[compteur].bedrooms, tab[compteur].bathrooms, tab[compteur].beds, tab[compteur].price, tab[compteur].minimum_nights, tab[compteur].maximum_nights, tab[compteur].number_of_review); 
			//permet de vérifier que le tableau est rempli
			
			distance_2 += powf(x[0]-tab[compteur].accommodates,2) + powf(x[1]-tab[compteur].bedrooms,2) +powf(x[2]-tab[compteur].beds,2); //calcule la distance au carré de x par rapport à y
			
			tab[compteur].distance=sqrt(distance_2); //remplit le champ distance de la structure
			
			distance_2=0; //initialise pour la suite de la boucle
			compteur+=1;
			
		}
		
		int i,j;
		Logement tmp;
		for (i=0; i<M; i++){//boucle qui randomise
			j=rand() % M;
			tmp=tab[i];
			tab[i]=tab[j];
			tab[j]=tmp;
			}
		/*compteur=0;
		printf("%f\n", tab[compteur].id);
		compteur=1;
		printf("%f\n", tab[compteur].id);*/
		//vérifie que les deux premières valeurs ont été randomisées
		trirapid(tab, 0,M-1);
		//printf("%f %f %f %f %f %f", tab[5].distance, tab[100].distance, tab[1000].distance, tab[3000].distance, tab[5000].distance, tab[7000].distance);
		//vérifie que le tableau semble trié
		float somme_prix=0.0;
		int k=1000; //choisis arbitrairement, correspond aux k logements sélectionnés
		for (int i=0; i<k; i++){
			somme_prix +=tab[i].price;}
		float prix_moy= somme_prix/k;
		printf("Pour un logement x de %f personne(s), %f chambre(s), %f lits, le prix moyen des k=%d plus proches logements est de %f euros", x[0],x[1],x[2],k,prix_moy);
		
		

		
		fclose(fichier);
		
	}
	else
	{
		printf("erreur fichier");
	}   //affiche erreur si le pointeur pointe vers NULL
	
	
	return 0;
}
