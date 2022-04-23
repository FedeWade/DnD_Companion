#ifndef PGCREATIONDIALOG_H
#define PGCREATIONDIALOG_H

#include "Model/modello.h"
#include <QComboBox>
#include <QDialog>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QSpinBox>
#include <QVBoxLayout>

class PGCreationDialog : public QDialog
{
    Q_OBJECT
public:
    PGCreationDialog(QWidget *parent = nullptr, Modello *model = nullptr);
    void update();
public slots:
    void createClicked();
signals:
    void PGCreated();

private:
    Modello *Model;

    QSpinBox *Esperienza;
    QComboBox *Razza;
    QSpinBox *Forza;
    QSpinBox *Destrezza;
    QSpinBox *Costituzione;
    QSpinBox *Intelligenza;
    QSpinBox *Saggezza;
    QSpinBox *Carisma;
    QLineEdit *Nome;
    QComboBox *Allineamento;
    QComboBox *Classe;

    QPushButton *Delete;
    QPushButton *Create;

    void popolateRazza();
    void popolateAllineamento();
    void popolateClasse();

    void setStyle();
};

#endif // PGCREATIONDIALOG_H
