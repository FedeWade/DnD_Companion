#include "incantatore.h"

Incantatore::Incantatore(const std::string &nome, Allineamenti allineamento)
    : Personaggio(nome, allineamento), IncantesimiExtra(SlotIncantesimi())
{}

std::string Incantatore::getDescIncantesimi() const
{
    return DescIncatesimi;
}

void Incantatore::setDescIncantesimi(const std::string &newincantesimi)
{
    DescIncatesimi = newincantesimi;
}

int Incantatore::getSlotIncantesimo(unsigned lvl) const
{
    SlotIncantesimi suggested = suggestedSlotIncantesimi();
    return suggested.getSlotIncantesimi(lvl) + IncantesimiExtra.getSlotIncantesimi(lvl);
}

void Incantatore::setSlotIncantesimo(unsigned lvl, int value)
{
    SlotIncantesimi suggested = suggestedSlotIncantesimi();
    IncantesimiExtra.setSlotIncantesimi(lvl, value - suggested.getSlotIncantesimi(lvl));
}

bool Incantatore::operator==(const Incantatore &x) const
{
    return Personaggio::operator==(x) && IncantesimiExtra == x.IncantesimiExtra
           && DescIncatesimi == x.DescIncatesimi;
}

bool Incantatore::operator!=(const Incantatore &x) const
{
    return !(*this == x);
}
