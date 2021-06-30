#ifndef CALCULS_H
#define CALCULS_H

double puissance(double a, double b)
{
	double result = 1;

	for (int i = 0; i < b; ++i)
	{
		result = result * a;
	}

	return result;
}

void somme(Polynome * poly1, Polynome * poly2, Polynome * result)
{	
	if(poly1->degre >= poly2->degre)
	{
		for(int i = 0; i <= poly1->degre; i++)
		{
			if(i <= poly2->degre)
			{
				result->monomes[i].coef = poly1->monomes[i].coef + poly2->monomes[i].coef;
			}
			else
			{
				result->monomes[i].coef = poly1->monomes[i].coef;
			}
		}
	}
	else
	{
		for(int i = 0; i <= poly2->degre; i++)
		{
			if(i >= poly1->degre)
			{
				result->monomes[i].coef = poly1->monomes[i].coef + poly2->monomes[i].coef;
			}
			else
			{
				result->monomes[i].coef = poly1->monomes[i].coef;
			}
		}
	}
}

Polynome * produit()
{

}

Polynome * derivee()
{

}

double image(Polynome * poly, double x)
{	
	double result = 0;
	for (int i = 0; i <= poly->degre; i++)
	{
		result = result + (poly->monomes[i].coef * (puissance(x, (poly->degre - i))));
	}
	return result;
}

double * horner()
{

}

Polynome * reduire()
{

}

int getMaxDegre(Polynome * poly1, Polynome * poly2)
{
	if(poly1->degre >= poly2->degre)
	{
		return (poly1->degre);
	}
	else
	{
		return (poly2->degre);
	}
}

int getDegre(Polynome * poly)
{
	return poly->degre;
}



#endif