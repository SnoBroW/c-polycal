#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#include "structs.h"
#include "calculs.h"
#include "io.h"



Polynome * poly;
Polynome * polyList[128];


unsigned int currentId = 0;

void poly_init(Polynome ** _poly, double coef, int degre)
{
	*_poly = malloc(sizeof(Polynome));

	if(*_poly == NULL)
	{
		exit(0);
	}

	else
	{
		(*_poly)->monomes = malloc((degre + 1) * sizeof(Monome));

		if(*_poly == NULL)
		{
			exit(0);
		}

		else
		{
			for(int i = 0; i <= degre; i++)
			{
				(*_poly)->monomes[i].coef = coef;
				(*_poly)->monomes[i].degre = degre - i;
			}
			(*_poly)->degre = degre;
		}
	}
}

void poly_free(Polynome ** _poly)
{
	free((*_poly)->monomes);
	free(*_poly);
}

void poly_free_all()
{
	if(polyList != NULL)
	{
		for(int i = 0; i < currentId; i++)
		{
			poly_free(&polyList[i]);
		}
	}
}

unsigned int poly_create(double coef, int degre)
{
	poly_init(&poly, coef, degre);
	polyList[currentId] = poly;
	return currentId++;
}

void poly_delete(unsigned int id)
{
	if(polyList[id] != NULL && id < currentId)
	{
		free(polyList[id]);
		polyList[id] = NULL;
		printf("\n\nPolynôme supprimé avec succès\n\n");
	}
	else
	{
		printf("\n\nErreur, ce polynôme n'existe pas\n\n");
	}
}

unsigned int poly_create_from_stream()
{
	int degre = lireDegreFromStream();
	unsigned int id = poly_create(0, degre);
	lireStream(&polyList[id]);
	return id;
}

void poly_write_to_stream(unsigned int id)
{
	ecrireStream(polyList[id]);
}

unsigned int poly_create_from_file()
{
	FILE * fp = ouvrirFichier("r");
	int degre = lireDegreFromFichier(fp);
	if(degre != 999)
	{
		unsigned int id = poly_create(0, degre);
		lireFichier(&polyList[id], fp);
		fclose(fp);
		return id;
	}
	else
	{
		printf("\n\nErreur, polynôme invalide\n\n");
		fclose(fp);
	}
}

void poly_write_to_file(unsigned int id)
{
	FILE * fp = ouvrirFichier("a");
	ecrireFichier(polyList[id], fp);
	fclose(fp);
}

unsigned int poly_create_from_default()
{
	unsigned int id = poly_create(0, defaultDegre());
	defaultPoly(&polyList[id]);
	poly_write_to_stream(id);
	return id;
}

bool checkPoly(unsigned int id1, unsigned int id2)
{
	if(polyList[id1] != NULL && polyList[id2] != NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

unsigned int poly_create_from_sum(unsigned int id1, unsigned int id2)
{
	unsigned int result = poly_create(0, getMaxDegre(polyList[id1], polyList[id2]));
	somme(polyList[id1], polyList[id2], polyList[result]);
	return result;
}

double poly_create_from_image(unsigned int id, double x)
{
	return image(polyList[id], x);
}

