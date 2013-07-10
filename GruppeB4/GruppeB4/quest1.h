#pragma once
class quest1
{
private:
	quest1(){};
	~quest1(){};
	bool questanfang;
	bool questfertig;
public:
	static quest1 & get_quest1()
	{
		static quest1 Instance;
		return Instance;
	}
	

	void set_questfertig();

};

