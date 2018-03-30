#include<string.h>
class Component
{
	private:

		int position;
		char type;
		int cNum;
		int init_net;
		int f_net;
		float value;
		char* val;

	public:

		int getPosition()
		{
			return position;
		}

		void setPosition(int pos)
		{
			position=pos;
		}

		void input(char t,int c,int i,int f,float v)
		{
			type=t;
			cNum=c;
			init_net=i;
			f_net=f;
			value=v;
		}

		char getType()
		{
			return type;
		}

		int getNum()
		{
			return cNum;
		}

		int getInitialNet()
		{
			return init_net;
		}

		int getFinalNet()
		{
			return f_net;
		}

		float getVal()
		{
			return value;
		}

		char* getStrValue()
		{
			return val;
		}

		void setStrValue(char* s)
		{
			val=s;
		}

		char setType(char t)
		{
			type=t;
		}

		int setNum(int t)
		{
			cNum=t;
		}

		int setInitialNet(int t)
		{
			init_net=t;
		}

		int setFinalNet(int t)
		{
			f_net=t;
		}

		float setVal(float t)
		{
			value=t;
		}

		void clear()
		{
			type=NULL;
			cNum=NULL;
			init_net=NULL;
			f_net=NULL;
			value=NULL;
		}
};
