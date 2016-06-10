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
	class SIG0 {
	  private:
		int 	fSamplingFreq;
		int 	iRec0[2];
	  public:
		int getNumInputs() 	{ return 0; }
		int getNumOutputs() 	{ return 1; }
		void init(int samplingFreq) {
			fSamplingFreq = samplingFreq;
			for (int i=0; i<2; i++) iRec0[i] = 0;
		}
		void fill (int count, float output[]) {
			for (int i=0; i<count; i++) {
				iRec0[0] = (1 + iRec0[1]);
				output[i] = sinf((9.587379924285257e-05f * float((iRec0[0] - 1))));
				// post processing
				iRec0[1] = iRec0[0];
			}
		}
	};


	static float 	ftbl0[65536];
	float 	fConst0;
	float 	fConst1;
	float 	fRec1[2];
	float 	fConst2;
	float 	fRec2[2];
	float 	fConst3;
	float 	fRec3[2];
	FAUSTFLOAT 	fslider0;
  public:
	static void metadata(Meta* m) 	{ 
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

	virtual int getNumInputs() 	{ return 0; }
	virtual int getNumOutputs() 	{ return 1; }
	static void classInit(int samplingFreq) {
		SIG0 sig0;
		sig0.init(samplingFreq);
		sig0.fill(65536,ftbl0);
	}
	virtual void instanceInit(int samplingFreq) {
		fSamplingFreq = samplingFreq;
		fConst0 = float(min(192000, max(1, fSamplingFreq)));
		fConst1 = (float(1320) / fConst0);
		for (int i=0; i<2; i++) fRec1[i] = 0;
		fConst2 = (float(880) / fConst0);
		for (int i=0; i<2; i++) fRec2[i] = 0;
		fConst3 = (float(440) / fConst0);
		for (int i=0; i<2; i++) fRec3[i] = 0;
		fslider0 = 0.3f;
	}
	virtual void init(int samplingFreq) {
		classInit(samplingFreq);
		instanceInit(samplingFreq);
	}
	virtual void buildUserInterface(UI* interface) {
		interface->openVerticalBox("0x00");
		interface->addHorizontalSlider("vol", &fslider0, 0.3f, 0.0f, 1.0f, 0.01f);
		interface->closeBox();
	}
	virtual void compute (int count, FAUSTFLOAT** input, FAUSTFLOAT** output) {
		float 	fSlow0 = float(fslider0);
		FAUSTFLOAT* output0 = output[0];
		for (int i=0; i<count; i++) {
			float fTemp0 = (fConst1 + fRec1[1]);
			fRec1[0] = (fTemp0 - floorf(fTemp0));
			float fTemp1 = (fConst2 + fRec2[1]);
			fRec2[0] = (fTemp1 - floorf(fTemp1));
			float fTemp2 = (fConst3 + fRec3[1]);
			fRec3[0] = (fTemp2 - floorf(fTemp2));
			output0[i] = (FAUSTFLOAT)(fSlow0 * ((ftbl0[int((65536.0f * fRec3[0]))] + (0.5f * ftbl0[int((65536.0f * fRec2[0]))])) + (0.3f * ftbl0[int((65536.0f * fRec1[0]))])));
			// post processing
			fRec3[1] = fRec3[0];
			fRec2[1] = fRec2[0];
			fRec1[1] = fRec1[0];
		}
	}
};


float 	mydsp::ftbl0[65536];
