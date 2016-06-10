//-----------------------------------------------------
//
// Code generated with Faust 0.9.70 (http://faust.grame.fr)
//-----------------------------------------------------
#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif  

typedef long double quad;
/* link with  */
#include <math.h>

#ifndef FAUSTCLASS 
#define FAUSTCLASS mydsp
#endif

class mydsp : public dsp {
  private:
	FAUSTFLOAT 	fslider0;
	FAUSTFLOAT 	fslider1;
	float 	fConst0;
	float 	fRec0[3];
  public:
	static void metadata(Meta* m) 	{ 
		m->declare("maxmsp.lib/name", "MaxMSP compatibility Library");
		m->declare("maxmsp.lib/author", "GRAME");
		m->declare("maxmsp.lib/copyright", "GRAME");
		m->declare("maxmsp.lib/version", "1.1");
		m->declare("maxmsp.lib/license", "LGPL");
		m->declare("music.lib/name", "Music Library");
		m->declare("music.lib/author", "GRAME");
		m->declare("music.lib/copyright", "GRAME");
		m->declare("music.lib/version", "1.0");
		m->declare("music.lib/license", "LGPL with exception");
		m->declare("math.lib/name", "Math Library");
		m->declare("math.lib/author", "GRAME");
		m->declare("math.lib/copyright", "GRAME");
		m->declare("math.lib/version", "1.0");
		m->declare("math.lib/license", "LGPL with exception");
	}

	virtual int getNumInputs() 	{ return 1; }
	virtual int getNumOutputs() 	{ return 1; }
	static void classInit(int samplingFreq) {
	}
	virtual void instanceInit(int samplingFreq) {
		fSamplingFreq = samplingFreq;
		fslider0 = 1.0f;
		fslider1 = 1e+03f;
		fConst0 = (6.283185307179586f / float(min(192000, max(1, fSamplingFreq))));
		for (int i=0; i<3; i++) fRec0[i] = 0;
	}
	virtual void init(int samplingFreq) {
		classInit(samplingFreq);
		instanceInit(samplingFreq);
	}
	virtual void buildUserInterface(UI* interface) {
		interface->openVerticalBox("0x00");
		interface->addHorizontalSlider("Freq", &fslider1, 1e+03f, 1e+02f, 1e+04f, 1.0f);
		interface->addHorizontalSlider("Q", &fslider0, 1.0f, 0.01f, 1e+02f, 0.01f);
		interface->closeBox();
	}
	virtual void compute (int count, FAUSTFLOAT** input, FAUSTFLOAT** output) {
		float 	fSlow0 = (fConst0 * max((float)0, float(fslider1)));
		float 	fSlow1 = (0.5f * (sinf(fSlow0) / max(0.001f, float(fslider0))));
		float 	fSlow2 = (1 - fSlow1);
		float 	fSlow3 = (0 - (2 * cosf(fSlow0)));
		float 	fSlow4 = (1.0f / (1 + fSlow1));
		float 	fSlow5 = (0 - fSlow1);
		FAUSTFLOAT* input0 = input[0];
		FAUSTFLOAT* output0 = output[0];
		for (int i=0; i<count; i++) {
			fRec0[0] = ((float)input0[i] - (fSlow4 * ((fSlow3 * fRec0[1]) + (fSlow2 * fRec0[2]))));
			output0[i] = (FAUSTFLOAT)(fSlow4 * ((fSlow5 * fRec0[2]) + (fSlow1 * fRec0[0])));
			// post processing
			fRec0[2] = fRec0[1]; fRec0[1] = fRec0[0];
		}
	}
};


