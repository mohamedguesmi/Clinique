#include "patient.h"
#include<QSqlQuery>
#include<QString>
#include<QVariant>

patient::patient()
{
    cin=0;
    tel=00;
    nom="";
    prenom="";
}

patient::patient(long cin,long tel,QString nom,QString prenom)
{
this->cin=cin;
this->tel=tel;
this->nom=nom;
this->prenom=prenom;
}

bool patient::ajouter()
{
    QSqlQuery query;
    QString res=QString::number(cin);
    QString res1=QString::number(tel);
          query.prepare("INSERT INTO patient (cin,tel, nom, prenom) "
                        "VALUES (:cin, :tel, :nom, :prenom)");
          query.bindValue(":cin", res);
          query.bindValue(":tel", res1);
          query.bindValue(":nom", nom);
          query.bindValue(":prenom", prenom);

          return  query.exec();
}

QSqlQueryModel * patient::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from patient");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Cin"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Telephone"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Prénom"));
    return model;
}

bool patient::supprimer(long cin)
{
QSqlQuery query;
QString res= QString::number(cin);
query.prepare("Delete from patient where cin = :cin ");
query.bindValue(":cin", res);
return    query.exec();
}


bool patient::modifier(long cin,long tel,QString nom,QString prenom){
    QSqlQuery query;
    QString res=QString::number(cin);
    QString res1=QString::number(tel);
    query.prepare("update patient set tel=:tel ,nom=:nom ,prenom=:prenom  where cin = :cin");
    query.bindValue(":cin", res);
    query.bindValue(":tel", res1);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    return query.exec();
}

bool patient::rech(long cin){
    QSqlQuery query;
    QString res=QString::number(cin);
    QString res1=QString::number(tel);
    query.prepare("select * from patient where cin = :cin");
    query.bindValue(":cin", res);
    query.bindValue(":tel", res1);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);

    return query.exec();
}

QSqlQueryModel * patient::afficherpatientchercher(long cin)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QString res=QString::number(cin);
    model->setQuery("select * from patient where Cin= :cin");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Cin"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Telephone"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Nom "));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Prénom"));
    return model;
}

QSqlQueryModel * patient::trier_cin()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from patient ORDER BY Cin");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Cin"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Telephone"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Nom "));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Prénom"));
        return model;
}


QSqlQueryModel * patient::patient_convention()
{

    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from patient JOIN convention ON patient.cin = convention.cin");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Cin"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Telephone"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Nom "));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Prénom"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Code"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("Cin"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("Date_Creation"));
        return model;
}


