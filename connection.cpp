#include "connection.h"
#include <QDebug>
#include <QString>
#include <QSqlError>
Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("test2");
db.setUserName("mohamed");//inserer nom de l'utilisateur
db.setPassword("esprit19");//inserer mot de passe de cet utilisateur

if (db.open())

test=true;

else
throw QString("Erreur"+db.lastError().text());


    return  test;
}
