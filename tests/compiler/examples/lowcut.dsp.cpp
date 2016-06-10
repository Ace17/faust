//-----------------------------------------------------
// name: "lowcut"
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
	FAUSTFLOAT 	fslider1;
	float 	fConst0;
	float 	fRec0[3];
  public:
	static void metadata(Meta* m) 	{ 
		m->declare("name", "lowcut");
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
		fslider1 = 1e+02f;
		fConst0 = (3.141592653589793f / float(min(192000, max(1, fSamplingFreq))));
		for (int i=0; i<3; i++) fRec0[i] = 0;
	}
	virtual void init(int samplingFreq) {
		classInit(samplingFreq);
		instanceInit(samplingFreq);
	}
	virtual void buildUserInterface(UI* interface) {
		interface->openVerticalBox("low-freq shelving cut");
		interface->declare(&fslider0, "style", "knob");
		interface->declare(&fslider0, "unit", "dB");
		interface->addHorizontalSlider("attenuation", &fslider0, 0.0f, -96.0f, 1e+01f, 0.1f);
		interface->declare(&fslider1, "style", "knob");
		interface->declare(&fslider1, "unit", "Hz");
		interface->addHorizontalSlider("freq", &fslider1, 1e+02f, 2e+01f, 5e+03f, 1.0f);
		interface->closeBox();
	}
	virtual void compute (int count, FAUSTFLOAT** input, FAUSTFLOAT** output) {
		float 	fSlow0 = powf(10,(0 - (0.05f * float(fslider0))));
		float 	fSlow1 = tanf((fConst0 * float(fslider1)));
		float 	fSlow2 = faustpower<2>(fSlow1);
		float 	fSlow3 = (2 * ((fSlow2 * fSlow0) - 1));
		float 	fSlow4 = sqrtf((2 * fSlow0));
		float 	fSlow5 = (fSlow1 * fSlow0);
		float 	fSlow6 = (1 + (fSlow1 * (fSlow5 - fSlow4)));
		float 	fSlow7 = (1.0f / (1 + (fSlow1 * (fSlow4 + fSlow5))));
		float 	fSlow8 = (1 + (fSlow1 * (fSlow1 - 1.4142135623730951f)));
		float 	fSlow9 = (2 * (fSlow2 - 1));
		float 	fSlow10 = (1 + (fSlow1 * (1.4142135623730951f + fSlow1)));
		FAUSTFLOAT* input0 = input[0];
		FAUSTFLOAT* output0 = output[0];
		for (int i=0; i<count; i++) {
			fRec0[0] = ((float)input0[i] - (fSlow7 * ((fSlow6 * fRec0[2]) + (fSlow3 * fRec0[1]))));
			output0[i] = (FAUSTFLOAT)(fSlow7 * (((fSlow10 * fRec0[0]) + (fSlow9 * fRec0[1])) + (fSlow8 * fRec0[2])));
			// post processing
			fRec0[2] = fRec0[1]; fRec0[1] = fRec0[0];
		}
	}
};


