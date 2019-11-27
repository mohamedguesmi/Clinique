#ifndef PATIENT_H
#define PATIENT_H
#include<QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class patient
{
    long cin,tel;
        QString nom,prenom;

public:
    patient();
    patient(long,long,QString,QString);
    long getcin(){return cin;}
    void setcin(long cin){this->cin=cin;}
    void settel(long tel){this->tel=tel;}
    void setnom(QString nom){this->nom=nom;}
    void setprenom(QString prenom){this->prenom=prenom;}
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(long);
    bool rech(long);
        bool modifier(long,long,QString,QString);
        QSqlQueryModel * afficherpatientchercher(long);
        QSqlQueryModel * afficher_patient_ch(int);

        QSqlQueryModel * trier_cin();
        QSqlQueryModel * patient_convention();

    ~patient(){}


};

#endif // PATIENT_H
