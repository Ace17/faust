//-----------------------------------------------------
// name: "Harpe"
// author: "Grame"
//
// Code generated with Faust 0.9.70 (http://faust.grame.fr)
//-----------------------------------------------------
#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif  

typedef long double quad;
/* link with  */
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
	float 	fRec2[2];
	int 	iVec0[2];
	float 	fRec1[2];
	int 	iRec3[2];
	FAUSTFLOAT 	fslider1;
	FAUSTFLOAT 	fslider2;
	int 	IOTA;
	float 	fVec1[32];
	float 	fRec0[3];
	int 	iVec2[2];
	float 	fRec5[2];
	float 	fVec3[32];
	float 	fRec4[3];
	int 	iVec4[2];
	float 	fRec7[2];
	float 	fVec5[64];
	float 	fRec6[3];
	int 	iVec6[2];
	float 	fRec9[2];
	float 	fVec7[64];
	float 	fRec8[3];
	int 	iVec8[2];
	float 	fRec11[2];
	float 	fVec9[64];
	float 	fRec10[3];
	int 	iVec10[2];
	float 	fRec13[2];
	float 	fVec11[64];
	float 	fRec12[3];
	int 	iVec12[2];
	float 	fRec15[2];
	float 	fVec13[64];
	float 	fRec14[3];
	int 	iVec14[2];
	float 	fRec17[2];
	float 	fVec15[128];
	float 	fRec16[3];
	int 	iVec16[2];
	float 	fRec19[2];
	float 	fVec17[128];
	float 	fRec18[3];
	int 	iVec18[2];
	float 	fRec21[2];
	float 	fVec19[128];
	float 	fRec20[3];
	int 	iVec20[2];
	float 	fRec23[2];
	float 	fVec21[128];
	float 	fRec22[3];
  public:
	static void metadata(Meta* m) 	{ 
		m->declare("name", "Harpe");
		m->declare("author", "Grame");
	}

	virtual int getNumInputs() 	{ return 0; }
	virtual int getNumOutputs() 	{ return 2; }
	static void classInit(int samplingFreq) {
	}
	virtual void instanceInit(int samplingFreq) {
		fSamplingFreq = samplingFreq;
		fslider0 = 0.0f;
		for (int i=0; i<2; i++) fRec2[i] = 0;
		for (int i=0; i<2; i++) iVec0[i] = 0;
		for (int i=0; i<2; i++) fRec1[i] = 0;
		for (int i=0; i<2; i++) iRec3[i] = 0;
		fslider1 = 0.5f;
		fslider2 = 0.005f;
		IOTA = 0;
		for (int i=0; i<32; i++) fVec1[i] = 0;
		for (int i=0; i<3; i++) fRec0[i] = 0;
		for (int i=0; i<2; i++) iVec2[i] = 0;
		for (int i=0; i<2; i++) fRec5[i] = 0;
		for (int i=0; i<32; i++) fVec3[i] = 0;
		for (int i=0; i<3; i++) fRec4[i] = 0;
		for (int i=0; i<2; i++) iVec4[i] = 0;
		for (int i=0; i<2; i++) fRec7[i] = 0;
		for (int i=0; i<64; i++) fVec5[i] = 0;
		for (int i=0; i<3; i++) fRec6[i] = 0;
		for (int i=0; i<2; i++) iVec6[i] = 0;
		for (int i=0; i<2; i++) fRec9[i] = 0;
		for (int i=0; i<64; i++) fVec7[i] = 0;
		for (int i=0; i<3; i++) fRec8[i] = 0;
		for (int i=0; i<2; i++) iVec8[i] = 0;
		for (int i=0; i<2; i++) fRec11[i] = 0;
		for (int i=0; i<64; i++) fVec9[i] = 0;
		for (int i=0; i<3; i++) fRec10[i] = 0;
		for (int i=0; i<2; i++) iVec10[i] = 0;
		for (int i=0; i<2; i++) fRec13[i] = 0;
		for (int i=0; i<64; i++) fVec11[i] = 0;
		for (int i=0; i<3; i++) fRec12[i] = 0;
		for (int i=0; i<2; i++) iVec12[i] = 0;
		for (int i=0; i<2; i++) fRec15[i] = 0;
		for (int i=0; i<64; i++) fVec13[i] = 0;
		for (int i=0; i<3; i++) fRec14[i] = 0;
		for (int i=0; i<2; i++) iVec14[i] = 0;
		for (int i=0; i<2; i++) fRec17[i] = 0;
		for (int i=0; i<128; i++) fVec15[i] = 0;
		for (int i=0; i<3; i++) fRec16[i] = 0;
		for (int i=0; i<2; i++) iVec16[i] = 0;
		for (int i=0; i<2; i++) fRec19[i] = 0;
		for (int i=0; i<128; i++) fVec17[i] = 0;
		for (int i=0; i<3; i++) fRec18[i] = 0;
		for (int i=0; i<2; i++) iVec18[i] = 0;
		for (int i=0; i<2; i++) fRec21[i] = 0;
		for (int i=0; i<128; i++) fVec19[i] = 0;
		for (int i=0; i<3; i++) fRec20[i] = 0;
		for (int i=0; i<2; i++) iVec20[i] = 0;
		for (int i=0; i<2; i++) fRec23[i] = 0;
		for (int i=0; i<128; i++) fVec21[i] = 0;
		for (int i=0; i<3; i++) fRec22[i] = 0;
	}
	virtual void init(int samplingFreq) {
		classInit(samplingFreq);
		instanceInit(samplingFreq);
	}
	virtual void buildUserInterface(UI* interface) {
		interface->openVerticalBox("0x00");
		interface->declare(&fslider2, "osc", "/1/fader3");
		interface->addHorizontalSlider("attenuation", &fslider2, 0.005f, 0.0f, 0.01f, 0.001f);
		interface->declare(&fslider0, "osc", "/accxyz/1 -10 10");
		interface->addHorizontalSlider("hand", &fslider0, 0.0f, 0.0f, 1.0f, 0.01f);
		interface->declare(&fslider1, "osc", "/accxyz/0 -10 10");
		interface->declare(&fslider1, "unit", "f");
		interface->addHorizontalSlider("level", &fslider1, 0.5f, 0.0f, 1.0f, 0.01f);
		interface->closeBox();
	}
	virtual void compute (int count, FAUSTFLOAT** input, FAUSTFLOAT** output) {
		float 	fSlow0 = (0.09999999999999998f * float(fslider0));
		float 	fSlow1 = (4.656612875245797e-10f * faustpower<2>(float(fslider1)));
		float 	fSlow2 = (0.5f * (1.0f - float(fslider2)));
		FAUSTFLOAT* output0 = output[0];
		FAUSTFLOAT* output1 = output[1];
		for (int i=0; i<count; i++) {
			fRec2[0] = ((0.9f * fRec2[1]) + fSlow0);
			float fTemp0 = max(fRec2[0], fRec2[1]);
			float fTemp1 = min(fRec2[0], fRec2[1]);
			int iTemp2 = ((fTemp1 < 0.9545454545454546f) & (0.9545454545454546f < fTemp0));
			iVec0[0] = iTemp2;
			fRec1[0] = ((fRec1[1] + ((iVec0[0] - iVec0[1]) > 0.0f)) - (0.039909297052154194f * (fRec1[1] > 0.0f)));
			iRec3[0] = (12345 + (1103515245 * iRec3[1]));
			fVec1[IOTA&31] = ((fSlow2 * (fRec0[1] + fRec0[2])) + (fSlow1 * (iRec3[0] * (fRec1[0] > 0.0f))));
			fRec0[0] = fVec1[(IOTA-24)&31];
			int iTemp3 = ((fTemp1 < 0.8636363636363636f) & (0.8636363636363636f < fTemp0));
			iVec2[0] = iTemp3;
			fRec5[0] = ((fRec5[1] + ((iVec2[0] - iVec2[1]) > 0.0f)) - (0.03474306102950518f * (fRec5[1] > 0.0f)));
			fVec3[IOTA&31] = ((fSlow2 * (fRec4[1] + fRec4[2])) + (fSlow1 * (iRec3[0] * (fRec5[0] > 0.0f))));
			fRec4[0] = fVec3[(IOTA-27)&31];
			int iTemp4 = ((fTemp1 < 0.7727272727272727f) & (0.7727272727272727f < fTemp0));
			iVec4[0] = iTemp4;
			fRec7[0] = ((fRec7[1] + ((iVec4[0] - iVec4[1]) > 0.0f)) - (0.03024559134986736f * (fRec7[1] > 0.0f)));
			fVec5[IOTA&63] = ((fSlow2 * (fRec6[1] + fRec6[2])) + (fSlow1 * (iRec3[0] * (fRec7[0] > 0.0f))));
			fRec6[0] = fVec5[(IOTA-32)&63];
			int iTemp5 = ((fTemp1 < 0.6818181818181818f) & (0.6818181818181818f < fTemp0));
			iVec6[0] = iTemp5;
			fRec9[0] = ((fRec9[1] + ((iVec6[0] - iVec6[1]) > 0.0f)) - (0.026330316586851404f * (fRec9[1] > 0.0f)));
			fVec7[IOTA&63] = ((fSlow2 * (fRec8[1] + fRec8[2])) + (fSlow1 * (iRec3[0] * (fRec9[0] > 0.0f))));
			fRec8[0] = fVec7[(IOTA-36)&63];
			int iTemp6 = ((fTemp1 < 0.5909090909090909f) & (0.5909090909090909f < fTemp0));
			iVec8[0] = iTemp6;
			fRec11[0] = ((fRec11[1] + ((iVec8[0] - iVec8[1]) > 0.0f)) - (0.02292187193644877f * (fRec11[1] > 0.0f)));
			fVec9[IOTA&63] = ((fSlow2 * (fRec10[1] + fRec10[2])) + (fSlow1 * (iRec3[0] * (fRec11[0] > 0.0f))));
			fRec10[0] = fVec9[(IOTA-42)&63];
			int iTemp7 = ((fTemp1 < 0.5f) & (0.5f < fTemp0));
			iVec10[0] = iTemp7;
			fRec13[0] = ((fRec13[1] + ((iVec10[0] - iVec10[1]) > 0.0f)) - (0.019954648526077097f * (fRec13[1] > 0.0f)));
			fVec11[IOTA&63] = ((fSlow2 * (fRec12[1] + fRec12[2])) + (fSlow1 * (iRec3[0] * (fRec13[0] > 0.0f))));
			fRec12[0] = fVec11[(IOTA-49)&63];
			float fTemp8 = (0.7071067811865476f * fRec12[0]);
			int iTemp9 = ((fTemp1 < 0.4090909090909091f) & (0.4090909090909091f < fTemp0));
			iVec12[0] = iTemp9;
			fRec15[0] = ((fRec15[1] + ((iVec12[0] - iVec12[1]) > 0.0f)) - (0.01737153051475259f * (fRec15[1] > 0.0f)));
			fVec13[IOTA&63] = ((fSlow2 * (fRec14[1] + fRec14[2])) + (fSlow1 * (iRec3[0] * (fRec15[0] > 0.0f))));
			fRec14[0] = fVec13[(IOTA-56)&63];
			int iTemp10 = ((fTemp1 < 0.3181818181818182f) & (0.3181818181818182f < fTemp0));
			iVec14[0] = iTemp10;
			fRec17[0] = ((fRec17[1] + ((iVec14[0] - iVec14[1]) > 0.0f)) - (0.015122795674933676f * (fRec17[1] > 0.0f)));
			fVec15[IOTA&127] = ((fSlow2 * (fRec16[1] + fRec16[2])) + (fSlow1 * (iRec3[0] * (fRec17[0] > 0.0f))));
			fRec16[0] = fVec15[(IOTA-65)&127];
			int iTemp11 = ((fTemp1 < 0.22727272727272727f) & (0.22727272727272727f < fTemp0));
			iVec16[0] = iTemp11;
			fRec19[0] = ((fRec19[1] + ((iVec16[0] - iVec16[1]) > 0.0f)) - (0.013165158293425702f * (fRec19[1] > 0.0f)));
			fVec17[IOTA&127] = ((fSlow2 * (fRec18[1] + fRec18[2])) + (fSlow1 * (iRec3[0] * (fRec19[0] > 0.0f))));
			fRec18[0] = fVec17[(IOTA-74)&127];
			int iTemp12 = ((fTemp1 < 0.13636363636363635f) & (0.13636363636363635f < fTemp0));
			iVec18[0] = iTemp12;
			fRec21[0] = ((fRec21[1] + ((iVec18[0] - iVec18[1]) > 0.0f)) - (0.011460935968224386f * (fRec21[1] > 0.0f)));
			fVec19[IOTA&127] = ((fSlow2 * (fRec20[1] + fRec20[2])) + (fSlow1 * (iRec3[0] * (fRec21[0] > 0.0f))));
			fRec20[0] = fVec19[(IOTA-86)&127];
			int iTemp13 = ((fTemp1 < 0.045454545454545456f) & (0.045454545454545456f < fTemp0));
			iVec20[0] = iTemp13;
			fRec23[0] = ((fRec23[1] + ((iVec20[0] - iVec20[1]) > 0.0f)) - (0.009977324263038548f * (fRec23[1] > 0.0f)));
			fVec21[IOTA&127] = ((fSlow2 * (fRec22[1] + fRec22[2])) + (fSlow1 * (iRec3[0] * (fRec23[0] > 0.0f))));
			fRec22[0] = fVec21[(IOTA-99)&127];
			output0[i] = (FAUSTFLOAT)(((((((((((0.9770084209183945f * fRec22[0]) + (0.9293203772845852f * fRec20[0])) + (0.8790490729915326f * fRec18[0])) + (0.8257228238447705f * fRec16[0])) + (0.7687061147858073f * fRec14[0])) + fTemp8) + (0.6396021490668313f * fRec10[0])) + (0.5640760748177662f * fRec8[0])) + (0.4767312946227962f * fRec6[0])) + (0.3692744729379982f * fRec4[0])) + (0.21320071635561033f * fRec0[0]));
			output1[i] = (FAUSTFLOAT)((((((fTemp8 + (((((0.21320071635561044f * fRec22[0]) + (0.3692744729379982f * fRec20[0])) + (0.4767312946227962f * fRec18[0])) + (0.5640760748177662f * fRec16[0])) + (0.6396021490668313f * fRec14[0]))) + (0.7687061147858074f * fRec10[0])) + (0.8257228238447705f * fRec8[0])) + (0.8790490729915326f * fRec6[0])) + (0.9293203772845852f * fRec4[0])) + (0.9770084209183945f * fRec0[0]));
			// post processing
			fRec22[2] = fRec22[1]; fRec22[1] = fRec22[0];
			fRec23[1] = fRec23[0];
			iVec20[1] = iVec20[0];
			fRec20[2] = fRec20[1]; fRec20[1] = fRec20[0];
			fRec21[1] = fRec21[0];
			iVec18[1] = iVec18[0];
			fRec18[2] = fRec18[1]; fRec18[1] = fRec18[0];
			fRec19[1] = fRec19[0];
			iVec16[1] = iVec16[0];
			fRec16[2] = fRec16[1]; fRec16[1] = fRec16[0];
			fRec17[1] = fRec17[0];
			iVec14[1] = iVec14[0];
			fRec14[2] = fRec14[1]; fRec14[1] = fRec14[0];
			fRec15[1] = fRec15[0];
			iVec12[1] = iVec12[0];
			fRec12[2] = fRec12[1]; fRec12[1] = fRec12[0];
			fRec13[1] = fRec13[0];
			iVec10[1] = iVec10[0];
			fRec10[2] = fRec10[1]; fRec10[1] = fRec10[0];
			fRec11[1] = fRec11[0];
			iVec8[1] = iVec8[0];
			fRec8[2] = fRec8[1]; fRec8[1] = fRec8[0];
			fRec9[1] = fRec9[0];
			iVec6[1] = iVec6[0];
			fRec6[2] = fRec6[1]; fRec6[1] = fRec6[0];
			fRec7[1] = fRec7[0];
			iVec4[1] = iVec4[0];
			fRec4[2] = fRec4[1]; fRec4[1] = fRec4[0];
			fRec5[1] = fRec5[0];
			iVec2[1] = iVec2[0];
			fRec0[2] = fRec0[1]; fRec0[1] = fRec0[0];
			IOTA = IOTA+1;
			iRec3[1] = iRec3[0];
			fRec1[1] = fRec1[0];
			iVec0[1] = iVec0[0];
			fRec2[1] = fRec2[0];
		}
	}
};


