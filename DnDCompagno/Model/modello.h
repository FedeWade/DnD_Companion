#ifndef MODELLO_H
#define MODELLO_H
#include "barbaro.h"
#include "chierico.h"
#include "contenitore.h"
#include "deeppointer.h"
#include "guerriero.h"
#include "mago.h"
#include <stdexcept>

class Modello
{
public:
    Modello();

    Personaggio *getSelectedPG() const;
    int getselectedPGIndex() const;
    void setSelectedPG(int);

    void addNewPG(Classi, int, Razze, int, int, int, int, int, int, const std::string &, Allineamenti);
    void removePG(int);

    int getPGsNumber() const;
    bool empty() const;
    Personaggio *getPG(int) const;

private:
    Contenitore<DeepPointer<Personaggio>> Lista;
    Personaggio *selectedPG;
};

#endif // MODELLO_H
