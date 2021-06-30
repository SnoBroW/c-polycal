#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "menuassets.h"

unsigned int poly_create_from_stream();
unsigned int poly_create_from_file();
unsigned int poly_create_from_default();

void poly_write_to_stream(unsigned int id);
void poly_write_to_file(unsigned int id);
void poly_free_all();
void lireFichier();
void checkPoly(unsigned int id1, unsigned int id2);

unsigned int poly_create_from_sum(unsigned int id1, unsigned int id2);
double poly_create_from_image(unsigned int id, double x);

unsigned int id1 = -1;
unsigned int id2 = -1;

unsigned int resultId = -1;


void menu()
{
	long int choice = 0;

	drawBanner();

	while(choice != 9)
	{
		double x = 0;

		drawSeparator();
		drawChoices(0);
		choice = getOption();

		switch(choice)
		{
			case 0:
				break;

			case 1:
				drawSeparator();
				drawChoices(1);
				choice = getOption();

				switch(choice)
				{
					case 1:
						drawSeparator();
						drawChoices(11);
						choice = getOption();

						switch(choice)
						{
							case 1:
								drawSeparator();
								id1 = poly_create_from_stream();
								poly_write_to_stream(id1);
								break;

							case 2:
								drawSeparator();
								id2 = poly_create_from_stream();
								poly_write_to_stream(id2);
								break;

							case 9:
								choice = 0;
								break;

							default:
								drawSeparator();
								printf("\n\nOption non reconnue\n\n");
								choice = 0;
								break;
						}
						break;

					case 2:
						drawSeparator();
						drawChoices(12);
						choice = getOption();

						switch(choice)
						{
							case 1:
								drawSeparator();
								id1 = poly_create_from_file();

								break;

							case 2:
								drawSeparator();
								id2 = poly_create_from_file();

								break;

							case 9:
								choice = 0;
								break;

							default:
								drawSeparator();
								printf("\n\nOption non reconnue\n\n");
								choice = 0;
								break;

						}
						break;

					case 3:
						drawSeparator();
						drawChoices(11);

						choice = getOption();

						switch(choice)
						{
							case 1:
								drawSeparator();
								id1 = poly_create_from_default();

								break;

							case 2:
								drawSeparator();
								id2 = poly_create_from_default();

								break;

							case 9:
								choice = 0;
								break;

							default:
								drawSeparator();
								printf("\n\nOption non reconnue\n\n");
								choice = 0;
								break;
						}

						break;

					case 9:
						choice = 0;
						break;

					default:
						drawSeparator();
						printf("\n\nOption non reconnue\n\n");
						choice = 0;
						break;
				}

				break;

			case 2:
				drawSeparator();
				drawChoices(2);

				choice = getOption();

				switch(choice)
				{
					case 1:
						drawSeparator();
						drawChoices(20);

						choice = getOption();

						switch(choice)
						{
							case 1:
								if(id1 != -1)
								{
									drawSeparator();
									poly_write_to_stream(id1);
								}
								else
								{
									drawSeparator();
									printf("\n\nErreur, pas de polynôme entré\n\n");
								}
								break;

							case 2:
								if(id2 != -1)
								{
									drawSeparator();
									poly_write_to_stream(id2);
								}
								else
								{
									drawSeparator();
									printf("\n\nErreur, pas de polynôme entré\n\n");
								}
								break;

							case 3:
								if(id2 != -1)
								{
									drawSeparator();
									poly_write_to_stream(resultId);
								}
								else
								{
									drawSeparator();
									printf("\n\nErreur, pas de polynôme entré\n\n");
								}
								break;


							case 9:
								choice = 0;
								break;

							default:
								drawSeparator();
								printf("\n\nOption non reconnue\n\n");
								choice = 0;
								break;
						}

						break;

					case 2:
						drawSeparator();
						drawChoices(20);

						choice = getOption();

						switch(choice)
						{
							case 1:
								if(id1 != -1)
								{
									drawSeparator();
									poly_write_to_file(id1);
								}
								else
								{
									drawSeparator();
									printf("\n\nErreur, pas de polynôme entré\n\n");
								}
								break;

							case 2:
								if(id2 != -1)
								{
									drawSeparator();
									poly_write_to_file(id2);
								}
								else
								{
									drawSeparator();
									printf("\n\nErreur, pas de polynôme entré\n\n");
								}
								break;

							case 3:
								if(id2 != -1)
								{
									drawSeparator();
									poly_write_to_file(resultId);
								}
								else
								{
									drawSeparator();
									printf("\n\nErreur, pas de polynôme entré\n\n");
								}
								break;

							case 9:
								choice = 0;
								break;

							default:
								drawSeparator();
								printf("\n\nOption non reconnue\n\n");
								choice = 0;
								break;
						}

						break;

					case 9:
						choice = 0;
						break;

					default:
						drawSeparator();
						printf("\n\nOption non reconnue\n\n");
						choice = 0;
						break;

				}
				break;

			case 3:
				drawSeparator();
				if(id1 != -1 && id2 != -1)
				{
					resultId = poly_create_from_sum(id1, id2);
					
					poly_write_to_stream(id1);
					printf("+\n\n");
					poly_write_to_stream(id2);
					printf("=\n\n");
					poly_write_to_stream(resultId);
				}
				else
				{
					printf("\n\nErreur, veuillez entrer les deux polynômes\n\n");
				}
				break;

			case 4:
				drawSeparator();
				printf("\n\nWIP\n\n");
				break;

			case 5:
				drawSeparator();
				drawChoices(5);

				choice = getOption();

				switch(choice)
				{
					case 1:
						drawSeparator();
						drawChoices(51);

						choice = getOption();

						switch(choice)
						{
							case 1:


								if(id1 != -1)
								{
									drawSeparator();
									poly_write_to_stream(id1);
									printf("Pour X = ");

									scanf(" %lf", &x);
									fflush(stdin);

									printf("\n\n%.2lf\n\n", poly_create_from_image(id1, x));
								}
								else
								{
									drawSeparator();
									printf("\n\nErreur, pas de polynôme entré\n\n");
								}
								break;



							case 2:
								if(id1 != -1)
								{
									drawSeparator();
									poly_write_to_stream(id2);
									printf("Pour X = ");

									scanf(" %lf", &x);
									fflush(stdin);

									printf("\n\n%.2lf\n\n", poly_create_from_image(id2, x));
								}
								else
								{
									drawSeparator();
									printf("\n\nErreur, pas de polynôme entré\n\n");
								}
								break;

							case 9:
								choice = 0;
								break;

							default:
								drawSeparator();
								printf("\n\nOption non reconnue\n\n");
								choice = 0;

						}
						break;
						
					case 2:
						drawSeparator();
						printf("\n\nWIP\n\n");						
						break;
					case 9:
						choice = 0;
						break;

					default:
						drawSeparator();
						printf("\n\nOption non reconnue\n\n");
						choice = 0;


				}
				break;

			case 6:
				drawSeparator();
				printf("\n\nWIP\n\n");
				break;

			case 7:
				drawSeparator();
				printf("\n\nWIP\n\n");
				break;

			case 9:
				drawSeparator();
				break;

			default:
				drawSeparator();
				printf("\n\nOption non reconnue\n\n");
				choice = 0;

		}
	}
	poly_free_all();
}