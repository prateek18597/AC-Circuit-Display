#ifndef NETWORKC_H
#define NETWORKC_H
#include "Start.h"
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
			return connectedNet;
		}

		Component getComponent()
		{
			return c;
		}

};
#endif