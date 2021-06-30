#ifndef IO_H
#define IO_H

bool checkEntier(double coef)
{
    int i = (int)coef;
    return (coef == i);
}

int lireDegreFromStream()
{
	int degre;

	printf("\nEntrez le degré du polynôme : ");
	scanf(" %d", &degre);

	return degre;
}

void lireStream(Polynome ** poly)
{
	double coef;
	int degre = (*poly)->degre;

	for(int i = degre; i > 0; i--)
	{
		printf("\nEntrez le coefficient du monome de degré %d : ", i);
		scanf(" %lf", &coef);
		fflush(stdin);

		(*poly)->monomes[degre - i].coef = coef;

	}
	printf("\nEntrez l'ordonnée à l'origine : ");
	scanf(" %lf", &coef);
	fflush(stdin);

	(*poly)->monomes[degre].coef = coef;

	printf("\n");
}

FILE * ouvrirFichier(char * option)
{
	FILE * fp;

	char nom[128];

	printf("\n\nEntrez le nom du fichier à ouvrir : ");
	scanf(" %s", &nom);
	fflush(stdin);

	if(strcmp(option, "r") == 0)
	{
		fp = fopen(nom, "r");
	}
	else if(strcmp(option, "a") == 0)
	{
		fp = fopen(nom, "a");
	}

	if(fp == NULL)
	{
		printf("\n\nErreur lors de la lecture du fichier\n\n");
	}
	else
	{
		return fp;
	}
}

int lireDegreFromFichier(FILE * fp)
{
	int checkFormat = 0, nb_monomes = 0, nb_part = 0;
	char line[256], *token, plus= '+', moins = '-', delim[] = " ";
	bool valid = true;


	if(fp == NULL)
	{
		printf("");
	}
	else
	{
		fgets(line, 256, fp);

		token = strtok(line, delim);

		while(token != NULL)
		{
			nb_part++;

			if(*token == plus || *token == moins)
			{
				checkFormat++;
			}
			else
			{
				checkFormat--;
				nb_monomes++;
			}

			if(checkFormat > 1 || checkFormat < -1)
			{
				valid = false;
				break;
			}

			token = strtok(NULL, delim);
		}


		if(valid)
		{
			return (nb_monomes - 1);
		}
		else
		{
			return -999;
		}

	}	
}

void lireFichier(Polynome ** poly, FILE * fp)
{

	int nb_monomes = 0, nb_signes = 0, nb_part = 0, checkFormat = 0, coef = 1, degre = 0;
	char line[256], *token1, *token2, *monomes[16], *signes[2], *temp, *temp2;
	char delim[] = " ", plus = '+', moins = '-', x[] = "X";
	bool valid = true;


	if(fp == NULL)
	{
		printf("");
	}
	else
	{
		fgets(line, 256, fp);

		token1 = strtok(line, delim);

		while(token1 != NULL)
		{
			nb_part++;

			if(*token1 == plus || *token1 == moins)
			{
				signes[nb_part] = token1;
				checkFormat++;
				nb_signes++;
			}
			else
			{
				monomes[nb_part] = token1;
				checkFormat--;
				nb_monomes++;
			}

			if(checkFormat > 1 || checkFormat < -1)
			{
				valid = false;
				break;
			}


			token1 = strtok(NULL, delim);
		}

		printf("\n\n");

		if(valid)
		{
			if(nb_signes == nb_monomes)
			{
				int compteur = 1;
				for (int i = 1; i <= nb_part; i++)
				{
					if(compteur == 1)
					{
						printf("%s ", signes[i]);
						compteur++;

						strcpy(temp, monomes[i + 1]);

						token2 = strtok(temp, x);
						
						char * ptr;
						int split = 0;

						while(token2 != NULL)
						{
							temp2 = token2;
							if(split == 0)
							{
								coef = (double)strtol(temp2, &ptr, 10);
							}
							else if(split == 1)
							{
								degre = (int)strtol(temp2, &ptr, 10);
							}

							token2 = strtok(NULL, x);
						}

						if(strcmp(signes[i], "-") == 0)
						{
							(*poly)->monomes[degre - i].coef = (-1 * coef);
						}
						else
						{
							(*poly)->monomes[degre - i].coef = coef;
						}
					}

					else
					{
						printf("%s ", monomes[i]);
						compteur--;
					}
				}
			}
			else if(nb_signes == (nb_monomes - 1))
			{
				int compteur = 1;
				for (int i = 1; i <= nb_part; i++)
				{
					if(compteur == 1)
					{
						printf("%s ", monomes[i]);
						compteur++;
					}
					else
					{
						printf("%s ", signes[i]);
						compteur--;

						strcpy(temp, monomes[i + 1]);

						if(strcmp(signes[i], "-") == 0)
						{
							token2 = strtok(temp, x);

							char * ptr;
							int split = 0;

							while(token2 != NULL)
							{
								temp2 = token2;
								if(split == 0)
								{
									coef = (double)strtol(temp2, &ptr, 10);
								}
								else if(split == 1)
								{
									degre = (int)strtol(temp2, &ptr, 10);
								}

								token2 = strtok(NULL, x);
							}

							if(strcmp(signes[i], "-") == 0)
							{
								(*poly)->monomes[degre - i].coef = (-1 * coef);
							}
							else
							{
								(*poly)->monomes[degre - i].coef = coef;
							}

						}
					}
				}
			}
			else
			{
				printf("Erreur, le polynôme n'est pas valide");
			}
		}
		else
		{
			printf("Erreur, le polynôme n'est pas valide");
		}
	}
}

