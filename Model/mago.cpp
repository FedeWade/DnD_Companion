#include "mago.h"

Mago::Mago(int exp,
           Razze razza,
           int forza,
           int destrezza,
           int costituzione,
           int intelligenza,
           int saggezza,
           int carisma,
           const std::string &nome,
           Allineamenti allineamento)
    : Caratteristiche(exp, razza, forza, destrezza, costituzione, intelligenza, saggezza, carisma),
      Incantatore(nome, allineamento)
{
    resetPuntiVita();
    setCompetenzeBaseTiriSalvezza();
}

Mago *Mago::clone() const
{
    return new Mago(*this);
}

std::string Mago::getClasse() const
{
    return "Mago";
}

Classi Mago::getEnumClasse() const
{
    return mago;
}

int Mago::getDadoVita() const
{
    return 6;
}

SlotIncantesimi Mago::suggestedSlotIncantesimi() const
{
    int LvlPg = getLivello();
    int Slot1 = 0, Slot2 = 0, Slot3 = 0, Slot4 = 0, Slot5 = 0, Slot6 = 0, Slot7 = 0,
              Slot8 = 0, Slot9 = 0;
    if (LvlPg == 1)
        Slot1 = 2;
    else if (LvlPg == 2)
        Slot1 = 3;
    else if (LvlPg == 3) {
        Slot1 = 4;
        Slot2 = 2;
    } else if (LvlPg == 4) {
        Slot1 = 4;
        Slot2 = 3;
    } else if (LvlPg == 5) {
        Slot1 = 4;
        Slot2 = 3;
        Slot3 = 2;
    } else if (LvlPg == 6) {
        Slot1 = 4;
        Slot2 = 3;
        Slot3 = 3;
    } else if (LvlPg == 7) {
        Slot1 = 4;
        Slot2 = 3;
        Slot3 = 3;
        Slot4 = 1;
    } else if (LvlPg == 8) {
        Slot1 = 4;
        Slot2 = 3;
        Slot3 = 3;
        Slot4 = 2;
    } else if (LvlPg == 9) {
        Slot1 = 4;
        Slot2 = 3;
        Slot3 = 3;
        Slot4 = 3;
        Slot5 = 1;
    } else if (LvlPg == 10) {
        Slot1 = 4;
        Slot2 = 3;
        Slot3 = 3;
        Slot4 = 3;
        Slot5 = 2;
    } else if (LvlPg == 11) {
        Slot1 = 4;
        Slot2 = 3;
        Slot3 = 3;
        Slot4 = 3;
        Slot5 = 2;
        Slot6 = 1;
    } else if (LvlPg == 12) {
        Slot1 = 4;
        Slot2 = 3;
        Slot3 = 3;
        Slot4 = 3;
        Slot5 = 2;
        Slot6 = 1;
    } else if (LvlPg == 13) {
        Slot1 = 4;
        Slot2 = 3;
        Slot3 = 3;
        Slot4 = 3;
        Slot5 = 2;
        Slot6 = 1;
        Slot7 = 1;
    } else if (LvlPg == 14) {
        Slot1 = 4;
        Slot2 = 3;
        Slot3 = 3;
        Slot4 = 3;
        Slot5 = 2;
        Slot6 = 1;
        Slot7 = 1;
    } else if (LvlPg == 15) {
        Slot1 = 4;
        Slot2 = 3;
        Slot3 = 3;
        Slot4 = 3;
        Slot5 = 2;
        Slot6 = 1;
        Slot7 = 1;
        Slot8 = 1;
    } else if (LvlPg == 16) {
        Slot1 = 4;
        Slot2 = 3;
        Slot3 = 3;
        Slot4 = 3;
        Slot5 = 2;
        Slot6 = 1;
        Slot7 = 1;
        Slot8 = 1;
    } else if (LvlPg == 17) {
        Slot1 = 4;
        Slot2 = 3;
        Slot3 = 3;
        Slot4 = 3;
        Slot5 = 2;
        Slot6 = 1;
        Slot7 = 1;
        Slot8 = 1;
        Slot9 = 1;
    } else if (LvlPg == 18) {
        Slot1 = 4;
        Slot2 = 3;
        Slot3 = 3;
        Slot4 = 3;
        Slot5 = 3;
        Slot6 = 1;
        Slot7 = 1;
        Slot8 = 1;
        Slot9 = 1;
    } else if (LvlPg == 19) {
        Slot1 = 4;
        Slot2 = 3;
        Slot3 = 3;
        Slot4 = 3;
        Slot5 = 3;
        Slot6 = 2;
        Slot7 = 1;
        Slot8 = 1;
        Slot9 = 1;
    } else if (LvlPg > 19) {
        Slot1 = 4;
        Slot2 = 3;
        Slot3 = 3;
        Slot4 = 3;
        Slot5 = 3;
        Slot6 = 2;
        Slot7 = 2;
        Slot8 = 1;
        Slot9 = 1;
    }

    SlotIncantesimi risultato
        = SlotIncantesimi(Slot1, Slot2, Slot3, Slot4, Slot5, Slot6, Slot7, Slot8, Slot9);
    return risultato;
}

std::string Mago::getCaratteristicaIncantatore() const
{
    return "Saggezza";
}

int Mago::getCDTiroSalvezzaIncantesimo() const
{
    return 8 + getBonusCompetenza() + getModificatoreIntelligenza();
}

int Mago::getModificatoreAttaccoIncantesimo() const
{
    return getBonusCompetenza() + getModificatoreIntelligenza();
}

void Mago::setCompetenzeBaseTiriSalvezza()
{
    setCompetenzaIntelligenza(true);
    setCompetenzaSaggezza(true);
}

bool Mago::operator==(const Mago &x) const
{
    return Incantatore::operator==(x);
}

bool Mago::operator!=(const Mago &x) const
{
    return Incantatore::operator!=(x);
}
