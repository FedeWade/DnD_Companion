#ifndef SLOTINCANTESIMI_H
#define SLOTINCANTESIMI_H
#include <stdexcept>
#include <vector>

class SlotIncantesimi
{
public:
    SlotIncantesimi(int lvl1 = 0,
                    int lvl2 = 0,
                    int lvl3 = 0,
                    int lvl4 = 0,
                    int lvl5 = 0,
                    int lvl6 = 0,
                    int lvl7 = 0,
                    int lvl8 = 0,
                    int lvl9 = 0);

    int getSlotIncantesimi(unsigned int) const;
    void setSlotIncantesimi(unsigned int, int);

    bool operator==(const SlotIncantesimi &x) const;
    bool operator!=(const SlotIncantesimi &x) const;

private:
    std::vector<int> Slots;
};

#endif // SLOTINCANTESIMI_H
