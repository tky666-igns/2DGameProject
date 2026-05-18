#pragma once


class Trap
{
public:
	void Init();
	void Load();
	void Step();
	void Draw();
	void Exit();
private:
	int m_hndl;
	int m_size;
};
