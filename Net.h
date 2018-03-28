#ifndef NET_H
#define NET_H
	 
class Net
{
	private:
		Source S[100];
		Component C[100];
		int sCount=0;
		int cCount=0;
	public:
		void addComp(Component c)
		{
			C[cCount]=(c);
			// C[cCount].setConnectedNet(c.getFinalNet());
			cCount++;

		}
		void addSour(Source s)
		{
			S[sCount]=(s);
			// S[sCount].setConnectedNet(s.getFinalNet());
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
		Source getSource(int i)
		{
			return S[i];
		}
		Component getComponent(int i)
		{
			return C[i];
		}
};
#endif