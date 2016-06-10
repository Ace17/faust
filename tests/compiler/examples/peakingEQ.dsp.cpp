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
	FAUSTFLOAT 	fslider2;
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
		fslider0 = 0.0f;
		fslider1 = 1.0f;
		fslider2 = 1e+03f;
		fConst0 = (6.283185307179586f / float(min(192000, max(1, fSamplingFreq))));
		for (int i=0; i<3; i++) fRec0[i] = 0;
	}
	virtual void init(int samplingFreq) {
		classInit(samplingFreq);
		instanceInit(samplingFreq);
	}
	virtual void buildUserInterface(UI* interface) {
		interface->openVerticalBox("0x00");
		interface->addHorizontalSlider("Freq", &fslider2, 1e+03f, 1e+02f, 1e+04f, 1.0f);
		interface->declare(&fslider0, "unit", "dB");
		interface->addHorizontalSlider("Gain", &fslider0, 0.0f, -1e+01f, 1e+01f, 0.1f);
		interface->addHorizontalSlider("Q", &fslider1, 1.0f, 0.01f, 1e+02f, 0.01f);
		interface->closeBox();
	}
	virtual void compute (int count, FAUSTFLOAT** input, FAUSTFLOAT** output) {
		float 	fSlow0 = powf(10,(0.025f * float(fslider0)));
		float 	fSlow1 = max(0.001f, float(fslider1));
		float 	fSlow2 = (fConst0 * max((float)0, float(fslider2)));
		float 	fSlow3 = sinf(fSlow2);
		float 	fSlow4 = (0.5f * (fSlow3 / (fSlow1 * fSlow0)));
		float 	fSlow5 = (1 - fSlow4);
		float 	fSlow6 = (0 - (2 * cosf(fSlow2)));
		float 	fSlow7 = (1.0f / (1 + fSlow4));
		float 	fSlow8 = (0.5f * ((fSlow3 * fSlow0) / fSlow1));
		float 	fSlow9 = (1 - fSlow8);
		float 	fSlow10 = (1 + fSlow8);
		FAUSTFLOAT* input0 = input[0];
		FAUSTFLOAT* output0 = output[0];
		for (int i=0; i<count; i++) {
			float fTemp0 = (fSlow6 * fRec0[1]);
			fRec0[0] = ((float)input0[i] - (fSlow7 * (fTemp0 + (fSlow5 * fRec0[2]))));
			output0[i] = (FAUSTFLOAT)(fSlow7 * ((fTemp0 + (fSlow10 * fRec0[0])) + (fSlow9 * fRec0[2])));
			// post processing
			fRec0[2] = fRec0[1]; fRec0[1] = fRec0[0];
		}
	}
};


