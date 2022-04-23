#include "guerriero.h"

Guerriero::Guerriero(int exp,
                     Razze razza,
                     int forza,
                     int destrezza,
                     int costituzione,
                     int intelligenza,
                     int saggezza,
                     int carisma,
                     const std::string &nome,
                     Allineamenti allineamento)
    : Caratteristiche(exp, razza, forza, destrezza, costituzione, intelligenza, saggezza, carisma),
      Personaggio(nome, allineamento)
{
    resetPuntiVita();
    setCompetenzeBaseTiriSalvezza();
}

Guerriero *Guerriero::clone() const
{
    return new Guerriero(*this);
}

std::string Guerriero::getClasse() const
{
    return "Guerriero";
}

Classi Guerriero::getEnumClasse() const
{
    return guerriero;
}

int Guerriero::getDadoVita() const
{
    return 10;
}

void Guerriero::setCompetenzeBaseTiriSalvezza()
{
    setCompetenzaForza(true);
    setCompetenzaCostituzione(true);
}

bool Guerriero::operator==(const Guerriero &x) const
{
    return Personaggio::operator==(x);
}

bool Guerriero::operator!=(const Guerriero &x) const
{
    return Personaggio::operator!=(x);
}
