#include "livello.h"

Livello::Livello(int exp) : Esperienza(exp), CompetenzaExtra(0)
{
    if (exp < 0)
        Esperienza = 0;
}

int Livello::getEsperienza() const
{
    return Esperienza;
}

int Livello::getLivello() const
{
    if (Esperienza < 300)
        return 1;
    if (Esperienza < 900)
        return 2;
    if (Esperienza < 2700)
        return 3;
    if (Esperienza < 6500)
        return 4;
    if (Esperienza < 14000)
        return 5;
    if (Esperienza < 23000)
        return 6;
    if (Esperienza < 34000)
        return 7;
    if (Esperienza < 48000)
        return 8;
    if (Esperienza < 64000)
        return 9;
    if (Esperienza < 85000)
        return 10;
    if (Esperienza < 100000)
        return 11;
    if (Esperienza < 120000)
        return 12;
    if (Esperienza < 140000)
        return 13;
    if (Esperienza < 165000)
        return 14;
    if (Esperienza < 195000)
        return 15;
    if (Esperienza < 225000)
        return 16;
    if (Esperienza < 265000)
        return 17;
    if (Esperienza < 305000)
        return 18;
    if (Esperienza < 355000)
        return 19;
    return 20;
}

void Livello::addEsperienza(int expToAdd)
{
    if (expToAdd < 0)
        throw new std::domain_error(
            "Errore: L'esperienza da aggiungere non può avere un valore negativo.");
    Esperienza += expToAdd;
}

void Livello::removeEsperienza(int expToRemove)
{
    if (expToRemove < 0)
        throw new std::domain_error(
            "Errore: L'esperienza da rimuovere non può avere un valore negativo.");
    expToRemove >= Esperienza ? Esperienza = 0 : Esperienza -= expToRemove;
}

void Livello::setEsperienza(int exp)
{
    if (exp <= 0)
        Esperienza = 0;
    else
        Esperienza = exp;
}

int Livello::getBonusCompetenza() const
{
    return getSuggestedCompetenza() + CompetenzaExtra;
}

void Livello::setBonusCompetenza(int competenza)
{
    if (competenza < 0)
        competenza = 0;
    CompetenzaExtra = competenza - getSuggestedCompetenza();
}

int Livello::getSuggestedCompetenza() const
{
    if (getLivello() < 5)
        return 2;
    if (getLivello() < 9)
        return 3;
    if (getLivello() < 13)
        return 4;
    if (getLivello() < 17)
        return 5;
    return 6;
}

bool Livello::operator==(const Livello &x) const
{
    return Esperienza == x.Esperienza && CompetenzaExtra == x.CompetenzaExtra;
}

bool Livello::operator!=(const Livello &x) const
{
    return !(*this == x);
}
