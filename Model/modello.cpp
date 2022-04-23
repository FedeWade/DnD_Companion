#include "modello.h"

Modello::Modello() : selectedPG(nullptr) {}

Personaggio *Modello::getSelectedPG() const
{
    return selectedPG;
}

int Modello::getselectedPGIndex() const
{
    if (selectedPG) {
        int y = 0;
        for (auto it = Lista.begin(); it != Lista.end(); it++) {
            if (&(**it) == selectedPG)
                return y;
            y++;
        }
    }
    throw new std::runtime_error(
        "Errore: Nessun personaggio è stato selezionato, impossibile ottenere l'indice.");
}

void Modello::setSelectedPG(int i)
{
    if (getPGsNumber() > i) {
        int y = 0;

        for (auto it = Lista.begin(); it != Lista.end(); it++) {
            if (i == y)
                selectedPG = &(**it);
            y++;
        }
    }
}

void Modello::addNewPG(Classi classe,
                       int exp,
                       Razze razza,
                       int forza,
                       int destrezza,
                       int costituzione,
                       int intelligenza,
                       int saggezza,
                       int carisma,
                       const std::string &nome,
                       Allineamenti allineamento)
{
    if (classe == 0)
        Lista.push_front(new Barbaro(exp,
                                     razza,
                                     forza,
                                     destrezza,
                                     costituzione,
                                     intelligenza,
                                     saggezza,
                                     carisma,
                                     nome,
                                     allineamento));

    else if (classe == 1)
        Lista.push_front(new Chierico(exp,
                                      razza,
                                      forza,
                                      destrezza,
                                      costituzione,
                                      intelligenza,
                                      saggezza,
                                      carisma,
                                      nome,
                                      allineamento));
    else if (classe == 2)
        Lista.push_front(new Guerriero(exp,
                                       razza,
                                       forza,
                                       destrezza,
                                       costituzione,
                                       intelligenza,
                                       saggezza,
                                       carisma,
                                       nome,
                                       allineamento));
    else if (classe == 3)
        Lista.push_front(new Mago(exp,
                                  razza,
                                  forza,
                                  destrezza,
                                  costituzione,
                                  intelligenza,
                                  saggezza,
                                  carisma,
                                  nome,
                                  allineamento));
    else
        throw new std::runtime_error("Errore: Impossibile creare il personaggio.");
}

void Modello::removePG(int i)
{
    if (selectedPG && getselectedPGIndex() == i)
        selectedPG = nullptr;
    Lista.remove(i);
}

int Modello::getPGsNumber() const
{
    return Lista.size();
}

bool Modello::empty() const
{
    return Lista.empty();
}

Personaggio *Modello::getPG(int i) const
{
    int y = 0;
    for (auto it = Lista.begin(); it != Lista.end(); it++) {
        if (i == y)
            return &(**it);
        y++;
    }
    return nullptr;
}
