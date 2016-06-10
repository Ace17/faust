//-----------------------------------------------------
//
// Code generated with Faust 0.9.70 (http://faust.grame.fr)
//-----------------------------------------------------
#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif  

typedef long double quad;
/* link with  */

#ifndef FAUSTCLASS 
#define FAUSTCLASS mydsp
#endif

class mydsp : public dsp {
  private:
  public:
	static void metadata(Meta* m) 	{ 
	}

	virtual int getNumInputs() 	{ return 5; }
	virtual int getNumOutputs() 	{ return 5; }
	static void classInit(int samplingFreq) {
	}
	virtual void instanceInit(int samplingFreq) {
		fSamplingFreq = samplingFreq;
	}
	virtual void init(int samplingFreq) {
		classInit(samplingFreq);
		instanceInit(samplingFreq);
	}
	virtual void buildUserInterface(UI* interface) {
		interface->openVerticalBox("0x00");
		interface->closeBox();
	}
	virtual void compute (int count, FAUSTFLOAT** input, FAUSTFLOAT** output) {
		FAUSTFLOAT* input0 = input[0];
		FAUSTFLOAT* input1 = input[1];
		FAUSTFLOAT* input2 = input[2];
		FAUSTFLOAT* input3 = input[3];
		FAUSTFLOAT* input4 = input[4];
		FAUSTFLOAT* output0 = output[0];
		FAUSTFLOAT* output1 = output[1];
		FAUSTFLOAT* output2 = output[2];
		FAUSTFLOAT* output3 = output[3];
		FAUSTFLOAT* output4 = output[4];
		for (int i=0; i<count; i++) {
			float fTemp0 = (float)input1[i];
			float fTemp1 = (float)input0[i];
			float fTemp2 = (float)input2[i];
			output0[i] = (FAUSTFLOAT)(fTemp2 + (fTemp1 + fTemp0));
			float fTemp3 = (float)input3[i];
			float fTemp4 = (2 * ((fTemp2 + (fTemp1 + (0.5f * fTemp0))) + (0.5f * fTemp3)));
			output1[i] = (FAUSTFLOAT)fTemp4;
			float fTemp5 = ((float)input4[i] + (fTemp3 + (fTemp1 + fTemp2)));
			float fTemp6 = (fTemp4 + fTemp5);
			output2[i] = (FAUSTFLOAT)fTemp6;
			output3[i] = (FAUSTFLOAT)fTemp6;
			output4[i] = (FAUSTFLOAT)fTemp5;
		}
	}
};


