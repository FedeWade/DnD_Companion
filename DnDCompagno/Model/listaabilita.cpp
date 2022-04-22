#include "listaabilita.h"

ListaAbilita::ListaAbilita()
{
    Vect.push_back(Abilita("Acrobazia", false, "Destrezza"));
    Vect.push_back(Abilita("Addestrare animali", false, "Saggezza"));
    Vect.push_back(Abilita("Arcano", false, "Intelligenza"));
    Vect.push_back(Abilita("Atletica", false, "Forza"));
    Vect.push_back(Abilita("Furtività", false, "Destrezza"));
    Vect.push_back(Abilita("Indagare", false, "Intelligenza"));
    Vect.push_back(Abilita("Inganno", false, "Carisma"));
    Vect.push_back(Abilita("Intimidire", false, "Carisma"));
    Vect.push_back(Abilita("Intrattenere", false, "Carisma"));
    Vect.push_back(Abilita("Intuizione", false, "Saggezza"));
    Vect.push_back(Abilita("Medicina", false, "Saggezza"));
    Vect.push_back(Abilita("Natura", false, "Intelligenza"));
    Vect.push_back(Abilita("Percezione", false, "Saggezza"));
    Vect.push_back(Abilita("Persuasione", false, "Carisma"));
    Vect.push_back(Abilita("Rapidità di mano", false, "Destrezza"));
    Vect.push_back(Abilita("Religione", false, "Intelligenza"));
    Vect.push_back(Abilita("Sopravvivenza", false, "Saggezza"));
    Vect.push_back(Abilita("Storia", false, "Intelligenza"));
}

int ListaAbilita::getValoreAbilita(const std::string &abilita) const
{
    for (auto cit = Vect.begin(); cit != Vect.end(); cit++) {
        if ((*cit).Nome == abilita) {
            if ((*cit).Competenza)
                return getModificatoreCaratteristica((*cit).CaratteristicaDiApppartenenza)
                       + getBonusCompetenza();
            return getModificatoreCaratteristica((*cit).CaratteristicaDiApppartenenza);
        }
    }
    throw new std::domain_error("Errore: L'abilità inserita non esiste.");
}

bool ListaAbilita::isCompetenteAbilita(const std::string &abilita) const
{
    for (auto cit = Vect.begin(); cit != Vect.end(); cit++) {
        if ((*cit).Nome == abilita)
            return (*cit).Competenza;
    }
    throw new std::domain_error("Errore: L'abilità inserita non esiste.");
}

bool ListaAbilita::isCompetenteAbilitaIndex(int nabilita) const
{
    int x = 0;
    for (auto cit = Vect.begin(); cit != Vect.end(); cit++) {
        if (x == nabilita)
            return (*cit).Competenza;
        x++;
    }
    throw new std::domain_error("Errore: Il numero abilità inserita non esiste.");
}

void ListaAbilita::setCompetenzaAbilita(const std::string &abilita, bool competenza)
{
    for (auto it = Vect.begin(); it != Vect.end(); it++) {
        if ((*it).Nome == abilita) {
            if (competenza != (*it).Competenza)
                (*it).Competenza = competenza;
            return;
        }
    }
    throw new std::domain_error("Errore: L'abilità inserita non esiste.");
}

void ListaAbilita::setCompetenzaAbilitaIndex(int nabilita, bool competenza)
{
    int x = 0;
    for (auto it = Vect.begin(); it != Vect.end(); it++) {
        if (x == nabilita) {
            if (competenza != (*it).Competenza)
                (*it).Competenza = competenza;
            return;
        }
        x++;
    }
    throw new std::domain_error("Errore: Il numero abilità inserito non esiste.");
}

bool ListaAbilita::operator==(const ListaAbilita &x) const
{
    return Caratteristiche::operator==(x) && Vect == x.Vect;
}

bool ListaAbilita::operator!=(const ListaAbilita &x) const
{
    return !(*this == x);
}

ListaAbilita::Abilita::Abilita(const std::string &nome, bool competenza, const std::string &caratteristica)
    : Nome(nome), Competenza(competenza), CaratteristicaDiApppartenenza(caratteristica)
{}

bool ListaAbilita::Abilita::operator==(const ListaAbilita::Abilita &x) const
{
    return Nome == x.Nome && Competenza == x.Competenza
           && CaratteristicaDiApppartenenza == x.CaratteristicaDiApppartenenza;
}

bool ListaAbilita::Abilita::operator!=(const ListaAbilita::Abilita &x) const
{
    return !(*this == x);
}
