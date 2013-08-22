#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include <QObject>

class GameScene;

class GameController: public QObject
{
	Q_OBJECT
public:
	GameController(GameScene *gameScene, QObject *parent = 0);

	/** Переместить ракетки влево.*/
	Q_INVOKABLE void racketsGoToLeft();
	/** Переместить ракетки вправо.*/
	Q_INVOKABLE void racketsGoToRight();

public slots:
	void tick();
private:
	GameScene *m_gameScene;

	void moveRackets(double step);
};

#endif // GAMECONTROLLER_H
