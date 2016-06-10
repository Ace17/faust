//-----------------------------------------------------
// name: "spat"
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
	float 	fRec1[2];
	float 	fRec2[2];
	float 	fRec3[2];
	float 	fRec4[2];
	float 	fRec5[2];
	float 	fRec6[2];
	float 	fRec7[2];
  public:
	static void metadata(Meta* m) 	{ 
		m->declare("name", "spat");
		m->declare("version", "1.0");
		m->declare("author", "Grame");
		m->declare("license", "BSD");
		m->declare("copyright", "(c)GRAME 2006");
	}

	virtual int getNumInputs() 	{ return 1; }
	virtual int getNumOutputs() 	{ return 8; }
	static void classInit(int samplingFreq) {
	}
	virtual void instanceInit(int samplingFreq) {
		fSamplingFreq = samplingFreq;
		fslider0 = 0.5f;
		fslider1 = 0.0f;
		for (int i=0; i<2; i++) fRec0[i] = 0;
		for (int i=0; i<2; i++) fRec1[i] = 0;
		for (int i=0; i<2; i++) fRec2[i] = 0;
		for (int i=0; i<2; i++) fRec3[i] = 0;
		for (int i=0; i<2; i++) fRec4[i] = 0;
		for (int i=0; i<2; i++) fRec5[i] = 0;
		for (int i=0; i<2; i++) fRec6[i] = 0;
		for (int i=0; i<2; i++) fRec7[i] = 0;
	}
	virtual void init(int samplingFreq) {
		classInit(samplingFreq);
		instanceInit(samplingFreq);
	}
	virtual void buildUserInterface(UI* interface) {
		interface->openVerticalBox("Spatializer 1x8");
		interface->addHorizontalSlider("angle", &fslider1, 0.0f, 0.0f, 1.0f, 0.01f);
		interface->addHorizontalSlider("distance", &fslider0, 0.5f, 0.0f, 1.0f, 0.01f);
		interface->closeBox();
	}
	virtual void compute (int count, FAUSTFLOAT** input, FAUSTFLOAT** output) {
		float 	fSlow0 = float(fslider0);
		float 	fSlow1 = (1.0f + fSlow0);
		float 	fSlow2 = float(fslider1);
		float 	fSlow3 = (4.999999999999449e-05f * (sqrtf(max(0.0f, (1.0f - (8 * (fSlow0 * fabsf((fmodf((fSlow2 + 1.5f),1.0f) - 0.5f))))))) * fSlow1));
		float 	fSlow4 = (4.999999999999449e-05f * (fSlow1 * sqrtf(max(0.0f, (1.0f - (8 * (fSlow0 * fabsf((fmodf((fSlow2 + 1.375f),1.0f) - 0.5f)))))))));
		float 	fSlow5 = (4.999999999999449e-05f * (fSlow1 * sqrtf(max(0.0f, (1.0f - (8 * (fSlow0 * fabsf((fmodf((fSlow2 + 1.25f),1.0f) - 0.5f)))))))));
		float 	fSlow6 = (4.999999999999449e-05f * (fSlow1 * sqrtf(max(0.0f, (1.0f - (8 * (fSlow0 * fabsf((fmodf((fSlow2 + 1.125f),1.0f) - 0.5f)))))))));
		float 	fSlow7 = (4.999999999999449e-05f * (fSlow1 * sqrtf(max(0.0f, (1.0f - (8 * (fSlow0 * fabsf((fmodf((1.0f + fSlow2),1.0f) - 0.5f)))))))));
		float 	fSlow8 = (4.999999999999449e-05f * (fSlow1 * sqrtf(max(0.0f, (1.0f - (8 * (fSlow0 * fabsf((fmodf((fSlow2 + 0.875f),1.0f) - 0.5f)))))))));
		float 	fSlow9 = (4.999999999999449e-05f * (fSlow1 * sqrtf(max(0.0f, (1.0f - (8 * (fSlow0 * fabsf((fmodf((fSlow2 + 0.75f),1.0f) - 0.5f)))))))));
		float 	fSlow10 = (4.999999999999449e-05f * (fSlow1 * sqrtf(max(0.0f, (1.0f - (8 * (fSlow0 * fabsf((fmodf((fSlow2 + 0.625f),1.0f) - 0.5f)))))))));
		FAUSTFLOAT* input0 = input[0];
		FAUSTFLOAT* output0 = output[0];
		FAUSTFLOAT* output1 = output[1];
		FAUSTFLOAT* output2 = output[2];
		FAUSTFLOAT* output3 = output[3];
		FAUSTFLOAT* output4 = output[4];
		FAUSTFLOAT* output5 = output[5];
		FAUSTFLOAT* output6 = output[6];
		FAUSTFLOAT* output7 = output[7];
		for (int i=0; i<count; i++) {
			fRec0[0] = ((0.9999f * fRec0[1]) + fSlow3);
			float fTemp0 = (float)input0[i];
			output0[i] = (FAUSTFLOAT)(fTemp0 * fRec0[0]);
			fRec1[0] = ((0.9999f * fRec1[1]) + fSlow4);
			output1[i] = (FAUSTFLOAT)(fTemp0 * fRec1[0]);
			fRec2[0] = ((0.9999f * fRec2[1]) + fSlow5);
			output2[i] = (FAUSTFLOAT)(fTemp0 * fRec2[0]);
			fRec3[0] = ((0.9999f * fRec3[1]) + fSlow6);
			output3[i] = (FAUSTFLOAT)(fTemp0 * fRec3[0]);
			fRec4[0] = ((0.9999f * fRec4[1]) + fSlow7);
			output4[i] = (FAUSTFLOAT)(fTemp0 * fRec4[0]);
			fRec5[0] = ((0.9999f * fRec5[1]) + fSlow8);
			output5[i] = (FAUSTFLOAT)(fTemp0 * fRec5[0]);
			fRec6[0] = ((0.9999f * fRec6[1]) + fSlow9);
			output6[i] = (FAUSTFLOAT)(fTemp0 * fRec6[0]);
			fRec7[0] = ((0.9999f * fRec7[1]) + fSlow10);
			output7[i] = (FAUSTFLOAT)(fTemp0 * fRec7[0]);
			// post processing
			fRec7[1] = fRec7[0];
			fRec6[1] = fRec6[0];
			fRec5[1] = fRec5[0];
			fRec4[1] = fRec4[0];
			fRec3[1] = fRec3[0];
			fRec2[1] = fRec2[0];
			fRec1[1] = fRec1[0];
			fRec0[1] = fRec0[0];
		}
	}
};


