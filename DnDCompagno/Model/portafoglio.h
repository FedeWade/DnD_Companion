#ifndef PORTAFOGLIO_H
#define PORTAFOGLIO_H

class Portafoglio
{
public:
    Portafoglio();
    Portafoglio(int);
    Portafoglio(int, int, int, int, int);

    int getRame() const;
    int getArgento() const;
    int getElectrum() const;
    int getOro() const;
    int getPlatino() const;

    void setRame(int);
    void setArgento(int);
    void setElectrum(int);
    void setOro(int);
    void setPlatino(int);

    bool operator==(const Portafoglio &x) const;
    bool operator!=(const Portafoglio &x) const;

private:
    int Rame;
    int Argento;
    int Electrum;
    int Oro;
    int Platino;
};

#endif // PORTAFOGLIO_H
