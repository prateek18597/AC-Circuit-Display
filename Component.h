class Component
{
	private:

		char type;
		int cNum;
		int init_net;
		int f_net;
		float value;

	public:

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
};
