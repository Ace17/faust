//-----------------------------------------------------
// name: "lowboost"
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
#ifndef FAUSTPOWER
#define FAUSTPOWER
#include <cmath>
template <int N> inline float faustpower(float x)          { return powf(x,N); } 
template <int N> inline double faustpower(double x)        { return pow(x,N); }
template <int N> inline int faustpower(int x)              { return faustpower<N/2>(x) * faustpower<N-N/2>(x); } 
template <>   inline int faustpower<0>(int x)            { return 1; }
template <>   inline int faustpower<1>(int x)            { return x; }
#endif

#ifndef FAUSTCLASS 
#define FAUSTCLASS mydsp
#endif

class mydsp : public dsp {
  private:
	FAUSTFLOAT 	fslider0;
	float 	fConst0;
	float 	fRec0[3];
	FAUSTFLOAT 	fslider1;
  public:
	static void metadata(Meta* m) 	{ 
		m->declare("name", "lowboost");
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
		fslider0 = 1e+03f;
		fConst0 = (3.141592653589793f / float(min(192000, max(1, fSamplingFreq))));
		for (int i=0; i<3; i++) fRec0[i] = 0;
		fslider1 = 0.0f;
	}
	virtual void init(int samplingFreq) {
		classInit(samplingFreq);
		instanceInit(samplingFreq);
	}
	virtual void buildUserInterface(UI* interface) {
		interface->openVerticalBox("low-freq shelving boost");
		interface->declare(&fslider0, "1", "");
		interface->declare(&fslider0, "style", "knob");
		interface->declare(&fslider0, "unit", "Hz");
		interface->addHorizontalSlider("freq", &fslider0, 1e+03f, 2e+01f, 2e+04f, 0.1f);
		interface->declare(&fslider1, "2", "");
		interface->declare(&fslider1, "style", "knob");
		interface->declare(&fslider1, "unit", "dB");
		interface->addHorizontalSlider("gain", &fslider1, 0.0f, -2e+01f, 2e+01f, 0.1f);
		interface->closeBox();
	}
	virtual void compute (int count, FAUSTFLOAT** input, FAUSTFLOAT** output) {
		float 	fSlow0 = tanf((fConst0 * float(fslider0)));
		float 	fSlow1 = faustpower<2>(fSlow0);
		float 	fSlow2 = (2 * (fSlow1 - 1));
		float 	fSlow3 = (1 + (fSlow0 * (fSlow0 - 1.4142135623730951f)));
		float 	fSlow4 = (1.0f / (1 + (fSlow0 * (1.4142135623730951f + fSlow0))));
		float 	fSlow5 = powf(10,(0.05f * float(fslider1)));
		float 	fSlow6 = sqrtf((2 * fSlow5));
		float 	fSlow7 = (fSlow5 * fSlow0);
		float 	fSlow8 = (1 + (fSlow0 * (fSlow7 - fSlow6)));
		float 	fSlow9 = (2 * ((fSlow5 * fSlow1) - 1));
		float 	fSlow10 = (1 + (fSlow0 * (fSlow6 + fSlow7)));
		FAUSTFLOAT* input0 = input[0];
		FAUSTFLOAT* output0 = output[0];
		for (int i=0; i<count; i++) {
			fRec0[0] = ((float)input0[i] - (fSlow4 * ((fSlow3 * fRec0[2]) + (fSlow2 * fRec0[1]))));
			output0[i] = (FAUSTFLOAT)(fSlow4 * (((fSlow10 * fRec0[0]) + (fSlow9 * fRec0[1])) + (fSlow8 * fRec0[2])));
			// post processing
			fRec0[2] = fRec0[1]; fRec0[1] = fRec0[0];
		}
	}
};


