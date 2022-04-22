#ifndef PGSELECTIONBOX_H
#define PGSELECTIONBOX_H

#include "Model/modello.h"
#include "View/pgcreationdialog.h"
#include "exceptionmessage.h"
#include <QComboBox>
#include <QDialog>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include <QGraphicsColorizeEffect>
#include <QPropertyAnimation>
#include <QListView>

class PGSelectionBox : public QWidget
{
    Q_OBJECT
public:
    PGSelectionBox(QWidget *parent = nullptr, Modello *model = nullptr);
    void update();

public slots:
    void loadClicked();
    void deleteClicked();
    void updatePGs();
    void showCreationDialog();
    void showDeleteDialog();

private:
    Modello *Model;
    QPushButton *Create;
    QComboBox *ComboPG;
    QPushButton *Load;
    QPushButton *Delete;

    PGCreationDialog *CreationDialog;
    QMessageBox * DeleteDialog;
    void setStyle();

    QPropertyAnimation *CreateAnimation;

signals:
    void pgChanged();
};

#endif // PGSELECTIONBOX_H
