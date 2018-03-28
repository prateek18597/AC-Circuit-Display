#ifndef NET_H
#define NET_H

#include "NetworkS.h"
#include "NetworkC.h"
class Net
{
	private:
		NetworkS S[100];
		NetworkC C[100];
		int sCount=0;
		int cCount=0;
	public:
		void addComp(Component c)
		{
			C[cCount].setComponent(c);
			C[cCount].setConnectedNet(c.getFinalNet());
			cCount++;

		}
		void addSour(Source s)
		{
			S[sCount].setSource(s);
			S[sCount].setConnectedNet(s.getFinalNet());
			sCount++;
		}
		int getSourceCount()
		{
			return sCount;
		}
		int getComponentCount()
		{
			return cCount;
		}
		NetworkS getSource(int i)
		{
			return S[i];
		}
		NetworkC getComponent(int i)
		{
			return C[i];
		}
};
#endif