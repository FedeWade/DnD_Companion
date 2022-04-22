#ifndef STAT_H
#define STAT_H

#include "Model/modello.h"
#include <QGroupBox>
#include <QLabel>
#include <QLineEdit>
#include <QSpinBox>
#include <QVBoxLayout>
#include <QWidget>

class Stat : public QWidget
{
    Q_OBJECT
public:
    Stat(QWidget *parent = nullptr, Modello *m = nullptr, const std::string &name = "noname");
    QSpinBox *Valore;
    QSpinBox *Modificatore;

    void update();
    void makeEditable();
    void makeUneditable();
    void setStyle();

private:
    Modello *Model;
    std::string Caratteristica;

signals:
};

#endif // STAT_H
