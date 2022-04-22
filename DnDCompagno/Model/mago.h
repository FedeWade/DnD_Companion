#ifndef MAGO_H
#define MAGO_H
#include "incantatore.h"

class Mago : public Incantatore
{
public:
    Mago(int,
         Razze,
         int,
         int,
         int,
         int,
         int,
         int,
         const std::string &nome = "NoName",
         Allineamenti allineamento = Neutrale);

    Mago *clone() const;

    virtual std::string getClasse() const;
    virtual Classi getEnumClasse() const;
    virtual int getDadoVita() const;

    //override incantatore
    virtual SlotIncantesimi suggestedSlotIncantesimi() const;
    virtual std::string getCaratteristicaIncantatore() const;
    virtual int getCDTiroSalvezzaIncantesimo() const;
    virtual int getModificatoreAttaccoIncantesimo() const;

    virtual void setCompetenzeBaseTiriSalvezza();

    bool operator==(const Mago &x) const;
    bool operator!=(const Mago &x) const;
};

#endif // MAGO_H
