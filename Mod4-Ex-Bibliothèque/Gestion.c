#include "Constante.h"
#include "Biblio.h"

Message ajouterLivre(Livre livre, ChainonLivre** pDebutLivres) {
	ChainonLivre* pLivre;
	ChainonLivre* pLivrePr�c;
	ChainonLivre* pNouvLivre;
	livreRecherche(livre, *pDebutLivres, &pLivre, &pLivrePr�c);
	if (pLivre != NULL && strcmp(livre.auteur, pLivre->livre.auteur) == 0 && livre.code == pLivre->livre.code)
		return LIVRE_EXISTANT;
	pNouvLivre = (ChainonLivre*)malloc(sizeof(*pNouvLivre));
	if (pNouvLivre == NULL)
		return ERREUR_MEMOIRE;
	pNouvLivre->livre = livre;
	pNouvLivre->pLivreSuiv = pLivre;
	if (pLivre == *pDebutLivres)
		*pDebutLivres = pNouvLivre;
	else
		pLivrePr�c->pLivreSuiv = pNouvLivre;
	return AJOUT_EFFECTUE;
}

void livreRecherche(Livre livre, ChainonLivre* pDebutLivres, ChainonLivre** pLivre, ChainonLivre** pLivrePrec) {
	*pLivre = pDebutLivres;
	while (*pLivre != NULL && strcmp(livre.auteur, (*pLivre)->livre.auteur) > 0) {
		(*pLivrePrec) = (*pLivre);
		(*pLivre) = (*pLivre)->pLivreSuiv;
	}

	while (*pLivre != NULL && strcmp(livre.auteur, (*pLivre)->livre.auteur) == 0 && livre.code > (*pLivre)->livre.code) {
		(*pLivrePrec) = (*pLivre);
		(*pLivre) = (*pLivre)->pLivreSuiv;
	}
}

Message supprimerLivre(Livre livreSupp, ChainonLivre** pD�butLivres) {
	ChainonLivre* pLivre;
	ChainonLivre* pLivrePr�c;
	livreRecherche(livreSupp, *pD�butLivres, &pLivre, &pLivrePr�c);
	if (pLivre == NULL || strcmp(livreSupp.auteur, pLivre->livre.auteur) != 0 || livreSupp.code != pLivre->livre.code)
		return LIVRE_INEXISTANT;
	if (pLivre == *pD�butLivres)
		*pD�butLivres = pLivre->pLivreSuiv;
	else
		pLivrePr�c->pLivreSuiv = pLivre->pLivreSuiv;
	free(pLivre);
	return SUPPRESSION_EFFECTUEE;
}

void libererListe(ChainonLivre** pD�butLivres) {
	ChainonLivre* pLivre;
	ChainonLivre* pLivreSauv�;
	pLivre = *pD�butLivres;
	while (pLivre != NULL) {
		pLivreSauv� = pLivre;
		pLivre = pLivre->pLivreSuiv;
		free(pLivreSauv�);
	}
	*pD�butLivres = NULL;
}