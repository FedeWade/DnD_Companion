#include "View/baseinfo.h"

BaseInfo::BaseInfo(QWidget *parent, Modello *model) : QWidget(parent), Model(model)
{
    QVBoxLayout *mainlayout = new QVBoxLayout();

    QHBoxLayout *row1 = new QHBoxLayout();
    QHBoxLayout *row2 = new QHBoxLayout();
    QHBoxLayout *row3 = new QHBoxLayout();

    QVBoxLayout *nomelayout = new QVBoxLayout();
    QVBoxLayout *classelayout = new QVBoxLayout();
    QVBoxLayout *razzalayout = new QVBoxLayout();
    QVBoxLayout *allineamentolayout = new QVBoxLayout();

    Save = new QPushButton(this);
    Edit = new QPushButton(this);

    Nome = new QLabel(this);
    Classe = new QLabel(this);
    Razza = new QLabel(this);
    Livello = new QLabel(this);
    Esperienza = new QSpinBox(this);
    Allineamento = new QLabel(this);

    Nome->setObjectName("nome");
    Classe->setObjectName("classe");
    Razza->setObjectName("razza");
    Livello->setObjectName("livello");
    Esperienza->setObjectName("esperienza");
    Allineamento->setObjectName("allineamento");

    QLabel *nomelabel = new QLabel("Nome", this);
    QLabel *classelabel = new QLabel("Classe", this);
    QLabel *razzalabel = new QLabel("Razza", this);
    QLabel *allineamentolabel = new QLabel("Allineamento", this);
    QLabel *livellolabel = new QLabel("Lvl.", this);
    QLabel *esperienzalabel = new QLabel("Esperienza", this);

    nomelabel->setObjectName("nomel");
    classelabel->setObjectName("classel");
    allineamentolabel->setObjectName("allineamentol");
    razzalabel->setObjectName("razzal");

    nomelayout->addWidget(Nome);
    nomelayout->addWidget(nomelabel);
    classelayout->addWidget(Classe);
    classelayout->addWidget(classelabel);
    razzalayout->addWidget(Razza);
    razzalayout->addWidget(razzalabel);
    allineamentolayout->addWidget(Allineamento);
    allineamentolayout->addWidget(allineamentolabel);

    row1->addLayout(nomelayout);
    row1->addLayout(classelayout);
    row2->addLayout(razzalayout);
    row2->addLayout(allineamentolayout);

    //Esperienza
    QGroupBox *expgroup = new QGroupBox("Livello", this);
    QHBoxLayout *grouplayout = new QHBoxLayout();
    QHBoxLayout *lvllayout = new QHBoxLayout();
    QHBoxLayout *explayout = new QHBoxLayout();

    lvllayout->addWidget(livellolabel);
    lvllayout->addWidget(Livello);
    explayout->addWidget(esperienzalabel);
    explayout->addWidget(Esperienza);

    grouplayout->addLayout(lvllayout);
    grouplayout->addLayout(explayout);
    grouplayout->addWidget(Edit);
    grouplayout->addWidget(Save);

    expgroup->setLayout(grouplayout);

    row3->addWidget(expgroup);

    mainlayout->addLayout(row1);
    mainlayout->addLayout(row2);
    mainlayout->addLayout(row3);

    Esperienza->setReadOnly(true);

    Esperienza->setMaximum(999999);

    setLayout(mainlayout);

    //---Style---
    row1->setContentsMargins(0, 5, 0, 15);
    row2->setContentsMargins(0, 0, 0, 15);

    expgroup->setMinimumWidth(450);

    nomelayout->setSpacing(0);
    classelayout->setSpacing(0);
    razzalayout->setSpacing(0);
    allineamentolayout->setSpacing(0);

    nomelayout->setAlignment(Qt::AlignCenter);
    classelayout->setAlignment(Qt::AlignCenter);
    razzalayout->setAlignment(Qt::AlignCenter);
    allineamentolayout->setAlignment(Qt::AlignCenter);

    nomelabel->setAlignment(Qt::AlignCenter);
    classelabel->setAlignment(Qt::AlignCenter);
    razzalabel->setAlignment(Qt::AlignCenter);
    allineamentolabel->setAlignment(Qt::AlignCenter);
    livellolabel->setAlignment(Qt::AlignCenter);
    esperienzalabel->setAlignment(Qt::AlignCenter);

    expgroup->setAlignment(Qt::AlignCenter);

    explayout->setAlignment(Qt::AlignHCenter);
    lvllayout->setAlignment(Qt::AlignHCenter);
    lvllayout->setSpacing(8);
    explayout->setSpacing(6);

    setStyle();
    setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    //---End Style---

    connect(Save, SIGNAL(clicked()), this, SLOT(saveClicked()));
    connect(Edit, SIGNAL(clicked()), this, SLOT(editClicked()));
}

void BaseInfo::update()
{
    if (!Model->getSelectedPG()) {
        Edit->setEnabled(false);
        Nome->setText("");
        Classe->setText("");
        Razza->setText("");
        Livello->setText("0");
        Esperienza->setValue(0);
        Allineamento->setText("");
    } else {
        Edit->setEnabled(true);
        Nome->setText(QString::fromStdString(Model->getSelectedPG()->getNome()));
        Classe->setText(QString::fromStdString(Model->getSelectedPG()->getClasse()));
        Razza->setText(QString::fromStdString(Model->getSelectedPG()->getRazza()));
        Livello->setText(QString::number(Model->getSelectedPG()->getLivello()));
        Esperienza->setValue(Model->getSelectedPG()->getEsperienza());
        Allineamento->setText(QString::fromStdString(Model->getSelectedPG()->getAllineamento()));
    }
}

void BaseInfo::editClicked()
{
    Edit->setVisible(false);
    Save->setVisible(true);

    Esperienza->setReadOnly(false);
}

void BaseInfo::saveClicked()
{
    Save->setVisible(false);
    Edit->setVisible(true);

    Esperienza->setReadOnly(true);

    (Model->getSelectedPG())->setEsperienza(Esperienza->value());
    emit(valuesChanged());
}

void BaseInfo::setStyle()
{
    Edit->setIcon(QIcon(QPixmap(":/Resources/Edit.svg")));
    Save->setIcon(QIcon(QPixmap(":/Resources/Save.svg")));

    Edit->setFixedSize(32, 32);
    Save->setFixedSize(32, 32);
    Save->setVisible(false);

    Nome->setAlignment(Qt::AlignCenter);
    Classe->setAlignment(Qt::AlignCenter);
    Razza->setAlignment(Qt::AlignCenter);
    Allineamento->setAlignment(Qt::AlignCenter);
    Livello->setAlignment(Qt::AlignCenter);
    Esperienza->setAlignment(Qt::AlignCenter);

    Esperienza->setFixedSize(100, 35);
    Esperienza->setButtonSymbols(QAbstractSpinBox::NoButtons);

    setStyleSheet(" #nome { font-size:25px; color: #15DB95; font-weight:bold;} "
                  " #classel, #razzal, #allineamentol, #nomel { font-size: 15px;} "
                  " #classe, #razza, #allineamento { font-size:25px; }"
                  " #livello { font-size: 55px; color:#15DB95; }"
                  " #esperienza {font-size: 22px; }"
                  " QLabel { font-size: 20px; }");
}
