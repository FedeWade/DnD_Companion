#include "caratteristiche.h"

Caratteristiche::Caratteristiche(int exp,
                                 Razze razza,
                                 int forza,
                                 int destrezza,
                                 int costituzione,
                                 int intelligenza,
                                 int saggezza,
                                 int carisma)
    : Livello(exp), Razza(razza), ForzaExtra(forza), DestrezzaExtra(destrezza),
      CostituzioneExtra(costituzione), IntelligenzaExtra(intelligenza), SaggezzaExtra(saggezza),
      CarismaExtra(carisma)
{}

Razze Caratteristiche::getEnumRazza() const
{
    return Razza;
}

std::string Caratteristiche::getRazza() const
{
    if (Razza == 0)
        return "Elfo";
    if (Razza == 1)
        return "Halfling";
    if (Razza == 2)
        return "Nano";
    if (Razza == 3)
        return "Umano";
    if (Razza == 4)
        return "Dragonide";
    if (Razza == 5)
        return "Gnomo";
    if (Razza == 6)
        return "Mezzelfo";
    if (Razza == 7)
        return "Mezzorco";
    if (Razza == 8)
        return "Tiefling";
    return "No Razza";
}

int Caratteristiche::getForza() const
{
    return ForzaExtra + getSuggestedForza();
}

int Caratteristiche::getSuggestedForza() const
{
    if (Razza == dragonide || Razza == mezzorco)
        return 2;
    if (Razza == umano)
        return 1;
    return 0;
}

int Caratteristiche::getModificatoreForza() const
{
    return (getForza() - 10) / 2;
}

void Caratteristiche::setForza(int val)
{
    val > 0 ? ForzaExtra = val - getSuggestedForza() : ForzaExtra = 0;
}

int Caratteristiche::getDestrezza() const
{
    return DestrezzaExtra + getSuggestedDestrezza();
}

int Caratteristiche::getSuggestedDestrezza() const
{
    if (Razza == elfo || Razza == halfling)
        return 2;
    if (Razza == umano)
        return 1;
    return 0;
}

int Caratteristiche::getModificatoreDestrezza() const
{
    return (getDestrezza() - 10) / 2;
}

void Caratteristiche::setDestrezza(int val)
{
    val > 0 ? DestrezzaExtra = val - getSuggestedDestrezza() : DestrezzaExtra = 0;
}

int Caratteristiche::getCostituzione() const
{
    return CostituzioneExtra + getSuggestedCostituzione();
}

int Caratteristiche::getSuggestedCostituzione() const
{
    if (Razza == nano)
        return 2;
    if (Razza == mezzorco || Razza == umano)
        return 1;
    return 0;
}

int Caratteristiche::getModificatoreCostituzione() const
{
    return (getCostituzione() - 10) / 2;
}

void Caratteristiche::setCostituzione(int val)
{
    val > 0 ? CostituzioneExtra = val - getSuggestedCostituzione() : CostituzioneExtra = 0;
}

int Caratteristiche::getIntelligenza() const
{
    return IntelligenzaExtra + getSuggestedIntelligenza();
}

int Caratteristiche::getSuggestedIntelligenza() const
{
    if (Razza == gnomo)
        return 2;
    if (Razza == tiefling || Razza == umano)
        return 1;
    return 0;
}

int Caratteristiche::getModificatoreIntelligenza() const
{
    return (getIntelligenza() - 10) / 2;
}

void Caratteristiche::setIntelligenza(int val)
{
    val > 0 ? IntelligenzaExtra = val - getSuggestedIntelligenza() : IntelligenzaExtra = 0;
}

int Caratteristiche::getSaggezza() const
{
    return SaggezzaExtra + getSuggestedSaggezza();
}

int Caratteristiche::getSuggestedSaggezza() const
{
    if (Razza == umano)
        return 1;
    return 0;
}

int Caratteristiche::getModificatoreSaggezza() const
{
    return (getSaggezza() - 10) / 2;
}

void Caratteristiche::setSaggezza(int val)
{
    val > 0 ? SaggezzaExtra = val - getSuggestedSaggezza() : SaggezzaExtra = 0;
}

int Caratteristiche::getCarisma() const
{
    return CarismaExtra + getSuggestedCarisma();
}

int Caratteristiche::getSuggestedCarisma() const
{
    if (Razza == mezzelfo || Razza == tiefling)
        return 2;
    if (Razza == dragonide || Razza == umano)
        return 1;
    return 0;
}

int Caratteristiche::getModificatoreCarisma() const
{
    return (getCarisma() - 10) / 2;
}

void Caratteristiche::setCarisma(int val)
{
    val > 0 ? CarismaExtra = val - getSuggestedCarisma() : CarismaExtra = 0;
}

int Caratteristiche::getCaratteristica(const std::string &caratteristica) const
{
    if (caratteristica == "Forza")
        return getForza();
    if (caratteristica == "Destrezza")
        return getDestrezza();
    if (caratteristica == "Costituzione")
        return getCostituzione();
    if (caratteristica == "Intelligenza")
        return getIntelligenza();
    if (caratteristica == "Saggezza")
        return getSaggezza();
    if (caratteristica == "Carisma")
        return getCarisma();
    throw new std::domain_error("Errore: La caratteristica inserita non esiste.");
}

int Caratteristiche::getModificatoreCaratteristica(const std::string &caratteristica) const
{
    if (caratteristica == "Forza")
        return getModificatoreForza();
    if (caratteristica == "Destrezza")
        return getModificatoreDestrezza();
    if (caratteristica == "Costituzione")
        return getModificatoreCostituzione();
    if (caratteristica == "Intelligenza")
        return getModificatoreIntelligenza();
    if (caratteristica == "Saggezza")
        return getModificatoreSaggezza();
    if (caratteristica == "Carisma")
        return getModificatoreCarisma();
    throw new std::domain_error("Errore: La caratteristica inserita non esiste.");
}

void Caratteristiche::setCaratteristica(const std::string &caratteristica, int val)
{
    if (caratteristica == "Forza")
        setForza(val);
    else if (caratteristica == "Destrezza")
        setDestrezza(val);
    else if (caratteristica == "Costituzione")
        setCostituzione(val);
    else if (caratteristica == "Intelligenza")
        setIntelligenza(val);
    else if (caratteristica == "Saggezza")
        setSaggezza(val);
    else if (caratteristica == "Carisma")
        setCarisma(val);
    else
        throw new std::domain_error("Errore: La caratteristica inserita non esiste.");
}

bool Caratteristiche::operator==(const Caratteristiche &x) const
{
    return Livello::operator==(x) && Razza == x.Razza && ForzaExtra == x.ForzaExtra
           && DestrezzaExtra == x.DestrezzaExtra && CostituzioneExtra == x.CarismaExtra
           && IntelligenzaExtra == x.IntelligenzaExtra && SaggezzaExtra == x.SaggezzaExtra
           && CarismaExtra == x.CarismaExtra;
}

bool Caratteristiche::operator!=(const Caratteristiche &x) const
{
    return !(*this == x);
}
