#ifndef CARATTERISTICHE_H
#define CARATTERISTICHE_H
#include "livello.h"

enum Razze { elfo, halfling, nano, umano, dragonide, gnomo, mezzelfo, mezzorco, tiefling };

class Caratteristiche : public Livello
{
public:
    Caratteristiche(
        int = 0, Razze = umano, int = 0, int = 0, int = 0, int = 0, int = 0, int = 0);

    Razze getEnumRazza() const;
    std::string getRazza() const;

    int getForza() const;
    int getModificatoreForza() const;
    void setForza(int);

    int getDestrezza() const;
    int getModificatoreDestrezza() const;
    void setDestrezza(int);

    int getCostituzione() const;
    int getModificatoreCostituzione() const;
    void setCostituzione(int);

    int getIntelligenza() const;
    int getModificatoreIntelligenza() const;
    void setIntelligenza(int);

    int getSaggezza() const;
    int getModificatoreSaggezza() const;
    void setSaggezza(int);

    int getCarisma() const;
    int getModificatoreCarisma() const;
    void setCarisma(int);

    int getCaratteristica(const std::string &) const;
    int getModificatoreCaratteristica(const std::string &) const;
    void setCaratteristica(const std::string &, int);

    int getSuggestedForza() const;
    int getSuggestedDestrezza() const;
    int getSuggestedCostituzione() const;
    int getSuggestedIntelligenza() const;
    int getSuggestedSaggezza() const;
    int getSuggestedCarisma() const;

    bool operator==(const Caratteristiche &x) const;
    bool operator!=(const Caratteristiche &x) const;

private:
    Razze Razza;
    int ForzaExtra;
    int DestrezzaExtra;
    int CostituzioneExtra;
    int IntelligenzaExtra;
    int SaggezzaExtra;
    int CarismaExtra;
};

#endif // CARATTERISTICHE_H
