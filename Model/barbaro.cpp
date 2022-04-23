#include "barbaro.h"

Barbaro::Barbaro(int exp,
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

Barbaro *Barbaro::clone() const
{
    return new Barbaro(*this);
}

std::string Barbaro::getClasse() const
{
    return "Barbaro";
}

Classi Barbaro::getEnumClasse() const
{
    return barbaro;
}

int Barbaro::getDadoVita() const
{
    return 12;
}

int Barbaro::getClasseArmatura() const
{
    return Personaggio::getClasseArmatura() + getModificatoreCostituzione();
}

void Barbaro::setClasseArmatura(int newvalue)
{
    Personaggio::setClasseArmatura(newvalue - getModificatoreCostituzione());
}

double Barbaro::getVelocita() const
{
    return getLivello() < 5 ? Personaggio::getVelocita() : Personaggio::getVelocita() + 3;
}

void Barbaro::setVelocita(double newvalue)
{
    getLivello() < 5 ? Personaggio::setVelocita(newvalue) : Personaggio::setVelocita(newvalue - 3);
}

void Barbaro::setCompetenzeBaseTiriSalvezza()
{
    setCompetenzaForza(true);
    setCompetenzaCostituzione(true);
}

bool Barbaro::operator==(const Barbaro &x) const
{
    return Personaggio::operator==(x);
}

bool Barbaro::operator!=(const Barbaro &x) const
{
    return Personaggio::operator!=(x);
}
