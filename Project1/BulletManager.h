#ifndef  BULLETMANAGER_H
#define BULLETMANAGER_H
#include<vector>
#include"Bullet.h"
#include"Player.h"
class BulletManager
{
private:
	std::vector<Bullet*> MAX_BULLETS;
	static BulletManager* instance;
public:

	BulletManager();
	virtual ~BulletManager();
	static BulletManager* getInstance();
	void recieveBulletList(std::vector<Bullet*> bullets);
	std::vector<Bullet*> sendBulletList();
	void bulletCalculations(float aimDirAngle);
	void bulletmangerUpdate();
	
};
#endif //BULLETMANAGER_H

