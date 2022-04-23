#ifndef PERSONAGGIO_H
#define PERSONAGGIO_H
#include "listaabilita.h"
#include "portafoglio.h"
#include "tirisalvezza.h"
#include <limits>
#include <tgmath.h>

enum Classi { barbaro, chierico, guerriero, mago };
enum Allineamenti {
    LegaleBuono,
    NeutraleBuono,
    CaoticoBuono,
    LegaleNeutrale,
    Neutrale,
    CaoticoNeutrale,
    LegaleMalvagio,
    NeutraleMalvagio,
    CaoticoMalvagio
};

class Personaggio : public ListaAbilita, public TiriSalvezza
{
public:
    Personaggio(const std::string &, Allineamenti);

    Portafoglio Inventario;

    virtual Personaggio *clone() const = 0;

    std::string getNome() const;
    Allineamenti getIndiceAllineamento() const;
    std::string getAllineamento() const;

    //----descrizione, TrattiPrivilegi, inventario
    std::string getDescrizione() const;
    void setDescrizione(const std::string &);
    std::string getTrattiPrivilegi() const;
    void setTrattiPrivilegi(const std::string &);
    std::string getDescInventario() const;
    void setDescInventario(const std::string &);

    //----Ispirazione
    virtual int getIspirazione() const;
    virtual void setIspirazione(int);

    //----ClasseArmatura
    virtual int getClasseArmatura() const;
    virtual void setClasseArmatura(int);

    //----BonusIniziativa
    virtual int getBonusIniziativa() const;
    virtual void setBonusIniziativa(int);

    //----Velocita
    virtual double getVelocita() const;
    virtual void setVelocita(double);

    //----Punti vita massimi
    virtual int getPuntiVitaMassimi() const;
    virtual void setPuntiVitaMassimi(int);

    //----punti vita info
    virtual int getDadoVita() const = 0;

    //----punti vita
    int getPuntiVita() const;
    void resetPuntiVita();
    void setPuntiVita(int);

    void increasePuntiVita(int);
    void decreasePuntiVita(int);

    //----Classe, e metodi per inizializzare competenza
    virtual std::string getClasse() const = 0;
    virtual Classi getEnumClasse() const = 0;
    virtual void setCompetenzeBaseTiriSalvezza() = 0;

    virtual bool operator==(const Personaggio &x) const;
    virtual bool operator!=(const Personaggio &x) const;

    virtual ~Personaggio() = default;

private:
    std::string Nome;
    Allineamenti Allineamento;
    std::string Descrizione;
    std::string TrattiPrivilegi;
    std::string DescInventario;

    int Ispirazione;
    int ClasseArmaturaBase;
    int IniziativaBase;
    double Velocita;

    int PuntiVitaBase;
    int PuntiVita;

    int suggestedPuntiVitaMassimi() const;
    int getMediaDadoVita() const;

    double suggestedVelocita() const;
};

#endif // PERSONAGGIO_H
