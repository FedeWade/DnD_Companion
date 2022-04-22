#ifndef GUERRIERO_H
#define GUERRIERO_H
#include "personaggio.h"

class Guerriero : public Personaggio
{
public:
    Guerriero(int,
              Razze,
              int,
              int,
              int,
              int,
              int,
              int,
              const std::string &nome = "NoName",
              Allineamenti allineamento = Neutrale);

    Guerriero *clone() const;

    virtual std::string getClasse() const;
    virtual Classi getEnumClasse() const;
    virtual int getDadoVita() const;

    //inizializzazione TS
    virtual void setCompetenzeBaseTiriSalvezza();

    bool operator==(const Guerriero &x) const;
    bool operator!=(const Guerriero &x) const;
};

#endif // GUERRIERO_H
