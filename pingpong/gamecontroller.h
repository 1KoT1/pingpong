#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include <QObject>

class GameScene;

class GameController: QObject
{
	Q_OBJECT
public:
	GameController(GameScene *gameScene);

	/** Переместить ракетки влево.*/
	void racketsGoToLeft();
	/** Переместить ракетки вправо.*/
	void racketsGoToRight();
private:
	GameScene *m_gameScene;

	void moveRackets(double step);
};

#endif // GAMECONTROLLER_H
