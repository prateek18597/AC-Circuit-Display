#ifndef NETWORKS_H
#define NETWORKS_H
#include "Start.h"
class NetworkS
{
	private:
	
		// Component c;
		Source s;
		int connectedNet;
		// char flag;
	
	public:
		
		// void setComponent(Component t)
		// {
		// 	c=t;
		// 	flag='c';
		// }

		void setSource(Source t)
		{
			s=t;
		}

		void setConnectedNet(int t)
		{
			connectedNet=t;
		}

		int getConnectedNet()
		{
			return connectedNet;
		}

		Source getSource()
		{
			return s;
		}

};
#endif