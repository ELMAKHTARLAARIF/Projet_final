#include <stdio.h>
#include <string.h>

#define MAX_PRODUITS 10

// ================= Structures ===================

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
	char nom[20];
	char category[50];
	float prix;
	int stock;
	char description[200];
} Prudact;

// catalogue produits
Prudact produits[MAX_PRODUITS];

// historique des achats
typedef struct {
	float   prix;
	int     clientid;
	char    clientnom[20];
	char    clientprenom[20];
	char    prudactnom[20];
	int     prudactid;
	char    prudactcategory[20];
	int     prudactstock;
	int     quantite;
} producthistory;

producthistory history[MAX_PRODUITS];
int acheter = 0;

// ================= Prototypes ===================
int menu1();
int menu2();
int menu3();
int Menu_principal();
void Ajoute_Cliente();
void Modification_Profil();
void Consultation_profil();
void Prudact_list();
void effectuerAchat();
void Afichage_montant();
void depot_argent();
void affichage_catalogue();
void recherche_produits();
void Affichage_info_produit();
void tri_produit();
void statistique();
int search_id(int id);
int vereficatin(char str[], char strpre[]);

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
				effectuerAchat();
				break;
			case 5:
				statistique();
				break;
			case 0:
				return 0;
			default:
				printf("Choix invalide.\n");
				break;
		}
	} while (1);
	return 0;
}

int menu1() 
{
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

		switch (choix) 
        {
			case 1:
				Ajoute_Cliente();
				break;
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

		switch (choix) 
        {
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
		printf("3-Tri des produits:\n");
		printf("4-Affichage info produit:\n");
		printf("5-Retour au menu principal:\n");
		printf("0-Quitter l'application:\n");
		printf("Entrer votre choix: ");
		scanf("%d", &choix);

		switch (choix) 
        {
			case 1:
				affichage_catalogue();
				break;
			case 2:
				recherche_produits();
				break;
			case 3:
				tri_produit();
				break;
			case 4:
				Affichage_info_produit();
				break;
			case 0:
				return 0;
			default:
				printf("Choix invalide.\n");
				break;
		}
	} while (1);
	return 0;
}

int vereficatin(char str[], char strpre[]) {
	int i = 0;
	while (str[i] != '\0') 
    {
		if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || str[i] == ' ')
			i++;
		else
			return -1;
	}
	i = 0;
	while (strpre[i] != '\0') 
    {
		if ((strpre[i] >= 'a' && strpre[i] <= 'z') || (strpre[i] >= 'A' && strpre[i] <= 'Z') || str[i] == ' ')
			i++;
		else
			return -1;
	}
	return 1;
}

void Ajoute_Cliente() 
{
	char str[20];
	char strpre[20];

	printf("ENTER YOUR NAME: ");
	scanf(" %[^\n]", str);
	printf("ENTER YOUR LAST NAME: ");
	scanf(" %[^\n]", strpre);

	if (vereficatin(str, strpre) == 1) 
        {
		strcpy(clientData.nom, str);
		strcpy(clientData.prenom, strpre);
	} else 
        {
		printf("Entrer nom et prenom avec alphabet seulement\n");
		Ajoute_Cliente();
	}

	clientData.idClient = 1;

	printf("Enter your solde: ");
	scanf("%f", &clientData.solde);
        
	sprintf(clientData.email, "%s.%s@gmail.com", clientData.nom, clientData.prenom);

	profil = 1;
	printf("Profil cree avec succes ! Email genere: %s\n", clientData.email);
}

void Modification_Profil() 
{
	if (profil == 1) 
        {
		printf("Choisissez un nouveau nom: ");
		scanf(" %[^\n]", clientData.nom);

		printf("Choisissez un nouveau prenom: ");
		scanf(" %[^\n]", clientData.prenom);

		printf("Nouveau solde: ");
		scanf("%f", &clientData.solde);

		sprintf(clientData.email, "%s.%s@gmail.com", clientData.nom, clientData.prenom);
	} else
	    printf("Vous n'avez pas de profil!\n");
}

void Consultation_profil() 
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

void Prudact_list() 
{
	produits[0] = (Prudact){1, "Laptop", "Electronics", 99, 3, "Portable computer with 16GB RAM"};
	produits[1] = (Prudact){2, "Phone", "Electronics", 100, 10, "Smartphone with OLED display"};
	produits[2] = (Prudact){3, "Shoes", "Fashion", 59.99, 5, "Comfortable running shoes"};
	produits[3] = (Prudact){4, "Book", "Education", 15.99, 20, "Programming in C guide"};
	produits[4] = (Prudact){5, "Watch", "Accessories", 120.00, 8, "Smartwatch with health tracking"};
	produits[5] = (Prudact){6, "Headset", "Electronics", 85.75, 12, "Wireless noise-canceling headset"};
	produits[6] = (Prudact){7, "Chair", "Furniture", 149.90, 15, "Ergonomic office chair"};
	produits[7] = (Prudact){8, "Backpack", "Fashion", 45.00, 60, "Durable waterproof backpack"};
	produits[8] = (Prudact){9, "Camera", "Electronics", 77.00, 8, "Mirrorless digital camera"};
	produits[9] = (Prudact){10, "Bottle", "Home", 12.50, 70, "Reusable stainless steel bottle"};
}

void affichage_catalogue() 
{
	for (int i = 0; i < MAX_PRODUITS; i++) 
    {
		printf("ID: %d | Nom: %s | Categorie: %s | Prix: %.2f Dh | Stock: %d | Description: %s\n",
		produits[i].idProduit,
		produits[i].nom,
		produits[i].category,
		produits[i].prix,
		produits[i].stock,
		produits[i].description);
	}
}

