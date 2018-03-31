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
			cCount++;

		}
		void addSour(Source s)
		{
			S[sCount]=(s);
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