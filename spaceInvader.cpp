#include "spaceInvader.h"
#include "ui_spaceInvader.h"
#include <iostream>
#include <QTimer>
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QString>


using namespace std;
spaceInvader::spaceInvader(QWidget *parent) :
    QDialog(parent),
    m_ship(),
    m_weapon(){

    //create a spaceship and bullet object

    //read in the initial x coordinate value
    //and ship size from the cnofig file
    int shipWidth = 120;
    int shipHeight = 40;
    QString initialxCoordinate;

    QFile configFile(":/textFile/config.txt");
    if(configFile.open(QIODevice::ReadOnly)){
       QTextStream in(&configFile);
       while(!in.atEnd()){
           QString line = in.readLine();

           //save x coordinate value to startxCoordinate
           if(line == "[coordinate]"){
               initialxCoordinate = in.readLine();
               //THIS IS JUST A TEST -- print out the initial x coordinate
               //value
           }

           if(line == "[size]"){
               QString shipSize = in.readLine();
               if(shipSize == "tiny"){
                   shipWidth = 90;
                   shipHeight = 30;
               }
               if(shipSize == "normal"){
                   shipWidth = 120;
                   shipHeight = 40;
               }
               if(shipSize == "large"){
                   shipWidth = 140;
                   shipHeight = 50;
               }
               if(shipSize == "giant"){
                   shipWidth = 170;
                   shipHeight = 60;
               }
           }
       }
       configFile.close();
    }else{
       cout << "File is not found or cannot be opened!" << endl;
    }


    string startxCoordinate = initialxCoordinate.toStdString();
    cout << "value of initialxCoordinate is " << startxCoordinate << endl;
    QPixmap temporary_shipImage;
    temporary_shipImage.load(":/images/defender.png");
    int maxX = this->width() - temporary_shipImage.width();
    //construct the spaceship object and its image
    spaceShip ship(initialxCoordinate.toInt(),350,3,maxX,
                   shipWidth,shipHeight);

    //test the values of the ship that was just created
    cout << "ship's initialxCoordinate is" << ship.getNewxCoordinate() << endl;
    cout << "ship's initialyCoordinate is" << ship.getNewyCoordinate() << endl;
    cout << "ship's speed is" << ship.getMovementSpeed()<< endl;
    cout << "ship's shipWidth is" << shipWidth << endl;
    cout << "ship's shipHeight is" << shipHeight<< endl;
    cout << "ship's maxX is" << ship.getMaxX()<< endl;


    weapon bullet(-1000,-1000,10,ship.getNewxCoordinate(),
                  ship.getNewyCoordinate(),ship.getSpaceShipImage());

    //assign the spaceship and weapon objects to member variables
    m_ship = ship;
    m_weapon = bullet;

    setStyleSheet("background-color: #112233;");
    this->resize(600,420);
    update();
    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(nextFrame()));
    timer->start(33);
}

spaceInvader::~spaceInvader()
{
}

//the paintEvent method to paint objects on the screen
void spaceInvader::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    painter.drawPixmap(m_ship.getNewxCoordinate(),
                       m_ship.getNewyCoordinate(),
                       m_ship.getSpaceShipImage());
    painter.drawPixmap(m_weapon.getNewxCoordinate(),
                       m_weapon.getNewyCoordinate(),
                       m_weapon.getWeaponImage());
}

void spaceInvader::nextFrame(){


    //negative for left movement, positive number for movement to the right
    QString readLine;
    int direction;
    bool isCommandFound = false;

    QFile configFile(":/textFile/config.txt");


    //search for the commands in the config file
    if(isCommandFound == false){
        if(configFile.open(QIODevice::ReadOnly)){
           QTextStream in(&configFile);
           while(in.readLine() != "[commands]"){
               QString line = in.readLine();
           }
           isCommandFound = true;
        }else{
            cout << "Cannot open the file!!" << endl;
        }
    }


    QTextStream in(&configFile);
    if(in.readLine() == "left"){
        direction = -1;
    }else if(in.readLine() == "right"){
        direction = 1;
    }

    m_ship.setMovementDirection(direction);

    //animate the spaceship
    m_ship.nextFrame();

    //animate the weapon
    m_weapon.nextFrame();


}


