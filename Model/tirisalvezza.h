#ifndef TIRISALVEZZA_H
#define TIRISALVEZZA_H
#include "caratteristiche.h"

class TiriSalvezza : virtual public Caratteristiche
{
public:
    TiriSalvezza(bool = false, bool = false, bool = false, bool = false, bool = false, bool = false);

    bool isCompetenteForza() const;
    int getTiroSalvezzaForza() const;
    void setCompetenzaForza(bool);

    bool isCompetenteDestrezza() const;
    int getTiroSalvezzaDestrezza() const;
    void setCompetenzaDestrezza(bool);

    bool isCompetenteCostituzione() const;
    int getTiroSalvezzaCostituzione() const;
    void setCompetenzaCostituzione(bool);

    bool isCompetenteIntelligenza() const;
    int getTiroSalvezzaIntelligenza() const;
    void setCompetenzaIntelligenza(bool);

    bool isCompetenteSaggezza() const;
    int getTiroSalvezzaSaggezza() const;
    void setCompetenzaSaggezza(bool);

    bool isCompetenteCarisma() const;
    int getTiroSalvezzaCarisma() const;
    void setCompetenzaCarisma(bool);

    bool isCompetenteStatistica(const std::string &) const;
    int getTiroSalvezzaStatistica(const std::string &) const;
    void setCompetenzaStatistica(const std::string &, bool);

    bool operator==(const TiriSalvezza &x) const;
    bool operator!=(const TiriSalvezza &x) const;

private:
    bool CompetenzaForza, CompetenzaDestrezza, CompetenzaCostituzione, CompetenzaIntelligenza,
        CompetenzaSaggezza, CompetenzaCarisma;
};

#endif // TIRISALVEZZA_H
