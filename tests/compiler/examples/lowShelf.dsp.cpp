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
		fslider0 = 1.0f;
		fslider1 = 1e+03f;
		fConst0 = (6.283185307179586f / float(min(192000, max(1, fSamplingFreq))));
		fslider2 = 0.0f;
		for (int i=0; i<3; i++) fRec0[i] = 0;
	}
	virtual void init(int samplingFreq) {
		classInit(samplingFreq);
		instanceInit(samplingFreq);
	}
	virtual void buildUserInterface(UI* interface) {
		interface->openVerticalBox("0x00");
		interface->addHorizontalSlider("Freq", &fslider1, 1e+03f, 1e+02f, 1e+04f, 1.0f);
		interface->declare(&fslider2, "unit", "dB");
		interface->addHorizontalSlider("Gain", &fslider2, 0.0f, -1e+01f, 1e+01f, 0.1f);
		interface->addHorizontalSlider("Q", &fslider0, 1.0f, 0.01f, 1e+02f, 0.01f);
		interface->closeBox();
	}
	virtual void compute (int count, FAUSTFLOAT** input, FAUSTFLOAT** output) {
		float 	fSlow0 = (fConst0 * max((float)0, float(fslider1)));
		float 	fSlow1 = powf(10,(0.025f * float(fslider2)));
		float 	fSlow2 = ((sqrtf(fSlow1) * sinf(fSlow0)) / max(0.001f, float(fslider0)));
		float 	fSlow3 = cosf(fSlow0);
		float 	fSlow4 = ((fSlow1 - 1) * fSlow3);
		float 	fSlow5 = (fSlow1 + fSlow4);
		float 	fSlow6 = ((1 + fSlow5) - fSlow2);
		float 	fSlow7 = (1 + fSlow1);
		float 	fSlow8 = (fSlow7 * fSlow3);
		float 	fSlow9 = (0 - (2 * ((fSlow1 + fSlow8) - 1)));
		float 	fSlow10 = (1 + (fSlow5 + fSlow2));
		float 	fSlow11 = (1.0f / fSlow10);
		float 	fSlow12 = (0 - ((fSlow4 + fSlow2) - fSlow7));
		float 	fSlow13 = (2 * (0 - ((1 + fSlow8) - fSlow1)));
		float 	fSlow14 = ((1 + (fSlow1 + fSlow2)) - fSlow4);
		float 	fSlow15 = (fSlow1 / fSlow10);
		FAUSTFLOAT* input0 = input[0];
		FAUSTFLOAT* output0 = output[0];
		for (int i=0; i<count; i++) {
			fRec0[0] = ((float)input0[i] - (fSlow11 * ((fSlow9 * fRec0[1]) + (fSlow6 * fRec0[2]))));
			output0[i] = (FAUSTFLOAT)(fSlow15 * (((fSlow14 * fRec0[0]) + (fSlow13 * fRec0[1])) + (fSlow12 * fRec0[2])));
			// post processing
			fRec0[2] = fRec0[1]; fRec0[1] = fRec0[0];
		}
	}
};


