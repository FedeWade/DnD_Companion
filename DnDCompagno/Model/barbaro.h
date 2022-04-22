#ifndef BARBARO_H
#define BARBARO_H
#include "personaggio.h"

class Barbaro : public Personaggio
{
public:
    Barbaro(int,
            Razze,
            int,
            int,
            int,
            int,
            int,
            int,
            const std::string &nome = "NoName",
            Allineamenti allineamento = Neutrale);

    Barbaro *clone() const;

    virtual std::string getClasse() const;
    virtual Classi getEnumClasse() const;
    virtual int getDadoVita() const;

    virtual int getClasseArmatura() const;
    //override di getClasseArmatura di Personaggio (per i barbari va aggiunto ache il mod costituzione)
    virtual void setClasseArmatura(int); //override di setCA

    virtual double getVelocita() const;
    virtual void setVelocita(double);

    //Inizializzazione TS
    virtual void setCompetenzeBaseTiriSalvezza();

    bool operator==(const Barbaro &x) const;
    bool operator!=(const Barbaro &x) const;
};

#endif // BARBARO_H
