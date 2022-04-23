#include "tirisalvezza.h"

TiriSalvezza::TiriSalvezza(bool cForza,
                           bool cDestrezza,
                           bool cCostituzione,
                           bool cIntelligenza,
                           bool cSaggezza,
                           bool cCarisma)
    : CompetenzaForza(cForza), CompetenzaDestrezza(cDestrezza),
      CompetenzaCostituzione(cCostituzione), CompetenzaIntelligenza(cIntelligenza),
      CompetenzaSaggezza(cSaggezza), CompetenzaCarisma(cCarisma)
{}

bool TiriSalvezza::isCompetenteForza() const
{
    return CompetenzaForza;
}

int TiriSalvezza::getTiroSalvezzaForza() const
{
    return CompetenzaForza ? getModificatoreForza() + getBonusCompetenza() : getModificatoreForza();
}

bool TiriSalvezza::isCompetenteDestrezza() const
{
    return CompetenzaDestrezza;
}

int TiriSalvezza::getTiroSalvezzaDestrezza() const
{
    return CompetenzaDestrezza ? getModificatoreDestrezza() + getBonusCompetenza()
                               : getModificatoreDestrezza();
}

bool TiriSalvezza::isCompetenteCostituzione() const
{
    return CompetenzaCostituzione;
}

int TiriSalvezza::getTiroSalvezzaCostituzione() const
{
    return CompetenzaCostituzione ? getModificatoreCostituzione() + getBonusCompetenza()
                                  : getModificatoreCostituzione();
}

bool TiriSalvezza::isCompetenteIntelligenza() const
{
    return CompetenzaIntelligenza;
}

int TiriSalvezza::getTiroSalvezzaIntelligenza() const
{
    return CompetenzaIntelligenza ? getModificatoreIntelligenza() + getBonusCompetenza()
                                  : getModificatoreIntelligenza();
}

bool TiriSalvezza::isCompetenteSaggezza() const
{
    return CompetenzaSaggezza;
}

int TiriSalvezza::getTiroSalvezzaSaggezza() const
{
    return CompetenzaSaggezza ? getModificatoreSaggezza() + getBonusCompetenza()
                              : getModificatoreSaggezza();
}

bool TiriSalvezza::isCompetenteCarisma() const
{
    return CompetenzaCarisma;
}

int TiriSalvezza::getTiroSalvezzaCarisma() const
{
    return CompetenzaCarisma ? getModificatoreCarisma() + getBonusCompetenza()
                             : getModificatoreCarisma();
}

void TiriSalvezza::setCompetenzaForza(bool competenza)
{
    if (competenza != isCompetenteForza())
        CompetenzaForza = competenza;
}

void TiriSalvezza::setCompetenzaDestrezza(bool competenza)
{
    if (competenza != isCompetenteDestrezza())
        CompetenzaDestrezza = competenza;
}

void TiriSalvezza::setCompetenzaCostituzione(bool competenza)
{
    if (competenza != isCompetenteCostituzione())
        CompetenzaCostituzione = competenza;
}

void TiriSalvezza::setCompetenzaIntelligenza(bool competenza)
{
    if (competenza != isCompetenteIntelligenza())
        CompetenzaIntelligenza = competenza;
}

void TiriSalvezza::setCompetenzaSaggezza(bool competenza)
{
    if (competenza != isCompetenteSaggezza())
        CompetenzaSaggezza = competenza;
}

void TiriSalvezza::setCompetenzaCarisma(bool competenza)
{
    if (competenza != isCompetenteCarisma())
        CompetenzaCarisma = competenza;
}

bool TiriSalvezza::isCompetenteStatistica(const std::string &stat) const
{
    if (stat == "Forza")
        return isCompetenteForza();
    if (stat == "Destrezza")
        return isCompetenteDestrezza();
    if (stat == "Costituzione")
        return isCompetenteCostituzione();
    if (stat == "Intelligenza")
        return isCompetenteIntelligenza();
    if (stat == "Saggezza")
        return isCompetenteSaggezza();
    if (stat == "Carisma")
        return isCompetenteCarisma();
    throw new std::domain_error("Errore: La caratteristica inserita non esiste.");
}

int TiriSalvezza::getTiroSalvezzaStatistica(const std::string &stat) const
{
    if (stat == "Forza")
        return getTiroSalvezzaForza();
    if (stat == "Destrezza")
        return getTiroSalvezzaDestrezza();
    if (stat == "Costituzione")
        return getTiroSalvezzaCostituzione();
    if (stat == "Intelligenza")
        return getTiroSalvezzaIntelligenza();
    if (stat == "Saggezza")
        return getTiroSalvezzaSaggezza();
    if (stat == "Carisma")
        return getTiroSalvezzaCarisma();
    throw new std::domain_error("Errore: La caratteristica inserita non esiste.");
}

void TiriSalvezza::setCompetenzaStatistica(const std::string &stat, bool value)
{
    if (stat == "Forza")
        setCompetenzaForza(value);
    else if (stat == "Destrezza")
        setCompetenzaDestrezza(value);
    else if (stat == "Costituzione")
        setCompetenzaCostituzione(value);
    else if (stat == "Intelligenza")
        setCompetenzaIntelligenza(value);
    else if (stat == "Saggezza")
        setCompetenzaSaggezza(value);
    else if (stat == "Carisma")
        setCompetenzaCarisma(value);
    else
        throw new std::domain_error("Errore: La caratteristica inserita non esiste.");
}

bool TiriSalvezza::operator==(const TiriSalvezza &x) const
{
    return Caratteristiche::operator==(x) && CompetenzaForza == x.CompetenzaForza
           && CompetenzaDestrezza == x.CompetenzaDestrezza
           && CompetenzaCostituzione == x.CompetenzaCostituzione
           && CompetenzaIntelligenza == x.CompetenzaIntelligenza
           && CompetenzaSaggezza == x.CompetenzaSaggezza
           && CompetenzaCarisma == x.CompetenzaCarisma;
}

bool TiriSalvezza::operator!=(const TiriSalvezza &x) const
{
    return !(*this == x);
}