int search_id(int id) {
	for (int i = 0; i < MAX_PRODUITS; i++) 
    {
		if (produits[i].idProduit == id)
		    return i;
	}
	return -1;
}

void Affichage_info_produit() 
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
	       produits[i].idProduit,
	       produits[i].nom,
	       produits[i].category,
	       produits[i].prix,
	       produits[i].stock,
	       produits[i].description);
}

void Afichage_montant() 
{
	if (clientData.solde <= 0) 
		printf("Votre solde n'est pas suffisant!\n");
    else
		printf("Le montant disponible: %.2f\n", clientData.solde);
}

void depot_argent() 
{
	float montant;
	printf("Entrez le montant a deposer: ");
	scanf("%f", &montant);

	if (montant > 0) 
    {
	    clientData.solde += montant;
		printf("Depot reussi! Nouveau solde: %.2f Dh\n", clientData.solde);
	} else
		printf("Montant invalide!\n");
}

void recherche_produits() 
{
	int choix;
	char searchnom[50];

	printf("1-Rechercher par nom  2-Recherche par categorie\n");
	printf("Entrer votre choix: ");
	scanf("%d", &choix);

	printf("Recherche: ");
	scanf("%s", searchnom);

	int found = 0;
	for (int i = 0; i < MAX_PRODUITS; i++) 
    {
		if ((choix == 1 && strcmp(produits[i].nom, searchnom) == 0) ||
		    (choix == 2 && strcmp(produits[i].category, searchnom) == 0)) 
        {
			printf("ID: %d | Nom: %s | Categorie: %s | Prix: %.2f Dh | Stock: %d | Description: %s\n",
			produits[i].idProduit,
			produits[i].nom,
			produits[i].category,
			produits[i].prix,
			produits[i].stock,
			produits[i].description);
			found = 1;
		}
	}

	if (!found)
		printf("Aucun produit trouve.\n");
}

void effectuerAchat() {
	if (!profil) {
		printf("Creez un profil d'abord.\n");
		return;
	}

	int choix, quantite;
	float total;

	affichage_catalogue();
	printf("\nEntrez l'ID du produit a acheter: ");
	scanf("%d", &choix);

	int i = search_id(choix);
	if (i == -1) 
    {
		printf("Produit introuvable.\n");
		return;
	}
	if (produits[i].stock <= 0) 
    {
		printf("Produit en rupture de stock.\n");
		return;
	}

	printf("Quantite a acheter: ");
	scanf("%d", &quantite);

	if (quantite <= 0) 
    {
		printf("Quantite invalide.\n");
		return;
	}
	if (quantite > produits[i].stock) 
    {
	    printf("Stock insuffisant. Disponible: %d\n", produits[i].stock);
		return;
	}
	total = produits[i].prix * quantite;
	if (clientData.solde < total) 
    {
		printf("Solde insuffisant. Rechargez votre compte.\n");
		return;
	}

	clientData.solde -= total;
	produits[i].stock -= quantite;

	history[acheter].clientid = clientData.idClient;
	strcpy(history[acheter].clientnom, clientData.nom);
	strcpy(history[acheter].clientprenom, clientData.prenom);
	strcpy(history[acheter].prudactnom, produits[i].nom);
	history[acheter].prudactid = produits[i].idProduit;
	strcpy(history[acheter].prudactcategory, produits[i].category);
	history[acheter].prudactstock = produits[i].stock;
	history[acheter].quantite = quantite;
	history[acheter].prix = total;

	acheter++;

	printf("Achat reussi: %s x%d (%.2f Dh) | Nouveau solde: %.2f Dh\n",
	       produits[i].nom, quantite, total, clientData.solde);
}

void tri_produit() {
	int choix;
	printf("1 - Tri par prix (croissant)\n");
	printf("2 - Tri par prix (decroissant)\n");
	printf("3 - Tri par nom (alphabetique)\n");
	printf("Entrez votre choix: ");
	scanf("%d", &choix);

	for (int i = 0; i < MAX_PRODUITS - 1; i++) 
    {
		for (int j = 0; j < MAX_PRODUITS - i - 1; j++) 
        {
			int condition = 0;
			if (choix == 1 && produits[j].prix > produits[j + 1].prix)
				condition = 1;
			if (choix == 2 && produits[j].prix < produits[j + 1].prix)
				condition = 1;
			if (choix == 3 && strcmp(produits[j].nom, produits[j + 1].nom) > 0)
				condition = 1;

			if (condition == 1) {
				Prudact temp = produits[j];
				produits[j] = produits[j + 1];
				produits[j + 1] = temp;
			}
		}
	}
	printf("\n--- Liste des produits ---\n");
	for (int i = 0; i < MAX_PRODUITS; i++) 
    {
		printf("%s - %.2f\n", produits[i].nom, produits[i].prix);
	}
}

void statistique() 
{
	if (!acheter) 
    {
		printf("Personne n'a encore achete\n");
		return;
	}
	float totalGeneral = 0.0;
	for (int i = 0; i < acheter; i++) 
    {
		printf("Produit achete: %d | Nom: %s | Categorie: %s | Prix total: %.2f Dh | Quantite: %d | Stock restant: %d\n",
	    history[i].prudactid,
		history[i].prudactnom,
		history[i].prudactcategory,
		history[i].prix,
		history[i].quantite,
		history[i].prudactstock);

		printf("  -> Client: %s %s\n", history[i].clientnom, history[i].clientprenom);

		totalGeneral += history[i].prix;
	}
    printf("\n=== Resume Statistique ===\n");
    printf("Nombre total d'achats : %d\n", acheter);
    printf("Montant total depense : %.2f Dh\n", totalGeneral);
}
int main() 
{
        Prudact_list();
        Menu_principal();
	    return 0;
}
