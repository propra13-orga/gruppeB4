#ifndef COLLISIOBALOBJECTMANAGER_H_
#define COLLISIOBALOBJECTMANAGER_H_


class S_CollisibalObjectManager
{
private:
	S_CollisibalObjectManager(){}
	~S_CollisibalObjectManager(){}
	S_CollisibalObjectManager(const S_CollisibalObjectManager &){}
public:
	static S_CollisibalObjectManager & get_CManager(){S_CollisibalObjectManager Instance;return Instance;}

};


#endif