//-----------------------------------------------------
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
	int 	iRec1[2];
	float 	fRec0[4];
	FAUSTFLOAT 	fcheckbox0;
	FAUSTFLOAT 	fbutton0;
	float 	fVec0[2];
	FAUSTFLOAT 	fcheckbox1;
	FAUSTFLOAT 	fbutton1;
	float 	fVec1[2];
	FAUSTFLOAT 	fbutton2;
	float 	fVec2[2];
  public:
	static void metadata(Meta* m) 	{ 
		m->declare("effect.lib/name", "Faust Audio Effect Library");
		m->declare("effect.lib/author", "Julius O. Smith (jos at ccrma.stanford.edu)");
		m->declare("effect.lib/copyright", "Julius O. Smith III");
		m->declare("effect.lib/version", "1.33");
		m->declare("effect.lib/license", "STK-4.3");
		m->declare("effect.lib/exciter_name", "Harmonic Exciter");
		m->declare("effect.lib/exciter_author", "Priyanka Shekar (pshekar@ccrma.stanford.edu)");
		m->declare("effect.lib/exciter_copyright", "Copyright (c) 2013 Priyanka Shekar");
		m->declare("effect.lib/exciter_version", "1.0");
		m->declare("effect.lib/exciter_license", "MIT License (MIT)");
		m->declare("filter.lib/name", "Faust Filter Library");
		m->declare("filter.lib/author", "Julius O. Smith (jos at ccrma.stanford.edu)");
		m->declare("filter.lib/copyright", "Julius O. Smith III");
		m->declare("filter.lib/version", "1.29");
		m->declare("filter.lib/license", "STK-4.3");
		m->declare("filter.lib/reference", "https://ccrma.stanford.edu/~jos/filters/");
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
		m->declare("oscillator.lib/name", "Faust Oscillator Library");
		m->declare("oscillator.lib/author", "Julius O. Smith (jos at ccrma.stanford.edu)");
		m->declare("oscillator.lib/copyright", "Julius O. Smith III");
		m->declare("oscillator.lib/version", "1.11");
		m->declare("oscillator.lib/license", "STK-4.3");
	}

	virtual int getNumInputs() 	{ return 2; }
	virtual int getNumOutputs() 	{ return 2; }
	static void classInit(int samplingFreq) {
	}
	virtual void instanceInit(int samplingFreq) {
		fSamplingFreq = samplingFreq;
		for (int i=0; i<2; i++) iRec1[i] = 0;
		for (int i=0; i<4; i++) fRec0[i] = 0;
		fcheckbox0 = 0.0;
		fbutton0 = 0.0;
		for (int i=0; i<2; i++) fVec0[i] = 0;
		fcheckbox1 = 0.0;
		fbutton1 = 0.0;
		for (int i=0; i<2; i++) fVec1[i] = 0;
		fbutton2 = 0.0;
		for (int i=0; i<2; i++) fVec2[i] = 0;
	}
	virtual void init(int samplingFreq) {
		classInit(samplingFreq);
		instanceInit(samplingFreq);
	}
	virtual void buildUserInterface(UI* interface) {
		interface->openHorizontalBox("Stereo Reverb Tester");
		interface->declare(0, "1", "");
		interface->openVerticalBox("Input Config");
		interface->declare(&fcheckbox1, "1", "");
		interface->declare(&fcheckbox1, "tooltip", "When this is checked, the stereo external audio inputs are disabled (good for hearing the impulse response or pink-noise response alone)");
		interface->addCheckButton("Mute Ext Inputs", &fcheckbox1);
		interface->declare(&fcheckbox0, "2", "");
		interface->declare(&fcheckbox0, "tooltip", "Pink Noise (or 1/f noise) is Constant-Q Noise (useful for adjusting the EQ sections)");
		interface->addCheckButton("Pink Noise", &fcheckbox0);
		interface->closeBox();
		interface->declare(0, "2", "");
		interface->openHorizontalBox("Impulse Selection");
		interface->declare(&fbutton0, "1", "");
		interface->declare(&fbutton0, "tooltip", "Send impulse into LEFT channel");
		interface->addButton("Left", &fbutton0);
		interface->declare(&fbutton1, "2", "");
		interface->declare(&fbutton1, "tooltip", "Send impulse into LEFT and RIGHT channels");
		interface->addButton("Center", &fbutton1);
		interface->declare(&fbutton2, "3", "");
		interface->declare(&fbutton2, "tooltip", "Send impulse into RIGHT channel");
		interface->addButton("Right", &fbutton2);
		interface->closeBox();
		interface->closeBox();
	}
	virtual void compute (int count, FAUSTFLOAT** input, FAUSTFLOAT** output) {
		float 	fSlow0 = (0.1f * float(fcheckbox0));
		float 	fSlow1 = float(fbutton0);
		float 	fSlow2 = (1 - float(fcheckbox1));
		float 	fSlow3 = float(fbutton1);
		float 	fSlow4 = float(fbutton2);
		FAUSTFLOAT* input0 = input[0];
		FAUSTFLOAT* input1 = input[1];
		FAUSTFLOAT* output0 = output[0];
		FAUSTFLOAT* output1 = output[1];
		for (int i=0; i<count; i++) {
			iRec1[0] = (12345 + (1103515245 * iRec1[1]));
			fRec0[0] = (((0.5221894f * fRec0[3]) + ((4.656612875245797e-10f * iRec1[0]) + (2.494956002f * fRec0[1]))) - (2.017265875f * fRec0[2]));
			float fTemp0 = (fSlow0 * (((0.049922035f * fRec0[0]) + (0.050612699f * fRec0[2])) - ((0.095993537f * fRec0[1]) + (0.004408786f * fRec0[3]))));
			fVec0[0] = fSlow1;
			fVec1[0] = fSlow3;
			int iTemp1 = ((fSlow3 - fVec1[1]) > 0);
			output0[i] = (FAUSTFLOAT)((iTemp1 + ((fSlow2 * (float)input0[i]) + ((fSlow1 - fVec0[1]) > 0))) + fTemp0);
			fVec2[0] = fSlow4;
			output1[i] = (FAUSTFLOAT)(((fSlow4 - fVec2[1]) > 0) + ((fSlow2 * (float)input1[i]) + (iTemp1 + fTemp0)));
			// post processing
			fVec2[1] = fVec2[0];
			fVec1[1] = fVec1[0];
			fVec0[1] = fVec0[0];
			for (int i=3; i>0; i--) fRec0[i] = fRec0[i-1];
			iRec1[1] = iRec1[0];
		}
	}
};


