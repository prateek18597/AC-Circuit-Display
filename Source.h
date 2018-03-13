class Source
{
	private:
		char type;
		int num;
		int initialNet;
		int finalNet;
		float DCO;
		float ampli;
		float freq;
		char* strFreq;
		char* strDelay;
		float delay;
		float damp;
	public:
		
		char getType()
		{
			return type;
		}

		int getNum()
		{
			return num;
		}

		int getInitialNet()
		{
			return initialNet;
		}

		int getFinalNet()
		{
			return finalNet;
		}

		float getDCO()
		{
			return DCO;
		}

		float getAmpli()
		{
			return ampli;
		}

		float getDelay()
		{
			return delay;
		}

		float getFreq()
		{
			return freq;
		}

		float getDamp()
		{
			return damp;
		}

		void setType(char a)
		{
			type=a;
		}

		void setNum(int n)
		{
			num=n;
		}

		void setInitialNet(int n)
		{
			initialNet=n;
		}

		void setFinalNet(int f)
		{
			finalNet=f;
		}

		void setDamp(float d)
		{
			damp=d;
		}

		void setAmpli(float a)
		{
			ampli=a;
		}

		void setFreq(float f)
		{
			freq=f;
		}

		void setDCO(float d)
		{
			DCO=d;
		}

		char* getStrFreq()
		{
			return strFreq;
		}

		void setStrFreq(char* s)
		{
			strFreq=s;
		}

		char* getStrDelay()
		{
			return strDelay;
		}

		void setStrDelay(char* s)
		{
			strDelay=s;
		}

		void setDelay(float d)
		{
			delay=d;
		}

		void clear()
		{
			type=NULL;
			num=NULL;
			initialNet=NULL;
			finalNet=NULL;
			DCO=NULL;
			delay=NULL;
			ampli=NULL;
			freq=NULL;
			damp=NULL;
		}
};
