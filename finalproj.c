#include <stdio.h>
#include <string.h>
#define MAX_PRODUITS 10

typedef struct {
	int idClient;
	char nom[50];
	char prenom[50];
	char email[100];
	float solde;
} client;
client clientData;
int profil = 0;

typedef struct {
	int idProduit;
	char nom[50];
	char category[50];
	float prix;
	int stock;
	char description[200];
} Prudact;
Prudact PrudactData[MAX_PRODUITS];

int menu1();
int menu2();
int menu3();
void Ajoute_Cliente();
void Modification_Profil();
void Consultation_profil();
void Prudact_list();
int Menu_principal();
void effectuerAchat();
void Afichage_montant();
void depot_argent();
void affichage_catalogue();
void recherche_produits();
void Affichage_info_produit();
int search_id(int id);
int Menu_principal() {
	do {
		int choix;
		printf("------------------Menu Principal-------------------\n");
		printf("1-Gestion du profil client:\n");
		printf("2-Gestion du solde virtuel:\n");
		printf("3-Consultation des produits:\n");
		printf("4-Effectuer un achat:\n");
		printf("5-Mes statistiques:\n");
		printf("0-Quitter l'application:\n");
		printf("Entrer votre choix: ");
		scanf("%d", &choix);

		switch (choix) 
                {
			case 1: 
                                menu1(); 
                                break;
			case 2: 
                                menu2(); 
                                break;
			case 3: 
                                menu3(); 
                                break;
			case 4: 
                                effectuerAchat(); break;
			case 0: 
                                return 0;
			default: 
                                printf("Choix invalide.\n"); 
                                break;
		}
	} while (1);
	return 0;
}

int menu1() {
	do {
		int choix;
		printf("------------------Gestion du Profil Client-------------------\n");
		printf("1-Creation de profil:\n");
		printf("2-Modification du profil:\n");
		printf("3-Consultation du profil:\n");
		printf("4-Retour au menu principal:\n");
		printf("0-Quitter l'application:\n");
		printf("Entrer votre choix: ");
		scanf("%d", &choix);

		switch (choix) {
			case 1: 
                                Ajoute_Cliente(); break;
			case 2: 
                                Modification_Profil(); 
                                break;
			case 3: 
                                Consultation_profil(); 
                                break;
			case 4: 
                                return 0;
			case 0: 
                                return 0;
			default: 
                                printf("Choix invalide.\n"); 
                                break;
		}
	} while (1);
}

int menu2() 
{
	do {
		int choix;
		printf("------------------Gestion du Solde Virtuel-------------------\n");
		printf("1-Affichage du montant disponible:\n");
		printf("2-Alimentation du solde virtuel:\n");
		printf("3-Contrôle du solde:\n");
		printf("4-Retour au menu principal:\n");
		printf("0-Quitter l'application:\n");
		printf("Entrer votre choix: ");
		scanf("%d", &choix);

		switch (choix) {
			case 1: 
                                Afichage_montant(); 
                                break;
			case 2: 
                                depot_argent(); 
                                break;
			case 3: 
                                Afichage_montant(); 
                                break;
			case 4: 
                                return 0;
			case 0: 
                                return 0;
			default: 
                                printf("Choix invalide.\n"); 
                                break;
		}
	} while (1);
	return 0;
}

int menu3() 
{
	do {
		int choix;
		printf("------------------Catalogue des Produits-------------------\n");
		printf("1-Affichage catalogue:\n");
		printf("2-Recherche produits:\n");
		printf("3-Affichage info produit:\n");
		printf("4-Retour au menu principal:\n");
		printf("0-Quitter l'application:\n");
		printf("Entrer votre choix: ");
		scanf("%d", &choix);

		switch (choix) {
			case 1: 
                                affichage_catalogue(); 
                                break;
			case 2:
                                recherche_produits(); 
                                break;
			case 3:         
                                Affichage_info_produit(); 
                                break;
			case 4: 
                                return 0;
			case 0: 
                                return 0;
			default: 
                                printf("Choix invalide.\n"); 
                                break;
		}
	} while (1);
	return 0;
}

void Ajoute_Cliente() 
{
	printf("ENTER YOUR NAME: ");
	scanf(" %[^\n]", clientData.nom);

	printf("ENTER YOUR LAST NAME: ");
	scanf(" %[^\n]", clientData.prenom);

	clientData.idClient = 1;

	printf("enter your solde: ");
	scanf("%f", &clientData.solde);

	sprintf(clientData.email, "%s.%s@gmail.com", clientData.nom, clientData.prenom);

	profil = 1;
	printf("Profil cree avec succes ! Email genere: %s\n", clientData.email);
}

void    Modification_Profil() 
{
	if (profil == 1) 
        {
		printf("Choisissez un nouveau nom: ");
		scanf(" %[^\n]", clientData.nom);

		printf("Choisissez un nouveau prenom: ");
		scanf(" %[^\n]", clientData.prenom);

		printf(" nouveau solde: ");
		scanf("%f", &clientData.solde);

		sprintf(clientData.email, "%s.%s@gmail.com", clientData.nom, clientData.prenom);
	} 
        else 
        {
		printf("Vous n'avez pas de profil!\n");
	}
}

void    Consultation_profil() 
{
	if (!profil) 
        {
		printf("Creez un profil d'abord.\n");
		return;
	}
	printf("ID: %d | Nom: %s | Prenom: %s | Solde: %.2f Dh | Email: %s\n",
	       clientData.idClient,
	       clientData.nom,
	       clientData.prenom,
	       clientData.solde,
	       clientData.email);
}

