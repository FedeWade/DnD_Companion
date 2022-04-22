#include "slotincantesimi.h"

SlotIncantesimi::SlotIncantesimi(int lvl1,
                                 int lvl2,
                                 int lvl3,
                                 int lvl4,
                                 int lvl5,
                                 int lvl6,
                                 int lvl7,
                                 int lvl8,
                                 int lvl9)
{
    Slots.push_back(lvl1);
    Slots.push_back(lvl2);
    Slots.push_back(lvl3);
    Slots.push_back(lvl4);
    Slots.push_back(lvl5);
    Slots.push_back(lvl6);
    Slots.push_back(lvl7);
    Slots.push_back(lvl8);
    Slots.push_back(lvl9);
}

int SlotIncantesimi::getSlotIncantesimi(unsigned int lvl) const
{
    if (Slots.size() > lvl - 1)
        return Slots[lvl - 1];
    throw new std::runtime_error("Errore: Slot incantesimo non valido.");
}

void SlotIncantesimi::setSlotIncantesimi(unsigned int lvl, int newvalue)
{
    if (Slots.size() > lvl - 1) {
        Slots[lvl - 1] = newvalue;
        return;
    }
    throw new std::runtime_error("Errore: Slot incantesimo non valido.");
}

bool SlotIncantesimi::operator==(const SlotIncantesimi &x) const
{
    return Slots == x.Slots;
}

bool SlotIncantesimi::operator!=(const SlotIncantesimi &x) const
{
    return !(*this == x);
}
