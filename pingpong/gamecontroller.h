#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

class GameScene;

class GameController
{
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