void    Prudact_list() 
{
	PrudactData[0] = (Prudact){1, "Laptop", "Electronics", 999, 10, "Portable computer with 16GB RAM"};
	PrudactData[1] = (Prudact){2, "Phone", "Electronics", 99.49, 25, "Smartphone with OLED display"};
	PrudactData[2] = (Prudact){3, "Shoes", "Fashion", 59.99, 50, "Comfortable running shoes"};
	PrudactData[3] = (Prudact){4, "Book", "Education", 15.99, 100, "Programming in C guide"};
	PrudactData[4] = (Prudact){5, "Watch", "Accessories", 120.00, 30, "Smartwatch with health tracking"};
	PrudactData[5] = (Prudact){6, "Headset", "Electronics", 85.75, 40, "Wireless noise-canceling headset"};
	PrudactData[6] = (Prudact){7, "Chair", "Furniture", 149.90, 15, "Ergonomic office chair"};
	PrudactData[7] = (Prudact){8, "Backpack", "Fashion", 45.00, 60, "Durable waterproof backpack"};
	PrudactData[8] = (Prudact){9, "Camera", "Electronics", 499.00, 8, "Mirrorless digital camera"};
	PrudactData[9] = (Prudact){10, "Bottle", "Home", 12.50, 70, "Reusable stainless steel bottle"};
}

void    affichage_catalogue() 
{
	for (int i = 0; i < MAX_PRODUITS; i++) 
        {
		printf("ID: %d | Nom: %s | Categorie: %s | Prix: %.2f Dh | Stock: %d | Description: %s\n",
		PrudactData[i].idProduit,
		PrudactData[i].nom,
		PrudactData[i].category,
		PrudactData[i].prix,
		PrudactData[i].stock,
		PrudactData[i].description);
	}
}

void    recherche_produits() 
{
	int choix;
	char searchnom[50];

	printf("1-Rechercher par nom  2-Recherche par categorie  ");
        printf("entrer vote choix :");
        scanf("%d",&choix);
	printf("Recherche: ");
	scanf("%s", searchnom);

	int found = 0;
	for (int i = 0; i < MAX_PRODUITS; i++) 
        {
		if ((choix == 1 && strcmp(PrudactData[i].nom, searchnom) == 0) ||
		    (choix == 2 && strcmp(PrudactData[i].category, searchnom) == 0)) 
                {
		        printf("ID: %d | Nom: %s | Categorie: %s | Prix: %.2f Dh | Stock: %d | Description: %s\n",
		        PrudactData[i].idProduit,
			PrudactData[i].nom,
			PrudactData[i].category,
			PrudactData[i].prix,
			PrudactData[i].stock,
			PrudactData[i].description);
			found = 1;
		}
	}
	if (!found) 
        {
		printf("Aucun produit trouve.\n");
	}
}
int search_id(int id) 
{
        int    found = 0;
	for (int i = 0; i < MAX_PRODUITS; i++)
        { 
		if (PrudactData[i].idProduit == id)
                {
                        return i;
                        found = 1;
                }
        }
        if (found == 0)
                return -1;
}
void    Affichage_info_produit() 
{
	int id;
	printf("Entrer ID du produit: ");
	scanf("%d", &id);

	int i = search_id(id);
	if (i == -1) 
        {
		printf("Aucun produit avec cet ID!\n");
		return;
	}
	printf("ID: %d | Nom: %s | Categorie: %s | Prix: %.2f Dh | Stock: %d | Description: %s\n",
	PrudactData[i].idProduit,
        PrudactData[i].nom,
        PrudactData[i].category,
	PrudactData[i].prix,
	PrudactData[i].stock,
	PrudactData[i].description);
}
void Afichage_montant()        
{
	if (clientData.solde <= 0) {
		printf("Votre solde n'est pas suffisant pour acheter!\n");
	} else {
		printf("Le montant disponible: %.2f\n", clientData.solde);
	}
}

void    depot_argent() 
{
	float montant;
	printf("Entrez le montant e deposer: ");
	scanf("%f", &montant);

	if (montant > 0) {
		clientData.solde += montant;
		printf("Depot reussi! Nouveau solde: %.2f Dh\n", clientData.solde);
	} else {
		printf("Montant invalide!\n");
	}
}

void    effectuerAchat() 
{
	if (!profil) 
        {
		printf("Creez un profil d'abord.\n");
		return;
	}
	int choix;
	affichage_catalogue();
	printf("\nEntrez l'ID du produit a acheter: ");
	scanf("%d", &choix);

	int i = search_id(choix);
	if (i == -1) {
		printf("Produit introuvable.\n");
		return;
	}

	if (PrudactData[i].stock <= 0) {
		printf("Produit en rupture de stock.\n");
		return;
	}
	if (clientData.solde < PrudactData[i].prix) {
		printf("Solde insuffisant. Rechargez votre compte.\n");
		return;
	}

	clientData.solde -= PrudactData[i].prix;
	PrudactData[i].stock--;
	printf("Achat reussi: %s (%.2f Dh) | Nouveau solde: %.2f Dh\n",
	       PrudactData[i].nom, PrudactData[i].prix, clientData.solde);
}

int main() {
	Prudact_list();
	Menu_principal();
	return 0;
}
