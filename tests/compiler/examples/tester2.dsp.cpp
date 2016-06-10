//-----------------------------------------------------
// name: "StereoAudioTester"
// version: "1.0"
// author: "Grame"
// license: "BSD"
// copyright: "(c)GRAME 2014"
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


	static float 	ftbl0[65537];
	FAUSTFLOAT 	fslider0;
	float 	fConst0;
	float 	fRec1[2];
	int 	iRec3[3];
	float 	fRec2[3];
	FAUSTFLOAT 	fslider1;
	FAUSTFLOAT 	fslider2;
	float 	fRec4[2];
	FAUSTFLOAT 	fslider3;
	float 	fRec5[2];
	float 	fRec6[2];
  public:
	static void metadata(Meta* m) 	{ 
		m->declare("name", "StereoAudioTester");
		m->declare("version", "1.0");
		m->declare("author", "Grame");
		m->declare("license", "BSD");
		m->declare("copyright", "(c)GRAME 2014");
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
	virtual int getNumOutputs() 	{ return 2; }
	static void classInit(int samplingFreq) {
		SIG0 sig0;
		sig0.init(samplingFreq);
		sig0.fill(65537,ftbl0);
	}
	virtual void instanceInit(int samplingFreq) {
		fSamplingFreq = samplingFreq;
		fslider0 = 4.4e+02f;
		fConst0 = (1.0f / float(min(192000, max(1, fSamplingFreq))));
		for (int i=0; i<2; i++) fRec1[i] = 0;
		for (int i=0; i<3; i++) iRec3[i] = 0;
		for (int i=0; i<3; i++) fRec2[i] = 0;
		fslider1 = 0.0f;
		fslider2 = 0.0f;
		for (int i=0; i<2; i++) fRec4[i] = 0;
		fslider3 = -96.0f;
		for (int i=0; i<2; i++) fRec5[i] = 0;
		for (int i=0; i<2; i++) fRec6[i] = 0;
	}
	virtual void init(int samplingFreq) {
		classInit(samplingFreq);
		instanceInit(samplingFreq);
	}
	virtual void buildUserInterface(UI* interface) {
		interface->openVerticalBox("Stereo Audio Tester");
		interface->declare(&fslider0, "1", "");
		interface->declare(&fslider0, "scale", "log");
		interface->declare(&fslider0, "unit", "Hz");
		interface->addHorizontalSlider("freq", &fslider0, 4.4e+02f, 4e+01f, 2e+04f, 1.0f);
		interface->declare(&fslider3, "2", "");
		interface->declare(&fslider3, "unit", "dB");
		interface->addHorizontalSlider("volume", &fslider3, -96.0f, -96.0f, 0.0f, 1.0f);
		interface->declare(&fslider1, "3", "");
		interface->declare(&fslider1, "style", "menu{'white noise':0;'pink noise':1;'sine':2}");
		interface->addVerticalSlider("signal", &fslider1, 0.0f, 0.0f, 2.0f, 1.0f);
		interface->declare(&fslider2, "4", "");
		interface->declare(&fslider2, "style", "radio{'none':0;'left':1;'right':2;'both':3}");
		interface->addHorizontalSlider("channel", &fslider2, 0.0f, 0.0f, 3.0f, 1.0f);
		interface->closeBox();
	}
	virtual void compute (int count, FAUSTFLOAT** input, FAUSTFLOAT** output) {
		float 	fSlow0 = (fConst0 * float(fslider0));
		int 	iSlow1 = int(float(fslider1));
		int 	iSlow2 = int(float(fslider2));
		int 	iSlow3 = ((iSlow2 & 1) != 0);
		float 	fSlow4 = (0.0010000000000000009f * powf(10,(0.05f * float(fslider3))));
		int 	iSlow5 = ((iSlow2 & 2) != 0);
		FAUSTFLOAT* output0 = output[0];
		FAUSTFLOAT* output1 = output[1];
		for (int i=0; i<count; i++) {
			float fTemp0 = (fRec1[1] + fSlow0);
			fRec1[0] = (fTemp0 - floorf(fTemp0));
			float fTemp1 = (65536.0f * fRec1[0]);
			int iTemp2 = int(fTemp1);
			float fTemp3 = ftbl0[iTemp2];
			iRec3[0] = (12345 + (1103515245 * iRec3[1]));
			fRec2[0] = (((6.9067828423840845e-12f * iRec3[2]) + ((1.80116083982126f * fRec2[1]) + (2.308528039463576e-11f * iRec3[0]))) - ((0.80257737639225f * fRec2[2]) + (2.9362651228132963e-11f * iRec3[1])));
			float fTemp4 = ((iSlow1==0)? (4.656612875245797e-10f * iRec3[0]) : ((iSlow1==1)?fRec2[0]:(fTemp3 + ((fTemp1 - floorf(fTemp1)) * (ftbl0[(1 + iTemp2)] - fTemp3)))) );
			fRec4[0] = ((int((fRec4[1] < iSlow3)))?min((0.00022675736961451248f + fRec4[1]), (float)iSlow3):max((fRec4[1] - 0.00022675736961451248f), (float)iSlow3));
			fRec5[0] = ((0.999f * fRec5[1]) + fSlow4);
			output0[i] = (FAUSTFLOAT)((fRec5[0] * fRec4[0]) * fTemp4);
			fRec6[0] = ((int((fRec6[1] < iSlow5)))?min((0.00022675736961451248f + fRec6[1]), (float)iSlow5):max((fRec6[1] - 0.00022675736961451248f), (float)iSlow5));
			output1[i] = (FAUSTFLOAT)((fRec5[0] * fRec6[0]) * fTemp4);
			// post processing
			fRec6[1] = fRec6[0];
			fRec5[1] = fRec5[0];
			fRec4[1] = fRec4[0];
			fRec2[2] = fRec2[1]; fRec2[1] = fRec2[0];
			iRec3[2] = iRec3[1]; iRec3[1] = iRec3[0];
			fRec1[1] = fRec1[0];
		}
	}
};


float 	mydsp::ftbl0[65537];
