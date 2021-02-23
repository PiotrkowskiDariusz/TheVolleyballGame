#include "Game.h"

Game::Game() {
    this->court = new Court(801, 414, true);
    QImage object = QImage((":/images/court.png"));
    QPixmap qPixMap = QPixmap::fromImage(object);
    qPixMap = qPixMap.scaled(this->court->getHeight(), this->court->getWidth());
    setBackgroundBrush(QBrush(qPixMap));

    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setWindowTitle(QT_TRANSLATE_NOOP(QGraphicsView, "Volleyball"));
    setFixedSize(this->court->getHeight(), this->court->getWidth());

    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, this->court->getHeight(), this->court->getWidth());
    setScene(scene);

    this->court->makeTeam("Polska", 1);
    this->court->makeTeam("Niemcy", 2);

    this->court->makeBall(400, 270, 20, 20);

    scene->addItem(score1);
    scene->addItem(score2);

    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(setObjectsOnScene()));
    timer->start(50);

}

void Game::buildObjects() {
    this->objects.append(new Object(this->court->getBall(), ":/images/object.png"));

    this->objects.append(new Object(this->court->getTeam1()->getPlayers()[0], ":/images/object.png"));
    this->objects.append(new Object(this->court->getTeam1()->getPlayers()[1], ":/images/object.png"));
    this->objects.append(new Object(this->court->getTeam1()->getPlayers()[2], ":/images/object.png"));
    this->objects.append(new Object(this->court->getTeam1()->getPlayers()[3], ":/images/object.png"));
    this->objects.append(new Object(this->court->getTeam1()->getPlayers()[4], ":/images/object.png"));
    this->objects.append(new Object(this->court->getTeam1()->getPlayers()[5], ":/images/object.png"));

    this->objects.append(new Object(this->court->getTeam2()->getPlayers()[0], ":/images/black.png"));
    this->objects.append(new Object(this->court->getTeam2()->getPlayers()[1], ":/images/black.png"));
    this->objects.append(new Object(this->court->getTeam2()->getPlayers()[2], ":/images/black.png"));
    this->objects.append(new Object(this->court->getTeam2()->getPlayers()[3], ":/images/black.png"));
    this->objects.append(new Object(this->court->getTeam2()->getPlayers()[4], ":/images/black.png"));
    this->objects.append(new Object(this->court->getTeam2()->getPlayers()[5], ":/images/black.png"));
}

void Game::setObjectsOnScene(){
    this->step();
    for (int i=0; i < objects.length(); i++)
        objects[i]->draw();
}

void Game::step() {
    for (int i=0; i < objects.length(); i++) {
        objects[i]->getLogicObject()->update();
    }

    scene->removeItem(score1);
    scene->removeItem(score2);
    QFont font("comic sans", 15);

    score1 = new QGraphicsTextItem((this->court->getTeam1()->getName()) + ": " + QString::number(this->court->getTeam1()->getPoints()));
    score1->setFont(font);
    score1->setPos(10, 10);
    scene->addItem(score1);

    score2 = new QGraphicsTextItem((this->court->getTeam2()->getName()) + ": " + QString::number(this->court->getTeam2()->getPoints()));
    score2->setFont(font);
    score2->setPos(700, 10);
    scene->addItem(score2);
}

