#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "patient.h"
#include "convention.h"
#include <QMessageBox>
#include<QDate>
#include<QDateEdit>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    ui->le_nom->setInputMask("aaaaaaaaaaaaaaaaa");
    ui->le_nom_2->setInputMask("aaaaaaaaaaaaaaaaa");
    ui->le_prenom->setInputMask("aaaaaaaaaaaaaaaa");
    ui->le_prenom_2->setInputMask("aaaaaaaaaaaaaaaaa");
    ui->le_code_2->setValidator( new QIntValidator(0, 999999999, this) );
    ui->le_code_->setValidator( new QIntValidator(0, 999999999, this) );
    ui->ancien_code->setValidator( new QIntValidator(0, 999999999, this) );
    ui->le_cin->setValidator( new QIntValidator(0, 99999999, this) );
    ui->le_cin_c_2->setValidator( new QIntValidator(0, 99999999, this) );
    ui->le_telephone->setValidator( new QIntValidator(0, 99999999, this) );
    ui->le_telephone_2->setValidator( new QIntValidator(0, 99999999, this) );
    ui->le_cin_5->setValidator( new QIntValidator(0, 99999999, this) );
    ui->ancien_cin->setValidator( new QIntValidator(0, 99999999, this) );
    ui->tabpatient->setModel(tmppatient.afficher());
    ui->tabconvention->setModel(tmpconvention.afficher_convention());
    ui->tabpatienttrier->setModel(tmppatient.afficher());
    ui->tabpatient_convention->setModel(tmppatient.patient_convention());
    ui->tabconventiontrier->setModel(tmpconvention.afficher_convention());
    ui->tabrechconvention->setModel(tmpconvention.afficher_convention());


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_ajouterpatient_clicked()
{

    long cin = ui->le_cin->text().toLong();
    long tel = ui->le_telephone->text().toLong();
    QString nom= ui->le_nom->text();
    QString prenom= ui->le_prenom->text();
  patient c(cin,tel,nom,prenom);
  bool test=c.ajouter();
  if(test)
{ui->tabpatient->setModel(tmppatient.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un patient"),
                  QObject::tr("patient ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un patient"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}


void MainWindow::on_supprimerpatient_clicked()
{
    long cin=ui->le_cin_5->text().toLong();
    bool test=tmppatient.supprimer(cin);
    if(test)
    {ui->tabpatient->setModel(tmppatient.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un patient"),
                    QObject::tr("patient supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un patient"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_ajouterconvention_clicked()
{
    long code = ui->le_code_2->text().toInt();
    int cin = ui->le_cin_c_2->text().toInt();

    QDate date_creation= ui->le_date_2->date();
  convention ct(code,cin,date_creation);
  bool test=ct.ajouter_convention();
  if(test)
{ui->tabconvention->setModel(tmpconvention.afficher_convention());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter une convention"),
                  QObject::tr("convention ajoutée.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter une convention"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_supprimerconvention_clicked()
{
    long code=ui->le_code_->text().toInt();

    bool test=tmpconvention.supprimer_convention(code);
    if(test)
    {ui->tabconvention->setModel(tmpconvention.afficher_convention());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer une convention"),
                    QObject::tr("convention supprimée.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer une convention"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}



void MainWindow::on_modifierpatient_clicked()
{
    long cin=ui->ancien_cin->text().toInt();
        long tel = ui->le_telephone_2->text().toLong();
        QString nom= ui->le_nom_2->text();
        QString prenom= ui->le_prenom_2->text();
        patient c1;

            if(c1.rech(cin)){
                bool test = c1.modifier(cin,tel,nom,prenom);
                if(test){
                    ui->tabpatient->setModel(tmppatient.afficher());
                    QMessageBox::information(nullptr, QObject::tr("Modifier un patient"),
                                QObject::tr("patient modifié.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
                }
                else
                    QMessageBox::critical(nullptr, QObject::tr("Modifier un patient"),
                                QObject::tr("Erreur !.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
            }

}

void MainWindow::on_modifierconvention_clicked()
{
    int code=ui->ancien_code->text().toInt();
    QDate date_creation= ui->le_date->date();

        convention ct;

            if(ct.rech(code)){
                bool test = ct.modifier(code,date_creation);
                if(test){
                    ui->tabconvention->setModel(tmpconvention.afficher_convention());
                    QMessageBox::information(nullptr, QObject::tr("Modifier une convention"),
                                QObject::tr("convention modifiée.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
                }
                else
                    QMessageBox::critical(nullptr, QObject::tr("Modifier une convention"),
                                QObject::tr("Erreur !.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
            }
}
void MainWindow::on_trierpatient_clicked()
{
    bool test=true;
        if(test){
                   if(ui->cin->isChecked())
               { ui->tabpatienttrier->setModel(tmppatient.trier_cin());
                QMessageBox::information(nullptr, QObject::tr("trier patient"),
                            QObject::tr("patient trier.\n"
                                        "Voulez-vous enregistrer les modifications ?"),
                                   QMessageBox::Save
                                   | QMessageBox::Cancel,
                                  QMessageBox::Save);
}

            }
            else
                QMessageBox::critical(nullptr, QObject::tr("trier patient"),
                            QObject::tr("Erreur !.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_trierconvention_clicked()
{
    bool test=true;

        if(test){
                if(ui->code->isChecked())
                {ui->tabconventiontrier->setModel(tmpconvention.trierconvention_code());
                QMessageBox::information(nullptr, QObject::tr("trier convention"),
                            QObject::tr("convention triée.\n"
                                        "Voulez-vous enregistrer les modifications ?"),
                                   QMessageBox::Save
                                   | QMessageBox::Cancel,
                                  QMessageBox::Save);}



}}

void MainWindow::on_cherch_code_textChanged(const QString &arg1)
{
    long code=ui->cherch_code->text().toLong();
    ui->tabrechconvention->setModel(tmpconvention.Rechercher(code));
}



