#ifndef LISTAABILITA_H
#define LISTAABILITA_H
#include "caratteristiche.h"
#include <vector>

class ListaAbilita : virtual public Caratteristiche
{
public:
    ListaAbilita();

    int getValoreAbilita(const std::string &) const;
    bool isCompetenteAbilita(const std::string &) const;
    bool isCompetenteAbilitaIndex(int) const;
    void setCompetenzaAbilita(const std::string &, bool);
    void setCompetenzaAbilitaIndex(int, bool);

    bool operator==(const ListaAbilita &x) const;
    bool operator!=(const ListaAbilita &x) const;

private:
    class Abilita
    {
    public:
        Abilita(const std::string &, bool, const std::string &);
        std::string Nome;
        bool Competenza;
        std::string CaratteristicaDiApppartenenza;

        bool operator==(const Abilita &x) const;
        bool operator!=(const Abilita &x) const;
    };

    std::vector<Abilita> Vect;
};

#endif // LISTAABILITA_H
