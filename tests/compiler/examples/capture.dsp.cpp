//-----------------------------------------------------
// name: "capture"
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
	FAUSTFLOAT 	fslider0;
	float 	fRec0[2];
	FAUSTFLOAT 	fbutton0;
	int 	IOTA;
	float 	fVec0[524288];
	int 	iVec1[2];
	int 	iRec2[2];
	float 	fRec1[2];
  public:
	static void metadata(Meta* m) 	{ 
		m->declare("name", "capture");
		m->declare("version", "1.0");
		m->declare("author", "Grame");
		m->declare("license", "BSD");
		m->declare("copyright", "(c)GRAME 2006");
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
		for (int i=0; i<2; i++) fRec0[i] = 0;
		fbutton0 = 0.0;
		IOTA = 0;
		for (int i=0; i<524288; i++) fVec0[i] = 0;
		for (int i=0; i<2; i++) iVec1[i] = 0;
		for (int i=0; i<2; i++) iRec2[i] = 0;
		for (int i=0; i<2; i++) fRec1[i] = 0;
	}
	virtual void init(int samplingFreq) {
		classInit(samplingFreq);
		instanceInit(samplingFreq);
	}
	virtual void buildUserInterface(UI* interface) {
		interface->openVerticalBox("Audio Capture");
		interface->addButton("Capture", &fbutton0);
		interface->addHorizontalSlider("level (db)", &fslider0, 0.0f, -96.0f, 4.0f, 0.1f);
		interface->closeBox();
	}
	virtual void compute (int count, FAUSTFLOAT** input, FAUSTFLOAT** output) {
		float 	fSlow0 = (0.0010000000000000009f * powf(10,(0.05f * float(fslider0))));
		float 	fSlow1 = float(fbutton0);
		float 	fSlow2 = (1.0f - fSlow1);
		int 	iSlow3 = int(fSlow1);
		FAUSTFLOAT* input0 = input[0];
		FAUSTFLOAT* output0 = output[0];
		for (int i=0; i<count; i++) {
			fRec0[0] = ((0.999f * fRec0[1]) + fSlow0);
			fVec0[IOTA&524287] = ((fSlow2 * fRec1[1]) + (fSlow1 * (float)input0[i]));
			iVec1[0] = iSlow3;
			iRec2[0] = ((iSlow3 + iRec2[1]) * ((iSlow3 - iVec1[1]) <= 0));
			fRec1[0] = fVec0[(IOTA-int((int((iRec2[0] - 1)) & 524287)))&524287];
			output0[i] = (FAUSTFLOAT)(fRec1[0] * fRec0[0]);
			// post processing
			fRec1[1] = fRec1[0];
			iRec2[1] = iRec2[0];
			iVec1[1] = iVec1[0];
			IOTA = IOTA+1;
			fRec0[1] = fRec0[0];
		}
	}
};


