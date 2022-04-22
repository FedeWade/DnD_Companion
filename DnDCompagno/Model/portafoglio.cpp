#include "portafoglio.h"

Portafoglio::Portafoglio() : Rame(0), Argento(0), Electrum(0), Oro(15), Platino(0) {}

Portafoglio::Portafoglio(int oro) : Rame(0), Argento(0), Electrum(0), Oro(oro), Platino(0) {}

Portafoglio::Portafoglio(int rame, int argento, int electrum, int oro, int platino)
    : Rame(rame), Argento(argento), Electrum(electrum), Oro(oro), Platino(platino)
{}

int Portafoglio::getRame() const
{
    return Rame;
}

int Portafoglio::getArgento() const
{
    return Argento;
}

int Portafoglio::getElectrum() const
{
    return Electrum;
}

int Portafoglio::getOro() const
{
    return Oro;
}

int Portafoglio::getPlatino() const
{
    return Platino;
}

void Portafoglio::setRame(int newValue)
{
    newValue < 0 ? Rame = 0 : Rame = newValue;
}

void Portafoglio::setArgento(int newValue)
{
    newValue < 0 ? Argento = 0 : Argento = newValue;
}

void Portafoglio::setElectrum(int newValue)
{
    newValue < 0 ? Electrum = 0 : Electrum = newValue;
}

void Portafoglio::setOro(int newValue)
{
    newValue < 0 ? Oro = 0 : Oro = newValue;
}

void Portafoglio::setPlatino(int newValue)
{
    newValue < 0 ? Platino = 0 : Platino = newValue;
}

bool Portafoglio::operator==(const Portafoglio &x) const
{
    return Rame == x.Rame && Argento == x.Argento && Electrum == x.Electrum && Oro == x.Oro
           && Platino == x.Platino;
}

bool Portafoglio::operator!=(const Portafoglio &x) const
{
    return !(*this == x);
}
