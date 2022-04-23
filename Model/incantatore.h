#ifndef INCANTATORE_H
#define INCANTATORE_H
#include "personaggio.h"
#include "slotincantesimi.h"

class Incantatore : public Personaggio
{
public:
    Incantatore(const std::string &, Allineamenti);

    std::string getDescIncantesimi() const;
    void setDescIncantesimi(const std::string &);

    virtual SlotIncantesimi suggestedSlotIncantesimi() const = 0;
    int getSlotIncantesimo(unsigned int) const;
    void setSlotIncantesimo(unsigned int, int);

    virtual std::string getCaratteristicaIncantatore() const = 0;
    virtual int getCDTiroSalvezzaIncantesimo() const = 0;
    virtual int getModificatoreAttaccoIncantesimo() const = 0;

    virtual bool operator==(const Incantatore &x) const;
    virtual bool operator!=(const Incantatore &x) const;

private:
    std::string DescIncatesimi;
    SlotIncantesimi IncantesimiExtra;
};

#endif // INCANTATORE_H
