//-----------------------------------------------------
// name: "stereoecho"
// version: "1.0"
// author: "Grame"
// license: "BSD"
// copyright: "(c)GRAME 2007"
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
	float 	fConst0;
	FAUSTFLOAT 	fslider1;
	int 	IOTA;
	float 	fRec0[131072];
	float 	fRec1[131072];
  public:
	static void metadata(Meta* m) 	{ 
		m->declare("name", "stereoecho");
		m->declare("version", "1.0");
		m->declare("author", "Grame");
		m->declare("license", "BSD");
		m->declare("copyright", "(c)GRAME 2007");
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
		fConst0 = (0.001f * min(192000, max(1, fSamplingFreq)));
		fslider1 = 0.0f;
		IOTA = 0;
		for (int i=0; i<131072; i++) fRec0[i] = 0;
		for (int i=0; i<131072; i++) fRec1[i] = 0;
	}
	virtual void init(int samplingFreq) {
		classInit(samplingFreq);
		instanceInit(samplingFreq);
	}
	virtual void buildUserInterface(UI* interface) {
		interface->openVerticalBox("stereo echo");
		interface->openVerticalBox("echo  1000");
		interface->addHorizontalSlider("feedback", &fslider1, 0.0f, 0.0f, 1e+02f, 0.1f);
		interface->addHorizontalSlider("millisecond", &fslider0, 0.0f, 0.0f, 1e+03f, 0.1f);
		interface->closeBox();
		interface->closeBox();
	}
	virtual void compute (int count, FAUSTFLOAT** input, FAUSTFLOAT** output) {
		int 	iSlow0 = int((1 + int((int((int((fConst0 * float(fslider0))) - 1)) & 65535))));
		float 	fSlow1 = (0.01f * float(fslider1));
		FAUSTFLOAT* input0 = input[0];
		FAUSTFLOAT* input1 = input[1];
		FAUSTFLOAT* output0 = output[0];
		FAUSTFLOAT* output1 = output[1];
		for (int i=0; i<count; i++) {
			fRec0[IOTA&131071] = ((float)input0[i] + (fSlow1 * fRec0[(IOTA-iSlow0)&131071]));
			output0[i] = (FAUSTFLOAT)fRec0[(IOTA-0)&131071];
			fRec1[IOTA&131071] = ((float)input1[i] + (fSlow1 * fRec1[(IOTA-iSlow0)&131071]));
			output1[i] = (FAUSTFLOAT)fRec1[(IOTA-0)&131071];
			// post processing
			IOTA = IOTA+1;
		}
	}
};


