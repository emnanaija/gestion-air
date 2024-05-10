#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test1=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("gestionv");
db.setUserName("dali");//inserer nom de l'utilisateur
db.setPassword("dali");//inserer mot de passe de cet utilisateur

if (db.open())
test1=true;





    return  test1;
}
