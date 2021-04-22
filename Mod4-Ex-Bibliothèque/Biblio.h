
#ifndef BIBLIO_H
#define BIBLIO_H
#include "Constante.h"

typedef struct livre Livre;
struct livre {
	char auteur[T_AUTEUR];
	int code;
	char titre[T_TITRE];
};

typedef struct chainonLivre ChainonLivre;
struct chainonLivre {
	Livre livre;
	ChainonLivre* pLivreSuiv;
};

void fonctionnalites(void);
Menu choixMenu(void);
void afficherLivres(ChainonLivre* pDebutLivres);
Livre livreLu(void);
Message ajouterLivre(Livre livre, ChainonLivre** pDebutLivres);
void livreRecherche(Livre livre, ChainonLivre* pDebutLivres, ChainonLivre** pLivre, ChainonLivre** pLivrePrec);
Message supprimerLivre(Livre livreSupp, ChainonLivre** pDebutLivres);
void libererListe(ChainonLivre** pDebutLivres);
Message sauvegarderLivres(ChainonLivre* pDebutLivres);
Message chargerFichier(ChainonLivre** pDebutLivres);
void afficherMessage(Message message);
#endif