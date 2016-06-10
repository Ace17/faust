//-----------------------------------------------------
// name: "tester"
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
#include <math.h>

#ifndef FAUSTCLASS 
#define FAUSTCLASS mydsp
#endif

class mydsp : public dsp {
  private:
	class SIG0 {
	  private:
		int 	fSamplingFreq;
		int 	iRec2[2];
	  public:
		int getNumInputs() 	{ return 0; }
		int getNumOutputs() 	{ return 1; }
		void init(int samplingFreq) {
			fSamplingFreq = samplingFreq;
			for (int i=0; i<2; i++) iRec2[i] = 0;
		}
		void fill (int count, float output[]) {
			for (int i=0; i<count; i++) {
				iRec2[0] = (1 + iRec2[1]);
				output[i] = sinf((9.587379924285257e-05f * float((iRec2[0] - 1))));
				// post processing
				iRec2[1] = iRec2[0];
			}
		}
	};


	int 	iRec1[3];
	float 	fRec0[3];
	FAUSTFLOAT 	fcheckbox0;
	FAUSTFLOAT 	fcheckbox1;
	static float 	ftbl0[65537];
	FAUSTFLOAT 	fslider0;
	float 	fConst0;
	float 	fRec3[2];
	FAUSTFLOAT 	fcheckbox2;
	FAUSTFLOAT 	fslider1;
	float 	fRec4[2];
	FAUSTFLOAT 	fslider2;
  public:
	static void metadata(Meta* m) 	{ 
		m->declare("name", "tester");
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
	virtual int getNumOutputs() 	{ return 8; }
	static void classInit(int samplingFreq) {
		SIG0 sig0;
		sig0.init(samplingFreq);
		sig0.fill(65537,ftbl0);
	}
	virtual void instanceInit(int samplingFreq) {
		fSamplingFreq = samplingFreq;
		for (int i=0; i<3; i++) iRec1[i] = 0;
		for (int i=0; i<3; i++) fRec0[i] = 0;
		fcheckbox0 = 0.0;
		fcheckbox1 = 0.0;
		fslider0 = 1e+03f;
		fConst0 = (1.0f / float(min(192000, max(1, fSamplingFreq))));
		for (int i=0; i<2; i++) fRec3[i] = 0;
		fcheckbox2 = 0.0;
		fslider1 = -96.0f;
		for (int i=0; i<2; i++) fRec4[i] = 0;
		fslider2 = 0.0f;
	}
	virtual void init(int samplingFreq) {
		classInit(samplingFreq);
		instanceInit(samplingFreq);
	}
	virtual void buildUserInterface(UI* interface) {
		interface->openVerticalBox("Audio Tester");
		interface->declare(&fslider0, "1", "");
		interface->declare(&fslider0, "unit", "Hz");
		interface->addHorizontalSlider("freq", &fslider0, 1e+03f, 1e+01f, 2e+04f, 1.0f);
		interface->declare(&fslider1, "2", "");
		interface->declare(&fslider1, "unit", "dB");
		interface->addHorizontalSlider("volume", &fslider1, -96.0f, -96.0f, 0.0f, 1.0f);
		interface->declare(&fslider2, "3", "");
		interface->addHorizontalSlider("destination", &fslider2, 0.0f, 0.0f, 8.0f, 1.0f);
		interface->addCheckButton("pink noise", &fcheckbox0);
		interface->addCheckButton("sine wave", &fcheckbox2);
		interface->addCheckButton("white noise", &fcheckbox1);
		interface->closeBox();
	}
	virtual void compute (int count, FAUSTFLOAT** input, FAUSTFLOAT** output) {
		float 	fSlow0 = (1e+01f * float(fcheckbox0));
		float 	fSlow1 = (4.656612875245797e-10f * float(fcheckbox1));
		float 	fSlow2 = (fConst0 * float(fslider0));
		float 	fSlow3 = float(fcheckbox2);
		float 	fSlow4 = (0.0010000000000000009f * powf(10,(0.05f * float(fslider1))));
		float 	fSlow5 = float(fslider2);
		int 	iSlow6 = (fSlow5 == 0);
		int 	iSlow7 = (fSlow5 == 1);
		int 	iSlow8 = (fSlow5 == 2);
		int 	iSlow9 = (fSlow5 == 3);
		int 	iSlow10 = (fSlow5 == 4);
		int 	iSlow11 = (fSlow5 == 5);
		int 	iSlow12 = (fSlow5 == 6);
		int 	iSlow13 = (fSlow5 == 7);
		FAUSTFLOAT* output0 = output[0];
		FAUSTFLOAT* output1 = output[1];
		FAUSTFLOAT* output2 = output[2];
		FAUSTFLOAT* output3 = output[3];
		FAUSTFLOAT* output4 = output[4];
		FAUSTFLOAT* output5 = output[5];
		FAUSTFLOAT* output6 = output[6];
		FAUSTFLOAT* output7 = output[7];
		for (int i=0; i<count; i++) {
			iRec1[0] = (12345 + (1103515245 * iRec1[1]));
			fRec0[0] = (((6.9067828423840845e-12f * iRec1[2]) + ((1.80116083982126f * fRec0[1]) + (2.308528039463576e-11f * iRec1[0]))) - ((0.80257737639225f * fRec0[2]) + (2.9362651228132963e-11f * iRec1[1])));
			float fTemp0 = (fRec3[1] + fSlow2);
			fRec3[0] = (fTemp0 - floorf(fTemp0));
			float fTemp1 = (65536.0f * fRec3[0]);
			int iTemp2 = int(fTemp1);
			float fTemp3 = ftbl0[iTemp2];
			fRec4[0] = ((0.999f * fRec4[1]) + fSlow4);
			float fTemp4 = (fRec4[0] * (((fSlow3 * (fTemp3 + ((fTemp1 - floorf(fTemp1)) * (ftbl0[(1 + iTemp2)] - fTemp3)))) + (fSlow1 * iRec1[0])) + (fSlow0 * fRec0[0])));
			output0[i] = (FAUSTFLOAT)(iSlow6 * fTemp4);
			output1[i] = (FAUSTFLOAT)(iSlow7 * fTemp4);
			output2[i] = (FAUSTFLOAT)(iSlow8 * fTemp4);
			output3[i] = (FAUSTFLOAT)(iSlow9 * fTemp4);
			output4[i] = (FAUSTFLOAT)(iSlow10 * fTemp4);
			output5[i] = (FAUSTFLOAT)(iSlow11 * fTemp4);
			output6[i] = (FAUSTFLOAT)(iSlow12 * fTemp4);
			output7[i] = (FAUSTFLOAT)(iSlow13 * fTemp4);
			// post processing
			fRec4[1] = fRec4[0];
			fRec3[1] = fRec3[0];
			fRec0[2] = fRec0[1]; fRec0[1] = fRec0[0];
			iRec1[2] = iRec1[1]; iRec1[1] = iRec1[0];
		}
	}
};


float 	mydsp::ftbl0[65537];
