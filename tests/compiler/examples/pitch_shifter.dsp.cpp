//-----------------------------------------------------
// name: "pitch-shifter"
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
	FAUSTFLOAT 	fslider1;
	float 	fRec0[2];
	FAUSTFLOAT 	fslider2;
	int 	IOTA;
	float 	fVec0[65536];
  public:
	static void metadata(Meta* m) 	{ 
		m->declare("name", "pitch-shifter");
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
		fslider1 = 1e+03f;
		for (int i=0; i<2; i++) fRec0[i] = 0;
		fslider2 = 1e+01f;
		IOTA = 0;
		for (int i=0; i<65536; i++) fVec0[i] = 0;
	}
	virtual void init(int samplingFreq) {
		classInit(samplingFreq);
		instanceInit(samplingFreq);
	}
	virtual void buildUserInterface(UI* interface) {
		interface->openVerticalBox("Pitch Shifter");
		interface->addHorizontalSlider("shift (semitones)", &fslider0, 0.0f, -12.0f, 12.0f, 0.1f);
		interface->addHorizontalSlider("window (samples)", &fslider1, 1e+03f, 5e+01f, 1e+04f, 1.0f);
		interface->addHorizontalSlider("xfade (samples)", &fslider2, 1e+01f, 1.0f, 1e+04f, 1.0f);
		interface->closeBox();
	}
	virtual void compute (int count, FAUSTFLOAT** input, FAUSTFLOAT** output) {
		float 	fSlow0 = float(fslider1);
		float 	fSlow1 = ((1 + fSlow0) - powf(2,(0.08333333333333333f * float(fslider0))));
		float 	fSlow2 = (1.0f / float(fslider2));
		float 	fSlow3 = (fSlow0 - 1);
		FAUSTFLOAT* input0 = input[0];
		FAUSTFLOAT* output0 = output[0];
		for (int i=0; i<count; i++) {
			fRec0[0] = fmodf((fRec0[1] + fSlow1),fSlow0);
			float fTemp0 = min((fSlow2 * fRec0[0]), (float)1);
			float fTemp1 = (float)input0[i];
			fVec0[IOTA&65535] = fTemp1;
			float fTemp2 = (fSlow0 + fRec0[0]);
			int iTemp3 = int(fTemp2);
			int iTemp4 = int(fRec0[0]);
			int iTemp5 = (1 + iTemp4);
			output0[i] = (FAUSTFLOAT)((((fVec0[(IOTA-int((iTemp4 & 65535)))&65535] * (iTemp5 - fRec0[0])) + ((fRec0[0] - iTemp4) * fVec0[(IOTA-int((int(iTemp5) & 65535)))&65535])) * fTemp0) + (((fVec0[(IOTA-int((iTemp3 & 65535)))&65535] * (0 - ((fRec0[0] + fSlow3) - iTemp3))) + ((fTemp2 - iTemp3) * fVec0[(IOTA-int((int((1 + iTemp3)) & 65535)))&65535])) * (1 - fTemp0)));
			// post processing
			IOTA = IOTA+1;
			fRec0[1] = fRec0[0];
		}
	}
};


