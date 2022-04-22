#ifndef CHIERICO_H
#define CHIERICO_H
#include "incantatore.h"

class Chierico : public Incantatore
{
public:
    Chierico(int,
             Razze,
             int,
             int,
             int,
             int,
             int,
             int,
             const std::string &nome = "NoName",
             Allineamenti allineamento = Neutrale);

    Chierico *clone() const;

    virtual std::string getClasse() const;
    virtual Classi getEnumClasse() const;
    virtual int getDadoVita() const;

    //override metodi di Incantatore
    virtual SlotIncantesimi suggestedSlotIncantesimi() const;
    virtual std::string getCaratteristicaIncantatore() const;
    virtual int getCDTiroSalvezzaIncantesimo() const;
    virtual int getModificatoreAttaccoIncantesimo() const;

    //inizializzazione TS
    virtual void setCompetenzeBaseTiriSalvezza();

    bool operator==(const Chierico &x) const;
    bool operator!=(const Chierico &x) const;

private:
};

#endif // CHIERICO_H
