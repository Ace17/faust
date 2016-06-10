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
	FAUSTFLOAT 	fslider2;
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
		fslider1 = 1e+03f;
		fConst0 = (6.283185307179586f / float(min(192000, max(1, fSamplingFreq))));
		fslider2 = 1.0f;
		for (int i=0; i<3; i++) fRec0[i] = 0;
	}
	virtual void init(int samplingFreq) {
		classInit(samplingFreq);
		instanceInit(samplingFreq);
	}
	virtual void buildUserInterface(UI* interface) {
		interface->openVerticalBox("0x00");
		interface->addHorizontalSlider("Freq", &fslider1, 1e+03f, 1e+02f, 1e+04f, 1.0f);
		interface->declare(&fslider0, "unit", "dB");
		interface->addHorizontalSlider("Gain", &fslider0, 0.0f, -1e+01f, 1e+01f, 0.1f);
		interface->addHorizontalSlider("Q", &fslider2, 1.0f, 0.01f, 1e+02f, 0.01f);
		interface->closeBox();
	}
	virtual void compute (int count, FAUSTFLOAT** input, FAUSTFLOAT** output) {
		float 	fSlow0 = powf(10,(0.025f * float(fslider0)));
		float 	fSlow1 = (fConst0 * max((float)0, float(fslider1)));
		float 	fSlow2 = cosf(fSlow1);
		float 	fSlow3 = (1 + fSlow0);
		float 	fSlow4 = (fSlow3 * fSlow2);
		float 	fSlow5 = (2 * (0 - ((1 + fSlow4) - fSlow0)));
		float 	fSlow6 = ((sqrtf(fSlow0) * sinf(fSlow1)) / max(0.001f, float(fslider2)));
		float 	fSlow7 = ((fSlow0 - 1) * fSlow2);
		float 	fSlow8 = (0 - ((fSlow7 + fSlow6) - fSlow3));
		float 	fSlow9 = (1.0f / ((1 + (fSlow0 + fSlow6)) - fSlow7));
		float 	fSlow10 = (fSlow0 + fSlow7);
		float 	fSlow11 = (fSlow0 * ((1 + fSlow10) - fSlow6));
		float 	fSlow12 = ((0 - (2 * fSlow0)) * ((fSlow0 + fSlow4) - 1));
		float 	fSlow13 = (fSlow0 * (1 + (fSlow6 + fSlow10)));
		FAUSTFLOAT* input0 = input[0];
		FAUSTFLOAT* output0 = output[0];
		for (int i=0; i<count; i++) {
			fRec0[0] = ((float)input0[i] - (fSlow9 * ((fSlow8 * fRec0[2]) + (fSlow5 * fRec0[1]))));
			output0[i] = (FAUSTFLOAT)(fSlow9 * (((fSlow13 * fRec0[0]) + (fSlow12 * fRec0[1])) + (fSlow11 * fRec0[2])));
			// post processing
			fRec0[2] = fRec0[1]; fRec0[1] = fRec0[0];
		}
	}
};


