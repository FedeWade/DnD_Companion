#include "personaggio.h"

Personaggio::Personaggio(const std::string &nome, Allineamenti allineamento)
    : Nome(nome), Allineamento(allineamento), Descrizione(""), TrattiPrivilegi(""), Ispirazione(0),
      ClasseArmaturaBase(10), IniziativaBase(0), Velocita(suggestedVelocita()), PuntiVitaBase(0),
      PuntiVita(0)
{}

std::string Personaggio::getNome() const
{
    return Nome;
}

Allineamenti Personaggio::getIndiceAllineamento() const
{
    return Allineamento;
}

std::string Personaggio::getAllineamento() const
{
    if (Allineamento == 0)
        return "Legale Buono";
    if (Allineamento == 1)
        return "Neutrale Buono";
    if (Allineamento == 2)
        return "Caotico Buono";
    if (Allineamento == 3)
        return "Legale Neutrale";
    if (Allineamento == 4)
        return "Neutrale";
    if (Allineamento == 5)
        return "Caotico Neutrale";
    if (Allineamento == 6)
        return "Legale Malvagio";
    if (Allineamento == 7)
        return "Neutrale Malvagio";
    if (Allineamento == 8)
        return "Caotico Malvagio";
    return "Nessun Allineamento";
}

std::string Personaggio::getDescrizione() const
{
    return Descrizione;
}

void Personaggio::setDescrizione(const std::string &newdescrizione)
{
    Descrizione = newdescrizione;
}

std::string Personaggio::getTrattiPrivilegi() const
{
    return TrattiPrivilegi;
}

void Personaggio::setTrattiPrivilegi(const std::string &newtrattiprivilegi)
{
    TrattiPrivilegi = newtrattiprivilegi;
}

std::string Personaggio::getDescInventario() const
{
    return DescInventario;
}

void Personaggio::setDescInventario(const std::string &newinventario)
{
    DescInventario = newinventario;
}

int Personaggio::getIspirazione() const
{
    return Ispirazione;
}

void Personaggio::setIspirazione(int newvalue)
{
    newvalue < 1 ? Ispirazione = 0 : Ispirazione = newvalue;
}

int Personaggio::getClasseArmatura() const
{
    return ClasseArmaturaBase + getModificatoreDestrezza();
}

void Personaggio::setClasseArmatura(int CA)
{
    CA <= 0 ? ClasseArmaturaBase = 0 - getModificatoreDestrezza()
            : ClasseArmaturaBase = CA - getModificatoreDestrezza();
}

int Personaggio::getBonusIniziativa() const
{
    return IniziativaBase + getModificatoreDestrezza();
}

void Personaggio::setBonusIniziativa(int iniziativa)
{
    IniziativaBase = iniziativa - getModificatoreDestrezza();
}

double Personaggio::getVelocita() const
{
    return Velocita;
}

void Personaggio::setVelocita(double vel)
{
    vel <= 0 ? Velocita = 0 : Velocita = vel;
}

int Personaggio::getPuntiVitaMassimi() const
{
    return PuntiVitaBase + suggestedPuntiVitaMassimi();
}

int Personaggio::getMediaDadoVita() const
{
    return getDadoVita() / 2 + 1;
}

int Personaggio::getPuntiVita() const
{
    return PuntiVita;
}

void Personaggio::setPuntiVitaMassimi(int pv)
{
    pv <= 0 ? PuntiVitaBase = 1 - suggestedPuntiVitaMassimi()
            : PuntiVitaBase = pv - suggestedPuntiVitaMassimi();
}

int Personaggio::suggestedPuntiVitaMassimi() const
{
    return getDadoVita() + (getLivello() * getModificatoreCostituzione())
           + ((getLivello() - 1) * getMediaDadoVita());
}

void Personaggio::resetPuntiVita()
{
    PuntiVita = getPuntiVitaMassimi();
}

void Personaggio::setPuntiVita(int pv)
{
    pv <= 0 ? PuntiVita = 0 : PuntiVita = pv;
}

void Personaggio::increasePuntiVita(int pvToAdd)
{
    if (pvToAdd > 0)
        PuntiVita += pvToAdd;
}

void Personaggio::decreasePuntiVita(int pvToDecrease)
{
    if (pvToDecrease > 0) {
        if (PuntiVita <= pvToDecrease)
            PuntiVita = 0;
        else
            PuntiVita -= pvToDecrease;
    }
}

double Personaggio::suggestedVelocita() const
{
    if (getEnumRazza() == halfling || getEnumRazza() == nano || getEnumRazza() == gnomo)
        return 7.5;
    return 9;
}

bool Personaggio::operator==(const Personaggio &x) const
{
    return typeid(*this) == typeid(x) && ListaAbilita::operator==(x) && TiriSalvezza::operator==(x)
           && Nome == x.Nome && Allineamento == x.Allineamento && Descrizione == x.Descrizione
           && TrattiPrivilegi == x.TrattiPrivilegi && DescInventario == x.DescInventario
           && Ispirazione == x.Ispirazione && ClasseArmaturaBase == x.ClasseArmaturaBase
           && IniziativaBase == x.IniziativaBase
           && fabs(Velocita - x.Velocita) < std::numeric_limits<double>::epsilon()
           && Inventario == x.Inventario;
    //Safe floating point comparison
}

bool Personaggio::operator!=(const Personaggio &x) const
{
    return !(*this == x);
}
