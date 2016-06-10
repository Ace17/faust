//-----------------------------------------------------
// name: "panpot"
// version: "1.0"
// author: "Grame"
// license: "BSD"
// copyright: "(c)GRAME 2006"
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
	FAUSTFLOAT 	fentry0;
  public:
	static void metadata(Meta* m) 	{ 
		m->declare("name", "panpot");
		m->declare("version", "1.0");
		m->declare("author", "Grame");
		m->declare("license", "BSD");
		m->declare("copyright", "(c)GRAME 2006");
	}

	virtual int getNumInputs() 	{ return 1; }
	virtual int getNumOutputs() 	{ return 2; }
	static void classInit(int samplingFreq) {
	}
	virtual void instanceInit(int samplingFreq) {
		fSamplingFreq = samplingFreq;
		fentry0 = 0.0f;
	}
	virtual void init(int samplingFreq) {
		classInit(samplingFreq);
		instanceInit(samplingFreq);
	}
	virtual void buildUserInterface(UI* interface) {
		interface->openVerticalBox("0x00");
		interface->declare(&fentry0, "1", "");
		interface->declare(&fentry0, "style", "knob");
		interface->addNumEntry("pan", &fentry0, 0.0f, -9e+01f, 9e+01f, 1.0f);
		interface->closeBox();
	}
	virtual void compute (int count, FAUSTFLOAT** input, FAUSTFLOAT** output) {
		float 	fSlow0 = (0.005555555555555556f * (float(fentry0) - 9e+01f));
		float 	fSlow1 = sqrtf((0 - fSlow0));
		float 	fSlow2 = sqrtf((1 + fSlow0));
		FAUSTFLOAT* input0 = input[0];
		FAUSTFLOAT* output0 = output[0];
		FAUSTFLOAT* output1 = output[1];
		for (int i=0; i<count; i++) {
			float fTemp0 = (float)input0[i];
			output0[i] = (FAUSTFLOAT)(fSlow1 * fTemp0);
			output1[i] = (FAUSTFLOAT)(fSlow2 * fTemp0);
		}
	}
};


