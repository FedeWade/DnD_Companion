#ifndef BASEINFO_H
#define BASEINFO_H

#include "Model/modello.h"
#include <QComboBox>
#include <QGridLayout>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QMessageBox>
#include <QPushButton>
#include <QSpinBox>
#include <QVBoxLayout>
#include <QWidget>

class BaseInfo : public QWidget
{
    Q_OBJECT
public:
    BaseInfo(QWidget *parent = nullptr, Modello *model = nullptr);
    void update();
public slots:
    void editClicked();
    void saveClicked();
signals:
    void valuesChanged();

private:
    QPushButton *Save;
    QPushButton *Edit;

    Modello *Model;
    QLabel *Nome;
    QLabel *Classe;
    QLabel *Razza;
    QLabel *Livello;
    QSpinBox *Esperienza;
    QLabel *Allineamento;

    void popolateRazza();
    void popolateClasse();
    void popolateAllineamento();
    void setStyle();
};

#endif // BASEINFO_H
