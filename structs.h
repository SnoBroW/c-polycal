#ifndef STRUCTS_H
#define STRUCTS_H


typedef struct Monome
{
	double coef;
	int degre;
} Monome;


typedef struct Polynome
{
	Monome * monomes;
    int degre;
} Polynome;


#endif