//-----------------------------------------------------
// name: "karplus"
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
	FAUSTFLOAT 	fbutton0;
	float 	fVec0[2];
	float 	fRec1[2];
	int 	iRec2[2];
	FAUSTFLOAT 	fslider1;
	FAUSTFLOAT 	fslider2;
	int 	IOTA;
	float 	fVec1[512];
	FAUSTFLOAT 	fslider3;
	float 	fRec0[3];
  public:
	static void metadata(Meta* m) 	{ 
		m->declare("name", "karplus");
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

	virtual int getNumInputs() 	{ return 0; }
	virtual int getNumOutputs() 	{ return 1; }
	static void classInit(int samplingFreq) {
	}
	virtual void instanceInit(int samplingFreq) {
		fSamplingFreq = samplingFreq;
		fslider0 = 128.0f;
		fbutton0 = 0.0;
		for (int i=0; i<2; i++) fVec0[i] = 0;
		for (int i=0; i<2; i++) fRec1[i] = 0;
		for (int i=0; i<2; i++) iRec2[i] = 0;
		fslider1 = 0.5f;
		fslider2 = 0.1f;
		IOTA = 0;
		for (int i=0; i<512; i++) fVec1[i] = 0;
		fslider3 = 128.0f;
		for (int i=0; i<3; i++) fRec0[i] = 0;
	}
	virtual void init(int samplingFreq) {
		classInit(samplingFreq);
		instanceInit(samplingFreq);
	}
	virtual void buildUserInterface(UI* interface) {
		interface->openVerticalBox("0x00");
		interface->openVerticalBox("excitator");
		interface->declare(&fslider0, "unit", "f");
		interface->addHorizontalSlider("excitation", &fslider0, 128.0f, 2.0f, 512.0f, 1.0f);
		interface->addButton("play", &fbutton0);
		interface->closeBox();
		interface->addHorizontalSlider("level", &fslider1, 0.5f, 0.0f, 1.0f, 0.01f);
		interface->openVerticalBox("resonator");
		interface->addHorizontalSlider("attenuation", &fslider2, 0.1f, 0.0f, 1.0f, 0.01f);
		interface->declare(&fslider3, "unit", "f");
		interface->addHorizontalSlider("duration", &fslider3, 128.0f, 2.0f, 512.0f, 1.0f);
		interface->closeBox();
		interface->closeBox();
	}
	virtual void compute (int count, FAUSTFLOAT** input, FAUSTFLOAT** output) {
		float 	fSlow0 = (1.0f / float(fslider0));
		float 	fSlow1 = float(fbutton0);
		float 	fSlow2 = (4.656612875245797e-10f * float(fslider1));
		float 	fSlow3 = (0.5f * (1.0f - float(fslider2)));
		int 	iSlow4 = int((int((float(fslider3) - 1.5f)) & 4095));
		FAUSTFLOAT* output0 = output[0];
		for (int i=0; i<count; i++) {
			fVec0[0] = fSlow1;
			fRec1[0] = ((fRec1[1] + ((fSlow1 - fVec0[1]) > 0.0f)) - (fSlow0 * (fRec1[1] > 0.0f)));
			iRec2[0] = (12345 + (1103515245 * iRec2[1]));
			fVec1[IOTA&511] = ((fSlow3 * (fRec0[1] + fRec0[2])) + (fSlow2 * (iRec2[0] * (fRec1[0] > 0.0f))));
			fRec0[0] = fVec1[(IOTA-iSlow4)&511];
			output0[i] = (FAUSTFLOAT)fRec0[0];
			// post processing
			fRec0[2] = fRec0[1]; fRec0[1] = fRec0[0];
			IOTA = IOTA+1;
			iRec2[1] = iRec2[0];
			fRec1[1] = fRec1[0];
			fVec0[1] = fVec0[0];
		}
	}
};


