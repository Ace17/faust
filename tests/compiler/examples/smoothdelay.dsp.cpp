//-----------------------------------------------------
// name: "SmoothDelay"
// author: "Yann Orlarey"
// copyright: "Grame"
// version: "1.0"
// license: "STK-4.3"
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
	int 	IOTA;
	float 	fVec0[524288];
	FAUSTFLOAT 	fslider1;
	int 	iConst0;
	float 	fConst1;
	FAUSTFLOAT 	fslider2;
	float 	fConst2;
	float 	fRec1[2];
	float 	fRec2[2];
	float 	fRec3[2];
	float 	fRec4[2];
	float 	fRec0[2];
	float 	fVec1[524288];
	float 	fRec5[2];
  public:
	static void metadata(Meta* m) 	{ 
		m->declare("name", "SmoothDelay");
		m->declare("author", "Yann Orlarey");
		m->declare("copyright", "Grame");
		m->declare("version", "1.0");
		m->declare("license", "STK-4.3");
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

	virtual int getNumInputs() 	{ return 2; }
	virtual int getNumOutputs() 	{ return 2; }
	static void classInit(int samplingFreq) {
	}
	virtual void instanceInit(int samplingFreq) {
		fSamplingFreq = samplingFreq;
		fslider0 = 0.0f;
		IOTA = 0;
		for (int i=0; i<524288; i++) fVec0[i] = 0;
		fslider1 = 1e+01f;
		iConst0 = min(192000, max(1, fSamplingFreq));
		fConst1 = (1e+03f / float(iConst0));
		fslider2 = 0.0f;
		fConst2 = (0.001f * iConst0);
		for (int i=0; i<2; i++) fRec1[i] = 0;
		for (int i=0; i<2; i++) fRec2[i] = 0;
		for (int i=0; i<2; i++) fRec3[i] = 0;
		for (int i=0; i<2; i++) fRec4[i] = 0;
		for (int i=0; i<2; i++) fRec0[i] = 0;
		for (int i=0; i<524288; i++) fVec1[i] = 0;
		for (int i=0; i<2; i++) fRec5[i] = 0;
	}
	virtual void init(int samplingFreq) {
		classInit(samplingFreq);
		instanceInit(samplingFreq);
	}
	virtual void buildUserInterface(UI* interface) {
		interface->openVerticalBox("0x00");
		interface->declare(&fslider2, "style", "knob");
		interface->declare(&fslider2, "unit", "ms");
		interface->addHorizontalSlider("delay", &fslider2, 0.0f, 0.0f, 5e+03f, 0.1f);
		interface->declare(&fslider0, "style", "knob");
		interface->addHorizontalSlider("feedback", &fslider0, 0.0f, 0.0f, 1e+02f, 0.1f);
		interface->declare(&fslider1, "style", "knob");
		interface->declare(&fslider1, "unit", "ms");
		interface->addHorizontalSlider("interpolation", &fslider1, 1e+01f, 1.0f, 1e+02f, 0.1f);
		interface->closeBox();
	}
	virtual void compute (int count, FAUSTFLOAT** input, FAUSTFLOAT** output) {
		float 	fSlow0 = (0.01f * float(fslider0));
		float 	fSlow1 = (fConst1 / float(fslider1));
		float 	fSlow2 = (0 - fSlow1);
		float 	fSlow3 = (fConst2 * float(fslider2));
		FAUSTFLOAT* input0 = input[0];
		FAUSTFLOAT* input1 = input[1];
		FAUSTFLOAT* output0 = output[0];
		FAUSTFLOAT* output1 = output[1];
		for (int i=0; i<count; i++) {
			float fTemp0 = ((float)input0[i] + (fSlow0 * fRec0[1]));
			fVec0[IOTA&524287] = fTemp0;
			float fTemp1 = ((int((fRec1[1] != 0.0f)))?((int(((fRec2[1] > 0.0f) & (fRec2[1] < 1.0f))))?fRec1[1]:0):((int(((fRec2[1] == 0.0f) & (fSlow3 != fRec3[1]))))?fSlow1:((int(((fRec2[1] == 1.0f) & (fSlow3 != fRec4[1]))))?fSlow2:0)));
			fRec1[0] = fTemp1;
			fRec2[0] = max(0.0f, min(1.0f, (fRec2[1] + fTemp1)));
			fRec3[0] = ((int(((fRec2[1] >= 1.0f) & (fRec4[1] != fSlow3))))?fSlow3:fRec3[1]);
			fRec4[0] = ((int(((fRec2[1] <= 0.0f) & (fRec3[1] != fSlow3))))?fSlow3:fRec4[1]);
			int iTemp2 = int((int(fRec4[0]) & 524287));
			int iTemp3 = int((int(fRec3[0]) & 524287));
			float fTemp4 = (1.0f - fRec2[0]);
			fRec0[0] = ((fTemp4 * fVec0[(IOTA-iTemp3)&524287]) + (fRec2[0] * fVec0[(IOTA-iTemp2)&524287]));
			output0[i] = (FAUSTFLOAT)fRec0[0];
			float fTemp5 = ((float)input1[i] + (fSlow0 * fRec5[1]));
			fVec1[IOTA&524287] = fTemp5;
			fRec5[0] = ((fTemp4 * fVec1[(IOTA-iTemp3)&524287]) + (fRec2[0] * fVec1[(IOTA-iTemp2)&524287]));
			output1[i] = (FAUSTFLOAT)fRec5[0];
			// post processing
			fRec5[1] = fRec5[0];
			fRec0[1] = fRec0[0];
			fRec4[1] = fRec4[0];
			fRec3[1] = fRec3[0];
			fRec2[1] = fRec2[0];
			fRec1[1] = fRec1[0];
			IOTA = IOTA+1;
		}
	}
};


