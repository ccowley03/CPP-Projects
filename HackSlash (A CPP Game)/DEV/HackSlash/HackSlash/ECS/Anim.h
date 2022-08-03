struct Anim
{
	int index;
	int frameNum;
	int speed;

	Anim()
	{

	}
	Anim(int i,int f, int s)
		:index(i),frameNum(f),speed(s)
	{}
};