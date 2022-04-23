#ifndef LIVELLO_H
#define LIVELLO_H
#include <stdexcept>

class Livello
{
public:
    Livello(int = 0);

    int getEsperienza() const;
    int getLivello() const;
    void addEsperienza(int expToAdd);
    void removeEsperienza(int expToRemove);
    void setEsperienza(int exp);

    int getBonusCompetenza() const;
    void setBonusCompetenza(int);
    int getSuggestedCompetenza() const;

    bool operator==(const Livello &x) const;
    bool operator!=(const Livello &x) const;

private:
    int Esperienza;
    int CompetenzaExtra;
};

#endif // LIVELLO_H
