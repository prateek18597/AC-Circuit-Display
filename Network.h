#include<string.h>
#include<Source.h>
#include<Component.h>
class NetworkC
{
	private:
	
		Component c;
		// Source s;
		int connectedNet;
		// char flag;
	
	public:
		
		void setComponent(Component t)
		{
			c=t;
			flag='c';
		}

		// void setSource(Source t)
		// {
		// 	s=t;
		// 	flag='s';
		// }

		void setConnectedNet(int t)
		{
			connectedNet=t;
		}

		int getConnectedNet()
		{
			return t;
		}

		Component getComponent()
		{
			return c;
		}

};