void ecrireStream(Polynome * poly)
{
	printf("\n");

	if(poly->monomes[0].coef < 0)
	{
		printf("- ");
	}

	for(int i = 0; i <= poly->degre; i++)
	{
		if(poly->monomes[i].coef != 0)
		{
			if(i != 0 && poly->monomes[i].coef < 0)
			{	
				printf("- ");
			}
			else if(i != 0)
			{
				printf("+ ");			
			}

			switch(poly->monomes[i].degre)
			{
				case 0:
					if(checkEntier(poly->monomes[i].coef))
					{
						printf("%d ", abs((int)poly->monomes[i].coef));
					}
					else
					{
						printf("%0.2f ", abs(poly->monomes[i].coef));						
					}
					break;

				case 1:
					if(checkEntier(poly->monomes[i].coef))
					{
						printf("%dX ", abs((int)poly->monomes[i].coef));
					}
					else
					{
						printf("%0.2fX ", abs(poly->monomes[i].coef));
					}
					break;

				default:
					if(checkEntier(poly->monomes[i].coef))
					{
						printf("%dX%d ", abs((int)poly->monomes[i].coef), poly->monomes[i].degre);
					}
					else
					{
						printf("%0.2fX%d ", abs(poly->monomes[i].coef), poly->monomes[i].degre);
					}
			}			
		}
	}
	printf("\n\n");
}

void ecrireFichier(Polynome * poly, FILE * fp)
{
	fprintf(fp, "\n");

	if(poly->monomes[0].coef < 0)
	{
		fprintf(fp, "- ");
	}

	for(int i = 0; i <= poly->degre; i++)
	{
		if(poly->monomes[i].coef != 0)
		{
			if(i != 0 && poly->monomes[i].coef < 0)
			{	
				fprintf(fp, "- ");
			}
			else if(i != 0)
			{
				fprintf(fp, "+ ");			
			}

			switch(poly->monomes[i].degre)
			{
				case 0:
					if(checkEntier(poly->monomes[i].coef))
					{
						fprintf(fp, "%d ", abs((int)poly->monomes[i].coef));
					}
					else
					{
						fprintf(fp, "%0.2f ", abs(poly->monomes[i].coef));						
					}
					break;

				case 1:
					if(checkEntier(poly->monomes[i].coef))
					{
						fprintf(fp, "%dX ", abs((int)poly->monomes[i].coef));
					}
					else
					{
						fprintf(fp, "%0.2fX ", abs(poly->monomes[i].coef));
					}
					break;

				default:
					if(checkEntier(poly->monomes[i].coef))
					{
						fprintf(fp, "%dX%d ", abs((int)poly->monomes[i].coef), poly->monomes[i].degre);
					}
					else
					{
						fprintf(fp, "%0.2fX%d ", abs(poly->monomes[i].coef), poly->monomes[i].degre);
					}
			}			
		}
	}
}


/////// POLYNOME PAR DEFAUT ///////

int defaultDegre()
{
	return 2;	
}

unsigned int defaultPoly(Polynome ** poly)
{	

	(*poly)->monomes[0].coef = 1;
	(*poly)->monomes[1].coef = 2;
	(*poly)->monomes[2].coef = 1;

}

///////////////////////////////////





#endif